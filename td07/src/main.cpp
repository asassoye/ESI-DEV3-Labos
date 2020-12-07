/**
 * @file main.cpp
 * @author Andrew SASSOYE
 */
#include <iostream>
#include <iomanip>
#include "td07.h"
#include "../../td06/src/utils.h"

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
}
