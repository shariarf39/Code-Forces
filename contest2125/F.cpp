#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int m = s.size();
    int n;
    cin >> n;
    vector<pair<int, int>> lr(n);
    for (int i = 0; i < n; ++i) {
        cin >> lr[i].first >> lr[i].second;
    }

    string target = "docker";
    int len = target.size();
    vector<int> occurrences;
    for (int i = 0; i <= m - len; ) {
        bool match = true;
        for (int j = 0; j < len; ++j) {
            if (s[i + j] != target[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            occurrences.push_back(i);
            i += len; // non-overlapping
        } else {
            i++;
        }
    }
    int current_k = occurrences.size();

    // Collect candidate k's
    vector<int> candidates;
    for (auto &p : lr) {
        candidates.push_back(p.first);
        candidates.push_back(p.second);
        candidates.push_back(max(0, p.first - 1));
        candidates.push_back(p.first + 1);
        candidates.push_back(max(0, p.second - 1));
        candidates.push_back(p.second + 1);
    }
    candidates.push_back(current_k);
    candidates.push_back(0);
    if (current_k > 0) {
        candidates.push_back(current_k - 1);
        candidates.push_back(current_k + 1);
    }

    // Also consider the maximum possible k (m / 6)
    int max_possible = m / len;
    candidates.push_back(max_possible);
    candidates.push_back(max(0, max_possible - 1));
    if (max_possible > 0) {
        candidates.push_back(max_possible + 1);
    }

    // Remove duplicates and invalid candidates (negative)
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    vector<int> valid_candidates;
    for (int k : candidates) {
        if (k >= 0) {
            valid_candidates.push_back(k);
        }
    }

    // Find best_k among valid_candidates
    int best_k = 0;
    int max_attendees = 0;
    for (int k : valid_candidates) {
        int cnt = 0;
        for (auto &p : lr) {
            if (p.first <= k && k <= p.second) {
                cnt++;
            }
        }
        if (cnt > max_attendees) {
            max_attendees = cnt;
            best_k = k;
        } else if (cnt == max_attendees) {
            if (abs(k - current_k) < abs(best_k - current_k)) {
                best_k = k;
            }
        }
    }

    // Compute minimal changes
    int changes_needed = 0;
    if (current_k < best_k) {
        int needed = best_k - current_k;
        changes_needed = needed * 6;
        // Check if possible to have best_k dockers
        if (best_k > max_possible) {
            // Need to find next best k <= max_possible
            max_attendees = 0;
            best_k = 0;
            for (int k : valid_candidates) {
                if (k > max_possible) continue;
                int cnt = 0;
                for (auto &p : lr) {
                    if (p.first <= k && k <= p.second) {
                        cnt++;
                    }
                }
                if (cnt > max_attendees) {
                    max_attendees = cnt;
                    best_k = k;
                } else if (cnt == max_attendees) {
                    if (abs(k - current_k) < abs(best_k - current_k)) {
                        best_k = k;
                    }
                }
            }
            changes_needed = (best_k - current_k) * 6;
        }
    } else if (current_k > best_k) {
        changes_needed = current_k - best_k;
    }

    cout << changes_needed << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
