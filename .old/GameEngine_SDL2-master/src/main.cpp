#include "GUI/Widgets/Window.h"
#include "GUI/Widgets/Text.h"
#include "GUI/Widgets/Button.h"
#include "GUI/Widgets/LineEdit.h"
#include "Renderers/ElasticImage.h"
#include "Renderers/Sprite.h"

Window window("HAHAHA", 800, 600);
ElasticImage image;
Sprite sprite;

void tick()
{
}

int main()
{
    window.connect(tick);
    window.loop();

    return 0;
}
