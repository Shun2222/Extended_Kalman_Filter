#include <iostream>
#include "test.hpp"
#include "vec3.hpp"
int main(){
    Matrix3 m = {{1,2,3}, {4,5,6}, {7,8,9}};
    Matrix3 m3({1,0,0}, {0,1,0}, {0,0,1});
    Matrix3 ones  = {{1,2,3},{1,2,3},{1,2,3}};
    Matrix3 zero;

    std::cout << m << std::endl;
    std::cout << m3<< std::endl;
    //std::cout << zero << std::endl;

    //std::cout << m+m3 << std::endl;
    //std::cout << m-m3 << std::endl;
    //std::cout << m*2.0 << std::endl;
    //std::cout << m/3.0 << std::endl;
    std::cout << m*m3 << std::endl;
    //std::cout << m*zero << std::endl;

    //m += m3;
    //std::cout << m << std::endl;
    //m -= m3;
    //std::cout << m << std::endl;
    //auto m4 = m*m3;
    //std::cout << m4 << std::endl;
    //m *= 3;
    //std::cout << m << std::endl;
    //m /= 3;
    //std::cout << m << std::endl;

    return 0;
}
