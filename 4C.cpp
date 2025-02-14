#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::unordered_map<std::string, int> database;
    
    for (int i = 0; i < n; ++i) {
        std::string name;
        std::cin >> name;
        
        if (database.find(name) == database.end()) {
            database[name] = 0;
            std::cout << "OK" << std::endl;
        } else {
            ++database[name];
            std::cout << name << database[name] << std::endl;
        }
    }
    
    return 0;
}