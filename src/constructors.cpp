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
                //std::cout << "Set sign to 0" << std::endl;
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
            throw std::runtime_error("Impossible to identify the number (letters inside)");
        }
    }
    popZeros();
}

Lil::BigNumbers::BigNumbers(const int& a): BigNumbers(std::to_string(a)){}
Lil::BigNumbers::BigNumbers(const double& a): BigNumbers(std::to_string(a)){}
