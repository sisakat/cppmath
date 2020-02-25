/// @file point.h
#pragma once

#include <iostream>
#include <vector>

namespace IsakMath {
    /// @brief Represents a point of a cartesian coordinate system
    class point {
    private:
      /// Values of the point
      std::vector<double> values;

      /// Name of the point
      std::string name;
    public:
      point(std::initializer_list<double> l) : values(l) {}

      /// Sets the name of the point
      void set_name(const std::string& name);

      /// Gets the name of the point
      std::string get_name() const;
      
      /// Number of components of the point (number of axes)
      int size() const;
      double& operator[](int i);
      double operator[](int i) const;
      
      friend std::ostream& operator<<(std::ostream& os, const point& p);
    };
}
