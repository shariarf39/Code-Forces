#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

/**
 * @brief Solves a single test case for the reachability problem.
 * * The core idea is to determine the possible range of distances from the starting
 * point after all n moves. Let the required distance be D.
 * * 1. Maximum Possible Distance: The furthest you can get from the start is if you
 * make all your moves in a single straight line. This distance is the sum of all `a_i`.
 * So, D <= sum(a_i).
 * * 2. Minimum Possible Distance: This is governed by a generalization of the triangle
 * inequality. To get as close as possible to the start, you should take your longest
 * move, `a_max`, in one direction, and then use all other moves to travel back
 * towards the start as much as possible. The sum of all other moves is `sum_rest = sum(a_i) - a_max`.
 * - If `a_max <= sum_rest`, it's possible to form a closed polygon, meaning you can
 * return to the starting point. The minimum distance is 0.
 * - If `a_max > sum_rest`, the closest you can get is `a_max - sum_rest`.
 * - Combining these, the minimum distance is `max(0, a_max - sum_rest)`.
 * * So, the target point is reachable if and only if the distance D is within the range
 * [min_possible_dist, max_possible_dist].
 * * To avoid floating-point precision issues with sqrt, we compare the squared distances instead.
 * D^2 must be in the range [min_possible_dist^2, max_possible_dist^2].
 */
void solve() {
    int n;
    std::cin >> n;
    long long px, py, qx, qy;
    std::cin >> px >> py >> qx >> qy;

    long long sum_a = 0;
    long long max_a = 0;
    for (int i = 0; i < n; ++i) {
        long long current_a;
        std::cin >> current_a;
        sum_a += current_a;
        if (current_a > max_a) {
            max_a = current_a;
        }
    }

    // Calculate the squared Euclidean distance to the target point.
    // Use long long to prevent overflow, as coordinates can be up to 10^7.
    long long dx = px - qx;
    long long dy = py - qy;
    long long dist_sq = dx * dx + dy * dy;

    // Calculate the squared upper bound of the reachable distance.
    // This is (sum of all a_i)^2.
    long long upper_bound_sq = sum_a * sum_a;

    // Calculate the squared lower bound of the reachable distance.
    long long sum_rest = sum_a - max_a;
    long long min_dist = 0;
    if (max_a > sum_rest) {
        min_dist = max_a - sum_rest;
    }
    long long lower_bound_sq = min_dist * min_dist;

    // Check if the required squared distance is within the possible range.
    if (dist_sq >= lower_bound_sq && dist_sq <= upper_bound_sq) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
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
