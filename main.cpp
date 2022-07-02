#include  "kalman_filter.hpp"

int main(void)
{
    KalmanFilter kf;
    for(int i=0; i<10; i++)
    {
        std::cout << kf.getXY() << std::endl;
        kf.filter();
    }
    return 0;
}
