#include <cmath>
#include "vector.h"

namespace IsakMath {
  vector::vector(const point &p1, const point &p2) {
    for (int i = 0; i < p1.size(); i++) {
      values.push_back(p2[i] - p1[i]);
    }
  }

  void vector::set_name(const std::string& name) {
    this->name = name;
  }

  std::string vector::get_name() const {
    return name;
  }

  int inline vector::size() const {
    return values.size();
  }

  double vector::length() const {
    if (values.size() == 0) return 0;
    if (values.size() == 1) return values[0];
    double curr_length = values[0];
    for (int i = 1; i < this->size(); i++) {
     curr_length = std::sqrt(curr_length * curr_length + values[i] * values[i]); 
    }
    return curr_length;
  }

  vector& vector::mirror(const vector& normal) {
    double s = (*this) * normal;
    *this -= normal * (2 * s);
    return *this;
  }

  double& vector::operator[](int i) {
    return values[i];
  }

  double vector::operator[](int i) const {
    return values[i];
  }

  vector& vector::operator+=(const vector& v) {
    for (int i = 0; i < this->size(); i++) {
      values[i] += v[i];
    }
    return *this;
  }

  vector& vector::operator-=(const vector& v) {
    for (int i = 0; i < this->size(); i++) {
      values[i] -= v[i];
    }
    return *this;
  }

  double vector::operator*=(const vector& v) {
    double sum = 0;

    for (int i = 0; i < this->size(); i++) {
      sum += values[i] * v.values[i];
    }

    return sum;
  }

  vector& vector::operator*=(double d) {
    for (int i = 0; i < this->size(); i++) {
      values[i] *= d;
    }
    return *this;
  }

  vector& vector::operator/=(double d) {
    for (int i = 0; i < this->size(); i++) {
      values[i] /= d;
    }
    return *this;
  }

  std::ostream& operator<<(std::ostream& os, const IsakMath::vector& p) {
    if (p.name.length() > 0)
      os << p.name;
    os << "->(";
    for (auto it = p.values.begin(); it != p.values.end(); ++it) {
      if (it != p.values.begin()) os << ",";
      os << *it;
    }
    os << ")";
    return os;
  }

  vector operator+(vector v1, const vector& v2) {
    return v1 += v2;
  }

  vector operator-(vector v1, const vector& v2) {
    return v1 -= v2;
  }

  double operator*(vector v1, const vector& v2) {
    return v1 *= v2;
  }

  vector operator*(vector v, double d) {
    return v *= d;
  }

  vector operator/(vector v, double d) {
    return v /= d;
  }
}
