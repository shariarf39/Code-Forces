#include <iostream>
#include <vector>
using namespace std;

// Helper function to count numbers divisible by x in [l, r]
long long count_divisible(long long l, long long r, long long x) {
    return r / x - (l - 1) / x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    // All one-digit primes
    vector<int> small_primes = {2, 3, 5, 7};

    while (t--) {
        long long l, r;
        cin >> l >> r;

        // Total numbers in [l, r]
        long long total = r - l + 1;

        // Inclusion-Exclusion Principle for numbers with only small primes
        long long bad = 0;
        int n = small_primes.size();
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long prod = 1;
            int bits = 0;
            bool overflow = false;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    ++bits;
                    if (prod > r / small_primes[i]) {
                        overflow = true;
                        break;
                    }
                    prod *= small_primes[i];
                }
            }
            if (overflow) continue;
            long long cnt = count_divisible(l, r, prod);
            if (bits % 2 == 1) bad += cnt;
            else bad -= cnt;
        }

        cout << total - bad << '\n';
    }
    return 0;
}