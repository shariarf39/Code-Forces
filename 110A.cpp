#include <iostream>
#include <string>
using namespace std;

bool isLucky(int count) {
    string s = to_string(count);
    for (char c : s) {
        if (c != '4' && c != '7') {
            return false;
        }
    }
    return true;
}

int main() {
    string n;
    cin >> n;

    int lucky_count = 0;
    for (char c : n) {
        if (c == '4' || c == '7') {
            lucky_count++;
        }
    }

    if (isLucky(lucky_count)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
