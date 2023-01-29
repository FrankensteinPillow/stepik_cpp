#include "classes.hpp"
#include <iostream>
using namespace std;

Rational::Rational(int numerator, int denominator)
  : numerator_(numerator), denominator_(denominator){};
void Rational::add(Rational num) {
  this->numerator_ *= num.denominator_;
  double numerator_value = num.numerator_ * this->denominator_;
  this->denominator_ *= num.denominator_;
  this->numerator_ += numerator_value;
}
void Rational::sub(Rational num) {
  this->numerator_ *= num.denominator_;
  double numerator_value = num.numerator_ * this->denominator_;
  this->denominator_ *= num.denominator_;
  this->numerator_ -= numerator_value;
}
void Rational::mul(Rational num) {
  this->numerator_ *= num.numerator_;
  this->denominator_ *= num.denominator_;
}
void Rational::div(Rational num) {
  this->numerator_ *= num.denominator_;
  this->denominator_ *= num.numerator_;
}
void Rational::neg() { this->numerator_ *= (-1); }
double Rational::to_double() const {
  return (1.0 * this->numerator_) / this->denominator_;
}
Rational::operator double() const { return this->to_double(); };

bool operator==(Rational num1, Rational num2) {
  return (num1.numerator_ * num2.denominator_) ==
         (num2.numerator_ * num1.denominator_);
}
bool operator!=(Rational num1, Rational num2) { return !(num1 == num2); }
bool operator>(Rational num1, Rational num2) {
  if (num1.numerator_ >= 0 && num2.numerator_ < 0) {
    return true;
  }
  if (num1.numerator_ < 0 && num2.numerator_ >= 0) {
    return false;
  }
  return (num1.numerator_ * num2.denominator_) >
         (num2.numerator_ * num1.denominator_);
}
bool operator<(Rational num1, Rational num2) {
  return !(num1 > num2) && !(num1 == num2);
}
bool operator>=(Rational num1, Rational num2) { return !(num1 < num2); }
bool operator>=(Rational num1, int num2) {
  Rational tmp(num2);
  return !(num1 < tmp);
}
bool operator>=(int num1, Rational num2) {
  Rational tmp(num1);
  return !(tmp < num2);
}
bool operator<=(Rational num1, Rational num2) { return !(num1 > num2); }

ostream &operator<<(ostream &out, Rational const &number) {
  out << number.numerator_ << "/" << number.denominator_;
  return out;
}

Rational &operator+=(Rational &num1, Rational num2) {
  num1.add(num2);
  return num1;
}

Rational &operator+=(int num1, Rational &num2) {
  num2.add(num1);
  return num2;
}

Rational &operator-=(Rational &num1, Rational num2) {
  num1.sub(num2);
  return num1;
}

Rational &operator-=(int num1, Rational &num2) {
  num2.sub(num1);
  return num2;
}

Rational &operator*=(Rational &num1, Rational num2) {
  num1.mul(num2);
  return num1;
}

Rational &operator*=(int num1, Rational &num2) {
  num2.mul(num1);
  return num2;
}

Rational &operator/=(Rational &num1, Rational num2) {
  num1.div(num2);
  return num1;
}

Rational &operator/=(int num1, Rational &num2) {
  num2.div(num1);
  return num2;
}

Rational operator+(Rational &num1) { return num1; }

Rational operator+(Rational num1, Rational num2) {
  num1.add(num2);
  return num1;
}

Rational operator+(int num1, Rational num2) {
  num2.add(num1);
  return num2;
}

Rational operator+(Rational num1, int num2) {
  num1.add(num2);
  return num2;
}

Rational operator-(Rational num1) {
  num1.neg();
  return num1;
}

Rational operator-(Rational num1, Rational num2) {
  num1.sub(num2);
  return num1;
}

Rational operator-(int num1, Rational num2) {
  num2.sub(num1);
  return num2;
}

Rational operator-(Rational num1, int num2) {
  num1.sub(num2);
  return num2;
}

Rational operator*(Rational num1, Rational num2) {
  num1.mul(num2);
  return num1;
}

Rational operator*(int num1, Rational num2) {
  num2.mul(num1);
  return num2;
}

Rational operator*(Rational num1, int num2) {
  num1.mul(num2);
  return num2;
}

Rational operator/(Rational num1, Rational num2) {
  num1.div(num2);
  return num1;
}

Rational operator/(int num1, Rational num2) {
  Rational tmp(num1);
  tmp.div(num2);
  return tmp;
}

Rational operator/(Rational num1, int num2) {
  num1.div(num2);
  return num2;
}

int main() {
  Rational *n1 = new Rational(3, 8);
  Rational *n2 = new Rational(2, 3);
  Rational *n3 = new Rational(8, 13);
  int n4 = 13;
  cout << *n1 << " > " << *n2 << " is " << ((*n1 > *n2) ? "true" : "false")
       << endl;
  cout << *n1 << " < " << *n2 << " is " << ((*n1 < *n2) ? "true" : "false")
       << endl;
  cout << *n2 << " < " << *n2 << " is " << ((*n2 < *n2) ? "true" : "false")
       << endl;
  cout << *n2 << " > " << *n2 << " is " << ((*n2 > *n2) ? "true" : "false")
       << endl;
  cout << *n2 << " == " << *n2 << " is " << ((*n2 == *n2) ? "true" : "false")
       << endl;
  cout << *n3 << " == " << *n2 << " is " << ((*n3 == *n2) ? "true" : "false")
       << endl;
  cout << *n3 << " != " << *n2 << " is " << ((*n3 != *n2) ? "true" : "false")
       << endl;
  cout << *n2 << " != " << *n2 << " is " << ((*n2 != *n2) ? "true" : "false")
       << endl;
  cout << *n2 << " <= " << *n2 << " is " << ((*n2 <= *n2) ? "true" : "false")
       << endl;
  cout << *n2 << " >= " << *n2 << " is " << ((*n2 >= *n2) ? "true" : "false")
       << endl;
  cout << *n3 << " <= " << *n2 << " is " << ((*n3 <= *n2) ? "true" : "false")
       << endl;
  cout << *n3 << " >= " << *n2 << " is " << ((*n3 >= *n2) ? "true" : "false")
       << endl;
  cout << n4 << " >= " << *n2 << " is " << ((n4 >= *n2) ? "true" : "false")
       << endl;
  cout << *n2 << " >= " << n4 << " is " << ((*n2 >= n4) ? "true" : "false")
       << endl;
  cout << *n2 << " + " << *n2 << " = " << (*n2 + *n2) << endl;
  cout << *n1 << " - " << *n2 << " = " << (*n1 - *n2) << endl;
  cout << *n2 << " * " << *n3 << " = " << (*n2 * *n3) << endl;
  cout << *n3 << " / " << *n1 << " = " << (*n3 / *n1) << endl;
  cout << n4 << " + " << *n2 << " = " << (n4 + *n2) << endl;
  cout << *n2 << " + " << n4 << " = " << (*n2 + n4) << endl;
  cout << *n1 << " - " << n4 << " = " << (*n1 - n4) << endl;
  cout << n4 << " - " << *n2 << " = " << (n4 - *n2) << endl;
  cout << n4 << " * " << *n3 << " = " << (n4 * *n3) << endl;
  cout << *n2 << " * " << n4 << " = " << (*n2 * n4) << endl;
  cout << n4 << " / " << *n1 << " = " << (n4 / *n1) << endl;
  cout << *n3 << " / " << n4 << " = " << (*n3 / n4) << endl;
  cout << "Negative " << *n3 << " is " << -*n3 << endl;
  n3->neg();
  cout << "Negative " << *n3 << " is " << -*n3 << endl;
  cout << "Positive " << *n3 << " is " << +*n3 << endl;
  n3->neg();
  cout << "Positive " << *n3 << " is " << +*n3 << endl;
  cout << *n1 << " += " << *n2 << " = " << (*n1 += *n2) << endl;
  cout << *n1 << " *= " << *n2 << " = " << (*n1 *= *n2) << endl;
  cout << *n2 << " /= " << *n1 << " = " << (*n2 /= *n1) << endl;
  cout << *n1 << " -= " << *n2 << " = " << (*n1 -= *n2) << endl;
  cout << n4 << " += " << *n3 << " = " << (n4 += *n3) << endl;
  cout << *n3 << " += " << n4 << " = " << (*n3 += n4) << endl;
  cout << n4 << " *= " << *n3 << " = " << (n4 *= *n3) << endl;
  cout << *n3 << " *= " << n4 << " = " << (*n3 *= n4) << endl;
  cout << n4 << " -= " << *n3 << " = " << (n4 -= *n3) << endl;
  cout << *n3 << " -= " << n4 << " = " << (*n3 -= n4) << endl;
  cout << n4 << " /= " << *n3 << " = " << (n4 /= *n3) << endl;
  cout << *n3 << " /= " << n4 << " = " << (*n3 /= n4) << endl;
  cout << *n1 << " as double number is: " << (double)*n1 << endl;
}
