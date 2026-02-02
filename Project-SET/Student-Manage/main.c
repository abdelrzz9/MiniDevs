#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Student
{
    char id[16];
    char name[50];
    int age;
    char major[50];
};

struct Student students[200];
int studentCounter = 0;

void ReadInput(char* buffer,int size)
{
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void  id_student(char *id){
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!@#$^&*qwertyuioplkjhgfdasxcvbnm";
    for(int i = 0;i<15;i++ ){
        id[i] = chars[rand() % (sizeof(chars)-1)];
    }
    id[15] = '\0';
} 

void AddStudent()
{
    char buffer[50];
    
    id_student(students[studentCounter].id);

    printf("What is your name? ");
    ReadInput(students[studentCounter].name, sizeof(students[studentCounter].name));

    printf("How old are you? ");
    ReadInput(buffer, sizeof(buffer));
    students[studentCounter].age = atoi(buffer);

    printf("What is your major? ");
    ReadInput(students[studentCounter].major, sizeof(students[studentCounter].major));


    studentCounter++;
}

void DisplayStudent()
{
    if(studentCounter == 0)
    {
        printf("No Students Added yet!\n");
    }

    for(int i = 0; i < studentCounter;i++)
    {
        printf("Name: %s\nAge: %d\nMajor: %s\nID: %s\n\n",
            students[i].name,
            students[i].age,
            students[i].major,
            students[i].id);
    }
}

int FindStudent()
{
    char buffer[100];
    printf("Select Student ID? ");
    ReadInput(buffer,sizeof(buffer));

    for (int i = 0; i < studentCounter;i++)
    {
        if(strcmp(buffer,students[i].id) == 0)
        {
            return i;
        }
    }

    printf("No students with such name, returning index -1\n");
    return -1;
}

void DeleteStudent()
{
    int studentToDelete = FindStudent();

    if (studentToDelete == -1) return;

    for (int i = studentToDelete; i<studentCounter-1;i++)
    {
        students[i] = students[i+1];
    }

    printf("Student Deleted!\n");
    studentCounter--;
}

void EditStudent()
{
    int studentToEdit = FindStudent();
    char buffer[50];

    if (studentToEdit == -1) return;

    printf("Select New Name: ");
    ReadInput(students[studentToEdit].name, sizeof(students[studentToEdit].name));

    printf("Select New Age: ");
    ReadInput(buffer, sizeof(buffer));
    students[studentToEdit].age = atoi(buffer);

    printf("Select New Major: ");
    ReadInput(students[studentToEdit].major, sizeof(students[studentToEdit].major));
}

int main()
{
    srand(time(NULL));
    printf("============\n");
    printf("1.Add Student\n");
    printf("2.Display Students\n");
    printf("3.Delete A Student\n");
    printf("4.Edit A Student\n");
    printf("5.Exit\n");
    printf("=============\n");

    while(1)
    {
        char index[20];
        printf("Choose! ");
        ReadInput(index,sizeof(index));

        switch(index[0])
        {
            case '1':
                AddStudent();
                break;
            case '2':
                DisplayStudent();
                break;
            case '3':
                DeleteStudent();
                break;
            case '4':
                EditStudent();
                break;
            case '5':
                return 1;
            default:
                printf("ERROR : Invalid Input, try again!\n");
                break;
        }
    }
}