#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"
#include "Texture.h"
#include "../Utils/Misc.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace graphics {

class Model
{
public:
    struct MeshEntry
    {
        Mesh* mesh;
        uint matIndex;
    };

    Model(const char* path);

    ~Model();

    void draw();

private:
    void processNode(const aiNode* node, const aiScene* scene);

    Mesh* processMesh(const aiMesh* mesh, const aiScene* scene);

    void loadTextures(aiMaterial** materials, const aiScene* scene);

    bool checkTextureConflict(std::string path);

    std::vector<MeshEntry> m_meshes;
    std::vector<Texture*> m_textures;
    std::string m_directory;

};

}
#endif // MODEL_H
