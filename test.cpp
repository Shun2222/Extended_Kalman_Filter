#include "EKF3.hpp"
#include <iostream>
int main(){
    class EKF ekf = EKF();
    Eigen::MatrixXd a = ekf.filtering(); 
    std::cout << a << std::endl;
    return 0;
}