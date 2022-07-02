#include "lat_lng.hpp"

double LatLng::distanceFrom(const LatLng & other) const
{
    // 以下を参考に実装(国土地理院の値と誤差0.1%の似た結果が出ることを確認できたので採用)
    // https://teratail.com/questions/90662

    // 地球の長半径
    constexpr double EARTH_RADIUS = 6378137.0;

    // ラジアンへ変換
    const double latRadian = Degree::toRadian(lat); // 緯度
    const double lngRadian = Degree::toRadian(lng); // 経度
    const double otherLatRadian = Degree::toRadian(other.lat);
    const double otherLngRadian = Degree::toRadian(other.lng);

    // 経度の差分
    const double lngRadianDiff = otherLngRadian - lngRadian;

    return EARTH_RADIUS * std::acos(
        std::sin(latRadian) * std::sin(otherLatRadian) +
        std::cos(latRadian) * std::cos(otherLatRadian) * std::cos(lngRadianDiff)
    );
}

double LatLng::azimuthFrom(const LatLng & other) const
{
    // ↓球を仮定しているためか国土地理院の計算ページ(※)との誤差が砂漠のGPS座標で5度程度出たため, この計算方法は廃止
    //   ※https://vldb.gsi.go.jp/sokuchi/surveycalc/surveycalc/bl2stf.html
    //   他の計算サイトでもほぼ同じ値が出たので国土地理院が正しいと思われる
    // return atan2(target.y - current.y, target.x - current.x) / M_PI * 180; // 2017以前の実装(x:lng, y:lat)

    // 以下を参考に実装(国土地理院の値と似た結果が出ることを確認できたので採用)
    // https://teratail.com/questions/90662

    // ラジアンへ変換
    const double latRadian = Degree::toRadian(lat); // 緯度
    const double lngRadian = Degree::toRadian(lng); // 経度
    const double otherLatRadian = Degree::toRadian(other.lat);
    const double otherLngRadian = Degree::toRadian(other.lng);

    const double lngRadianDiff = otherLngRadian - lngRadian;
    const double y = std::sin(lngRadianDiff);
    const double x = std::cos(latRadian) * std::tan(otherLatRadian) - std::sin(latRadian) * std::cos(lngRadianDiff);

    return Degree::normalizeAbsolute(Degree::fromRadian(std::atan2(y, x)) + 180.0);
}
