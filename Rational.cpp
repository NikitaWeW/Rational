//Copyright (c) 2024 Nikita Martynau
//
//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include <ostream>
#include "Rational.hpp"

namespace rational {
    Rational operator+(Rational left, Rational right) {
        return Rational(left) += right;
    }
    Rational operator-(Rational left, Rational right) {
        return Rational(left) -= right;
    }
    Rational operator*(Rational left, Rational right) {
        return Rational(left) *= right;
    }
    Rational operator/(Rational left, Rational right) {
        return Rational(left) /= right;
    }

    bool operator==(Rational left, Rational right) {
        return left.asDouble() == right.asDouble();
    }
    bool operator!=(Rational left, Rational right) {
        return !(left == right);
    }
    bool operator>(Rational left, Rational right) {
        return left.asDouble() > right.asDouble();
    }
    bool operator<(Rational left, Rational right) {
        return right > left;
    }
    bool operator<=(Rational left, Rational right) {
        return !(left > right);
    }
    bool operator>=(Rational left, Rational right) {
        return !(left < right);
    }

    std::ostream &operator<<(std::ostream &out, Rational rational) {
        return out << rational.getNumerator() << '/' << rational.getDenominator();
    }

    int GCF(int a, int b) {
        return b == 0 ? a : GCF(b, a % b);
    }

    Rational::Rational(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {};
    Rational::Rational(Rational const &other) : numerator_(other.numerator_), denominator_(other.denominator_) {};
    Rational::Rational(Rational &&other) {
        swap(other);
    };

    void Rational::add(Rational const &other) {
        numerator_ = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        denominator_ *= other.denominator_;
    }
    void Rational::sub(Rational const &other) {
        numerator_ = numerator_ * other.denominator_ - other.numerator_ * denominator_;
        denominator_ *= other.denominator_;
    }
    void Rational::mul(Rational const &other) {
        numerator_ *= other.numerator_;
        denominator_ *= other.denominator_;
    }
    void Rational::div(Rational const &other) {
        numerator_ *= other.denominator_;
        denominator_ *= other.numerator_;
    }
    
    void Rational::neg() {
        numerator_ = -numerator_;
    }
    void Rational::inv() {
        std::swap(numerator_, denominator_);
    }
    double Rational::asDouble() const {
        return numerator_ / (double) denominator_;
    }
    void Rational::swap(Rational & other) {
        std::swap(numerator_, other.numerator_);
        std::swap(denominator_, other.denominator_);
    }
    Rational &Rational::cancel() {
        int gcf = GCF(numerator_, denominator_);
        numerator_ /= gcf;
        denominator_ /= gcf;
        return *this;
    }

    Rational &Rational::operator=(Rational &&other) {
        swap(other);
        return *this;
    }

    Rational &Rational::operator=(Rational const &other) {
        numerator_ = other.numerator_;
        denominator_ = other.denominator_;
        return *this;
    }
    Rational &Rational::operator+=(Rational const &other) {
        add(other);
        return *this;
    }
    Rational &Rational::operator-=(Rational const &other) {
        sub(other);
        return *this;
    }
    Rational &Rational::operator*=(Rational const &other) {
        mul(other);
        return *this;
    }
    Rational &Rational::operator/=(Rational const &other) {
        div(other);
        return *this;
    }

    Rational &Rational::operator=(int const &number) {
        numerator_ = number;
        denominator_ = 1;
        return *this;
    }
    Rational &Rational::operator+=(int const &number) {
        numerator_ += number * denominator_;
        return *this;
    }
    Rational &Rational::operator-=(int const &number) {
        numerator_ -= number * denominator_;
        return *this;
    }
    Rational &Rational::operator*=(int const &number) {
        numerator_ *= number;
        return *this;
    }
    Rational &Rational::operator/=(int const &number) {
        denominator_ *= number;
        return *this;
    }

    Rational Rational::operator-() const {
        return Rational(-numerator_, -denominator_);
    }
    Rational Rational::operator+() const {
        return *this;
    }

    int Rational::getNumerator() {
        return numerator_;
    }
    int Rational::getDenominator() {
        return denominator_;
    }

}