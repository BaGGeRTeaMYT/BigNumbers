#include <big.h>


Lil::BigNumbers::BigNumbers(const std::string &input) {
    _value = {};
    int dots_count = 0;
    _accuracy = 0;
    bool flag = 0;
    for (char symbol : input) {
        //std::cout << "Working with symbol  " << symbol << std::endl;
        if (dots_count) {
            _accuracy++;
        }
        if (!flag) {
            if (symbol ==  '-') {
                _sign = 1;
                //std::cout << "Set sign to 1" << std::endl;
                flag = 1;
                continue;
            } else {
                // correct interpretation for numbers like .0123
                // .123 = 0.123
                if (symbol == '.') {
                    _value.push_back(0);
                }
                _sign = 0;
                flag = 1;
            }
        }
        if (symbol == '.') {
            dots_count++;
            if (dots_count > 1) {
                throw std::runtime_error("Impossible to identify the number (more than one dot)");
            }
        } else if (isdigit(symbol)) {
            _value.push_back(symbol - '0');
        } else {
            throw std::runtime_error("Impossible to identify the number (symbol which is not a digit or dot))");
        }
    }
    popZeros();
    if (isZero()) {
        _sign = 0;
    }
}

Lil::BigNumbers::BigNumbers(const int& a): BigNumbers(std::to_string(a)){}
Lil::BigNumbers::BigNumbers(const long long& a): BigNumbers(std::to_string(a)){}
Lil::BigNumbers::BigNumbers(const double& a): BigNumbers(std::to_string(a)){}
