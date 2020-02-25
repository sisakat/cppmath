#include "point.h"

namespace IsakMath {
  void point::set_name(const std::string& name) {
    this->name = name;
  }

  std::string point::get_name() const {
    return name;
  }

  int point::size() const {
    return values.size();
  }

  double& point::operator[](int i) {
    return values[i];
  }

  double point::operator[](int i) const {
    return values[i];
  }

  std::ostream& operator<<(std::ostream& os, const IsakMath::point& p) {
    if (p.name.length() > 0)
      os << p.name;
    os << "(";
    for (auto it = p.values.begin(); it != p.values.end(); ++it) {
      if (it != p.values.begin()) os << ",";
      os << *it;
    }
    os << ")";
    return os;
  }
}
