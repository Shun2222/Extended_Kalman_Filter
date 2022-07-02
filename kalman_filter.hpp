#pragma once
#include"matrix3.hpp"
#include "Vex3.hpp"

class KalmanFilter
{
    private:
        // 分散
        const double m_sigmaWheelX;
        const double m_sigmaWheelY;
        const double m_sigmaWheelTheta;
        const double m_sigmaLoRaX;
        const double m_sigmaLoRaY;
        const double m_sigmaLoRaTheta;

        const double m_T;
        const double m_theta;
        const double m_dt;

        const Matrix3 m_Q;
        const Matrix3 m_R;
        Vec3 xhat;
        Matrix3 m_P;
        Matrix3 m_Phat;
        Matrix3 m_K;

    public:
        KalmanFilter();
        ~KalmanFilter();
        Vec3 f();
        Vec3 h();
        Vec3 filtering();
}


