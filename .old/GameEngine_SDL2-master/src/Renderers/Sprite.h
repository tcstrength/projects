#ifndef SPRITE_H
#define SPRITE_H

#include "RenderObject.h"

class Sprite : public RenderObject {
public:
    struct Animation {
        std::string name;
        int row;
        int cols;
        int width;
        int height;
    };

    Sprite();

    virtual ~Sprite();

    // Read .sprite file extension
    void read(SDL_Renderer* renderer, const char* fileName);

    // Play a sequence of 'cols' cropped images at row 'row'
    void playAnimation(int row, int cols, int imgW, int imgH);

    void playAnimation(std::string animationName);

    void tick();

    void delay(uint ticks);

private:
    std::map<std::string, Animation> _animations;
    uint _ticks;
    uint _currentRow;
    uint _cols;
    uint _delay;
    uint _delayTicks;
};

#endif // SPRITE_H
