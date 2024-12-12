#include<iostream>
using namespace std;
int main(){

string s;
cin>>s;
int flag=0;

for(int i=0;i<s.length();i++){
    if(s[i]=='h' && flag==0){
       flag=1;
    }
    else if(s[i]=='e' && flag==1){
        flag=2;
    }
    else if(s[i]=='l' && flag==2){
        flag=3;
    }
    else if(s[i]=='l' && flag==3){
        flag=4;
    }
    else if(s[i]=='o' && flag==4){
        flag=5;
    }
}

if (flag==5)
{
    cout<<"YES";
}
else{
    cout<<"NO";
}



}