/**
 * @file main.cpp
 *
 * @author Andrew SASSOYE <andrew@sasoye.be>
 * @copyright Copyright © 2021 Andrew SASSOYE. This project is released under the MIT License.
 */

#include <iostream>
#include "m_vector.h"
#include "../resources/data.hpp"

using namespace std;
using namespace he2b;

int main() {
  std::vector<g54327::m_vector> v;
  auto generated = nvs::data(50);
  unsigned string_error = 0;
  unsigned string_zero_error = 0;
  unsigned size_error = 0;

  for (auto &element : generated) {
    int nb;
    try {
      nb = std::stoi(get<0>(element));
    } catch (std::invalid_argument &e) {
      ++string_error;
      continue;
    }

    std::vector<double> &values = get<1>(element);

    if (nb < 0) {
      ++string_error;
      continue;
    }

    if (nb == 0) {
      ++string_zero_error;
      continue;
    }

    if (nb != values.size()) {
      ++size_error;
      continue;
    }
    v.emplace_back(values);
  }

  cout << "===Exercice 5===" << endl;

  cout << " 1) Le nombre d'erreurs de format de std::string : " << string_error << endl
       << " 2) le nombre de std::string égal a zero : " << string_zero_error << endl
       << " 3) Le nombre de std::string est different de la taille du vecteur : " << size_error << endl
       << " 4) Le nombre de tuples sans erreurs : " << v.size() << endl;

  cout << endl << "===Exercice 6===" << endl;

  for (auto &mv : v) {
    cout << " " << mv << endl;
  }

  cout << endl << "===Exercice 7===" << endl;
  std::vector<std::reference_wrapper<const g54327::m_vector>> rw{v.begin(), v.end()};

  cout << endl << "===Exercice 8===" << endl;
  std::sort(rw.begin(), rw.end(), [](const g54327::m_vector &l, const g54327::m_vector &r) {
    if (l.size() == r.size()) {
      return l < r;
    }
    return l.size() < r.size();
  });

  for (auto &mv : rw) {
    cout << " " << mv << endl;
  }

  return 0;
}
