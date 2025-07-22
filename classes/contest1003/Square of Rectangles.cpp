#include <iostream>
#include <algorithm>
using namespace std;

bool can_form_square(int l1, int b1, int l2, int b2, int l3, int b3) {
    // All rectangles must be aligned, no rotation allowed

    // Try to align all rectangles along one side
    // Case 1: All rectangles have the same length
    if (l1 == l2 && l2 == l3) {
        if (b1 + b2 + b3 == l1) return true;
    }
    // Case 2: All rectangles have the same breadth
    if (b1 == b2 && b2 == b3) {
        if (l1 + l2 + l3 == b1) return true;
    }

    // Case 3: Two rectangles have the same length, third is different
    // Try to put two rectangles side by side, third on top
    if (l1 == l2 && b1 + b2 == l1 && l3 == l1 && b3 == l1 - b1) return true;
    if (l1 == l2 && b1 + b2 == l1 && l3 == l1 && b3 == l1 - b2) return true;

    // Try to put two rectangles on top of each other, third beside
    if (b1 == b2 && l1 + l2 == b1 && b3 == b1 && l3 == b1 - l1) return true;
    if (b1 == b2 && l1 + l2 == b1 && b3 == b1 && l3 == b1 - l2) return true;

    // Try to put the largest rectangle and stack the other two beside it
    int side = max(l1, b1);
    if ((l1 == side && l2 + l3 == side && b2 == b3 && b2 + b1 == side) ||
        (b1 == side && b2 + b3 == side && l2 == l3 && l2 + l1 == side)) {
        return true;
    }

    // Try all possible arrangements
    // Place the largest rectangle, and the other two in the remaining space
    int S = max(l1, b1);
    if ((l1 == S && l2 + l3 == S && b2 == b3 && b2 + b1 == S) ||
        (b1 == S && b2 + b3 == S && l2 == l3 && l2 + l1 == S)) {
        return true;
    }

    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        if (can_form_square(l1, b1, l2, b2, l3, b3))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}