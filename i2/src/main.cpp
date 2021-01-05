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
  auto generated = nvs::data(20);
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

    std::vector<double> values = get<1>(element);

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
  return 0;
}
