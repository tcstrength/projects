#include "src/Screen.h"
#include "src/Clock.h"
#include "src/Sprite.h"

std::vector<std::string> crap =
{
    "{}      {}",
    "((((()))))",
    " (((()))) ",
    "  ((()))  "
};

int main()
{
    Screen screen(80, 20);
    screen.setFrameLimit(60);

    Sprite sprite(crap);
    sprite.setPosX(15);
    sprite.setPosY(3);

    while(1)
    {
        screen.clear();

        for (uint i = 0; i < 3; ++i)
        {
            sprite.setPosY(i * 5);
            sprite.setPosX(sprite.getPosX() + 1);
            sprite.render(screen);

            if (sprite.getPosX() >= 80)
                sprite.setPosX(0);
        }

        for (uint i = 0; i < 3; ++i)
        {
            sprite.setPosY(i * 5);
            sprite.setPosX(sprite.getPosX() + 3);
            sprite.render(screen);

            if (sprite.getPosX() >= 80)
                sprite.setPosX(0);
        }

        screen.display();
    }
    return 0;
}
