/**
 * @file main.cpp
 * @author Andrew SASSOYE
 */
#include <iostream>
#include <vector>
#include <iomanip>
#include "../resources/mathesicpp.hpp"
#include "../resources/utilscpp.hpp"

using namespace std;

static void printEuclideanDivision(int dividend, int divisor, std::pair<int, int> pair, bool verification);

static void printEuclideanDivision(int dividend, int divisor, std::pair<int, int> pair, size_t fill);

int main() {
  cout << "\t===Exercice 6.1===" << endl;
  int number = rand();
  cout << number << (g54327::math::isPrime(number) ? " est premier!" : " n'est pas premier..") << endl;
  cout << "Le nombre premier qui suit " << number << " est " << g54327::math::nextPrime(number) << endl;

  cout << endl << "\t===Exercice 6.2===" << endl;
  unsigned min = 200;
  unsigned max = 349;
  auto v = g54327::math::primeList(200, 349);
  cout << "Les nombres premiers entre " << min << " et " << max << " : " << endl << v << endl;

  cout << endl << "\t===Exercice 6.3===" << endl;
  int dividend = rand();
  int divisor = rand() % 100 + 1;
  auto pair = g54327::math::euclideanDivision(dividend, divisor);
    cout << "Dividende = Diviseur * Quotient + Reste" << endl;
    printEuclideanDivision(dividend, divisor, pair, true);
    cout << endl;


    cout << endl << "\t===Exercice 6.4===" << endl;
    dividend = 27;
    for (int i = 1; i <= 27; ++i) {
      divisor = i;
      pair = g54327::math::euclideanDivision(dividend, divisor);
      printEuclideanDivision(dividend, divisor, pair, static_cast<size_t>(2));
        cout << endl;
    }

    return EXIT_SUCCESS;
}

static void printEuclideanDivision(int dividend, int divisor, std::pair<int, int> pair, bool verification) {
    cout << dividend << " = " << divisor << " * " << pair.first << " + " << pair.second;

    if (verification) {
        cout << " => " << ((dividend == (divisor * pair.first + pair.second)) ? "OK" : "ERROR");
    }
}

static void printEuclideanDivision(int dividend, int divisor, std::pair<int, int> pair, size_t fill) {
    cout << std::setw(fill) << dividend << " = " << std::setw(fill) << divisor << " * " << std::setw(fill) << pair.first
            << " + " << std::setw(fill) << pair.second;
}



