#include <big.h>

int main() {
    Lil::BigNumbers a("1030.11");
    Lil::BigNumbers b = "1"_big;
    Lil::BigNumbers c("0");
    Lil::BigNumbers f = 5_big;

    std::vector<Lil::BigNumbers> arr = {a, b, c, f};
    // answers
    std::vector<Lil::BigNumbers> answer_sum = {"2060.22"_big, "1031.11"_big,
    "1030.11"_big, "1035.11"_big, "1031.11"_big, "2"_big, "1"_big,
    "6"_big, "1030.11"_big, "1"_big, "0"_big, "5"_big, "1035.11"_big,
    "6"_big, "5"_big, "10"_big};
    std::vector<Lil::BigNumbers> answer_sub = {"0.00"_big, "1029.11"_big,
    "1030.11"_big, "1025.11"_big, "-1029.11"_big, "0"_big, "1"_big,
    "-4"_big, "-1030.11"_big, "-1"_big, "0"_big, "-5"_big, "-1025.11"_big,
    "4"_big, "5"_big, "0"_big};
    std::vector<Lil::BigNumbers> answer_mult = {"1061126.6121"_big,
    "1030.11"_big, "0.00"_big, "5150.55"_big, "1030.11"_big, "1"_big,
    "0"_big, "5"_big, "0.00"_big, "0"_big, "0"_big, "0"_big, "5150.55"_big,
    "5"_big, "0"_big, "25"_big};
    std::vector<Lil::BigNumbers> answer_div = {"1.00"_big, "1030.11"_big,
    "206.02"_big, "0.00"_big, "1"_big, "0"_big, "0.00"_big, "0"_big,
    "0"_big, "0.00"_big, "5"_big, "1"_big};

    int ans_iter = 0;

    std::cout << "\nSummations:\n";
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            std::cout << "(" << arr[i] << ") + (" << arr[j]
            << ") = " << (arr[i] + arr[j]) << std::endl;
            std::cout << "The answer should be: " << answer_sum[ans_iter++] << std::endl << std::endl;
        }
    }

    ans_iter = 0;
    std::cout << "\nSubstractions:\n";
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            std::cout << "(" << arr[i] << ") - (" << arr[j]
            << ") = " << (arr[i] - arr[j]) << std::endl;
            std::cout << "The answer should be: " << answer_sub[ans_iter++] << std::endl << std::endl;
        }
    }

    ans_iter = 0;
    std::cout << "\nMultiplications:\n";
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            std::cout << "(" << arr[i] << ") * (" << arr[j]
            << ") = " << (arr[i] * arr[j]) << std::endl;
            std::cout << "The answer should be: " << answer_mult[ans_iter++] << std::endl << std::endl;
        }
    }

    ans_iter = 0;
    std::cout << "\nDivisions (the result will have accuracy = max{op1, op2}):\n";
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] != 0) {
                std::cout << "(" << arr[i] << ") / (" << arr[j]
                << ") = " << (arr[i] / arr[j]) << std::endl;
                std::cout << "The answer should be: " << answer_div[ans_iter++] << std::endl << std::endl;
            }
        }
    }
    return 0;
}