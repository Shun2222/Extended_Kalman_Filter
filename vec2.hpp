//#pragma once
#include <cmath>
#include <ostream>

struct Vec2
{
    double x;
    double y;

    Vec2()
        : x(0.0)
        , y(0.0)
    {
    }

    constexpr Vec2(double x, double y)
        : x(x)
        , y(y)
    {
    }

    double norm() const
    {
        return std::sqrt(dot(*this));
    }

    constexpr double dot(const Vec2 & other) const
    {
        return x * other.x + y * other.y;
    }

    double distanceFrom(const Vec2 & other) const
    {
        return (other - *this).norm();
    }

    Vec2 normalized() const
    {
        return *this / norm();
    }

    constexpr Vec2 operator+() const
    {
        return *this;
    }

    constexpr Vec2 operator-() const
    {
        return{ -x, -y };
    }

    constexpr Vec2 operator+(const Vec2 & other) const
    {
        return{ x + other.x, y + other.y };
    }

    constexpr Vec2 operator-(const Vec2 & other) const
    {
        return{ x - other.x, y - other.y };
    }

    constexpr Vec2 operator*(double s) const
    {
        return{ x * s, y * s };
    }

    constexpr Vec2 operator/(double s) const
    {
        return{ x / s, y / s };
    }

    Vec2 & operator+=(const Vec2 & other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2 & operator-=(const Vec2 & other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2 & operator*=(double s)
    {
        x *= s;
        y *= s;
        return *this;
    }

    Vec2 & operator/=(double s)
    {
        x /= s;
        y /= s;
        return *this;
    }

    friend std::ostream & operator<<(std::ostream & os, const Vec2 & vec2)
    {
        return os << '(' << vec2.x << ", " << vec2.y << ')';
    }
};