/**
 * @file main.cpp
 * @author Andrew SASSOYE
 */
#include <iostream>
#include "../resources/utilscpp.hpp"
#include "../src/sign.hpp"

using namespace std;
using namespace dev3;

void exe1();

int main() {
    utils::exercise("Exercice 8.1", exe1);
}

void exe1() {
    cout << "cout << Sign::PLUS => " << Sign::PLUS << endl;
    cout << "cout << Sign::MINUS => " << Sign::MINUS << endl;
    cout << "cout << Sign::ZERO => " << Sign::ZERO << endl;
}
