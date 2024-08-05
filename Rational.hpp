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