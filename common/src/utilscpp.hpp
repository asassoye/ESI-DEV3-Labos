#ifndef DEV3_UTILSCPP_HPP
#define DEV3_UTILSCPP_HPP

#include <vector>
#include <ostream>
#include <functional>

namespace dev3::utils {
    const std::string BOX = "\033[1;7m";
    const std::string BOLD = "\033[3;4m";
    const std::string ITALIC = "\033[1m";
    const std::string RESET = "\033[0m";

    void exercise(const std::string &name, const std::function<void()> &exe);
}


/**
 * @author Romain ABSIL
 */
template<template<class, class ...> class Container, class T, class ... OtherParams>
std::ostream &operator<<(std::ostream &out, const Container<T, OtherParams...> &container) {
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
