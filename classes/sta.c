#include<stdio.h>
#include<string.h>

struct Student{
    int id;
    char name[20];
    float gpa;
};

int main(){

    struct Student s1, s2;

    s1.id = 1;
    strcpy(s1.name, "John Doe");
    s1.gpa = 3.75;

    s2.id = 2;
    strcpy(s2.name, "Jane Smith");
    scanf("%f", &s2.gpa);
   

    printf("ID: %d\n", s1.id);
    printf("Name: %s\n", s1.name);  
    printf("GPA: %.2f\n", s1.gpa);

    printf("ID: %d\n", s2.id);
    printf("Name: %s\n", s2.name);  
    printf("GPA: %.2f\n", s2.gpa);




}