#include "EKF3.hpp"


EKF::EKF()
    : m_sigmaWr(0.05)
    , m_sigmaWl(0.05)
    , m_sigmaax(0.001)
    , m_sigmaay(0.001)
    , m_T(0.05)
    , m_theta(0.1)
    , m_Rr(0.08)
    , m_Rl(0.08)
    , m_dt(0.1)
{
    // 誤差の設定
    Q = Eigen::MatrixXd::Zero(2, 2);
    Q(0, 0) = m_sigmaWr * m_sigmaWr;
    Q(1, 1) = m_sigmaWl * m_sigmaWl;
    // VはFを線形化に必要
    V = Eigen::MatrixXd::Zero(2, 2);
    V(0, 0) = - ( m_Rr * m_Rr * m_dt * m_dt * std::sin( m_theta ) ) / ( 2 * m_T );
    V(0, 1) = - ( m_Rl * m_Rl * m_dt * m_dt * std::sin( m_theta ) ) / ( 2 * m_T );
    V(1, 0) =   ( m_Rr * m_Rr * m_dt * m_dt * std::cos( m_theta ) ) / ( 2 * m_T );
    V(1, 1) =   ( m_Rl * m_Rl * m_dt * m_dt * std::cos( m_theta ) ) / ( 2 * m_T ); 

    // 状態値の分散  
    Q = V * Q * V.transpose();

    // 観測値の分散
    R = Eigen::MatrixXd::Zero(2, 2);
    R(0, 0) = m_sigmaax * m_sigmaax;
    R(1, 1) = m_sigmaay * m_sigmaay;
    V = Eigen::MatrixXd::Zero(2, 2);
    V(0, 0) = m_dt * m_dt;
    V(1, 1) = m_dt * m_dt;
    R = V * R * V.inverse();

    // 状態値と観測値の初期値
    x = f();
    y = h();

    // 観測値のヤコビ行列(今回は単位行列のために行列ではなくdouble型)
    H = Eigen::MatrixXd::Identity(2, 2);
    I = Eigen::MatrixXd::Identity(2, 2); // 単位行列
    Phat = Eigen::MatrixXd::Zero(2, 2); // 事後誤差共分散行列

    std::cout << "Q" << std::endl;
    std::cout << Q << std::endl;
    std::cout << "R" << std::endl;
    std::cout << R << std::endl;
}

EKF::~EKF()
{
}

Eigen::MatrixXd EKF::f()
{
    Eigen::MatrixXd x(2, 1);
    x(0, 0) = 1.8;
    x(1, 0) = 0.5;
    return x;
}

Eigen::MatrixXd EKF::h()
{
    Eigen::MatrixXd x(2, 1);
    x(0, 0) = 1;
    x(1, 0) = 1;
    return x;
}

Eigen::MatrixXd EKF::filtering()
{
    //Prediction Step
    x = f(); // Predixt State Value
    y = h(); // Observation Value
    P = Phat + Q;
    // Filtering Step
    K = P * ( P + R ).inverse();
    x = x + K * ( y - x ); // estimate State Value
    Phat = ( I - K ) * P; // update Phat
    return x;
}