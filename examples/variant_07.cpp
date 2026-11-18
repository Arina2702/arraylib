#include "arraylib.h"

#include <cstddef>
#include <iomanip>
#include <iostream>

int main() {
    // Variant 7: grades in ten disciplines (five-point scale).
    int grades[] = {4, 5, 3, 4, 5, 5, 4, 3, 4, 5};
    const std::size_t n = sizeof(grades) / sizeof(grades[0]);

    int fives = 0;
    int below_four = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (grades[i] == 5) ++fives;
        if (grades[i] < 4) ++below_four;
    }

    std::cout << "Variant 07: grades in ten disciplines\nGrades: ";
    for (std::size_t i = 0; i < n; ++i) {
        if (i != 0) std::cout << ' ';
        std::cout << grades[i];
    }
    std::cout << '\n' << std::fixed << std::setprecision(2)
              << "Average grade: " << arr_average(grades, n) << '\n'
              << "Maximum grade: " << arr_max(grades, n) << '\n'
              << "Minimum grade: " << arr_min(grades, n) << '\n'
              << "Number of fives: " << fives << '\n'
              << "Grades below 4: " << below_four << '\n'
              << "Median grade: " << arr_median(grades, n) << '\n';
    return 0;
}
