#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> cubes(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> cubes[i];
    }

    std::sort(cubes.begin(), cubes.end());

    for (int i = 0; i < n; ++i) {
        std::cout << cubes[i] << " ";
    }

    return 0;
}