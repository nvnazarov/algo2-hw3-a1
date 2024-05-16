#pragma once

#include <vector>
#include <string>
#include "less.h"

typedef std::vector<std::string> array_t;


int partition(array_t &array, int l, int r, int &cnt) {
    std::string &pivot = array[r];
    
    int i = l - 1;
    for (int j = l; j <= r; j++) {
        if (less(array[j], pivot, cnt)) {
            ++i;
            std::swap(array[i], array[j]);
        }
    }

    std::swap(array[i + 1], array[r]);
    return i + 1;
}


void quicksort(array_t &array, int l, int r, int &cnt) {
    if (l < r) {
        int p = partition(array, l, r, cnt);
        quicksort(array, l , p - 1, cnt);
        quicksort(array, p + 1, r, cnt);
    }
}