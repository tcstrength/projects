#include "Misc.h"

double Misc::deg2Rad(double deg)
{
    return deg * RAD_UNIT;
}

double Misc::rad2Deg(double rad)
{
    return rad / RAD_UNIT;
}

int Misc::rand2m(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

float Misc::randf()
{
    return static_cast<float>(randlf());
}

double Misc::randlf()
{
    bool neg = rand() % 2;

    if (neg)
        return -1 * rand() / RAND_MAX;

    return rand() % RAND_MAX;
}

Misc::Vector2d::Vector2d()
:   Vector2d(0.l, 0.l)
{

}

Misc::Vector2d::Vector2d(double x_, double y_)
:   x(x_)
,   y(y_)
{

}

double Misc::distance2Vec(const Misc::Vector2d & p1, const Misc::Vector2d & p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return std::sqrt(dx * dx + dy * dy);
}

Misc::Vector2d& Misc::polarProjection(const Misc::Vector2d & p1, const double & offset, const double & radian)
{
    static Vector2d result;
    result.x = p1.x + offset * std::cos(radian);
    result.y = p1.y + offset * std::sin(radian);
    return result;
}
