#include "GameHandler.h"

GameHandler::GameHandler(Context& context)
:   m_context(context)
{

}

GameHandler::~GameHandler()
{
    for (auto obj : m_objects)
        delete obj.second;

    m_objects.clear();
}

uint GameHandler::createBasicEnemy(sf::Vector2f position)
{
    BasicEnemy* enemy = new BasicEnemy(m_context);
    uint index = m_indexer.allocate();

    enemy->setPosition(position);
    enemy->setScale(4.f);

    m_objects[index] = enemy;
    return index;
}

BasicEnemy*GameHandler::getBasicEnemy(uint index)
{
    return (BasicEnemy*)getObject(index);
}

uint GameHandler::createRifleMan(sf::Vector2f position)
{
    Rifleman* rifleman = new Rifleman(m_context);
    uint index = m_indexer.allocate();

    rifleman->setPosition(position);
    rifleman->setScale(4.f);

    m_objects[index] = rifleman;
    return index;
}

Rifleman*GameHandler::getRifleman(uint index)
{
    return (Rifleman*)getObject(index);
}

uint GameHandler::createBullet(sf::Vector2f position)
{
    Bullet* bullet = new Bullet(m_context);
    uint index = m_indexer.allocate();
    bullet->setPosition(position);
    m_objects[index] = bullet;
    return index;

}

void GameHandler::destroyObject(uint index)
{
    auto it = m_objects.find(index);

    if (it == m_objects.end())
    {
        LOG_DEBUG("Object is not existing");
        return;
    }

    m_indexer.deallocate(index);
    delete it->second;
    m_objects.erase(it);
}

GameObject* GameHandler::getObject(uint index)
{
    auto it = m_objects.find(index);

    if (it == m_objects.end())
    {
        return nullptr;
    }

    return it->second;
}

void GameHandler::tick()
{
    for (auto obj : m_objects)
    {
        obj.second->tick();
        if (obj.second->isDone())
        {
            destroyObject(obj.first);
            continue;
        }
    }
}

void GameHandler::draw()
{
    for (auto obj : m_objects)
    {
        obj.second->draw();
    }
}
