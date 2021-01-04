#ifndef DEV3_UTILSCPP_HPP
#define DEV3_UTILSCPP_HPP

#include <vector>
#include <ostream>
#include <functional>

namespace g54327::utils {
const std::string BOX = "\033[1;7m";
const std::string BOLD = "\033[3;4m";
const std::string ITALIC = "\033[1m";
const std::string RESET = "\033[0m";

void exercise(const std::string &name, const std::function<void()> &exe);
}

template<class T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &container) {
  bool first = true;

  out << "{";
  for (const T &t : container) {
    if (!first) {
      out << ", ";
    }

    out << t;
    first = false;
    }
    out << "}";

    return out;
}

#endif //DEV3_UTILSCPP_HPP
