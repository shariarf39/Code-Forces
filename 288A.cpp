#include <iostream>
#include <set>

int main() {
    int s1, s2, s3, s4;
    std::cin >> s1 >> s2 >> s3 >> s4;

    std::set<int> unique_colors;
    unique_colors.insert(s1);
    unique_colors.insert(s2);
    unique_colors.insert(s3);
    unique_colors.insert(s4);

    int horseshoes_to_buy = 4 - unique_colors.size();
    std::cout << horseshoes_to_buy << std::endl;

    return 0;
}