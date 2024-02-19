#include <big.h>

int main() {
    Lil::BigNumbers a("1030.11");
    Lil::BigNumbers b("1");
    Lil::BigNumbers c("0");
    Lil::BigNumbers d("-1010.123");
    Lil::BigNumbers e("2");
    Lil::BigNumbers f("5");
    std::vector<Lil::BigNumbers> arr = {a, b, c, d, e, f};

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            std::cout << "(" << arr[i].toStr() << ") + (" << arr[j].toStr()
            << ") = " << (arr[i] + arr[j]).toStr() << std::endl;
            std::cout << "(" << arr[i].toStr() << ") - (" << arr[j].toStr()
            << ") = " << (arr[i] - arr[j]).toStr() << std::endl;
        }
    }
    std::cout << "Multiplications:\n";
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            std::cout << "(" << arr[i].toStr() << ") * (" << arr[j].toStr()
            << ") = " << (arr[i] * arr[j]).toStr() << std::endl;
        }
    }
    std::cout << "(" << c.toStr() << ") * (" << c.toStr()
            << ") = " << (c * c).toStr() << std::endl;
    return 0;
}