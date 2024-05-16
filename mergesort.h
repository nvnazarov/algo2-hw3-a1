#pragma once

#include <string>
#include <vector>
#include "less.h"

typedef std::vector<std::string> array_t;


void merge(array_t &array, int l, int r, int m, int &cnt) {
    int cur = 0;
    std::vector<std::string> merged(r - l + 1);

    int li = l;
    int ri = m + 1;
    while (li <= m && ri <= r) {
        if (less(array[li], array[ri], cnt)) {
            merged[cur++] = array[li++];
        } else {
            merged[cur++] = array[ri++];
        }
    }

    while (li <= m) {
        merged[cur++] = array[li++];
    }

    while (ri <= r) {
        merged[cur++] = array[ri++];
    }

    for (int i = 0; i < merged.size(); ++i) {
        array[l + i] = merged[i];
    }
}


void mergesort(array_t &array, int l, int r, int &cnt) {
    if (l < r) {
        int m = (l + r) / 2;
        mergesort(array, l, m, cnt);
        mergesort(array, m + 1, r, cnt);
        merge(array, l, r, m, cnt);
    }
}