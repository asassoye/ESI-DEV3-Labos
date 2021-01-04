/**
 * @file main.cpp
 * @author Andrew SASSOYE
 */
#include <iostream>
#include <algorithm>
#include <functional>
#include "../resources/utilscpp.hpp"
#include "../src/sign.hpp"
#include "../resources/data_fraction.h"
#include "fraction_constexpr.hpp"

using namespace std;
using namespace g54327;

const size_t N_FRACTIONS = 50;

void exe2();

void exe6();

void exe89();

static void printFraction(std::string, const std::vector<Fraction> &);
static void printFraction(std::string, const std::vector<const Fraction *> &);
static void printFraction(std::string, const std::vector<std::reference_wrapper<Fraction>> &);

int main() {
  utils::exercise("Exercice 8.2", exe2);
  utils::exercise("Exercice 8.6 + 8.7", exe6);
  utils::exercise("Exercice 8.8 + 8.9", exe89);
}

void exe2() {
  cout << "cout << Sign::PLUS => " << Sign::PLUS << endl;
  cout << "cout << Sign::MINUS => " << Sign::MINUS << endl;
  cout << "cout << Sign::ZERO => " << Sign::ZERO << endl;
}

void exe6() {
  auto v = nvs::data_signed(N_FRACTIONS);
  std::vector<Fraction> fractions{N_FRACTIONS};
  size_t errors{};
  for (auto tuple : v) {
    try {
      fractions.emplace_back(
          Fraction{
              std::get<0>(tuple),
              std::get<1>(tuple)
          });
    } catch (std::invalid_argument &e) {
      ++errors;
    }
  }

  cout << "error_count: " << errors << endl
       << "fractions.size(): " << fractions.size() << endl << endl;

  printFraction("fractions content: ", fractions);

  std::vector<const Fraction *> fractions_ptr{fractions.size()};
  std::generate(fractions_ptr.begin(), fractions_ptr.end(),
                [&fractions]() -> const Fraction * {
                  static int i = 0;
                  return &fractions[i++];
                }
  );

  printFraction("before sorting (pointer): ", fractions_ptr);
  std::sort(
      fractions_ptr.begin(),
      fractions_ptr.end(),
      [](const Fraction *f1, const Fraction *f2) {
        return *f1 < *f2;
      });
  printFraction("after sorting (pointer): ", fractions_ptr);
}

void exe89() {
  auto v = nvs::data_unsigned(N_FRACTIONS);
  std::vector<Fraction> fractions{N_FRACTIONS};
  size_t errors{};
  for (auto tuple : v) {
    try {
      fractions.emplace_back(
          Fraction{
              g54327::sign(std::get<0>(tuple)),
              std::get<1>(tuple),
              std::get<2>(tuple)
          });
    } catch (std::invalid_argument &e) {
      ++errors;
    }
  }

  cout << "error_count: " << errors << endl
       << "fractions.size(): " << fractions.size() << endl << endl;

  printFraction("fractions content: ", fractions);

  std::vector<std::reference_wrapper<Fraction>> rw{fractions.begin(), fractions.end()};
  printFraction("before sorting (reference wrapper): ", rw);

  std::sort(rw.begin(), rw.end(), std::less<>());
  printFraction("after sorting (reference wrapper): ", rw);
}

void printFraction(std::string description, const vector<Fraction> &fractions) {
  int i = 1;
  cout << description.data() << endl;

  for (const auto &fraction : fractions) {
    cout << fraction << (i++ % 16 == 0 ? "\n" : " ");
  }

  cout << endl << endl;
}
void printFraction(std::string description, const vector<const Fraction *> &fractions) {
  int i = 1;
  cout << description.data() << endl;

  for (const auto fraction : fractions) {
    cout << *fraction << (i++ % 16 == 0 ? "\n" : " ");
  }

  cout << endl << endl;
}
void printFraction(std::string description, const vector<std::reference_wrapper<Fraction>> &fractions) {
  int i = 1;
  cout << description.data() << endl;

  for (const auto &fraction : fractions) {
    cout << fraction << (i++ % 16 == 0 ? "\n" : " ");
  }

  cout << endl << endl;
}


