#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int k;
    cin >> k;
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        cout << "? " << l << " " << mid << endl;
        cout.flush();
        int response;
        cin >> response;
        if (response == -1) exit(0);

        if (mid - l + 1 < k) {
            if (response == 1) {
                r = mid;
            } else {
                l = mid + 1;
            }
        } else {
            if (response == 0) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
    }

    cout << "! " << l << endl;
    cout.flush();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}