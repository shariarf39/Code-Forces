#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> permutation(n + 1);
        for (int i = 1; i <= n; ++i) {
            permutation[i] = i;
        }

        // Sort the permutation in descending order
        sort(permutation.begin() + 1, permutation.end(), greater<int>());

        // Assign numbers to blocks
        int block_size = k;
        int block_start = 1;
        while (block_start <= n) {
            // Assign numbers to the current block
            for (int i = block_start; i <= min(block_start + block_size - 1, n); ++i) {
                cout << permutation[i] << " ";
            }
            block_start += block_size;
        }
        cout << endl; // Print a newline after each test case
    }

    return 0;
}
