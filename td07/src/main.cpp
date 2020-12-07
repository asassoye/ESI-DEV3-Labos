/**
 * @file main.cpp
 * @author Andrew SASSOYE
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "td07.h"
#include "../../td06/src/utils.h"
#include "../resources/random.hpp"

using namespace std;

int main() {
    cout << "\t===Exercice 7.1===" << endl;
    auto array = test_nvs_random<20>(10000000);

    for (size_t i = 0; i < array.size(); ++i) {
        cout << "nombre de " << setw(2) << i
             << " : " << array[i].first
             << " (" << setprecision(2) << array[i].second * 100 << " %)"
             << endl;
    }

    cout << endl << "\t===Exercice 7.2===" << endl;
    vector<int> vector1 = {1, 2, 3, 4, 5, 6};
    print(vector1);

    cout << endl << "\t===Exercice 7.3===" << endl;
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
