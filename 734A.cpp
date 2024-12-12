#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>> a;
    char str[a-1];

    for(int i = 0; i<a; i++)
    {

        cin>> str[i];
    }
    int count_a= 0;
    int count_d = 0;

    for(int i = 0; i<a; i++)
    {


    if(str[i] == 'A')
        count_a++;





    if(str[i] == 'D')
        count_d++;



    }

    if(count_a== count_d){
        cout<< "Friendship";
    }
    else if(count_a> count_d){
        cout<< "Anton";
    }
    else{
        cout<< "Danik";
    }



}
