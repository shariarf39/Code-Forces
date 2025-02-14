#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> events(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> events[i];
    }
    
    int untreatedCrimes = 0;
    int availableOfficers = 0;
    
    for (int i = 0; i < n; ++i) {
        if (events[i] == -1) {
            if (availableOfficers > 0) {
                --availableOfficers;
            } else {
                ++untreatedCrimes;
            }
        } else {
            availableOfficers += events[i];
        }
    }
    
    std::cout << untreatedCrimes << std::endl;
    
    return 0;
}