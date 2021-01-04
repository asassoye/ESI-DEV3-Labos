#include "catch2/catch.hpp"
#include "../src/sign.hpp"

using namespace g54327;

TEST_CASE("constexpr Sign opposite(Sign sign)", "[opposite]") {
    REQUIRE(opposite(Sign::PLUS) == Sign::MINUS);
    REQUIRE(opposite(Sign::MINUS) == Sign::PLUS);
    REQUIRE(opposite(Sign::ZERO) == Sign::ZERO);
}

TEST_CASE("constexpr Sign sign(int value)", "[sign]") {
    REQUIRE(sign(-500) == Sign::MINUS);
    REQUIRE(sign(42) == Sign::PLUS);
    REQUIRE(sign(0) == Sign::ZERO);
    REQUIRE(sign(-0) == Sign::ZERO);
}

TEST_CASE("inline std::string to_string(Sign sign)", "[to_string]") {
    REQUIRE(to_string(Sign::MINUS) == "MINUS (-)");
    REQUIRE(to_string(Sign::PLUS) == "PLUS (+)");
    REQUIRE(to_string(Sign::ZERO) == "ZERO (0)");
}

TEST_CASE("constexpr Sign product(Sign lhs, Sign rhs)", "[product]") {
    REQUIRE(product(Sign::PLUS, Sign::PLUS) == Sign::PLUS);
    REQUIRE(product(Sign::PLUS, Sign::MINUS) == Sign::MINUS);
    REQUIRE(product(Sign::PLUS, Sign::ZERO) == Sign::ZERO);
    REQUIRE(product(Sign::MINUS, Sign::PLUS) == Sign::MINUS);
    REQUIRE(product(Sign::MINUS, Sign::MINUS) == Sign::PLUS);
    REQUIRE(product(Sign::MINUS, Sign::ZERO) == Sign::ZERO);
    REQUIRE(product(Sign::ZERO, Sign::PLUS) == Sign::ZERO);
    REQUIRE(product(Sign::ZERO, Sign::MINUS) == Sign::ZERO);
    REQUIRE(product(Sign::ZERO, Sign::ZERO) == Sign::ZERO);
}

TEST_CASE("constexpr Sign operator*(Sign lhs, Sign rhs)", "[operator*]") {
    REQUIRE(Sign::PLUS * Sign::PLUS == Sign::PLUS);
    REQUIRE(Sign::PLUS * Sign::MINUS == Sign::MINUS);
    REQUIRE(Sign::PLUS * Sign::ZERO == Sign::ZERO);
    REQUIRE(Sign::MINUS * Sign::PLUS == Sign::MINUS);
    REQUIRE(Sign::MINUS * Sign::MINUS == Sign::PLUS);
    REQUIRE(Sign::MINUS * Sign::ZERO == Sign::ZERO);
    REQUIRE(Sign::ZERO * Sign::PLUS == Sign::ZERO);
    REQUIRE(Sign::ZERO * Sign::MINUS == Sign::ZERO);
    REQUIRE(Sign::ZERO * Sign::ZERO == Sign::ZERO);
}

TEST_CASE("constexpr Sign operator-(Sign sign)", "[operator-]") {
    REQUIRE(-Sign::PLUS == Sign::MINUS);
    REQUIRE(-Sign::MINUS == Sign::PLUS);
    REQUIRE(-Sign::ZERO == Sign::ZERO);
}