#include <big.h>


int main() {
    std::string init("12346789.1234546");
    Lil::BigNumbers a(init);
    double b = -00.000123;
    a = b;
    std::string d = a.toStr();
    std::cout << "a is " << d << std::endl;
    return  0;
}