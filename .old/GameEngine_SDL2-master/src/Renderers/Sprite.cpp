#include "Sprite.h"

Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}

void Sprite::read(SDL_Renderer* renderer, const char* fileName)
{
    std::ifstream inStream(fileName);
    std::string buffer;
    std::string substr;
    std::string value;
    Animation anim;

    while (std::getline(inStream, buffer))
    {
        LOG_DEBUG("Buffer: " << buffer);

        if (buffer[0] == '[')
        {
            substr = buffer.substr(1, buffer.length() - 2);

            if (substr == "end")
            {
                _animations[anim.name] = anim;
                LOG_DEBUG("Name: " << anim.name);
                LOG_DEBUG("Row: " << anim.row);
                LOG_DEBUG("Cols: " << anim.cols);
                LOG_DEBUG("Width: " << anim.width);
                LOG_DEBUG("Height: " << anim.height);
            }
            else
                anim.name = substr;
        }
        else
        {
            substr = buffer.substr(0, buffer.rfind('='));
            value = buffer.substr(buffer.rfind('=') + 1);
        }

        if (substr == "image")
            load(renderer, value.c_str());
        else if (substr == "row")
            anim.row = std::stoi(value);
        else if (substr == "cols")
            anim.cols = std::stoi(value);
        else if (substr == "width")
            anim.width = std::stoi(value);
        else if (substr == "height")
            anim.height = std::stoi(value);
    }
}

void Sprite::delay(uint ticks)
{
    _delay = ticks;
    _delayTicks = 0;
}

void Sprite::tick()
{
    if (++_delayTicks < _delay)
        return;
    else
        _delayTicks = 0;

    if (_ticks >= _cols)
        _ticks = 0;

    _crop.x = _crop.w * _ticks;
    _crop.y = _crop.h * _currentRow;

    ++_ticks;
}

void Sprite::playAnimation(std::string animationName)
{
    Animation anim = _animations[animationName];

    if (anim.name.empty())
        return;

    playAnimation(anim.row, anim.cols, anim.width, anim.height);
}

void Sprite::playAnimation(int row, int cols, int imgW, int imgH)
{
    _currentRow = row;
    _cols = cols;
    _crop.w = imgW;
    _crop.h = imgH;
    _ticks = 0;

    _crop.x = _crop.w * _ticks;
    _crop.y = _crop.h * _currentRow;
}

