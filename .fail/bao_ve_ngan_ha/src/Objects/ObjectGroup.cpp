#include "ObjectGroup.h"

ObjectGroup::ObjectGroup()
{

}

ObjectGroup::~ObjectGroup()
{
    destroy();
}

void ObjectGroup::add(GameObject *go)
{
    if (go == nullptr)
        return;

    m_gobjects.push_back(go);
}

void ObjectGroup::del(GameObject *go)
{
    if (go == nullptr)
        return;

    m_gobjects.remove(go);
    delete go;
}

void ObjectGroup::destroy()
{
    for (auto obj : m_gobjects)
        delete obj;

    m_gobjects.clear();
}

void ObjectGroup::tick()
{
    for (auto obj : m_gobjects)
        obj->tick();
}

void ObjectGroup::draw()
{
    for (auto obj : m_gobjects)
        obj->draw();
}
