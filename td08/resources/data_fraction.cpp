#include <vector>
#include <utility>
#include <tuple>
#include <cmath>

#include "data_fraction.h"
#include "random.hpp"

namespace nvs {

    std::vector<std::pair<int, int>> data_signed(unsigned size,
                                                 Random type) {
        using std::vector;
        using std::pair;
        using std::sqrt;

        vector<pair<int, int>> result(size);

        if (type == Random::UNIQUE) {
            nvs::randomize();
        }

        int max{static_cast<int>(sqrt(size))};
        int min{-max};
        for (unsigned idx{0}; idx < size; ++idx) {
            result[idx] = {nvs::random_value(min, max),
                           nvs::random_value(min, max)
            };
        }

        return result;
    }

    std::vector<std::tuple<int, unsigned, unsigned>> data_unsigned(
            unsigned size, Random type) {
        using std::vector;
        using std::tuple;
        using std::sqrt;

        vector<tuple<int, unsigned, unsigned>> result(size);

        if (type == Random::UNIQUE) {
            nvs::randomize();
        }

        unsigned max{static_cast<unsigned>(sqrt(size))};
        for (unsigned idx{0}; idx < size; ++idx) {
            result[idx] = {nvs::random_value(-1, 1),
                           nvs::random_value(0u, max),
                           nvs::random_value(0u, max)
            };
        }

        return result;
    }

}
