#include<stdio.h>
#include<conio.h>
#include<process.h>

struct record {  //structure definition 
char name[50];
int age;
float wage;
};

void main() { //begin main program
    FILE *fp; //file declaration
    
    struct record myfriend; //structure declaration
    char file[12];
    int a;

    printf("Enter filename: ");
    gets(file);
    fp = fopen(file, "wb"); //opening a file for writing

if(fp == NULL) { //error trapping
    printf("Error creating file");
    exit(1);
}

for(a = 0; a < 3; a++) { //input record having 3 members
    printf("Enter name: ");
    scanf(" ");
    scanf("%s", &myfriend.name);
    printf("Enter age: ");
    scanf("%d", &myfriend.age);
    printf("Enter wage: ");
    scanf("%f", &myfriend.wage);
    fwrite(&myfriend, sizeof(struct record),1,fp); //writing the values to a file
}

fclose(fp); //closing the file
}