#include <iostream>
using namespace std;

// Function to check if the ball will reach a pocket
bool will_pot(int s, int dx, int dy, int x, int y) {
    // The ball moves at 45 degrees, so after some bounces, it will reach a corner if and only if
    // the number of bounces in x and y directions are equal.
    // The time to reach a wall in x: tx = (dx == 1 ? s - x : x)
    // The time to reach a wall in y: ty = (dy == 1 ? s - y : y)
    // After each bounce, the direction reverses, and the ball continues.
    // The ball is potted if after some t, (x + dx * t) % (2*s) == 0 or s, and same for y.

    // The ball will be potted if and only if (dx == dy and x == y) or (dx != dy and x + y == s)
    if (dx == dy) {
        return x == y;
    } else {
        return x + y == s;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int dx, dy, x, y;
            cin >> dx >> dy >> x >> y;
            if (will_pot(s, dx, dy, x, y)) {
                ++count;
            }
        }
        cout << count << '\n';
    }
    return 0;
}