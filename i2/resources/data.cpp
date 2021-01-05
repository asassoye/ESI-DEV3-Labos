#include "data.hpp"

#include <vector>
#include <tuple>
#include <algorithm>

#include "random/random.hpp"

namespace he2b::nvs {

std::vector<std::tuple<std::string, std::vector<double>>>
data(std::size_t size, Randomness reproductible) {
  if (reproductible == Randomness::NON_REPRODUCTIBLE) {
    randomize();
  }

  decltype(data()) result(size);

  std::generate(std::begin(result), std::end(result), [] {
    const auto error_rate{100u};
    auto ok{random_value(0u, error_rate - 1u)};
    auto size{ok ? random_value(1u, 10u) : 0u};
    ok = random_value(0u, error_rate - 1u);
    auto data
        {
            std::vector<double>(ok ? size :
                                std::max(0, static_cast<int>(size) +
                                    random_value(-3, 7)))
        };
    std::generate(std::begin(data), std::end(data), [] {
      return random_value(-10., 10.);
    });
    auto size_s{std::to_string(size)};
    ok = random_value(0u, error_rate - 1u);
    if (!ok) {
      // sans decltype, c'est la variante avec des doubles qui est
      // invoquée => intervalle ouvert à droite...
      // or ici on veut un intervalle fermé
      size_s.insert(random_value<decltype(size_s.size())>(0, size_s.size()),
                    random_value(1u, 3u),
                    random_value('a', 'z'));
    }
    return std::make_tuple(size_s, data);
  });

  return result;
}

} // namespace he2b::nvs
