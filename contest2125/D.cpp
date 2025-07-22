#include <iostream>
#include <vector>
#include <numeric>

/**
 * @brief This solution calculates the probability that every cell in a strip of
 * length m is covered by exactly one segment.
 *
 * The problem is solved using dynamic programming. The core idea is to transform
 * the probability calculation. The probability of any specific configuration C (a
 * subset of chosen segments) can be written as:
 * P(C) = (product_{j in C} v_j) * P_all_none
 * where v_j = p_j / (1-p_j) and P_all_none is the probability that no segments
 * are chosen at all.
 *
 * A configuration is valid if the chosen segments form an exact partition of [1, m].
 * The total probability is P_all_none * (sum over all valid partitions C of product_{j in C} v_j).
 *
 * We define a DP state V[i] = sum over all partitions C of [1,i] of (product_{j in C} v_j).
 * The recurrence for V[i] is:
 * V[i] = sum_{for all segments j ending at i} (v_j * V[l_j - 1])
 * where l_j is the start of segment j.
 *
 * The final answer is P_all_none * V[m].
 */

// Use long long for modular arithmetic
using ll = long long;

const int MOD = 998244353;

/**
 * @brief Computes (base^exp) % MOD using binary exponentiation.
 * @param base The base of the power.
 * @param exp The exponent.
 * @return The result of (base^exp) % MOD.
 */
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

/**
 * @brief Computes the modular multiplicative inverse of n modulo MOD.
 * @param n The number to find the inverse of.
 * @return The modular inverse of n.
 */
ll modInverse(ll n) {
    return power(n, MOD - 2);
}

/**
 * @brief Main logic to solve the problem for a single test case.
 */
void solve() {
    int n, m;
    std::cin >> n >> m;

    // Store segments grouped by their right endpoint.
    // Each pair is {left_endpoint, v_value}.
    std::vector<std::vector<std::pair<int, ll>>> segs_by_r(m + 1);
    ll p_all_none = 1;

    // Pre-calculate values for each segment
    for (int i = 0; i < n; ++i) {
        int l, r;
        ll p, q;
        std::cin >> l >> r >> p >> q;

        ll prob = (p * modInverse(q)) % MOD;
        ll nprob = (1 - prob + MOD) % MOD;
        ll v = (prob * modInverse(nprob)) % MOD;

        segs_by_r[r].push_back({l, v});
        p_all_none = (p_all_none * nprob) % MOD;
    }

    // DP state array
    std::vector<ll> V(m + 1, 0);
    V[0] = 1; // Base case: an empty range [1,0] has one partition (the empty set) with product 1.

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (auto const& seg : segs_by_r[i]) {
            int l = seg.first;
            ll v = seg.second;
            // A segment [l,i] contributes to V[i] based on the partitions of [1, l-1]
            if (l > 0) {
                ll term = (v * V[l - 1]) % MOD;
                V[i] = (V[i] + term) % MOD;
            }
        }
    }

    // Final result is P_all_none * V[m]
    ll result = (p_all_none * V[m]) % MOD;
    std::cout << result << std::endl;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // This problem has a single test case.
    solve();

    return 0;
}
