#include<stdio.h>
int main(){

    int num = 10;
    int *ptr = 6422036; 

    printf("Value of num: %d\n", num); 
    printf("Value pointed to by ptr: %d\n", ptr);
    printf("New value of num: %d\n", *ptr); 

    return 0;
}