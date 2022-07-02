#include "kalman_filter.hpp"

KalmanFilter::KalmanFilter()
    : m_sigmaWheelX(0.01)
    , m_sigmaWheelY(0.01)
    , m_sigmaWheelTheta(0.01)
    , m_sigmaLoRaX(0.01)
    , m_sigmaLoRaY(0.01)
    , m_sigmaLoRaTheta()
    , m_O({{m_sigmaWheelX, 0, 0}\
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

KalmanFilter::f()
{
    // get data form wheel
    return m_xhat + {1.01, 1.01, 1.01};
}

KalmanFilter::h()
{
    // get data from lora
    return m_xhat + {1, 1, 1};
}

KalmanFilter::filter()
{
    Vec3 x = f();
    Vec3 y = h();
    m_P = m_Phat + m_Q;
    m_K = m_P * (m_P + m_R).inv();
    m_xhat = x + m_K * (y - x);  
}
    
