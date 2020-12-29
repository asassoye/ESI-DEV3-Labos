// TODO : include manquants

#include "fraction_incomplete.h"

namespace nvs {

// méthodes

    Fraction::Fraction(int numerator, int denominator) :
    // TODO
            sign_{},
            numerator_{},
            denominator_{} {}

    Fraction::Fraction(Sign sign, unsigned numerator,
                       unsigned denominator) :
    // TODO
            sign_{},
            numerator_{},
            denominator_{} {}

    std::string Fraction::to_string() const {
        // TODO
        return {};
    }

// fonctions

    bool operator<(const Fraction &lhs,
                   const Fraction &rhs) {
        // TODO
        return {};
    }

    Fraction operator+(const Fraction &lhs,
                       const Fraction &rhs) {
        // TODO
        return {};
    }

    Fraction operator*(const Fraction &lhs,
                       const Fraction &rhs) {
        // TODO
        return {};
    }

    Fraction operator/(const Fraction &lhs, const Fraction &rhs) {
        // TODO
        return {};
    }

} // namespave nvs
