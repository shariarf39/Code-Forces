#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> percentages(n);
    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        std::cin >> percentages[i];
        sum += percentages[i];
    }

    double result = sum / n;
    std::cout << std::fixed << std::setprecision(12) << result << std::endl;

    return 0;
}