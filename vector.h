/// @file vector.h
#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include "point.h"

namespace IsakMath {
    /// Represents a vector in a cartesian coordinate system
    class vector {
    private:
      std::vector<double> values;
      std::string name;
    public:
      vector(const point &p1, const point &p2);
      vector(std::initializer_list<double> l) : values(l) {}

      /// Sets the name of the vector
      void set_name(const std::string& name);

      /// Gets the name of the vector
      std::string get_name() const;

      /// Gets the size of the vector (number of axes)
      int inline size() const;

      /// Gets the vector length
      double length() const;

      /// Mirrors the vector to a given normal line
      /// @param normal a normal vector defining the mirror vector
      vector& mirror(const vector& normal);

      /// Rotates the vector by the given angle counterclockwise around the origin
      /// Note that this function only works with 2d vectors
      /// @param angle rotation angle in radiants
      vector& rotate2d(double angle);

      double& operator[](int i); 
      double operator[](int i) const;
      vector& operator+=(const vector &v);
      vector& operator-=(const vector &v);

      /// Vector multiplication (dot product)
      double operator*=(const vector& v);

      /// Scalar multiplication
      vector& operator*=(double d);
      vector& operator/=(double d);

      friend std::ostream& operator<<(std::ostream& os, const vector& v);
      friend vector operator+(vector v1, const vector& v2);
      friend vector operator-(vector v1, const vector& v2);
      friend double operator*(vector v1, const vector& v2);
      friend vector operator*(vector v, double d);
      friend vector operator/(vector v, double d);
    };
}
