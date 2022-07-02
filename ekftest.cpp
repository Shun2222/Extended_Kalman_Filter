#include <iostream>
#include "extended_kalman_filter.hpp"

int main(){
    class EKF ekf = EKF();
    Eigen::MatrixXd a = ekf.filtering(); 
    std::cout << a << std::endl;
    return 0;
}