#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "GameObjects/GameObject.h"
#include "GameObjects/BasicEnemy.h"
#include "GameObjects/Rifleman.h"
#include "GameObjects/Bullet.h"
#include "../Utils/Indexer.h"

class GameHandler
{
public:
    GameHandler(Context& context);

    ~GameHandler();

    uint createBasicEnemy(sf::Vector2f position = sf::Vector2f(0.f, 0.f));

    BasicEnemy* getBasicEnemy(uint index);

    uint createRifleMan(sf::Vector2f position);

    Rifleman* getRifleman(uint index);

    uint createBullet(sf::Vector2f position);

    void destroyObject(uint index);

    GameObject* getObject(uint index);

    void tick();

    void draw();
private:
    Context& m_context;
    Indexer m_indexer;
    std::map<uint, GameObject*> m_objects;
};

#endif // GAMEHANDLER_H
