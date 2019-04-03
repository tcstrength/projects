#ifndef OBJECTGROUP_H
#define OBJECTGROUP_H

#include "GameObject.h"
#include "Player.h"
#include <list>

class ObjectGroup
{
public:
    ObjectGroup();

    ~ObjectGroup();

    void add(GameObject* go);

    void del(GameObject* go);

    void destroy();

    void tick();

    void draw();

private:

    std::list<GameObject*> m_gobjects;
};

#endif // OBJECTGROUP_H
