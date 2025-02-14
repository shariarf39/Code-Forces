#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> prefix(n + 1), suffix(n + 2);
        int distinct_prefix = 0, distinct_suffix = 0;

        for (int i = 1; i <= n; ++i) {
            prefix[i] = distinct_prefix;
            if (i > 1 && s[i - 1] != s[i - 2]) {
                ++distinct_prefix;
            }
        }

        for (int i = n; i >= 1; --i) {
            suffix[i] = distinct_suffix;
            if (i < n && s[i - 1] != s[i]) {
                ++distinct_suffix;
            }
        }

        long long ans = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'L') {
                ans = (ans * (prefix[i - 1] + 1)) % MOD;
            } else {
                ans = (ans * (suffix[i + 1] + 1)) % MOD;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
