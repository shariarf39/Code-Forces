#include <iostream>
#include <numeric>      // For std::gcd in C++17, but we'll provide a fallback.
#include <algorithm>    // For std::max and std::swap
#include <utility>      // For std::swap

// Define long long for convenience with large numbers
using ll = long long;

/**
 * @brief Computes the greatest common divisor of two numbers using the Euclidean algorithm.
 *
 * This function is provided for compatibility with compilers that do not support
 * std::gcd from C++17.
 *
 * @param a The first number.
 * @param b The second number.
 * @return The greatest common divisor of a and b.
 */
ll custom_gcd(ll a, ll b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}


/**
 * @brief Solves a single test case for the robot movement problem.
 *
 * The function determines the minimum cost to move a robot from (a, b) to (0, 0).
 *
 * The logic is as follows:
 * 1. A cost of 1 is possible if and only if we can find a single move type (dx, dy)
 * that can be repeated some number of times to cover the total distance (a, b).
 * Any such move must have the same ratio as a:b. The smallest integer move
 * with this ratio is (a/gcd(a,b), b/gcd(a,b)).
 * If this smallest possible move is valid (i.e., both its components are <= k),
 * then the cost is 1.
 *
 * 2. If the smallest possible move is not valid (one of its components is > k),
 * then no single move type can solve the problem. The problem statement implies
 * a solution with two move types is always possible, so the cost is 2.
 */
void solve() {
    ll a, b, k;
    std::cin >> a >> b >> k;

    // Calculate the greatest common divisor of a and b using our custom function.
    ll common_divisor = custom_gcd(a, b);

    // Calculate the components of the required base move. This is the smallest
    // possible integer move (dx, dy) that maintains the a:b ratio.
    ll dx_base = a / common_divisor;
    ll dy_base = b / common_divisor;

    // The condition for a cost of 1 is that the largest component of this base
    // move does not exceed the limit k.
    if (std::max(dx_base, dy_base) <= k) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 2 << std::endl;
    }
}

/**
 * @brief Main function to handle multiple test cases.
 *
 * Sets up fast I/O and reads the number of test cases, then calls
 * solve() for each test case.
 */
int main() {
    // Fast I/O for performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
