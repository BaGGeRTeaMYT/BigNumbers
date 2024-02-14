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
            BigNumbers(const long&);
            BigNumbers(const long long&);
            BigNumbers(const unsigned int&);
            BigNumbers(const unsigned long&);
            BigNumbers(const unsigned long long&);
            BigNumbers(const float&);
            BigNumbers(const double&);
            BigNumbers(const std::string&);
            BigNumbers(): accuracy(0), value({}), sign(0) {};  // default

        // operators
            friend const BigNumbers operator+(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator-(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator*(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator/(const BigNumbers&, const BigNumbers&);

        // functions
            std::string toStr() const;


        private:
            int accuracy; // guess int is enough for your satisfaction
            std::vector<long long> value;
            bool sign;
            
    };

} // namespace
// nvm
int TestFunction(const int&);