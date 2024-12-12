#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int min = 101, max = 0;
    int minIndex = 0, maxIndex = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i] <= min){
            min = a[i];
            minIndex = i;
        }
        if(a[i] > max){
            max = a[i];
            maxIndex = i;
        }
    }
    int ans = maxIndex + (n-1-minIndex);
    if(maxIndex > minIndex){
        ans--;
    }
    cout<<ans<<endl;
    return 0;
}