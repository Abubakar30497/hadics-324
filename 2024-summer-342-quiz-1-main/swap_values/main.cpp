#include "util.hpp"

int main() {
    int x = 5, y = 10;
    std::cout << "Before swap: x = " << x << ", y = " << y << "\n";
    swap(x, y); // the function that is being called here is the one using "by refernce"
    std::cout << "After swap: x = " << x << ", y = " << y << "\n";

    float a = 1.5, b = 2.5;
    std::cout << "Before swap: a = " << a << ", b = " << b << "\n";
    swap(&a, &b); // The function is being called here is the one using pointers
    std::cout << "After swap: a = " << a << ", b = " << b << "\n";
}
