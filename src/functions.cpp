#include <big.h>

namespace Lil {

void BigNumbers::popZeros() {
    while ( !((static_cast<int>(_value.size()) <= _accuracy + 1) || (_value[0])) ) {
        _value.erase(_value.begin());
    }
}

std::string BigNumbers::toStr() const {  
    std::string result = "";
    int integer_size = _value.size() - _accuracy;
    if (_sign == 1) {
        result += "-";
    }
    for (size_t i = 0; i < _value.size(); i++) {
        if (_value.size() - i == _accuracy) {
            result += '.';
        }
        if (i < integer_size + MAX_ACCURACY - 3) {
            result += _value[i] + '0';
        }
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
    int res_integer_part = result._value.size() - result._accuracy;
    int required_accuracy = res_integer_part + MAX_ACCURACY;
    for (size_t i = 0; i < left._value.size(); i++) {
        for (size_t j = 0; j < right._value.size(); j++) {
            if (i + j <= required_accuracy) {
                result._value[i + j] += (left._value[i])*(right._value[j]);
            } else {
                break;
            }
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

BigNumbers::operator bool() const {
    return (*(this) != 0);
}

BigNumbers BigNumbers::Calculate_Pi(const int b) {
    if (b <= 0) {
        (*this) = 3;
        return 3;
    }

    int a = b + 1;
    BigNumbers magic_num;
    BigNumbers magic_zero = 0;
    magic_zero._value.resize(a + 1);
    magic_zero._accuracy = a;
    (*this) = magic_zero;
    magic_num._value.resize(a + 1);
    magic_num._accuracy = a;
    magic_num._value[0] = 1; // now it is 1
    (*this)._accuracy = a;
    (*this)._value.resize(a + 1);
    BigNumbers num1;
    num1._value.resize(a + 1);
    num1._accuracy = a;
    num1._value[0] = 1;
    BigNumbers num2;
    num2._value.resize(a + 1);
    num2._accuracy = a;
    num2._value[0] = 4;
    BigNumbers num3;
    num3._value.resize(a + 1);
    num3._accuracy = a;
    num3._value[0] = 5;
    BigNumbers num4;
    num4._value.resize(a + 1);
    num4._accuracy = a;
    num4._value[0] = 6;
    while (true) {
        BigNumbers tmp = magic_num*(4/num1 - 2/num2 - 1/num3 - 1/num4);
        if (tmp <= 0) {
            break;
        }
        (*this) += tmp;
        magic_num /= 16;
        num1 += 8;
        num2 += 8;
        num3 += 8;
        num4 += 8;
    }
    (*this)._accuracy = b;
    (*this)._value.resize(b + 1);
    return (*this);
}

}