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
    std::cout << "}" << std::endl;
}

void sort(std::vector<int> &data, bool ascending) {
    int c;
    for (int j = 1; j <= data.size(); j++)
        for (int i = 0; i < data.size() - 1; i++)
            if (ascending ? data[i] > data[i + 1] : data[i] < data[i + 1]) {
                c = data[i];
                data[i] = data[i + 1];
                data[i + 1] = c;
            }
}
