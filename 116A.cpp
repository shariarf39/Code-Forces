#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a,b;
    int max = 0;
    int current = 0;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        current = current - a + b;
        if(current > max){
            max = current;
        }
    }
    cout<<max;
}