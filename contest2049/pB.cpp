#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isValidPermutation(const string& s, int n) {
    int pCount = 0, sCount = 0;

    // Traverse the string to check for conflicts
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'p') pCount = i + 1;  // First `i+1` elements must be valid
        if (s[i] == 's') sCount = i + 1;  // Last `n-i` elements must be valid

        if (pCount > 0 && sCount > 0 && pCount >= sCount) {
            return false;  // Conflict
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        if (isValidPermutation(s, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
