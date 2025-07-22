#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];

        ll g = b[0];
        for (int i = 1; i < n; ++i)
            g = __gcd(g, b[i]);

        ll x = 1;
        for (int i = 0; i < n; ++i) {
            if (b[i] % g == 0)
                x = lcm(x, b[i] / g);
        }

        cout << x << "\n";
    }

    return 0;
}
