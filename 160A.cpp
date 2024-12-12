#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> coins(n);
    int totalSum = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
        totalSum += coins[i];
    }

    std::sort(coins.rbegin(), coins.rend());

    int mySum = 0;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        mySum += coins[i];
        count++;
        if (mySum > totalSum - mySum) {
            break;
        }
    }

    std::cout << count << std::endl;

    return 0;
}