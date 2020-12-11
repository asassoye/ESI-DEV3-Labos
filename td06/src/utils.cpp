#include <iostream>
#include <functional>
#include <iomanip>
#include <algorithm>
#include "utils.h"

const std::string BOX = "\033[1;7m";
const std::string BOLD = "\033[3;4m";
const std::string ITALIC = "\033[1m";
const std::string RESET = "\033[0m";

std::string box(std::string string) {
    return "======= " + BOX + "  " + string + "  " + RESET + " =======";
}

std::string cpu(double ms) {
    return BOLD + "========= " + ITALIC + std::to_string(ms) + " ms =========" + RESET;
}

void exercice(const std::string &name, const std::function<void()> &exe) {
    std::cout << box(name).data() << std::endl << std::endl;
    std::clock_t start = std::clock();
    exe();
    std::clock_t end = std::clock();

    std::cout << std::endl << std::fixed << std::setprecision(2)
              << cpu(1000.0 * static_cast<double>(end - start) / CLOCKS_PER_SEC).data()
              << std::endl << std::endl;
}

