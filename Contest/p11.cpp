#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a(n, 0);
        bool possible = true;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                a[i] = i;
            } else {
                a[i] = n - i - 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L' && a[i] != i) {
                possible = false;
                break;
            }
            if (s[i] == 'R' && a[i] != n - i - 1) {
                possible = false;
                break;
            }
        }

        if (possible) {
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
