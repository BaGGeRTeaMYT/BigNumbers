#include <big.h>

int Lil::BigNumbers::TestFunction(const int& b) {
    std::cout << "Test function is working\n";
    return b + 1;
}

void Lil::BigNumbers::popZeros() {
    while ( !((static_cast<int>(_value.size()) <= _accuracy + 1) || (_value[0])) ) {
        _value.erase(_value.begin());
    }
}

std::string Lil::BigNumbers::toStr() const {  
    std::string result = "";
    for (size_t i = 0; i < _value.size(); i++) {
        if (_value.size() - i == _accuracy) {
            result += '.';
        }
        result += _value[i] + '0';
    }
    return result;
}

bool Lil::BigNumbers::isZero() {
    for (short i : _value) {
        if (i) {
            return false;
        }
    }
    return true;
}
