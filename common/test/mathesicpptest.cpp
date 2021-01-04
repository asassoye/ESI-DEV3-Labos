#include <vector>
#include <string>
#include "catch2/catch.hpp"
#include "../src/mathesi.hpp"

TEST_CASE("bool isPrime(unsigned number)", "[isPrime]") {
    std::vector<unsigned> input = {0, 1, 2, 3, 5, 4294967291};
    std::vector<bool> output = {false, false, true, true, true, true};
    REQUIRE(input.size() == output.size());

    size_t i_size = input.size();
    for (size_t i = 0; i < i_size; ++i) {
        SECTION("isPrime(" + std::to_string(input[i]) + ") = " + (output[i] ? "true" : "false")) {
        REQUIRE(g54327::math::isPrime(input[i]) == output[i]);
      }
    }
}

TEST_CASE("unsigned nextPrime(unsigned actualPrime)", "[nextPrime]") {
    std::vector<unsigned> input = {0, 1, 2, 3, 5, 4294967279};
    std::vector<unsigned> output = {2, 2, 3, 5, 7, 4294967291};
    REQUIRE(input.size() == output.size());

    size_t i_size = input.size();
    for (size_t i = 0; i < i_size; ++i) {
        SECTION("nextPrime(" + std::to_string(input[i]) + ") = " + std::to_string(output[i])) {
        REQUIRE(g54327::math::nextPrime(input[i]) == output[i]);
      }
    }
}

TEST_CASE("std::vector<unsigned> primeList(unsigned min, unsigned max);", "[primeList]") {
  std::vector<unsigned> v = g54327::math::primeList(200, 350);
  std::vector<unsigned> wanted = {211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307,
                                  311, 313, 317, 331, 337, 347, 349};
    REQUIRE(v.size() == wanted.size());

    size_t i_size = v.size();
    for (size_t i = 0; i < i_size; ++i) {
        SECTION("primeList(200, 350)[" + std::to_string(i) + "] = " + std::to_string(wanted[i])) {
            REQUIRE(v[i] == wanted[i]);
        }
    }
}

TEST_CASE("std::pair<int, int> euclideanDivision(int dividend, int divisor)", "[euclideanDivision]") {
    int dividend = 27;
    int divisor;
    std::pair<int, int> pair;
    for (int i = 1; i <= 27; ++i) {
        divisor = i;
        SECTION("euclideanDivision(" + std::to_string(dividend) + ", " + std::to_string(divisor) + ")") {
        pair = g54327::math::euclideanDivision(dividend, divisor);
            REQUIRE(dividend == divisor * pair.first + pair.second);
        }
    }
}
