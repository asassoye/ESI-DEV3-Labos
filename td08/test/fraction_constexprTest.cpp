#include <cstdio>
#include "catch2/catch.hpp"
#include "../src/sign.hpp"
#include "../src/fraction_constexpr.hpp"
#include "../resources/mathesi.hpp"
#include "../resources/data_fraction.h"

using namespace dev3;

TEST_CASE("Fraction::Fraction(Sign sign, unsigned numerator, unsigned denominator)", "[Fraction]") {
  SECTION("(ZERO, 1, 1) => EXCEPTION") {
    CHECK_THROWS(Fraction{Sign::ZERO, 1, 1});
  }SECTION("(PLUS, 1, 0) => EXCEPTION") {
    CHECK_THROWS(Fraction{Sign::PLUS, 1, 0});
  }

  std::tuple<Sign, unsigned, unsigned> cases[] = {
      std::make_tuple(Sign::PLUS, 1, 2),
      std::make_tuple(Sign::PLUS, 2, 4),
      std::make_tuple(Sign::MINUS, 2, 4),
      std::make_tuple(Sign::ZERO, 0, 1),
      std::make_tuple(Sign::ZERO, 0, 2),
      std::make_tuple(Sign::PLUS, 10, 2),
  };
  Sign sign;
  unsigned numerator, denominator;

  for (auto c : cases) {
    sign = std::get<0>(c);
    numerator = std::get<1>(c);
    denominator = std::get<2>(c);
    Fraction fraction{sign, numerator, denominator};
    std::string str =
        "(" + to_string(sign) +
            ", " + std::to_string(numerator) +
            ", " + std::to_string(denominator) + ")";

    SECTION(str + " = " + fraction.to_string()) {
      REQUIRE(fraction.numerator() == dev3::Fraction::reduce(numerator, denominator).first);
      REQUIRE(fraction.denominator() == dev3::Fraction::reduce(numerator, denominator).second);
      REQUIRE(fraction.sign() == sign);
    }
  }
}

TEST_CASE("constructor with nvs::data_signed()") {
  auto v = nvs::data_signed(43);
  for (auto tuple : v) {
    SECTION("(" + std::to_string(tuple.first) + ", " + std::to_string(tuple.second) + ")") {
      if (tuple.second == 0) {
        CHECK_THROWS(Fraction{tuple.first, tuple.second});
      } else {
        Fraction f{tuple.first, tuple.second};
        auto reduced = dev3::Fraction::reduce(std::abs(tuple.first), std::abs(tuple.second));
        REQUIRE(f.sign() == sign(tuple.first * tuple.second));
        REQUIRE(f.numerator() == reduced.first);
        REQUIRE(f.denominator() == reduced.second);
      }
    }
  }
}

TEST_CASE("constructor with nvs::data_unsigned()") {
  auto v = nvs::data_unsigned(43);
  for (auto tuple : v) {
    SECTION("(" + std::to_string(std::get<0>(tuple)) + ", " + std::to_string(std::get<1>(tuple)) + ", "
                + std::to_string(std::get<2>(tuple)) + ")") {
      if (std::get<2>(tuple) == 0) {
        CHECK_THROWS(Fraction{dev3::sign(std::get<0>(tuple)), std::get<1>(tuple), std::get<2>(tuple)});
      } else if (
          (dev3::sign(std::get<0>(tuple)) == Sign::ZERO && std::get<1>(tuple)) ||
              (std::get<1>(tuple) == 0 && dev3::sign(std::get<0>(tuple)) != Sign::ZERO)
          ) {
        CHECK_THROWS(Fraction{dev3::sign(std::get<0>(tuple)), std::get<1>(tuple), std::get<2>(tuple)});
      } else {
        Fraction f{dev3::sign(std::get<0>(tuple)), std::get<1>(tuple), std::get<2>(tuple)};
        auto reduced = dev3::Fraction::reduce(std::get<1>(tuple), std::get<2>(tuple));
        REQUIRE(f.sign() == dev3::sign(std::get<0>(tuple)));
        REQUIRE(f.numerator() == reduced.first);
        REQUIRE(f.denominator() == reduced.second);
      }
    }
  }
}

TEST_CASE("bool operator<(const Fraction &lhs, const Fraction &rhs)") {
  Fraction f1{Sign::PLUS, 1, 2};
  Fraction f2{Sign::MINUS, 1, 1};

  REQUIRE(operator<(f1, f2) == false);
  REQUIRE(operator<(f2, f1) == true);
}

TEST_CASE("bool operator+(const Fraction &lhs, const Fraction &rhs)") {
  Fraction f1{Sign::PLUS, 1, 2};
  Fraction f2{Sign::MINUS, 1, 1};

  REQUIRE(operator+(f1, f2) == Fraction{Sign::MINUS, 1, 2});
}

TEST_CASE("abs", "abs") {
  Sign sign = Sign::MINUS;
  unsigned numerator = 1;
  unsigned denominator = 2;

  ;
  Fraction fraction = dev3::abs(Fraction{sign, numerator, denominator});
  REQUIRE(fraction.sign() == Sign::PLUS);
  REQUIRE(fraction.numerator() == numerator);
  REQUIRE(fraction.denominator() == denominator);
}