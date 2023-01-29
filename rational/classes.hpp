#pragma once
#include <iostream>
using namespace std;

class Rational {
public:
  Rational(int numerator = 0, int denominator = 1);

  void add(Rational rational);
  void sub(Rational rational);
  void mul(Rational rational);
  void div(Rational rational);

  void neg();
  void inv();
  double to_double() const;
  operator double() const;
  friend ostream &operator<<(ostream &out, Rational const &number);
  friend bool operator==(Rational num1, Rational num2);
  friend bool operator!=(Rational num1, Rational num2);
  friend bool operator>(Rational num1, Rational num2);
  friend bool operator<(Rational num1, Rational num2);
  friend bool operator>=(Rational num1, Rational num2);
  friend bool operator<=(Rational num1, Rational num2);

private:
  int numerator_;
  int denominator_;
};
