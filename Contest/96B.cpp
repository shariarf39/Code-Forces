#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void generateSuperLuckyNumbers(string current, int len, int count4, int count7, vector<string>& superLucky) {

    if (current.length() == len) {
        if (count4 == count7) {
            superLucky.push_back(current);
        }
        return;
    }

    generateSuperLuckyNumbers(current + "4", len, count4 + 1, count7, superLucky);
    generateSuperLuckyNumbers(current + "7", len, count4, count7 + 1, superLucky);
}

string findLeastSuperLucky(long long n) {
    string nStr = to_string(n);
    int len = nStr.size();
    vector<string> superLucky;


    for (int i = len; i <= len + 1; ++i) {
        generateSuperLuckyNumbers("", i, 0, 0, superLucky);
    }

    sort(superLucky.begin(), superLucky.end());


    for (const string& num : superLucky) {
        if (stoll(num) >= n) {
            return num;
        }
    }
    return "";
}

int main() {
    long long n;
    cin >> n;
    cout << findLeastSuperLucky(n) << endl;
    return 0;
}
