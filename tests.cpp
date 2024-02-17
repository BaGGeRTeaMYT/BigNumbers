#include <big.h>

int main() {
    // checking  ==

    Lil::BigNumbers a("1000.1");
    Lil::BigNumbers b("-0.");
    Lil::BigNumbers c("0");
    Lil::BigNumbers d("1000.12");
    Lil::BigNumbers e("1001.1");
    std::vector<Lil::BigNumbers> arr = {a, b, c, d, e};
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[i] == arr[j]) {
                std::cout << arr[i].toStr() << "==" << arr[j].toStr() << "\t\t";
            }  else {
                std::cout << arr[i].toStr() << "!=" << arr[j].toStr() << "\t\t";
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                std::cout << arr[i].toStr() << ">" << arr[j].toStr() << "\t\t";
            }  else {
                std::cout << arr[i].toStr() << "<=" << arr[j].toStr() << "\t\t";
            }
        }
        std::cout << std::endl;
    }

    arr[0] += arr[1];
    return  0;
}