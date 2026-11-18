#include "arraylib.h"

#include <cassert>
#include <cmath>
#include <iostream>

static bool close(double a, double b) {
    return std::fabs(a - b) < 1e-9;
}

int main() {
    int a[] = {-5, 0, 3, 3, 8, -2};
    const std::size_t n = sizeof(a) / sizeof(a[0]);
    assert(arr_sum(a, n) == 7);
    assert(arr_max(a, n) == 8);
    assert(arr_min(a, n) == -5);
    assert(close(arr_average(a, n), 7.0 / 6.0));
    assert(arr_count_positive(a, n) == 3);
    assert(arr_count_negative(a, n) == 2);
    assert(arr_count_zero(a, n) == 1);
    assert(arr_product(a, n) == 0);

    int b[] = {7, 1, 9, 3};
    assert(close(arr_median(b, 4), 5.0));
    for (std::size_t i = 0; i < 4; ++i) {
        const int original[] = {7, 1, 9, 3};
        assert(b[i] == original[i]);
    }

    int c[] = {5, 1, 3};
    assert(close(arr_median(c, 3), 3.0));

    int d[] = {1, 2, 3, 4};
    assert(arr_product(d, 4) == 24);

    int singleton[] = {-7};
    assert(arr_sum(singleton, 1) == -7);
    assert(arr_min(singleton, 1) == -7);
    assert(close(arr_median(singleton, 1), -7.0));

    std::cout << "[unit] All tests passed\n";
    return 0;
}
