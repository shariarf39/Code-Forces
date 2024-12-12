#include<iostream>
using namespace std;

    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>
    #include <cctype>
    using namespace std;

    bool isForbidden(const string &w, const vector<string> &forbidden, int start, int end) {
        string sub = w.substr(start, end - start + 1);
        transform(sub.begin(), sub.end(), sub.begin(), ::tolower);
        for (const string &f : forbidden) {
            string lower_f = f;
            transform(lower_f.begin(), lower_f.end(), lower_f.begin(), ::tolower);
            if (sub == lower_f) {
                return true;
            }
        }
        return false;
    }

    int main() {
        int n;
        cin >> n;
        vector<string> forbidden(n);
        for (int i = 0; i < n; ++i) {
            cin >> forbidden[i];
        }
        string w;
        cin >> w;
        char letter;
        cin >> letter;

        int len = w.length();
        vector<bool> toReplace(len, false);

        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                if (isForbidden(w, forbidden, i, j)) {
                    fill(toReplace.begin() + i, toReplace.begin() + j + 1, true);
                }
            }
        }

        for (int i = 0; i < len; ++i) {
            if (toReplace[i]) {
                w[i] = isupper(w[i]) ? toupper(letter) : letter;
            }
        }

        cout << w << endl;
        return 0;
    }
