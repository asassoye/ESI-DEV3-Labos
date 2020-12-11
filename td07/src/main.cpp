/**
 * @file main.cpp
 * @author Andrew SASSOYE
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "td07.hpp"
#include "../resources/utilscpp.hpp"

using namespace std;
using namespace dev3;

void exe1();

void exe2();

void exe3();

void exe4();

void exe5();

int main() {
    utils::exercise("Exercice 7.1", exe1);
    utils::exercise("Exercice 7.2", exe2);
    utils::exercise("Exercice 7.3", exe3);
    utils::exercise("Exercice 7.4", exe4);
    utils::exercise("Exercice 7.5", exe5);
}

void exe1() {
    auto array = test_nvs_random<10>(40000000);

    for (size_t i = 0; i < array.size(); ++i) {
        cout << "nombre de " << setw(2) << i
             << " : " << array[i].first
             << " (" << setprecision(2) << array[i].second * 100 << " %)"
             << endl;
    }
}

void exe2() {
    vector<int> vector1 = {1, 2, 3, 4, 5, 6};
    print(vector1);
}

void exe3() {
    int times = nvs::random_value(5, 20);
    vector<int> vector2(times);
    generate(vector2.begin(), vector2.end(), []() {
        return nvs::random_value(-5, 5);
    });
    cout << "avant:" << endl;
    print(vector2);

    cout << "apres ascendant:" << endl;
    sort(vector2, true);
    print(vector2);

    cout << "apres descendant:" << endl;
    sort(vector2, false);
    print(vector2);
}

void exe4() {
    int times = nvs::random_value(5, 20);
    vector<int> vector3(times);
    generate(vector3.begin(), vector3.end(), []() {
        return nvs::random_value(-5, 5);
    });
    cout << "avant:" << endl;
    print(vector3);

    cout << "croissant:" << endl;
    std::sort(vector3.begin(), vector3.end(), less<>());
    print(vector3);

    cout << "décroissant:" << endl;
    std::sort(vector3.begin(), vector3.end(), greater<>());
    print(vector3);
}

void exe5() {
    std::map<unsigned, unsigned> decomposition{};
    unsigned value = 1552521050;

    for (unsigned i = 0; i < 10; ++i) {
        primeFactor(decomposition, ++value);
        printPrimeFactor(value, decomposition);
    }
}