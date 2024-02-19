#include <big.h>

namespace Lil {

void BigNumbers::popZeros() {
    while ( !((static_cast<int>(_value.size()) <= _accuracy + 1) || (_value[0])) ) {
        _value.erase(_value.begin());
    }
}

std::string BigNumbers::toStr() const {  
    std::string result = "";
    if (_sign == 1) {
        result += "-";
    }
    for (size_t i = 0; i < _value.size(); i++) {
        if (_value.size() - i == _accuracy) {
            result += '.';
        }
        result += _value[i] + '0';
    }
    return result;
}

bool BigNumbers::isZero() {
    for (size_t i = 0; i < _value.size(); i++) {
        if (_value[i]) {
            return false;
        }
    }
    return true;
}

void BigNumbers::extendVector(size_t length) {
    while (length & (length - 1)) {
        _value.insert(_value.begin(), 0);
        length++;
    }
}

void BigNumbers::normalize() {
    for (size_t i = _value.size() - 1 ; i > 0; i--) {
        _value[i - 1] += _value[i]/10;
        _value[i] %= 10;
    }
    if (_value[0] > 9) {
        _value.insert(_value.begin(), _value[0]/10);
        _value[1] %= 10;
    }
}

BigNumbers naiveMultiplication(const BigNumbers& left, const BigNumbers& right) {
    BigNumbers result;
    result._value.resize(left._value.size() + right._value.size() - 1);
    result._accuracy = (left._accuracy) + (right._accuracy);
    result._sign = (left._sign)^(right._sign);
    for (size_t i = 0; i < left._value.size(); i++) {
        for (size_t j = 0; j < right._value.size(); j++) {
            result._value[i + j] += (left._value[i])*(right._value[j]);
        }
    }
    if (result.isZero()) {
        result._sign = 0;
    }
    result.normalize();
    result.popZeros();
    return result;
}

void BigNumbers::TenPow(int a) {
    (*this) = 1;
    while (a > 0) {
        (*this)._value.push_back(0);
        a--;
    }
    if (a < 0) {
        (*this)._accuracy = -a;
        (*this)._value.resize((*this)._accuracy + 1);
        (*this)._value[0] = 0;
        (*this)._value[(*this)._value.size() - 1] = 1;
    }
}

}