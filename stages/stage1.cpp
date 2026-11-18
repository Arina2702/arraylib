// Stage 1: all functions and main in a single file.
#ifndef ARRAYLIB_H
#define ARRAYLIB_H

#include <cstddef>

#if defined(ARRAYLIB_STATIC)
#  define ARRAYLIB_API
#elif defined(_WIN32)
#  if defined(ARRAYLIB_BUILD)
#    define ARRAYLIB_API __declspec(dllexport)
#  else
#    define ARRAYLIB_API __declspec(dllimport)
#  endif
#else
#  define ARRAYLIB_API
#endif

// Preconditions: arr != nullptr and n > 0.
// Integer sum/product overflow is outside the defined domain of this laboratory.
ARRAYLIB_API int    arr_sum(const int* arr, std::size_t n);
ARRAYLIB_API int    arr_max(const int* arr, std::size_t n);
ARRAYLIB_API int    arr_min(const int* arr, std::size_t n);
ARRAYLIB_API double arr_average(const int* arr, std::size_t n);
ARRAYLIB_API int    arr_count_positive(const int* arr, std::size_t n);
ARRAYLIB_API int    arr_count_negative(const int* arr, std::size_t n);
ARRAYLIB_API int    arr_count_zero(const int* arr, std::size_t n);
ARRAYLIB_API int    arr_product(const int* arr, std::size_t n);
ARRAYLIB_API double arr_median(const int* arr, std::size_t n);

#endif // ARRAYLIB_H



#include <algorithm>
#include <vector>

int arr_sum(const int* arr, std::size_t n) {
    int result = 0;
    for (std::size_t i = 0; i < n; ++i) {
        result += arr[i];
    }
    return result;
}

int arr_max(const int* arr, std::size_t n) {
    int result = arr[0];
    for (std::size_t i = 1; i < n; ++i) {
        if (arr[i] > result) result = arr[i];
    }
    return result;
}

int arr_min(const int* arr, std::size_t n) {
    int result = arr[0];
    for (std::size_t i = 1; i < n; ++i) {
        if (arr[i] < result) result = arr[i];
    }
    return result;
}

double arr_average(const int* arr, std::size_t n) {
    return static_cast<double>(arr_sum(arr, n)) / static_cast<double>(n);
}

int arr_count_positive(const int* arr, std::size_t n) {
    int result = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] > 0) ++result;
    }
    return result;
}

int arr_count_negative(const int* arr, std::size_t n) {
    int result = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] < 0) ++result;
    }
    return result;
}

int arr_count_zero(const int* arr, std::size_t n) {
    int result = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] == 0) ++result;
    }
    return result;
}

int arr_product(const int* arr, std::size_t n) {
    int result = 1;
    for (std::size_t i = 0; i < n; ++i) {
        result *= arr[i];
    }
    return result;
}

double arr_median(const int* arr, std::size_t n) {
    std::vector<int> copy(arr, arr + n);
    std::sort(copy.begin(), copy.end());
    if (n % 2 != 0) {
        return static_cast<double>(copy[n / 2]);
    }
    return (static_cast<double>(copy[n / 2 - 1]) +
            static_cast<double>(copy[n / 2])) / 2.0;
}



#include <cstddef>
#include <iomanip>
#include <iostream>

int main() {
    const int data[] = {-5, 0, 3, 3, 8, -2};
    const std::size_t n = sizeof(data) / sizeof(data[0]);

    std::cout << "Array: ";
    for (std::size_t i = 0; i < n; ++i) {
        if (i != 0) std::cout << ' ';
        std::cout << data[i];
    }
    std::cout << '\n' << std::fixed << std::setprecision(2)
              << "Sum: " << arr_sum(data, n) << '\n'
              << "Max: " << arr_max(data, n) << '\n'
              << "Min: " << arr_min(data, n) << '\n'
              << "Average: " << arr_average(data, n) << '\n'
              << "Positive: " << arr_count_positive(data, n) << '\n'
              << "Negative: " << arr_count_negative(data, n) << '\n'
              << "Zero: " << arr_count_zero(data, n) << '\n'
              << "Product: " << arr_product(data, n) << '\n'
              << "Median: " << arr_median(data, n) << '\n';
    return 0;
}
