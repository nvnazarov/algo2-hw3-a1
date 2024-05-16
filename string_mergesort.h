#pragma once

#include <string>
#include <vector>

typedef std::vector<std::string> array_t;


auto lcp_compare(const std::string &a, const std::string &b, int &cnt) {
    int pl = 0;
    while (pl < a.length() && pl < b.length() && a[pl] == b[pl]) {
        ++pl;
        ++cnt;
    }
    return pl;
}


void string_merge(array_t &array, int l, int r, int m, int &cnt) {
    int cur = 0;
    std::vector<std::string> merged(r - l + 1);

    int li = l;
    int ri = m + 1;
    while (li <= m && ri <= r) {
        int lcp = lcp_compare(array[li], array[ri], cnt);
        
        if (lcp >= array[li].length()) {
            merged[cur++] = array[li++];
            continue;
        }
        
        if (lcp < array[ri].length()) {
            merged[cur++] = array[ri++];
            continue;
        }

        ++cnt;
        if (array[li][lcp] <= array[ri][lcp]) {
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

    for (int i = 0; i < merged.size(); i++) {
        array[l + i] = merged[i];
    }
}


void string_mergesort(array_t &array, int l, int r, int &cnt) {
    if (l < r) {
        int m = (r + l) / 2;
        string_mergesort(array, l, m, cnt);
        string_mergesort(array, m + 1, r, cnt);
        string_merge(array, l, r, m, cnt);
    }
}