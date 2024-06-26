#include <vector>
#include <iostream>

void swap(int &a, int &b);

template<typename T>
void swap(T *a, T *b) {
    *a += *b;
    *b = *a - *b;
    *a = *a - *b;
}
