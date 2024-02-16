#include <big.h>

Lil::BigNumbers::BigNumbers(const std::string &input) {
    _value = {};
    int dots_count = 0;
    _accuracy = 0;
    bool flag = 0;
    for (char symbol : input) {
        if (dots_count) {
            _accuracy++;
        }
        if (!flag) {
            flag = 1;
            if (symbol == '-') {
                _sign = 1;
            }
        } else if (symbol == '.') {
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


template <typename T>
Lil::BigNumbers::BigNumbers(const T) {
    Lil::BigNumbers::BigNumbers(std::to_string(T));
}
