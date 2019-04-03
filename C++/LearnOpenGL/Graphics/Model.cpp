#include "Model.h"

namespace graphics {

Model::Model(const char* path)
{
    if (utils::isFileExist(path) == false)
    {
        LOG_ERROR("File not found " << path);
    }

    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_JoinIdenticalVertices);

    if (!scene || scene->mRootNode == nullptr)
    {
        LOG_ERROR("Failed to load model " << path);
    }

    m_directory = std::string(path);
    m_directory = m_directory.substr(0, m_directory.find_last_of('/')) + '/';

    processNode(scene->mRootNode, scene);
    loadTextures(scene->mMaterials, scene);
}

Model::~Model()
{
    for (uint i = 0; i < m_meshes.size(); ++i)
    {
        delete m_meshes[i].mesh;
    }

    for (uint i = 0; i < m_textures.size(); ++i)
    {
        delete m_textures[i];
    }
}

void Model::draw()
{
    for (uint i = 0; i < m_meshes.size(); ++i)
    {
        uint index = m_meshes[i].matIndex;

        if (index < m_textures.size() && m_textures[index])
        {
            m_textures[index]->bind();
        }

        m_meshes[i].mesh->draw();
    }
}

void Model::processNode(const aiNode* node, const aiScene* scene)
{
    for (uint i = 0; i < node->mNumMeshes; ++i)
    {
        const aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        LOG_DEBUG("material index: " << mesh->mMaterialIndex);
        m_meshes.push_back({processMesh(mesh, scene), mesh->mMaterialIndex});
    }

    for (uint i = 0; i < node->mNumChildren; ++i)
    {
        processNode(node->mChildren[i], scene);
    }
}

Mesh*Model::processMesh(const aiMesh* mesh, const aiScene* scene)
{
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;

    for (uint i = 0; i < mesh->mNumVertices; ++i)
    {
        Vertex vertex;
        glm::vec3 vec3(0.f);
        glm::vec2 vec2(0.f);

        vec3.x = mesh->mVertices[i].x;
        vec3.y = mesh->mVertices[i].y;
        vec3.z = mesh->mVertices[i].z;
        vertex.position = vec3;

        if (mesh->mTextureCoords[0])
        {
            vec2.x = mesh->mTextureCoords[0][i].x;
            vec2.y = mesh->mTextureCoords[0][i].y;
            vertex.texCoord = vec2;
        }

        vertex.texCoord = vec2;

        vertices.push_back(vertex);
    }

    for (uint i = 0; i < mesh->mNumFaces; ++i)
    {
        aiFace face = mesh->mFaces[i];

        for (uint j = 0; j < face.mNumIndices; ++j)
        {
            indices.push_back(face.mIndices[j]);
        }
    }

    return new Mesh(vertices, indices);
}

void Model::loadTextures(aiMaterial** materials, const aiScene* scene)
{
    m_textures.resize(scene->mNumMaterials, nullptr);

    for (uint i = 0; i < scene->mNumMaterials; ++i)
    {
        aiMaterial* mat = materials[i];
        if (mat->GetTextureCount(aiTextureType_DIFFUSE) > 0)
        {
            aiString texturePath;
            if (mat->GetTexture(aiTextureType_DIFFUSE, 0, &texturePath) == AI_SUCCESS)
            {
                std::string fullPath = m_directory + texturePath.data;
                m_textures[i] = new Texture(fullPath.c_str());
            }
        }
    }
}

bool Model::checkTextureConflict(std::string path)
{
    for (uint i = 0; i < m_textures.size(); ++i)
    {
        if (m_textures[i] != nullptr)
        {
            if (m_textures[i]->getPath() == path)
            {
                return true;
            }
        }
    }

    return false;
}

}


