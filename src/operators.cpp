#include <big.h>

namespace Lil {

// unary operators
const BigNumbers operator+(const BigNumbers& a) {
    return a;
}

const BigNumbers operator-(const BigNumbers& a) {
    BigNumbers result = a;
    result._sign = !result._sign;
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
    // int i = (left._value.size() - left._accuracy) - (right._value.size() - right._accuracy);
    // while (right._accuracy > left._accuracy) {
    //     left._value.push_back(0);
    //     left._accuracy++;
    // }
    // while (i < 0) {
    //     left._value.insert(left._value.begin(), 0);
    //     i++;
    // }
    // if (left._sign != right._sign) {

    // }

    // return left;
}

}