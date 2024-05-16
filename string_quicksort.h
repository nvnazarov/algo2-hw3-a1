#pragma once

#include <vector>
#include <string>

typedef std::vector<std::string> array_t;


void string_quicksort(array_t &array, int l, int r, int ind, int &cnt) {
    if (l >= r) {
        return;
    }

    int i = l;
    int j = r;
    while (i < j) {
        if (array[j].length() <= ind) {
            std::swap(array[i], array[j]);
            --j;
            ++i;
        } else {
            --j;
        }
    }

    int s = i;
    std::string &pivot = array[r];
    j = r;
    int cur = i;
    while (cur < j) {
        ++cnt;
        if (array[cur][ind] < pivot[ind]) {
            std::swap(array[cur], array[i]);
            ++i;
            ++cur;
            continue;
        }
        if (array[cur][ind] > pivot[ind]) {
            std::swap(array[cur], array[j]);
            --j;
            ++cur;
            continue;
        }
        if (array[cur][ind] == pivot[ind]) {
            ++cur;
            continue;
        }
    }

    string_quicksort(array, s, i - 1, ind, cnt);
    string_quicksort(array, i, j, ind + 1, cnt);
    string_quicksort(array, j + 1, r, ind, cnt);
}


void string_quicksort_adapter(array_t &array, int l, int r, int &cnt) {
    string_quicksort(array, l, r, 0, cnt);
}