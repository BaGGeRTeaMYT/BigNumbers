// here you can see the greatest names of all time
#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace Lil {

    class BigNumbers {
       public:
       // constructors
            template<typename T>
            BigNumbers(const T);
            BigNumbers(const std::string&);
            BigNumbers(): _accuracy(0), _value({}), _sign(0) {};  // default

        // operators
            friend const BigNumbers operator+(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator-(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator*(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator/(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator+=(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator-=(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator*=(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator/=(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator==(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator!=(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator>=(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator<=(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator>(const BigNumbers&, const BigNumbers&);
            friend const BigNumbers operator<(const BigNumbers&, const BigNumbers&);
            const BigNumbers operator+();
            const BigNumbers operator-();

        // functions
            std::string toStr() const;

        // nvm
            int TestFunction(const int&);

        private:
            int _accuracy; // guess int is enough for your satisfaction
            std::vector<short> _value;
            bool _sign;
            

            void popZeros();
            bool isZero();
    };

} // namespace