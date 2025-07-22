#include <iostream>
#include <vector>
#include <string>

/**
 * @brief Solves a single test case for the greedy path problem.
 *
 * The problem asks if it's possible to construct an n x m grid of non-negative
 * integers where no "greedy" path has the maximum possible value among all
 * valid down/right paths.
 *
 * A greedy path always moves from the current cell (i, j) to the neighbor
 * (i+1, j) or (i, j+1) that has the larger value.
 *
 * The key insight is about the number of available paths:
 *
 * 1.  If n = 1 or m = 1, the grid is just a single row or a single column.
 * In this case, there is only one possible path from the top-left cell (1, 1)
 * to the bottom-right cell (n, m). Since there's only one path, this path
 * is automatically both the greedy path (as there are no choices to make)
 * and the path with the maximum value. Therefore, it's impossible to
 * construct a grid where the greedy path is not the optimal one.
 * The answer must be "NO".
 *
 * 2.  If n >= 2 and m >= 2, the grid has at least two rows and two columns.
 * This means at the very first cell (1, 1), we have a choice: move right
 * to (1, 2) or move down to (2, 1). This allows us to construct a "trap"
 * for the greedy algorithm.
 *
 * Example Construction:
 * - Let's force the greedy path to go right. We can do this by setting the
 * value at (1, 2) to be much larger than the value at (2, 1).
 * For example, grid[1][2] = 100, grid[2][1] = 1.
 * - Now, we make the rest of the path starting with the "right" move have very
 * low values (e.g., 0 for all other cells on that path).
 * - We then make the path starting with the "down" move (the non-greedy choice)
 * have very high values. For example, we can put a large number at cell (2, 2)
 * or anywhere else on the path that starts by going down.
 * - By doing this, the total value of the non-greedy path can be made larger
 * than the total value of any greedy path.
 * - Since such a construction is always possible when n >= 2 and m >= 2,
 * the answer is "YES".
 */
void solve() {
    int n, m;
    std::cin >> n >> m;

    if (n > 1 && m > 1) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Use std::ios_base::sync_with_stdio(false) and std::cin.tie(NULL)
    // for faster input/output operations.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases.
    while (t--) {
        solve();
    }

    return 0;
}
