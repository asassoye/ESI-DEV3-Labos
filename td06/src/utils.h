#ifndef DEV3_UTILS_H
#define DEV3_UTILS_H

#include <vector>
#include <ostream>

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

#endif //DEV3_UTILS_H
