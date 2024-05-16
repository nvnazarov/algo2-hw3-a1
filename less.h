#pragma once

#include <string>


bool less(std::string &a, std::string &b, int &cnt) {
    size_t min_length = std::min(a.length(), b.length());

    for (size_t i = 0; i < min_length; ++i) {
        ++cnt;
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
    }

    return a.length() < b.length();
}