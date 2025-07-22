#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[a[i]]++;
        }

        int maxClones = 0;
        for (auto &entry : freq) {
            maxClones = max(maxClones, entry.second);
        }

        cout << maxClones << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}