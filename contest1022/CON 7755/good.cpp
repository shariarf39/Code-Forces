#include <iostream>

// This macro is used to check for GCC/Clang compilers to use their fast built-in functions.
#if defined(__GNUC__) || defined(__clang__)
#define HAS_BUILTIN
#endif

/**
 * @brief Solves a single test case for the problem.
 * * The logic is divided into three main cases based on the value of n.
 * 1. n is odd: The condition simplifies, and a simple greedy choice works.
 * 2. n = 2: A special case where no solution is possible.
 * 3. n is even and n >= 4: This requires a deeper analysis of the bitwise constraints.
 */
void solve() {
    long long n, l, r, k;
    std::cin >> n >> l >> r >> k;

    // Case 1: n is odd
    // The lexicographically smallest array is a = [l, l, ..., l].
    // For this array, the bitwise AND of all elements is `l`.
    // The bitwise XOR of all elements is also `l` because `x ^ x ^ ... ^ x` (odd times) is `x`.
    // So, AND = XOR = l. This is the smallest possible array as all elements are `l`.
    if (n % 2 != 0) {
        std::cout << l << std::endl;
        return;
    }

    // From this point, n is even.

    // Case 2: n = 2
    // The condition is a[1] & a[2] = a[1] ^ a[2].
    // Let's analyze this bit by bit. For any bit position:
    // - If bits are (0,1) or (1,0), AND is 0 and XOR is 1. Fails.
    // - If bits are (1,1), AND is 1 and XOR is 0. Fails.
    // The equality only holds if for every bit position, the bits of a[1] and a[2] are (0,0).
    // This implies a[1] = 0 and a[2] = 0. But the problem states l >= 1.
    // So, no solution exists for n = 2.
    if (n == 2) {
        std::cout << -1 << std::endl;
        return;
    }

    // Case 3: n is even and n >= 4
    // Let's analyze the condition A = X (AND = XOR) bit by bit.
    // For a bit `j`, let C_j be the count of numbers in `a` that have bit `j` set.
    // The j-th bit of A is 1 iff C_j = n.
    // The j-th bit of X is 1 iff C_j is odd.
    // Since n is even, it's impossible for C_j to be equal to n AND be odd.
    // So, for the j-th bits of A and X to be equal, they must both be 0. This requires:
    // 1. j-th bit of A is 0 => C_j < n.
    // 2. j-th bit of X is 0 => C_j is even.

    // The condition C_j < n for all j means that for any bit, there must be at least one
    // number in `a` that has this bit as 0. This implies it's impossible for all numbers
    // in the range [l, r] to have a common set bit.
    long long common_bits_in_range;
    if (l == r) {
        common_bits_in_range = l;
    } else {
        // Find the most significant bit where l and r differ.
        #ifdef HAS_BUILTIN
        int h = 63 - __builtin_clzll(l ^ r);
        #else
        // Fallback for compilers without the builtin.
        long long temp_xor = l ^ r;
        int h = 0;
        if (temp_xor > 0) {
            while ((1LL << (h + 1)) <= temp_xor && h < 62) {
                h++;
            }
        }
        #endif
        // Bits above h are common to all numbers in [l,r].
        // We create a mask to keep only bits above h and check if any are set in l.
        unsigned long long mask = ~((1ULL << (h + 1)) - 1);
        common_bits_in_range = l & mask;
    }

    if (common_bits_in_range > 0) {
        // There is at least one bit that is set for all numbers in the range [l, r].
        // For this bit j, any choice of a_i from [l,r] will result in C_j = n.
        // This violates the C_j < n condition. No solution.
        std::cout << -1 << std::endl;
        return;
    }

    // If the check passes, we construct the lexicographically smallest array.
    // A simple construction satisfying A=0, X=0 is using pairs of identical numbers.
    // To make the array smallest, we use `l` as much as possible.
    // Let's try an array with n-2 copies of `l` and 2 copies of some value `v`.
    // a = [l, l, ..., l, v, v].
    // For this to be a valid solution, we need:
    // 1. v is in [l, r].
    // 2. A = l & v = 0.
    // 3. X = 0 (guaranteed as all element counts are even).
    // We need to find the smallest `v >= l` such that `l & v = 0`.
    // This value will be the smallest power of 2 that is strictly greater than `l`.
    unsigned long long v_min = 1;
    if (l > 0) {
      while (v_min <= (unsigned long long)l) {
          v_min <<= 1;
      }
    }

    if (v_min > (unsigned long long)r) {
        // The smallest possible `v` is outside our range [l, r].
        // This construction fails. It can be shown that no other construction starting
        // with `l` works, and any other solution would be lexicographically larger.
        std::cout << -1 << std::endl;
    } else {
        // A solution exists: [l, l, ..., l, v_min, v_min]
        // We now just need to output the k-th element.
        if (k <= n - 2) {
            std::cout << l << std::endl;
        } else {
            std::cout << (long long)v_min << std::endl;
        }
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
