#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mex(const vector<int>& friends) {
    vector<bool> present(friends.size() + 1, false);
    for (int f : friends) {
        if (f < present.size()) {
            present[f] = true;
        }
    }
    for (int i = 0; i < present.size(); ++i) {
        if (!present[i]) {
            return i;
        }
    }
    return present.size();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n, -1);
        a[x - 1] = 0;
        a[y - 1] = 1;

        for (int i = 0; i < n; ++i) {
            if (a[i] == -1) {
                vector<int> friends;
                friends.push_back(a[(i - 1 + n) % n]);
                friends.push_back(a[(i + 1) % n]);
                if (i == x - 1) {
                    friends.push_back(a[y - 1]);
                } else if (i == y - 1) {
                    friends.push_back(a[x - 1]);
                }
                a[i] = mex(friends);
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}