#include <vector>
#include <utility>
#include <string>
#include <stdexcept>
#include <numeric>
#include <algorithm>
#include <iterator>

#include "random.hpp"

namespace nvs {

namespace lotto {

std::vector<std::pair<std::string, std::vector<unsigned>>>
data(unsigned pronostic_count, unsigned grid_length,
     unsigned grid_maximum, unsigned grid_minimum) {
  if (grid_length == 0 ||
      grid_maximum < grid_minimum ||
      grid_maximum - grid_minimum + 1 < grid_length) {
    throw std::invalid_argument{"boom !"};
  }

  static const std::vector<std::string> owner
      {
          "38708", "39238", "39864", "41298", "41326", "41949", "42176",
          "42258", "42265", "42392", "42394", "42482", "42835", "42933",
          "42945", "42969", "42971", "42991", "43004", "43009", "43015",
          "43093", "43121", "43256", "43268", "43272", "43308", "43338",
          "43353", "43370", "43382", "43398", "43453", "43466", "43612",
          "44343", "44422", "44423", "44424", "44582", "44902", "44942",
          "45022", "45242", "45324", "45582", "45682", "47802", "47923",
          "47942", "48022", "48442", "48982", "49102", "49262", "49282",
          "49382", "49702", "49709", "49720", "49732", "49736", "49737",
          "49738", "49739", "49762", "49773", "49778", "49791", "49845",
          "49853", "49869", "49877", "49921", "49923", "51395", "51426",
          "51531", "51594", "51603", "51885", "53785",
      };
  static const unsigned owner_last_index
      {static_cast<unsigned>(owner.size()) - 1};

  std::vector<unsigned> pronostic(grid_maximum - grid_minimum + 1);
  std::iota(std::begin(pronostic), std::end(pronostic),
            grid_minimum);

  decltype(data(0, 0, 0, 0)) result(pronostic_count);

  for (std::size_t i{0}; i < pronostic_count; ++i) {
    result[i].first = owner[nvs::random_value(0u, owner_last_index)];

    std::shuffle(std::begin(pronostic), std::end(pronostic),
                 nvs::urng());
    result[i].second = {std::cbegin(pronostic),
                        std::cbegin(pronostic) + grid_length
    };
  }

  return result;
}

} // namespace lotto

} // namespace nvs
