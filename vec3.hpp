#pragma once
#include <cmath>
#include <ostream>

struct Vec3
{
    double x;
    double y;
    double z;

    Vec3()
        : x(0.0)
        , y(0.0)
        , z(0.0)
    {
    }

    constexpr Vec3(double x, double y, double z)
        : x(x)
        , y(y)
        , z(z)
    {
    }

    double norm() const
    {
        return std::sqrt(dot(*this));
    }

    constexpr double dot(const Vec3& other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    double distanceFrom(const Vec3& other) const
    {
        return (other - *this).norm();
    }

    Vec3 normalized() const
    {
        return *this / norm();
    }

    constexpr Vec3 operator+() const
    {
        return *this;
    }

    constexpr Vec3 operator-() const
    {
        return{ -x, -y, -z };
    }

    constexpr Vec3 operator+(const Vec3& other) const
    {
        return{ x + other.x, y + other.y, z + other.z };
    }

    constexpr Vec3 operator-(const Vec3& other) const
    {
        return{ x - other.x, y - other.y, z - other.z };
    }

    constexpr Vec3 operator*(double s) const
    {
        return{ x * s, y * s, z * s };
    }

    constexpr Vec3 operator/(double s) const
    {
        return{ x / s, y / s, z / s };
    }

    Vec3 & operator+=(const Vec3 & other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vec3 & operator-=(const Vec3 & other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vec3 & operator*=(double s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    Vec3 & operator/=(double s)
    {
        x /= s;
        y /= s;
        z /= s;
        return *this;
    }

    friend std::ostream & operator<<(std::ostream & os, const Vec3 & vec3)
    {
        return os << '(' << vec3.x << ", " << vec3.y << ", " << vec3.z << ')';
    }
};
