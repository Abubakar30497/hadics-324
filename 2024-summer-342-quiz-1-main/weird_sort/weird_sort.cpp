#include "weird_sort.hpp"

void swap(int &a, int &b) {
    a += b;
    b = a - b;
    a  = a - b;
}

void sort_even_elements(int *data, size_t len, long &num_comparison) {
    /*
     * TODO: this function sorts the values in the given array that are at even indices in the ascending (small to large) order.
     *  For example, data[0], data[2], data[4]....will be sorted.
     *  And data[1], data[3], data[5] will not be modified.
     *  This is to be done by modifying the bubble sort algorithm.
     *  The commented code in this function when you get it from the teacher is just plain bubble sort for explanation purpose.
     *  The SPACE complexity for this is required to be O(1).
     *  A bonus goal for this is to achieve the least amount of comparison which happens on the line illustrated below.
     */


    if (data == nullptr || len < 2) {
        return;
    }

    for (size_t i = 0; i < len; i++) {
        for (size_t j = 0; j < len - i - 1; j++) {
            if (data[j] > data[j + 1]) {    // this is where comparison happens
               swap(data[j], data[j + 1]);
            }
        }
    }
}

int main() {
    unit_test();
}

void copy_array(int *data_dest, int *data_src, size_t len) {
    if (len == 0) {
        return;
    }
    memcpy(data_dest, data_src, len);
}

void unit_test() {
    long best_comp = 9999999;

    for (size_t len = 1; len < 500; len++) {
        int *data = new int[len];
        long num_of_comparison = 0;

        /*
         * Some sample inputs. One case per line.
         *
         * 1
         * 2 1
         * 3 2 1
         * 4 3 2 1
         * 5 4 3 2 1
         * 6 5 4 3 2 1
         *
         * Expected output:
         * 1
         * 1 2
         * 1 2 3
         * 1 2 3 4
         * 1 2 3 4 5
         * 1 2 3 4 5 6
         */
        for (size_t j = 0; j < len; ++j) {
            data[j] = (int) (len - j);
        }
        int *data_copy = new int[len];
        copy_array(data_copy, data, len);

        sort_even_elements(data, len, num_of_comparison);

        /*
         * verify the even index number
         */
        bool fail = false;
        int expect = (len % 2 == 0) ? 2 : 1;
        for (size_t j = 0; j < len; j += 2) {
            if (data[j] != expect) {
                fail = true;
                break;
            }
            expect += 2;
        }
        VERIFY(data, data_copy, len, fail);

        /*
         * verify the odd index number
         */
        fail = false;
        expect = (int) len - 1;
        for (size_t j = 1; j < len; j += 2) {
            if (data[j] != expect) {
                fail = true;
                break;
            }
            expect -= 2;
        }
        VERIFY(data, data_copy, len, fail);

        if (num_of_comparison < best_comp){
            best_comp = num_of_comparison;
        }

        //  Optimize it to be as small as possible.
        printf("%ld\tcomparions: %ld\nbest comparisons: %ld\n", len, num_of_comparison, best_comp);
    }
}

void print_array(int *data, size_t len) {
    printf("{");
    for (size_t i = 0; i < len; i++) {
        printf("%d", data[i]);
        if (i != len - 1) {
            printf(", ");
        } else {
            printf("}\n");
        }
    }
}