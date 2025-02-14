#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    std::vector<int> even_indices;
    std::vector<int> odd_indices;

    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
        if (numbers[i] % 2 == 0) {
            even_indices.push_back(i + 1);
        } else {
            odd_indices.push_back(i + 1);
        }
    }

    if (even_indices.size() == 1) {
        std::cout << even_indices[0] << std::endl;
    } else {
        std::cout << odd_indices[0] << std::endl;
    }

    return 0;
}