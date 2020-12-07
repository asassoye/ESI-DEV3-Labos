/**
 * @file td07.cpp
 * @author Andrew SASSOYE
 */
#include <iostream>
#include "td07.h"

void print(const std::vector<int> &data) {
    std::cout << "{";
    for (size_t i = 0; i < data.size(); ++i) {
        if (i != 0) {
            std::cout << ", ";
        }
        std::cout << data[i];
    }
    std::cout << "}";
}