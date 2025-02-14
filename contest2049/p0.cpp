#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int find_mex(const vector<int>& arr) {
    set<int> s(arr.begin(), arr.end());
    int mex = 0;
    while (s.find(mex) != s.end()) {
        ++mex;
    }
    return mex;
}

int min_operations(vector<int>& arr) {
    int n = arr.size();
    int mex = find_mex(arr);
    if (mex == 0) {
        return 0;
    }
    bool has_zero = find(arr.begin(), arr.end(), 0) != arr.end();
    return 1 + (has_zero ? 0 : 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << min_operations(arr) << endl;
    }
    return 0;
}