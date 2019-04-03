#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
public:
    Player(Context& context);

    void tick();
};

#endif // PLAYER_H
