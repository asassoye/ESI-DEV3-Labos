#ifndef M_VECTOR_H
#define M_VECTOR_H

#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <string>
#include <ostream>
#include <algorithm>
#include <cmath>

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
  if (index >= size_) {
    throw std::invalid_argument(
        "erreur de taille avec (index, size) : " + std::to_string(index) + " " + std::to_string(size_));
  }
}

m_vector::m_vector(std::size_t size) :
    size_{size},
    data_(size, 0.0) {
  if (size == 0) {
    throw std::invalid_argument("size est nul");
  }
}

m_vector::m_vector(std::size_t size, double value) :
    size_{size},
    data_(size, value) {
  if (size == 0) {
    throw std::invalid_argument("size est nul");
  }
}

m_vector::m_vector(std::initializer_list<double> data) :
    size_{data.size()},
    data_{data.begin(), data.end()} {
  if (data.size() == 0) {
    throw std::invalid_argument("le vecteur est vide");
  }
}

m_vector::m_vector(std::vector<double> data) :
    size_{data.size()},
    data_{data.begin(), data.end()} {
  if (data.size() == 0) {
    throw std::invalid_argument("le vecteur est vide");
  }
}

std::size_t m_vector::size() const {
  return size_;
}

bool m_vector::equal_size(const m_vector &v) const {
  return size_ == v.size();
}

const std::vector<double> &m_vector::data() const {
  return data_;
}

void m_vector::data(const std::vector<double> &new_data) {
  if (!equal_size(new_data)) {
    throw std::invalid_argument("Le nouveau vecteur n'est pas de bonne taille");
  }

  data_ = {new_data.begin(), new_data.end()};
}

double m_vector::operator[](std::size_t index) const {
  return data_[index];
}

double &m_vector::operator[](std::size_t index) {
  return data_[index];
}

double m_vector::at(std::size_t index) const {
  if (index >= size()) {
    throw std::invalid_argument("l'index excede le vector");
  }

  return data_[index];
}

double &m_vector::at(std::size_t index) {
  if (index >= size()) {
    throw std::invalid_argument("l'index excede le vector");
  }

  return data_[index];
}

std::string m_vector::to_string() const {
  std::string s = std::to_string(size_) + " : ";
  for (size_t i = 0; i < size_; ++i) {
    s += std::to_string(data_[i]) + " ";
  }
  return s;
}

m_vector::operator double() const {
  return norm(*this);
}

// implémentations des fonctions inline

std::ostream &operator<<(std::ostream &out, const m_vector &v) {
  return out << v.to_string();
}

std::string to_string(const m_vector &v) {
  return v.to_string();
}

bool equal_size(const m_vector &lhs, const m_vector &rhs) {
  return lhs.equal_size(rhs);
}

inline void validate_size(const m_vector &lhs, const m_vector &rhs) {
  if (!equal_size(lhs, rhs)) {
    throw std::invalid_argument("size not equal");
  }
}

m_vector operator*(double d, const m_vector &v) {
  std::vector<double> dat(v.size());
  std::generate(dat.begin(), dat.end(), [&v, d]() -> double {
    static size_t i = 0;
    return v[i++] * d;
  });

  return dat;
}

m_vector operator*(const m_vector &v, double d) {
  return operator*(d, v);
}

double operator*(const m_vector &lhs, const m_vector &rhs) {
  validate_size(lhs, rhs);

  double response = 0;
  for (size_t i = 0; i < lhs.size(); ++i) {
    response += lhs[i] * rhs[i];
  }
  return response;
}

double norm(const m_vector &v) {
  return sqrt(operator*(v, v));
}

bool operator<(const m_vector &lhs, const m_vector &rhs) {
  if (equal_size(lhs, rhs)) {
    if (lhs.data() == rhs.data()) {
      return false;
    }
    return norm(lhs) < norm(rhs);
  }
  return lhs.size() < rhs.size();
}

} // namespace he2b::g54327

#endif // M_VECTOR_H
