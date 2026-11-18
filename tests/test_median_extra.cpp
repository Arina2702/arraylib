#include "arraylib.h"

#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>

int main() {
    int two_extremes[] = {INT_MAX, INT_MIN};
    // Casts to double are performed before the two middle values are added.
    assert(std::fabs(arr_median(two_extremes, 2) + 0.5) < 1e-9);

    int duplicates[] = {8, 8, -2, 8, 0};
    assert(arr_median(duplicates, 5) == 8.0);
    assert(duplicates[0] == 8 && duplicates[1] == 8 &&
           duplicates[2] == -2 && duplicates[3] == 8 && duplicates[4] == 0);
    std::cout << "[median extra] All tests passed\n";
    return 0;
}
