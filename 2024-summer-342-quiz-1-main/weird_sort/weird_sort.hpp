//
// Created by hadic on 6/25/2024.
//

#include <cstdio>
#include <string.h>

#define VERIFY(data, data_copy, len, fail)          \
if (fail) {                                     \
printf("Case with %lu elements failed\n", (len)); \
printf("Input: ");                          \
print_array((data_copy), (len));            \
printf("Output: ");                         \
print_array((data), (len));                 \
break;                                      \
}

void sort_even_elements(int *data, size_t len, long &num_comparison);
void unit_test();
void copy_array(int *data_dest, int *data_src, size_t len);
void print_array(int *data, size_t len);
void swap(int &a, int &b);
