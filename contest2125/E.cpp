#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 2e5 + 5;

vector<int> fact(MAXN), inv_fact(MAXN);

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
    }
    inv_fact[MAXN - 1] = binpow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; --i) {
        inv_fact[i] = 1LL * inv_fact[i + 1] * (i + 1) % MOD;
    }
}

int comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return 1LL * fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

void solve() {
    int n, x;
    cin >> n >> x;

    if (n == 1) {
        cout << x % MOD << "\n";
        return;
    }

    if (n == 2) {
        if (x >= 2) {
            cout << 1LL * x * (x - 1) / 2 % MOD << "\n";
        } else {
            cout << "0\n";
        }
        return;
    }

    if (x >= 2 * n - 1) {
        cout << comb(x, n) << "\n";
    } else {
        cout << "0\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
