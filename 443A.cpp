#include<iostream>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    int a[26] = {0};
    for(int i=0; i<s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            a[s[i]-'a'] = 1;
        }
    }
    int ans = 0;
    for(int i=0; i<26; i++){
        ans += a[i];
    }
    cout<<ans<<endl;
    return 0;
}