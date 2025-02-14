#include<iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    bool all_upper = true;
    for (int i = 1; i < n; ++i) {
        if (islower(s[i])) {
            all_upper = false;
            break;
        }
    }
    if (all_upper) {
        for (int i = 0; i < n; ++i) {
            if (isupper(s[i])) {
                s[i] = tolower(s[i]);
            } else {
                s[i] = toupper(s[i]);
            }
        }
    }
    cout << s << endl;
    return 0;
}