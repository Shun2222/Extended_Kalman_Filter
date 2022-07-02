#include <typeinfo>
#include <iostream>

int main(){
    auto a = {0, 0, 0};
    double b = 0;
    std::cout << typeid({0, 0, 0}).name() << std::endl;
    return 0;
}
