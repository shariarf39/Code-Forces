#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count = 1;
    int max = 1;
    int prev;
    cin>>prev;
    for (int i = 1; i < n; i++)
    {
        int a;
        cin>>a;
        if (a >= prev)
        {
            count++;
            if (count > max)
            {
                max = count;
            }
        }
        else
        {
            count = 1;
        }
        prev = a;
    }
    cout<<max<<endl;
}