#ifndef MISC_H
#define MISC_H

#include <iostream>
#include <assert.h>
#include <cmath>

namespace Misc {

    struct Vector2d {
        Vector2d();

        Vector2d(double x_, double y_);

        double x;
        double y;
    };

    const double PI = std::acos(-1);

    const double RAD_UNIT = PI/180;

    ///////////////////////////////////
    /// \brief randlf random between -1..1
    /// \return double
    ///
    double randlf();

    ///////////////////////////////////
    /// \brief randf random between -1..1
    /// \return float
    ///
    float randf();

    //////////////////////////////////
    /// \brief rand2m random integer between min..max
    ///
    int rand2m(int min, int max);

    //////////////////////////////////
    /// \brief deg2Rad convert degree to radian
    /// \param deg
    /// \return
    ///
    double deg2Rad(double deg);

    //////////////////////////////////
    /// \brief rad2Deg convert radian to degree
    /// \param rad
    /// \return
    ///
    double rad2Deg(double rad);

    //////////////////////////////////
    /// \brief distance2Vec compute distance between 2 vectors
    /// \param p1
    /// \param p2
    /// \return
    ///
    double distance2Vec(const Vector2d& p1, const Vector2d& p2);

    //////////////////////////////////
    /// \brief polarProjection everyone know this
    /// \param p1
    /// \param offset
    /// \param radian
    /// \return
    ///
    Vector2d& polarProjection(const Vector2d& p1, const double& offset, const double& radian);
}

#endif // MISC_H
