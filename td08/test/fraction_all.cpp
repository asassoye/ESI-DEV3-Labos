#include <cstdio>
#include "catch2/catch.hpp"

using namespace g54327;

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
      REQUIRE(fraction.numerator() == g54327::Fraction::reduce(numerator, denominator).first);
      REQUIRE(fraction.denominator() == g54327::Fraction::reduce(numerator, denominator).second);
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
        auto reduced = g54327::Fraction::reduce(std::abs(tuple.first), std::abs(tuple.second));
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
        CHECK_THROWS(Fraction{g54327::sign(std::get<0>(tuple)), std::get<1>(tuple), std::get<2>(tuple)});
      } else if (
          (g54327::sign(std::get<0>(tuple)) == Sign::ZERO && std::get<1>(tuple)) ||
              (std::get<1>(tuple) == 0 && g54327::sign(std::get<0>(tuple)) != Sign::ZERO)
          ) {
        CHECK_THROWS(Fraction{g54327::sign(std::get<0>(tuple)), std::get<1>(tuple), std::get<2>(tuple)});
      } else {
        Fraction f{g54327::sign(std::get<0>(tuple)), std::get<1>(tuple), std::get<2>(tuple)};
        auto reduced = g54327::Fraction::reduce(std::get<1>(tuple), std::get<2>(tuple));
        REQUIRE(f.sign() == g54327::sign(std::get<0>(tuple)));
        REQUIRE(f.numerator() == reduced.first);
        REQUIRE(f.denominator() == reduced.second);
      }
    }
  }
}

TEST_CASE("bool operator<(const Fraction &lhs, const Fraction &rhs)") {
  std::pair<Fraction, Fraction> checks[] = {
      std::make_pair(Fraction{1, 2}, Fraction{1, 1}),
      std::make_pair(Fraction{-1, 1}, Fraction{1, 2}),
  };

  for (auto check : checks) {
    Fraction f1 = check.first;
    Fraction f2 = check.second;

    std::string name = f1.to_string() + " < " + f2.to_string() + " == true";
    SECTION(name) {
      REQUIRE(operator<(f1, f2) == true);
      REQUIRE(operator<(f2, f1) == false);
    }
  }
}

TEST_CASE("bool operator+(const Fraction &lhs, const Fraction &rhs)") {
  std::tuple<Fraction, Fraction, Fraction> checks[] = {
      std::make_tuple(
          Fraction{0, 1},
          Fraction{5, 13},
          Fraction{5, 13}),
      std::make_tuple(
          Fraction{1, 2},
          Fraction{0, 1},
          Fraction{1, 2}),
      std::make_tuple(
          Fraction{1, 2},
          Fraction{1, 2},
          Fraction{1, 1}),
      std::make_tuple(
          Fraction{-1, 2},
          Fraction{2, 2},
          Fraction{1, 2}),
      std::make_tuple(
          Fraction{3, 2},
          Fraction{-1, 2},
          Fraction{1, 1})
  };

  for (auto check : checks) {
    Fraction f1 = std::get<0>(check);
    Fraction f2 = std::get<1>(check);
    Fraction pred = std::get<2>(check);

    std::string name = f1.to_string() + " + " + f2.to_string() + " = " + pred.to_string();
    SECTION(name) {
      REQUIRE(f1 + f2 == pred);
    }
  }

}

TEST_CASE("abs(Fraction)") {
  Sign sign = Sign::MINUS;
  unsigned numerator = 1;
  unsigned denominator = 2;

  Fraction fraction = g54327::abs(Fraction{sign, numerator, denominator});
  REQUIRE(fraction.sign() == Sign::PLUS);
  REQUIRE(fraction.numerator() == numerator);
  REQUIRE(fraction.denominator() == denominator);
}

TEST_CASE("sign()") {
  std::tuple<Sign, unsigned, unsigned> tuples[]{
      std::make_tuple(Sign::ZERO, 0u, 1u),
      std::make_tuple(Sign::PLUS, 1u, 2u),
      std::make_tuple(Sign::MINUS, 1u, 2u)
  };

  for (auto tuple : tuples) {
    Sign s = std::get<0>(tuple);
    unsigned n = std::get<1>(tuple);
    unsigned d = std::get<2>(tuple);
    Fraction f{s, n, d};

    std::string name = "sign(" + f.to_string() + ") = " + to_string(s);
    SECTION(name) {
      REQUIRE(f.sign() == s);
    }
  }
}

TEST_CASE("numerator()") {
  std::tuple<Sign, unsigned, unsigned> tuples[]{
      std::make_tuple(Sign::ZERO, 0u, 1u),
      std::make_tuple(Sign::PLUS, 1u, 2u),
      std::make_tuple(Sign::MINUS, 2u, 3u)
  };

  for (auto tuple : tuples) {
    Sign s = std::get<0>(tuple);
    unsigned n = std::get<1>(tuple);
    unsigned d = std::get<2>(tuple);
    Fraction f{s, n, d};

    std::string name = "numerator(" + f.to_string() + ") = " + std::to_string(n);
    SECTION(name) {
      REQUIRE(f.numerator() == n);
    }
  }
}

TEST_CASE("denominator()") {
  std::tuple<Sign, unsigned, unsigned> tuples[]{
      std::make_tuple(Sign::ZERO, 0u, 1u),
      std::make_tuple(Sign::PLUS, 1u, 2u),
      std::make_tuple(Sign::MINUS, 2u, 3u)
  };

  for (auto tuple : tuples) {
    Sign s = std::get<0>(tuple);
    unsigned n = std::get<1>(tuple);
    unsigned d = std::get<2>(tuple);
    Fraction f{s, n, d};

    std::string name = "denominator(" + f.to_string() + ") = " + std::to_string(d);
    SECTION(name) {
      REQUIRE(f.denominator() == d);
    }
  }
}

TEST_CASE("unit_form()") {
  std::pair<Fraction, std::tuple<Sign, unsigned, unsigned, unsigned>> checks[] = {
      std::make_pair(Fraction{5, 6}, std::make_tuple(Sign::PLUS, 0, 5, 6)),
      std::make_pair(Fraction{15, 6}, std::make_tuple(Sign::PLUS, 2, 1, 2)),
      std::make_pair(Fraction{0, 6}, std::make_tuple(Sign::ZERO, 0, 0, 1)),
      std::make_pair(Fraction{-18, 6}, std::make_tuple(Sign::MINUS, 3, 0, 1)),
      std::make_pair(Fraction{-23, 6}, std::make_tuple(Sign::MINUS, 3, 5, 6)),
  };

  for (auto check : checks) {
    Fraction f = check.first;
    auto unitf = check.second;

    std::string name = "unit_form(" + f.to_string() + ")";
    SECTION(name) {
      REQUIRE(std::get<0>(f.unit_form()) == std::get<0>(unitf));
      REQUIRE(std::get<1>(f.unit_form()) == std::get<1>(unitf));
      REQUIRE(std::get<2>(f.unit_form()) == std::get<2>(unitf));
      REQUIRE(std::get<3>(f.unit_form()) == std::get<3>(unitf));
    }
  }
}

TEST_CASE("inverse()") {
  std::pair<Fraction, Fraction> checks[]{
      std::make_pair(Fraction{0, 1}, Fraction{0, 1}),
      std::make_pair(Fraction{1, 4}, Fraction{4, 1}),
      std::make_pair(Fraction{-1, 3}, Fraction{-3, 1}),
  };

  for (auto check : checks) {
    Fraction f1 = check.first;
    Fraction f2 = check.second;

    std::string name = "inverse(" + f1.to_string() + ") = " + f2.to_string();
    SECTION(name) {
      REQUIRE(inverse(f1) == f2);
    }
  }
}