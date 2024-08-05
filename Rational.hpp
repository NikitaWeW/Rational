//Copyright (c) 2024 Nikita Martynau
//
//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#pragma once
#include <ostream>

namespace rational {
    struct Rational
    {
        Rational(int numerator = 0, int denominator = 1);
        Rational(Rational const &other);
        Rational(Rational &&other);

        void add(Rational const &other);
        void sub(Rational const &other);
        void mul(Rational const &other);
        void div(Rational const &other);
        
        void neg();
        void inv();
        double asDouble() const;
        void swap(Rational & other);
        Rational &cancel();
        
        Rational &operator=(Rational &&other);

        Rational &operator=(Rational const &other);
        Rational &operator+=(Rational const &other);
        Rational &operator-=(Rational const &other);
        Rational &operator*=(Rational const &other);
        Rational &operator/=(Rational const &other);

        Rational &operator=(int const &number);
        Rational &operator+=(int const &number);
        Rational &operator-=(int const &number);
        Rational &operator*=(int const &number);
        Rational &operator/=(int const &number);

        Rational operator-() const;
        Rational operator+() const;

        int getNumerator();
        int getDenominator();
        
    private:
        int numerator_;
        int denominator_;
    };
    

    Rational operator+(Rational left, Rational right);
    Rational operator-(Rational left, Rational right);
    Rational operator*(Rational left, Rational right);
    Rational operator/(Rational left, Rational right);

    bool operator==(Rational left, Rational right);
    bool operator!=(Rational left, Rational right);
    bool operator>(Rational left, Rational right);
    bool operator<(Rational left, Rational right);
    bool operator<=(Rational left, Rational right);
    bool operator>=(Rational left, Rational right);

    std::ostream &operator<<(std::ostream &out, Rational rational);

    int GCF(int a, int b);
}