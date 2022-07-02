//#pragma once
#include <cmath>
#include "degree.hpp"

// 注意:
//   旧プログラム(2018以前)では, 経度/緯度としてVec3のx/yが使用されていました(zは標高のはずだが結局不使用)
//   移植の際には, xがlng, yがlatとなり, 対応する順番が逆なので注意してください
//   また, 旧プログラムであっても一部チームでは順番が逆(xがlat, yがlng)なので十分に注意してください(例: 2018 Ares)
//
//   xyz座標系と混同すると非常に危険なので, 今後は地理座標にはVec3ではなくLatLngを使用するようにしてください

// 緯度/経度
struct LatLng
{
    double lat; // 緯度(latitude) 度単位
    double lng; // 経度(longitude) 度単位

    constexpr LatLng(double lat, double lng)
        : lat(lat)
        , lng(lng)
    {
    }

    // 指定地点からの距離を返す(メートル単位)
    double distanceFrom(const LatLng & other) const;

    // 指定地点から矢印を引いた場合の方位を返す(度単位, 0〜360の範囲)
    double azimuthFrom(const LatLng & other) const;
};
