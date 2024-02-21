#include <big.h>

int main() {
    int accuracy = 0;
    std::cout << "How many symbols after coma do you want: ";
    std::cin >> accuracy;
    std::cout << std::endl;
    Lil::BigNumbers pi;
    // Lil::BigNumbers pi_("3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067");
    
    const auto start{std::chrono::steady_clock::now()};
    const auto pi_timer{pi.Calculate_Pi(accuracy)};
    const auto end{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds{end - start};
    std::cout << "Pi is: " << pi << std::endl;
    // std::cout << "Difference: " << (pi - pi_) << std::endl;
    std::cout << "Required: " << elapsed_seconds.count() << "s\n";
    return  0;
}