#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <random>

#define A1_DIV 10ul
#define A1_MIN_STRING_LENGTH 10ul
#define A1_MAX_STRING_LENGTH 200ul


class StringGenerator {
public:
    enum Hint {
        RANDOM,
        REVERSE_SORTED,
        ALMOST_SORTED,
    };


    StringGenerator(uint_fast32_t seed) {
        engine_ = std::default_random_engine(seed);
    }


    std::vector<std::string> generate_array(size_t size, Hint hint) {
        std::vector<std::string> array(size);

        for (std::string &s : array) {
            s = generate_string();
        }

        if (hint != Hint::RANDOM) {
            std::sort(array.begin(), array.end());
        }

        if (hint == Hint::ALMOST_SORTED) {
            size_t n_replaces = size / A1_DIV + 1;
            std::uniform_int_distribution<size_t> uid(0, size);
            for (size_t i = 0; i < n_replaces; ++i) {
                size_t l = uid(engine_);
                size_t r = uid(engine_);
                std::swap(array[l], array[r]);
            }
        } else {
            std::reverse(array.begin(), array.end());
        }

        return array;
    }

    std::string generate_string() {
        std::uniform_int_distribution<size_t> uid_length(A1_MIN_STRING_LENGTH, A1_MAX_STRING_LENGTH + 1);
        size_t length = uid_length(engine_);

        std::string s;
        std::uniform_int_distribution<size_t> uid(0, symbols_.size());
        for (size_t i = 0; i < length; ++i) {
            s += symbols_[uid(engine_)];
        }

        return s;
    }

private:
    const std::string symbols_ = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#%:;^&*()-";
    std::default_random_engine engine_;
};