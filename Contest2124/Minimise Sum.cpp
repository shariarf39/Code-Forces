#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>

// Function to calculate power of a number, handling potential overflow
long long power(long long base, int exp) {
    long long res = 1;
    long long limit = 2e9; // A bit larger than 10^9 to be safe
    for (int i = 0; i < exp; ++i) {
        if (__builtin_mul_overflow(res, base, &res)) {
            return limit;
        }
        if (res > limit) {
            return limit;
        }
    }
    return res;
}

// Function to get prime factorization of a number
void get_prime_factorization(int n, std::map<int, int>& factors) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            factors[i] = count;
        }
    }
    if (n > 1) {
        factors[n] = 1;
    }
}

// DP to check if a given exponent 'y' for a prime is valid
bool is_valid_y(int y, const std::vector<int>& c) {
    int n = c.size();
    if (n == 0) return true;

    // dp[i][0] is true if a valid sequence exists up to index i, ending with a_i = c_i
    // dp[i][1] is true if a valid sequence exists up to index i, ending with a_i = c_i - y
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(2, false));

    // Base case for i = 0
    dp[0][0] = true;
    if (c[0] >= y) {
        dp[0][1] = true;
    }

    for (int i = 1; i < n; ++i) {
        // Calculate dp[i][0]
        bool possible_from_prev0 = dp[i - 1][0] && (c[i] >= c[i - 1]);
        bool possible_from_prev1 = dp[i - 1][1] && (c[i] >= c[i - 1] - y);
        dp[i][0] = possible_from_prev0 || possible_from_prev1;

        // Calculate dp[i][1]
        if (c[i] >= y) {
            possible_from_prev0 = dp[i - 1][0] && (c[i] - y >= c[i - 1]);
            possible_from_prev1 = dp[i - 1][1] && (c[i] - y >= c[i - 1] - y);
            dp[i][1] = possible_from_prev0 || possible_from_prev1;
        }
    }

    return dp[n - 1][0] || dp[n - 1][1];
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> b(n);
    std::map<int, std::vector<int>> prime_exponents;
    std::set<int> all_primes;

    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        int temp = b[i];
        for (int j = 2; j * j <= temp; ++j) {
            if (temp % j == 0) {
                all_primes.insert(j);
                while (temp % j == 0) {
                    temp /= j;
                }
            }
        }
        if (temp > 1) {
            all_primes.insert(temp);
        }
    }

    for (int p : all_primes) {
        prime_exponents[p].resize(n);
    }

    for (int i = 0; i < n; ++i) {
        int temp = b[i];
        for (int p : all_primes) {
            if (p * p > temp && temp > 1 && p != temp) continue;
            if (p > temp && temp > 1) continue;

            if (temp % p == 0) {
                int count = 0;
                while (temp % p == 0) {
                    count++;
                    temp /= p;
                }
                prime_exponents[p][i] = count;
            }
        }
         if (temp > 1) { // Remaining factor is a prime
            if(all_primes.count(temp)) {
               prime_exponents[temp][i] = 1;
            }
        }
    }

    long long ans_x = 1;
    for (int p : all_primes) {
        const auto& c = prime_exponents[p];
        int max_exp = 0;
        for(int val : c) max_exp = std::max(max_exp, val);

        for (int y = 0; y <= max_exp + 1; ++y) {
            if (is_valid_y(y, c)) {
                ans_x = ans_x * power(p, y);
                break;
            }
        }
    }

    std::cout << ans_x << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
