#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool is_difficult(const string& s) {
    return s.find("FFT") != string::npos || s.find("NTT") != string::npos;
}

string make_easy(string s) {
    // If not difficult, return as is
    if (!is_difficult(s)) return s;

    // Count all letters
    vector<int> cnt(26, 0);
    for (char c : s) cnt[c - 'A']++;

    // Try to avoid "FFT" and "NTT"
    // Place all 'F' first, then all 'N', then all 'T', then others
    string res;
    // Place all except F, N, T
    for (int i = 0; i < 26; ++i) {
        if (i == ('F'-'A') || i == ('N'-'A') || i == ('T'-'A')) continue;
        res += string(cnt[i], 'A'+i);
    }
    // Place all F, then N, then T
    res += string(cnt['F'-'A'], 'F');
    res += string(cnt['N'-'A'], 'N');
    res += string(cnt['T'-'A'], 'T');
    // This order avoids "FFT" and "NTT"
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << make_easy(s) << '\n';
    }
    return 0;
}