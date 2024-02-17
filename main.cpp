#include <big.h>


int main() {
    std::string init("12346789.1234546");
    Lil::BigNumbers a(init);
    Lil::BigNumbers e = a;
    double b = -00.000123;
    a = b;
    a = -a;
    std::string d = a.toStr();
    if (a == b) {
        std::cout << "a is " << d << std::endl;
    }
    return  0;
}