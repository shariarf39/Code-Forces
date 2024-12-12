#include<iostream>
using namespace std;
int main(){
    
    string s;
    string t;
    cin>>s>>t;
    int len = s.length();
    int len2 = t.length();
    if(len!=len2){
        cout<<"NO";
        return 0;
    }
    for(int i = 0; i<len; i++){
        if(s[i]!=t[len-i-1]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}