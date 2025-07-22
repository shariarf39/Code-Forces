#include <stdio.h>


int printSum(int a, int b);

int main() {
    int num1 = 5, num2 = 10;

   int add = printSum(num1, num2);
   printf("The sum of %d\n", add);

    return 0;
}


int printSum(int a, int b) {
    int sum = a + b;
   return sum;
   
}