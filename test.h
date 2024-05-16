#pragma once

#include <cstdint>
#include <chrono>
#include <vector>
#include <string>
#include <fstream>

#include "quicksort.h"
#include "mergesort.h"
#include "string_quicksort.h"
#include "string_mergesort.h"


typedef std::vector<std::string> array_t;


struct Result {
    int64_t microseconds;
    int n_compares;
};


Result test_sort_func(void (*sort_func)(array_t &array, int l, int r, int &n), array_t &array, int size) {
    int n_compares = 0;
    array_t array_copy(array);
    
    auto start_time = std::chrono::high_resolution_clock::now();
    sort_func(array_copy, 0, size - 1, n_compares);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    return Result{.microseconds=delta.count(), .n_compares=n_compares};
}


void test_and_save_results(const std::string &prefix, array_t array, size_t min_size, size_t max_size, size_t step) {
    void (*sort_funcs[])(array_t &array, int l, int r, int &n) = {
        quicksort,
        mergesort,
        string_quicksort_adapter,
        string_mergesort,
    };
    std::vector<std::string> prefixes = {
        "_qs",
        "_ms",
        "_sqs"
        "_sms",
    };

    for (int i = 0; i < 3; ++i) {
        auto sort_func = sort_funcs[i];

        std::ofstream compares_os(prefix + prefixes[i] + "_compares.txt");
        std::ofstream times_os(prefix + prefixes[i] + "_times.txt");

        for (size_t array_size = min_size; array_size <= max_size; array_size += step) {
            Result res = test_sort_func(sort_func, array, array_size);
            compares_os << res.n_compares << "\n";
            times_os << res.microseconds << "\n";
        }

        compares_os.close();
        times_os.close();
    }
}