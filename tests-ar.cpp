#include <big.h>

int main() {
    Lil::BigNumbers a("1030.11");
    Lil::BigNumbers b = "1"_big;
    Lil::BigNumbers c("0");
    Lil::BigNumbers d = -1010.12300000000000_big;
    Lil::BigNumbers e("2.00");
    Lil::BigNumbers f = 5_big;
    std::vector<Lil::BigNumbers> arr = {a, b, c, d, e, f};

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            std::cout << "(" << arr[i] << ") + (" << arr[j]
            << ") = " << (arr[i] + arr[j]) << std::endl;
            std::cout << "(" << arr[i] << ") - (" << arr[j]
            << ") = " << (arr[i] - arr[j]) << std::endl;
        }
    }
    std::cout << "Multiplications:\n";
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            std::cout << "(" << arr[i] << ") * (" << arr[j]
            << ") = " << (arr[i] * arr[j]) << std::endl;
        }
    }
    std::cout << "Divisions:\n";
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] != 0) {
                std::cout << "(" << arr[i] << ") / (" << arr[j]
                << ") = " << (arr[i] / arr[j]) << std::endl;
            }
        }
    }
    return 0;
}