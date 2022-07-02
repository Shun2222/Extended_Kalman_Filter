//#pragma once
#define _USE_MATH_DEFINES
#include <cmath> // TODO: C++20以降では<numbers>ヘッダが使えるようになるのでそっちを使う

namespace Degree
{
    constexpr double toRadian(double deg)
    {
        return deg * M_PI / 180.0;
    }

    constexpr double fromRadian(double rad)
    {
        return rad * 180.0 / M_PI;
    }

    // 角度を -180 〜 180 の範囲に丸める
    double normalizeRelative(double deg);

    // 角度を 0 〜 360 の範囲に丸める
    double normalizeAbsolute(double deg);
}
