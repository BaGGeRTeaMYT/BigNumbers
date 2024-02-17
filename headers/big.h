// here you can see the greatest names of all time
#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace Lil {

    class BigNumbers {
       public:
       // constructors
            BigNumbers(const int&);
            BigNumbers(const double&);
            BigNumbers(const std::string&);
            BigNumbers(): _accuracy(0), _value({}), _sign(0) {};  // default

        // operators
            friend const BigNumbers operator+(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator-(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator*(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator/(const BigNumbers&, const BigNumbers&);
            friend BigNumbers operator+=(BigNumbers&, const BigNumbers&);
            friend BigNumbers operator-=(BigNumbers&, const BigNumbers&);
            friend BigNumbers operator*=(BigNumbers&, const BigNumbers&);
            friend BigNumbers operator/=(BigNumbers&, const BigNumbers&);
            friend const bool operator==(const BigNumbers&, const BigNumbers&);
            friend const bool operator!=(const BigNumbers&, const BigNumbers&);
            friend const bool operator>=(const BigNumbers&, const BigNumbers&);
            friend const bool operator<=(const BigNumbers&, const BigNumbers&);
            friend const bool operator>(const BigNumbers&, const BigNumbers&);
            friend const bool operator<(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator+(const BigNumbers&);
            friend const BigNumbers operator-(const BigNumbers&);

        // functions
            std::string toStr() const;
            const BigNumbers abs();

        private:
            int _accuracy; // guess int is enough for your satisfaction
            std::vector<short> _value;
            bool _sign;
            
            void popZeros();
            bool isZero();
    };
} // namespace

Lil::BigNumbers operator""_big (const char* a);