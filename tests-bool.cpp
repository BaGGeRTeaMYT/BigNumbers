#include <big.h>

int main() {
    // checking  ==

    Lil::BigNumbers a("1.1");
    Lil::BigNumbers b("-0.");
    Lil::BigNumbers c("0");
    Lil::BigNumbers d("-1.12");
    Lil::BigNumbers e("11.1");
    std::vector<Lil::BigNumbers> arr = {a, b, c, d, e};

    std::cout << "I guess you don't answers for this kind of tests\n";
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                std::cout << arr[i] << " > " << arr[j];
            } else if (arr[i] == arr[j]) {
                std::cout << arr[i] << " == " << arr[j];
            } else if (arr[i] < arr[j]) {
                std::cout << arr[i] << " < " << arr[j];
            }
            std::cout << std::endl;
        }
    }
    return  0;
}