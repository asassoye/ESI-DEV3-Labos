/**
 * @file fraction.cpp
 * @author Andrew SASSOYE
 */
#include <cmath>
#include <numeric>
#include "fraction.hpp"

namespace dev3 {
    Fraction::Fraction(int numerator, int denominator) :
            Fraction(
                    dev3::sign(numerator * denominator),
                    std::abs(numerator),
                    std::abs(denominator)
            ) {}


    Fraction::Fraction(Sign sign, unsigned numerator,
                       unsigned denominator) :
            sign_{sign},
            numerator_{reduce(numerator, denominator).first},
            denominator_{reduce(numerator, denominator).second} {
        if (denominator == 0) {
            throw std::invalid_argument("denominator est nul");
        }
        if (sign == Sign::ZERO && numerator != 0) {
            throw std::invalid_argument("sign est Sign::ZERO alors que numerator n'est pas nul.");
        }
    }

    std::pair<unsigned, unsigned> Fraction::reduce(unsigned int numerator, unsigned int denominator) {
        if (numerator == 0) {
            return std::pair<unsigned, unsigned>{0, 1};
        }
        if (denominator != 0) {
            unsigned gcd = std::gcd(numerator, denominator);
            return std::pair<unsigned, unsigned>{numerator / gcd, denominator / gcd};
        }

        return {};
    }

    std::string Fraction::to_string() const {
        std::string result = std::to_string(numerator());
        if (sign() == Sign::MINUS) {
            result = "-" + result;
        }
        if (denominator() != 1) {
            result += "/" + std::to_string(denominator());
        }
        return result;
    }

// fonctions

    bool operator<(const Fraction &lhs,
                   const Fraction &rhs) {
        if (lhs.sign() != rhs.sign()) {
            return lhs.sign() < rhs.sign();
        }

        return lhs.numerator() * rhs.denominator() < rhs.numerator() * lhs.numerator();
    }

    Fraction operator+(const Fraction &lhs,
                       const Fraction &rhs) {
        auto l = lhs.sign() == Sign::MINUS ? -lhs.numerator() : lhs.numerator();
        auto r = rhs.sign() == Sign::MINUS ? -rhs.numerator() : rhs.numerator();
        auto d = lhs.denominator() * rhs.denominator();

        l *= rhs.denominator();
        r *= lhs.denominator();

        return Fraction(static_cast<int>(l + r), static_cast<int>(d));
    }

    Fraction operator*(const Fraction &lhs,
                       const Fraction &rhs) {
        return {
                product(lhs.sign(), rhs.sign()),
                lhs.numerator() * rhs.numerator(),
                lhs.denominator() * rhs.denominator()
        };
    }

    Fraction operator/(const Fraction &lhs, const Fraction &rhs) {
        return lhs * inverse(rhs);
    }
}
