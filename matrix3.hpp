#pragma once
#include <cmath>
#include <ostream>
#include <vector>
#include "vec3.hpp"

struct Matrix3
{
    Vec3 x;
    Vec3 y;
    Vec3 z;


    Matrix3()
        : x({0.0, 0.0, 0.0})
        , y({0.0, 0.0, 0.0})
        , z({0.0, 0.0, 0.0})
    {
    }
    
    constexpr Matrix3(Vec3 a, Vec3 b, Vec3 c)
        : x(a)
        , y(b)
        , z(c) 
    {
    }

    double norm()
    {
        double a = x.x * y.y * z.z + x.y * y.z * z.x + x.y * y.x * z.y;
        double b = x.z * y.y * z.x + x.x * y.z * z.y + x.y * y.x * z.z;
        return a - b;
    }

    Matrix3 inv()
    {
        double d = this.norm();
        if(d == 0)
        {
            std::cout << "error: there is no inverse." << std::endl;
            return null;
        }
         Matrix mat =  {},\
                       {},\
                       {}};
         return mat/this.norm();
    }

    constexpr Matrix3 operator+() const
    {
        return *this;
    } 

    constexpr Matrix3 operator-() const
    {
        return {-x, -y, -z};
    }

    constexpr Matrix3 operator+(const Matrix3 &other) const
    { 
        return {x+other.x, y+other.y, z+other.z};
    }

    constexpr Matrix3 operator-(const Matrix3 other) const
    {
        return {x-other.x, y-other.y, z-other.z};
    }

    constexpr Matrix3 operator*(const Matrix3 &other)
    {
        Vec3 r1 = {other.x.x, other.y.x, other.z.x};
        Vec3 r2 = {other.x.y, other.y.y, other.z.y};
        Vec3 r3 = {other.x.z, other.y.z, other.z.z};
        x = {x.dot(r1), x.dot(r2), x.dot(r3)};
        y = {y.dot(r1), y.dot(r2), y.dot(r3)};
        z = {z.dot(r1), z.dot(r2), z.dot(r3)};
        return *this;
    }

    constexpr Matrix3 operator*(const double s)
    {
        return {x*s, y*s, z*s};
    }

    constexpr Matrix3 operator/(const double s)
    {
        return {x/s, y/s, z/s};
    }

    Matrix3 & operator+=(const Matrix3 &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Matrix3 & operator-=(const Matrix3 &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Matrix3 & operator*=(double s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    Matrix3 & operator/=(double s)
    {
        x /= s;
        y /= s;
        z /= s;
        return *this;
    }
    friend std::ostream & operator<<(std::ostream & os, const Matrix3 & mat)
    {
        return os << "(" << mat.x<< std::endl << " " << mat.y << std::endl << " " << mat.z << ")";
    }
};
