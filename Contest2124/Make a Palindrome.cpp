#include <iostream>
#include <vector>
using namespace std;

bool is_palindrome(const vector<int>& a, int l, int r, int skip) {
    while (l < r) {
        if (a[l] == a[r]) {
            l++;
            r--;
        } else if (a[l] == skip) {
            l++;
        } else if (a[r] == skip) {
            r--;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int l = 0, r = n - 1;
        while (l < r && a[l] == a[r]) {
            l++;
            r--;
        }

        if (l >= r) {
            cout << "YES\n";  // Already a palindrome
        } else {
            // Try skipping a[l] or a[r] and check
            if (is_palindrome(a, l, r, a[l]) || is_palindrome(a, l, r, a[r])) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
