#include <iostream>
#include "string_generator.h"
#include "test.h"

#define A1_MIN_ARRAY_SIZE 100ul
#define A1_MAX_ARRAY_SIZE 3000ul
#define A1_STEP 100ul
#define A1_SEED 2024


int main(void) {
    StringGenerator string_generator(A1_SEED);

    auto random_strings = string_generator.generate_array(A1_MAX_ARRAY_SIZE, StringGenerator::RANDOM);
    auto reverse_sorted_strings = string_generator.generate_array(A1_MAX_ARRAY_SIZE, StringGenerator::REVERSE_SORTED);
    auto almost_sorted_strings = string_generator.generate_array(A1_MAX_ARRAY_SIZE, StringGenerator::ALMOST_SORTED);

    test_and_save_results("./out/rs", random_strings, A1_MIN_ARRAY_SIZE, A1_MAX_ARRAY_SIZE, A1_STEP);
    test_and_save_results("./out/rss", reverse_sorted_strings, A1_MIN_ARRAY_SIZE, A1_MAX_ARRAY_SIZE, A1_STEP);
    test_and_save_results("./out/ass", almost_sorted_strings, A1_MIN_ARRAY_SIZE, A1_MAX_ARRAY_SIZE, A1_STEP);

    return 0;
}