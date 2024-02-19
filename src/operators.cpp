#include <big.h>

namespace Lil {

// unary operators
const BigNumbers operator+(const BigNumbers& a) {
    return a;
}

const BigNumbers operator-(const BigNumbers& a) {
    BigNumbers result = a;
    if (!(result.isZero())) {
        result._sign = !result._sign;
    }
    return result;
}

// binary operators 
const bool operator==(const BigNumbers& a, const BigNumbers& b) {
    
    if (a._sign != b._sign) {
        return false;
    }

    size_t i = 0;
    char flag = 0;

    // comparing numbers with different amount numbers after dot.
    while (a._accuracy - i > b._accuracy) {
        if (a._value[a._value.size() - 1 - i]) {
            return false;
        }
        i++;
        flag = 1;
    }
    while (b._accuracy - i > a._accuracy) {
        if (b._value[b._value.size() - 1 - i]) {
            return false;
        }
        i++;
        flag = 2;
    }

    // now i is accuracy difference
    if (flag == 2) { // b is more accurate
        if (b._value.size() - i != a._value.size()) {
            // there are no leading zeros
            return false;
        }
    } else if (flag == 1) { // a is more accurate
        if (a._value.size() - i != b._value.size()) {
            // there are no leading zeros
            return false;
        }
    }

    // comparing two numbers of the same size
    for (int i = 0; i < std::min(a._value.size(), b._value.size()); i++) {
        if (a._value[i] != b._value[i]) {
            return false;
        }
    }
    return true;
}

const bool operator!=(const BigNumbers& a, const BigNumbers& b) {
    return !(a == b);
}

const bool operator>(const BigNumbers& a, const BigNumbers& b) {
    if (a._sign > b._sign) { // means a is negative and b is positive or zero
        return false;
    } else if (a._sign < b._sign) {
        return true;
    } else { // we have to compare them
        if (a._sign) {  // both numbers are negative
            
            // a > b
            // a, b < 0 =>
            // |a| < |b| =>
            // -b > -a
            return (-b > -a);

        } else { // both positive
            // if their integer part have different size
            if (a._value.size() - a._accuracy > b._value.size() - b._accuracy) {
                return true;
            }
            if (b._value.size() - b._accuracy > a._value.size() - a._accuracy) {
                return false;
            }

            size_t i = 0;
            // comparing numbers
            while (i < a._value.size() && i < b._value.size()) {
                if (a._value[i] > b._value[i]) {
                    return true;
                }
                if (a._value[i] < b._value[i]) {
                    return false;
                }
                i++;
            }
            while (i < a._value.size()) {
                if (a._value[i]) {
                    return true;
                }
                i++;
            }
            while (i < b._value.size()) {
                if (b._value[i]) {
                    return false;
                }
                i++;
            }
        }
    }
    return false;
}

const bool operator<(const BigNumbers& a, const BigNumbers& b) {
    return !(a > b || a == b);
}

const bool operator>=(const BigNumbers& a, const BigNumbers& b) {
    return !(a < b);
}

const bool operator<=(const BigNumbers& a, const BigNumbers& b) {
    return !(a > b);
}

BigNumbers operator+=(BigNumbers& left, const BigNumbers& right) { // Still working on it
    // std::cout << "Inside operator += [\n";
    if (left.isZero()) {
        // std::cout << "Left is zero\n]\n";
        left = right;
        return left;
    }
    int i = (left._value.size() - left._accuracy) - (right._value.size() - right._accuracy);
    while (right._accuracy > left._accuracy) {
        left._value.push_back(0);
        left._accuracy++;
    }
    while (i < 0) {
        left._value.insert(left._value.begin(), 0);
        i++;
    }
    // std::cout << "Left is " << left.toStr() << " now\n";
    if (left._sign != right._sign) { // different signs
        // std::cout << "Got different signs\n";
        if (left._sign == 1) { // left is negative
            // std::cout << "Left is negative\n";
            if (-left > right) { // left remains negative
                // std::cout << "Left will remain negative\n";
                for (short num : right._value) {
                    left._value[i++] -= num;
                }
                // abs(left) > abs(right) so left._value[0] >= 0
                for (size_t j = left._value.size() - 1; j > 0; j--) {
                    if (left._value[j] < 0) {
                        left._value[j] += 10;
                        left._value[j - 1]--;
                    }
                }

            } else { // left should be positive now
                // std::cout << "Left will become positive\n";
                left._sign = 0;
                for (short num : right._value) {
                    left._value[i] = num - left._value[i];
                    i++;
                }

                for (size_t j = left._value.size() - 1; j > 0; j--) {
                    if (left._value[j] < 0) {
                        left._value[j] += 10;
                        left._value[j - 1]--;
                    }
                }

            }

        } else if (right._sign == 1) { // left is positive

            left = right + left; // calling situtation when left is negative

        }
    } else { // same signs
        // std::cout << "Got same signs\n";
        // left will keep its sign
        for (short num : right._value) {
            left._value[i++] += num;
        }
        for (int j = left._value.size(); j > 0; j--) {
            if (left._value[j] > 9) {
                left._value[j] -= 10;
                left._value[j - 1]++;
            }
        }
        if (left._value[0] > 9) {
            left._value[0] -= 10;
            left._value.insert(left._value.begin(), 1);
        }

    }
    // std::cout << "]\n";
    if (left.isZero()) {
        left._sign = 0;
    }
    left.popZeros();
    return left;
}

const BigNumbers operator+(const BigNumbers& left, const BigNumbers& right) {
    BigNumbers sum = 0;
    // std::cout << "Inside operator+ {\n";
    // std::cout << sum.toStr() << " + " << left.toStr() << std::endl;
    sum += left;
    // std::cout << " = " << sum.toStr() << std::endl;
    // std::cout << sum.toStr() << " + " << right.toStr() << std::endl;
    sum += right;
    // std::cout << " = " << sum.toStr() << std::endl << "}\n";
    return sum;
}

const BigNumbers operator-(const BigNumbers& left, const BigNumbers& right) {
    return left + (-right);
}

BigNumbers operator-=(BigNumbers& left, const BigNumbers& right) {
    left += -right;
    return left;
}

const BigNumbers operator*(const BigNumbers& left, const BigNumbers& right)  {
    BigNumbers result = naiveMultiplication(left, right);
    return result;
}

BigNumbers operator*=(BigNumbers& left, const BigNumbers& right) {
    left = left*right;
    return  left;
}

std::ostream& BigNumbers::operator<<(std::ostream& os) {
    os << (*this).toStr();
    return os;
}

const BigNumbers operator/(const BigNumbers& left, const BigNumbers& right) {
    if (right == 0) {
        throw std::runtime_error("Division by zero");
    }
    BigNumbers result;
    BigNumbers new_left = left;
    new_left._sign = 0;
    result._sign = (left._sign)^(right._sign);
    int digit_difference = std::max((static_cast<int>(left._value.size()) - left._accuracy) 
    - (static_cast<int>(right._value.size()) - right._accuracy), 0);
    result._value.resize(digit_difference + 1 + std::max(left._accuracy, right._accuracy));
    result._accuracy = std::max(left._accuracy, right._accuracy);
    for (int i = 0; i < result._value.size(); i++) {
        
        short lhs = 0, rhs = 10;
        BigNumbers power;
        power.TenPow(digit_difference - i);
        power._sign = right._sign;

        while (rhs - lhs > 1) {
            short mid = (lhs + rhs)/2;
            if (right*mid*power > new_left) {
                rhs = mid;
            } else {
                lhs = mid;
            }
        }
        new_left -= right*lhs*power;
        result._value[i] = lhs;

    }
    return result;
}

BigNumbers operator/=(BigNumbers& left, const BigNumbers& right) {
    left = left/right;
    return left;
}
}