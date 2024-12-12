#include<iostream>
using namespace std;
int main(){

int total, h;

cin>> total >> h;
 int man[total -1];
 int count = 0;

 for(int i = 0; i < total; i++){

    cin>> man[i];

    if(man[i]> h){
        count+=2;
    }
    else{
        count++;
    }
 }

 cout<< count;

}
