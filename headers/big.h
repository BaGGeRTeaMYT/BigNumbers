// here you can see the greatest names of all time
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

namespace Lil {
    
    #define MAX_ACCURACY 103

    class BigNumbers {
       public:
       // constructors
            BigNumbers(const int&);
            BigNumbers(const long long&);
            BigNumbers(const unsigned long long&);
            BigNumbers(const double&);
            BigNumbers(const long double&);
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
            friend std::ostream& operator <<(std::ostream&, const BigNumbers&);

        // functions
            std::string toStr() const;
            BigNumbers Calculate_Pi(const int b);
            explicit operator bool() const;

        private:
            int _accuracy; // guess int is enough for your satisfaction
            std::vector<short> _value;
            bool _sign;
            
            void popZeros();
            bool isZero();
            void extendVector(size_t);
            friend BigNumbers naiveMultiplication(const BigNumbers&, const BigNumbers&);
            void normalize();
            void TenPow(int a);
    };

} // namespace
Lil::BigNumbers operator""_big (const char* a, size_t length);
Lil::BigNumbers operator""_big (unsigned long long a);
Lil::BigNumbers operator""_big (long double a);