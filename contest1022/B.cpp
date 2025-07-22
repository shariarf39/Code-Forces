#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        if (n == 1) {
            cout << x << endl;
        } else if (n == 2) {
            cout << x << endl;
        } else {
            if (n % 2 == 0) {
                cout << x << endl;
            } else {
                if (x == 0) {
                    cout << n << endl;
                } else {
                    cout << x + 1 << endl;
                }
            }
        }
    }
    return 0;
}
