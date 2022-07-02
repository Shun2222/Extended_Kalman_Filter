#include "kalman_filter.hpp"

KalmanFilter::KalmanFilter()
    : m_sigmaWheelX(0.01)
    , m_sigmaWheelY(0.01)
    , m_sigmaWheelTheta(0.01)
    , m_sigmaLoRaX(0.01)
    , m_sigmaLoRaY(0.01)
    , m_sigmaLoRaTheta()
    , m_Q({{m_sigmaWheelX, 0, 0}\
          ,{0, m_sigmaWheelY, 0}\
          ,{0, 0, m_sigmaWheelTheta}}) 
    , m_R({{m_sigmaLoRaX, 0, 0}\
          ,{0, m_sigmaLoRaY, 0}\
          ,{0, 0, m_sigmaLoRaTheta}})
    , m_T(0.1)
    , m_theta(0.0)
    , m_dt(0.1)
    , m_xhat({0, 0, 0})
{
}
KalmanFilter::~KalmanFilter()
{
    m_xhat = {0, 0, 0};
}
Vec2 KalmanFilter::getXY()
{
    Vec2 xy = {m_xhat.x, m_xhat.y};
    return xy;
}

double KalmanFilter::getTheta()
{
    return m_xhat.z;
}

Vec3 KalmanFilter::f()
{
    // get data form wheel
    Vec3 delta = {1.01, 1.01, 1.01};
    return m_xhat + delta;
}

Vec3 KalmanFilter::h()
{
    // get data from lora
    Vec3 delta = {1, 1, 1};
    return m_xhat + delta;
}

Vec3 KalmanFilter::filter()
{
    Vec3 x = f();
    Vec3 y = h();
    m_P = m_Phat + m_Q;
    m_K = m_P * (m_P + m_R).inv();
    Vec3 xy = y - x;
    m_xhat = x + m_K * xy;
    return m_xhat;  
}
    
