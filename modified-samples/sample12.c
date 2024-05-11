#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>

struct record {         //structure definition
    char name[50];
    int age;
    float wage;
};

int main(){ 
    FILE *fp, *tp;  //file declarations
    char key;

    struct record myfriend = {"John", 20, 200.50}; 
    char file[12];

    printf("Enter filename: ");
    gets(file);
    
    if((fp = fopen(file, "rb")) == NULL){ //open file for reading
        printf("Error: File '%s' does not exist.", file);
        exit(1);
    }

    if((tp = fopen("temp.dat", "wb")) == NULL){ //open temporary file for writing
        printf("Error creating temporary file.");
        fclose(fp);  
        exit(1);
    }

    fwrite(&myfriend, sizeof(struct record), 1, fp);
    fclose(fp);

    if((fp = fopen(file, "rb")) == NULL){ //open file for reading
        printf("Error");
        exit(1);
    }
    
    while (fread(&myfriend, sizeof(struct record), 1, fp) != 1){
        printf("name: %s\nage: %d\nwage: %.2f\n", myfriend.name, myfriend.age, myfriend.wage); //display values
        printf("edit(y/n) ");
    
        key = toupper(getch());
        if(key == 'Y'){
            printf("\nRe-enter name: ");
            scanf("%s", myfriend.name);
            printf("Re-enter age: ");
            scanf("%d", &myfriend.age);
            printf("Re-enter wage: ");
            scanf("%f", &myfriend.wage);
            fwrite(&myfriend, sizeof(struct record), 1, tp); 

        }
        else{
            break;
        }
        
    }

    // Closing the files
    fclose(fp); 
    fclose(tp);

    // Removing original file and renaming the temporary file
    remove(file);
    rename("temp.dat", "file");
    
    printf("\nFile '%s' updated successfully.\n", file);

    return 0;
}
