#include "degree.hpp"
#include <iostream>

namespace Degree
{

    double normalizeRelative(double deg)
    {
        // NaNは足しても引いてもNaNのままなので無限ループに陥る
        if (std::isnan(deg))
        {
            std::cout << "Error: Failed to normalize degree! (deg=" << deg << ')' << std::endl;
            return deg;
        }

        // 値の指数が大きいと360を足しても引いても変わらなくて無限ループに陥る
        if (deg > 1e9 || deg < -1e9)
        {
            std::cout << "Error: Failed to normalize degree! (deg=" << deg << ')' << std::endl;
            return 0.0;
        }

        while (deg >= 180.0)
        {
            deg -= 360.0;
        }

        while (deg < -180.0)
        {
            deg += 360.0;
        }

        return deg;
    }

    double normalizeAbsolute(double deg)
    {
        // NaNは足しても引いてもNaNのままなので無限ループに陥る
        if (std::isnan(deg))
        {
            std::cout << "Error: Failed to normalize degree! (deg=" << deg << ')' << std::endl;
            return deg;
        }

        // 値の指数が大きいと360を足しても引いても変わらなくて無限ループに陥る
        if (deg > 1e9 || deg < -1e9)
        {
            std::cout << "Error: Failed to normalize degree! (deg=" << deg << ')' << std::endl;
            return 0.0;
        }

        while (deg >= 360.0)
        {
            deg -= 360.0;
        }

        while (deg < 0.0)
        {
            deg += 360.0;
        }

        return deg;
    }
}
