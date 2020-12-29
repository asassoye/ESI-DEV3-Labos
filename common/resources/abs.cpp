#include <iostream>
#include <type_traits>
#include <vector>
#include <string>

template<class>
struct sfinae_true : std::true_type {
};

template<class ToPrint>
static auto test_insertion(int) -> sfinae_true<decltype(std::cout << std::declval<ToPrint>())>;

template<class ToPrint>
static auto test_insertion(long) -> std::false_type;

template<class ToPrint>
struct is_printable : decltype(test_insertion<ToPrint>(0)) {
};
template<class ToPrint> using NotPrintable = std::enable_if_t<!is_printable<ToPrint>::value>;

//overload not availlable if operator<< is already defined (avoids ambiguity)
template<template<class, class ...> class Container, class T, class ... Whatever, NotPrintable<Container<T, Whatever...>> * = nullptr>
std::ostream &operator<<(std::ostream &out, const Container<T, Whatever...> &container) {
    out << "{ ";

    auto it = container.begin();
    auto it_end = container.end();

    if (it != it_end) {
        out << *it;
        ++it;
    }

    for (; it != it_end; ++it)
        out << " , " << (*it);

    out << " }";

    return out;
}

using namespace std;

int main() {
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2;

    cout << v1 << endl;
    cout << v2 << endl; //this line won't work 
    //error: no match for ‘operator<<’ (operand types are ‘std::ostream {aka std::basic_ostream<char>}’ and ‘std::vector<int>’)
    //also : 

    cout << string{"Hello"} << endl;
}