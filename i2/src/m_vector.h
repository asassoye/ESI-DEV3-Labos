#ifndef M_VECTOR_H
#define M_VECTOR_H

#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <string>
#include <ostream>

// TODO : éventuellement ajouter include

namespace he2b::g54327 {

class m_vector {
  const std::size_t size_;
  std::vector<double> data_;

  inline void validate_index(std::size_t index) const;

 public:

  inline explicit m_vector(std::size_t size);
  inline m_vector(std::size_t size, double value);
  inline m_vector(std::initializer_list<double> data);
  inline m_vector(std::vector<double> data);

  inline std::size_t size() const;

  inline bool equal_size(const m_vector &v) const;

  inline const std::vector<double> &data() const;
  inline void data(const std::vector<double> &new_data);

  inline double operator[](std::size_t index) const;
  inline double &operator[](std::size_t index);

  inline double at(std::size_t index) const;
  inline double &at(std::size_t index);

  inline std::string to_string() const;

  inline explicit operator double() const;
};

// prototypes

inline std::ostream &operator<<(std::ostream &out,
                                const m_vector &v);

inline std::string to_string(const m_vector &v);

inline bool equal_size(const m_vector &lhs, const m_vector &rhs);

inline void validate_size(const m_vector &lhs, const m_vector &rhs);

inline m_vector operator*(double d, const m_vector &v);

inline m_vector operator*(const m_vector &v, double d);

inline double operator*(const m_vector &lhs, const m_vector &rhs);

inline double norm(const m_vector &v);

inline bool operator<(const m_vector &lhs, const m_vector &rhs);

// implémentations des méthodes inline

void m_vector::validate_index(std::size_t index) const {
  // TODO : compléter / modifier
}

m_vector::m_vector(std::size_t size) :
// TODO : compléter / modifier
    size_{},
    data_{} {}

m_vector::m_vector(std::size_t size, double value) :
// TODO : compléter / modifier
    size_{},
    data_{} {}

m_vector::m_vector(std::initializer_list<double> data) :
// TODO : compléter / modifier
    size_{},
    data_{} {}

m_vector::m_vector(std::vector<double> data) :
// TODO : compléter / modifier
    size_{},
    data_{} {}

std::size_t m_vector::size() const {
  // TODO : compléter / modifier
  return {};
}

bool m_vector::equal_size(const m_vector &v) const {
  // TODO : compléter / modifier
  return {};
}

const std::vector<double> &m_vector::data() const {
  // TODO : compléter / modifier
  return {};
}

void m_vector::data(const std::vector<double> &new_data) {
  // TODO : compléter / modifier
}

double m_vector::operator[](std::size_t index) const {
  // TODO : compléter / modifier
  return {};
}

double &m_vector::operator[](std::size_t index) {
  // TODO : compléter / modifier
  // FIXME : erreur de compilation ici
  return {};
}

double m_vector::at(std::size_t index) const {
  // TODO : compléter / modifier
  return {};
}

double &m_vector::at(std::size_t index) {
  // TODO : compléter / modifier
  // FIXME : erreur de compilation ici
  return {};
}

std::string m_vector::to_string() const {
  // TODO : compléter / modifier
  return {};
}

m_vector::operator double() const {
  // TODO : compléter / modifier
  return {};
}

// implémentations des fonctions inline

std::ostream &operator<<(std::ostream &out, const m_vector &v) {
  // TODO : compléter / modifier
  // FIXME : erreur de compilation ici
  return {};
}

std::string to_string(const m_vector &v) {
  // TODO : compléter / modifier
  return {};
}

bool equal_size(const m_vector &lhs, const m_vector &rhs) {
  // TODO : compléter / modifier
  return {};
}

inline void validate_size(const m_vector &lhs, const m_vector &rhs) {
  // TODO : compléter / modifier
}

m_vector operator*(double d, const m_vector &v) {
  // TODO : compléter / modifier
  return {};
}

m_vector operator*(const m_vector &v, double d) {
  // TODO : compléter / modifier
  return {};
}

double operator*(const m_vector &lhs, const m_vector &rhs) {
  // TODO : compléter / modifier
  return {};
}

double norm(const m_vector &v) {
  // TODO : compléter / modifier
  return {};
}

bool operator<(const m_vector &lhs, const m_vector &rhs) {
  // TODO : compléter / modifier
  return {};
}

} // namespace he2b::nvs

#endif // M_VECTOR_H
