#include "GameEngine.h"

int main()
{
    Config config;
    GameEngine game(config);
    game.run();
    return 0;
}






























//#include "Context.h"
//#include "Info.h"
//#include "GUI/Widget.h"
//#include "GUI/Button.h"
//#include "GUI/Container.h"

//void handleEvents(Context& context);
//void draw(Context& context);

//int main()
//{
//    Config config;
//    Context context(config);
//    Container container;

//    Button widget(context);
//    Button btn2(context);

//    Info info(context, config);

//    btn2.setPosition({200, 400});
//    btn2.setTextString("What the fuck");
//    btn2.setWidth(400);
//    widget.setPosition({200, 200});
//    widget.setWidth(400);

//    container.add(&btn2);
//    container.add(&widget);

////    sf::RoundedRectangleShape bug;

//    while (context.window.isOpen())
//    {
//        info.update();
//        handleEvents(context);

//        container.handleEvents();

//        context.window.clear();

//        container.draw();
//        info.draw();

//        if (widget.wasPressed())
//        {
//            LOG_DEBUG("Pressed");
//        }

////        context.window.draw(bug);
//        context.window.display();
//    }

//    return 0;
//}

//void draw(Context& context)
//{
//    context.window.clear();

//    context.window.display();
//}

//void handleEvents(Context& context)
//{
//    while (context.window.pollEvent(context.event))
//    {
//        switch(context.event.type)
//        {
//            case sf::Event::Closed:
//                context.window.close();
//                break;

//            case sf::Event::KeyPressed:
//                if (context.event.key.code == sf::Keyboard::Escape)
//                {
//                    context.window.close();
//                }
//                break;

//            default:
//                break;
//        }
//    }
//}
