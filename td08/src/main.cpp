/**
 * @file main.cpp
 * @author Andrew SASSOYE
 */
#include <iostream>
#include "../resources/utilscpp.hpp"
#include "../src/sign.hpp"

using namespace std;
using namespace dev3;

void exe2();

int main() {
    utils::exercise("Exercice 8.2", exe2);
}

void exe2() {
    cout << "cout << Sign::PLUS => " << Sign::PLUS << endl;
    cout << "cout << Sign::MINUS => " << Sign::MINUS << endl;
    cout << "cout << Sign::ZERO => " << Sign::ZERO << endl;
}
