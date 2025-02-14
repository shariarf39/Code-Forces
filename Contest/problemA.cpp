#include <iostream>
using namespace std;

bool canUnlock(int x) {
    while (x >= 33) {
        if (x % 100 == 33) {
            x /= 100;
        } else {
            x -= 33;
        }
    }
    return x == 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        if (canUnlock(x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}