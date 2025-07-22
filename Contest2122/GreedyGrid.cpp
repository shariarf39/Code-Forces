#include <iostream>

/**
 * @brief Solves a single test case for the greedy path problem.
 *
 * The problem asks if an n x m grid can exist where no greedy path
 * has the maximum possible value among all down/right paths.
 *
 * Logic:
 * 1. If n = 1 or m = 1, the grid is a single row or column. There is only
 * one possible path from the top-left to the bottom-right. This single
 * path is therefore both the greedy path (as there are no choices to make)
 * and the path with the maximum value. In this case, a grid where the
 * greedy path is not optimal cannot exist. So, the answer is "NO".
 *
 * 2. If n >= 2 and m >= 2, we have at least a 2x2 grid. This allows for
 * choices between moving right and moving down. We can construct a grid
 * that acts as a "trap" for the greedy algorithm.
 *
 * Example Construction for n>=2, m>=2:
 * - Set a[1][2] > a[2][1]. For instance, a[1][2] = 2 and a[2][1] = 1.
 * This forces any greedy path to make its first move to the right.
 * - Make the rest of the path starting with the "right" move have very low
 * values (e.g., 0). The total value of any greedy path will be low.
 * - Place a very large value on the path that starts by moving "down"
 * (the non-greedy choice). For example, set a[n][1] to a large number.
 * - The path that starts by moving down will have a much higher total value
 * than any greedy path.
 *
 * Since such a grid can be constructed if and only if n >= 2 and m >= 2,
 * the answer is "YES" in this case.
 */
void solve() {
    int n, m;
    std::cin >> n >> m;

    // If the grid is a single row or a single column
    if (n == 1 || m == 1) {
        std::cout << "NO\n";
    } else { // If the grid has at least 2 rows and 2 columns
        std::cout << "YES\n";
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve();
    }

    return 0;
}
