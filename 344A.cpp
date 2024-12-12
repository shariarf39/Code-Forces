#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> magnets(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> magnets[i];
    }

    int groups = 1;
    for (int i = 1; i < n; ++i) {
        if (magnets[i] != magnets[i - 1]) {
            ++groups;
        }
    }

    std::cout << groups << std::endl;

    return 0;
}
