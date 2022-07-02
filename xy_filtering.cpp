#include "extended_kalman_filter.hpp"
 
EKF::EKF()
    : m_sigmaWr(0.08)
    , m_sigmaWl(0.08)
    , m_sigmaax(0.05)
    , m_sigmaay(0.05)
    , m_dt(0.1)
    , m_Rr(0.01)
    , m_Rl(0.01)
    , m_theta(0.1)
    , m_T(0.01)
{
    // 誤差の設定
    m_Q = Eigen::MatrixXd::Zero(2, 2);
    m_Q(0, 0) = m_sigmaWr * m_sigmaWr;
    m_Q(1, 1) = m_sigmaWl * m_sigmaWl;
    // Vはオドメトリのヤコビアン
    m_V = Eigen::MatrixXd::Zero(2, 2);
    m_V(0, 0) = - ( m_Rr * m_Rr * m_dt * m_dt * std::sin( m_theta ) ) / ( 2 * m_T );
    m_V(0, 1) = - ( m_Rl * m_Rl * m_dt * m_dt * std::sin( m_theta ) ) / ( 2 * m_T );
    m_V(1, 0) =   ( m_Rr * m_Rr * m_dt * m_dt * std::cos( m_theta ) ) / ( 2 * m_T );
    m_V(1, 1) =   ( m_Rl * m_Rl * m_dt * m_dt * std::cos( m_theta ) ) / ( 2 * m_T ); 

    // 状態値の分散  
    m_Q =m_ V * m_Q * m_V.transpose();

    // 観測値の分散
    m_R = Eigen::MatrixXd::Zero(2, 2);
    m_R(0, 0) = m_sigmaax * m_sigmaax;
    m_R(1, 1) = m_sigmaay * m_sigmaay;
    m_R *= m_dt;
}

EKF::~EKF()
{
}

Eigen::MatrixXd EKF::f()
{
    Eigen::Matrix<double, 2, 1> x(2, 1);
    x(0, 0) = 1.8; // test value
    x(1, 0) = 0.5; // test value
    return x;
}

Eigen::Matrix<double, 2, 1> EKF::h()
{
    Eigen::Matrix<double, 2, 1> x(2, 1);
    x(0, 0) = 1.6; // test value
    x(1, 0) = 0.1; // test value
    return x;
}

Eigen::Matrix<double, 2, 1> EKF::filtering()
{
    //Prediction Step
    m_x = f(); // Predixt State Value
    m_y = h(); // Observation Value
    
    // Filtering Step
    m_K = m_Q ( m_P + m_R ).inverse();
    m_x += m_K * ( m_y - m_x ); // estimate State Value
    return m_x;
}
