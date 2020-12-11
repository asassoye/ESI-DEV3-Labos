#include <iostream>
#include <functional>
#include <iomanip>
#include <algorithm>
#include "utilscpp.hpp"

namespace dev3::utils {
    std::string box(const std::string &string) {
        return "======= " + BOX + "  " + string + "  " + RESET + " =======";
    }

    std::string cpu(const double &ms) {
        return BOLD + "========= " + ITALIC + std::to_string(ms) + " ms =========" + RESET;
    }

    void exercise(const std::string &name, const std::function<void()> &exe) {
        std::cout << box(name).data() << std::endl << std::endl;
        clock_t start = clock();
        exe();
        clock_t end = clock();

        std::cout << std::endl << std::fixed << std::setprecision(2)
                  << cpu(1000.0 * static_cast<double>(end - start) / CLOCKS_PER_SEC).data()
                  << std::endl << std::endl;
    }
}

