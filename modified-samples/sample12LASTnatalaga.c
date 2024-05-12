#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <process.h>
#include <ctype.h>

struct record //structure definition
{
    char name[50];
    int age;
    float wage;
};

int main() //begin main program
{
    FILE *fp, *tp; //file declaration
    char key;
    struct record myfriend; //structure declaration
    char file[12];
    int a;

    printf("Enter filename: ");
    gets(file);

    if ((fp = fopen(file, "rb")) == NULL) //opening a file for reading only
    {
        printf("Error\n");
        exit(1);
    }

    if ((tp = fopen("temp.dat", "wb")) == NULL) //opening a file for writing only
    {
        printf("Error\n");
        exit(1);
    }

    while (fread(&myfriend, sizeof(struct record), 1, fp) != 0) //reading a file
    {
        printf("Name: %s\nAge: %d\nWage: %.2f\n", myfriend.name, myfriend.age, myfriend.wage); //display values
        printf("Edit? (y/n): ");
        key = toupper(getch());

        if (key == 'Y')
        {
            printf("\nRe-enter name: ");
            scanf("%s", myfriend.name);
            printf("Re-enter age: ");
            scanf("%d", &myfriend.age);
            printf("Re-enter wage: ");
            scanf("%f", &myfriend.wage);
        }
        fwrite(&myfriend, sizeof(struct record), 1, tp);
    }

    fclose(fp); //closing the file
    fclose(tp);
    remove(file);
    rename("temp.dat", file);

    if ((fp = fopen(file, "rb")) == NULL) //opening a file for reading only
    {
        printf("Error\n");
        exit(1);
    }

    printf("\n\nNew file\n\n");

    while (fread(&myfriend, sizeof(struct record), 1, fp) != 0)
    {
        printf("Name: %s\nAge: %d\nWage: %.2f\n", myfriend.name, myfriend.age, myfriend.wage);
    }
    // last na to mami

    fclose(fp);
    getch();
    return 0;
}
