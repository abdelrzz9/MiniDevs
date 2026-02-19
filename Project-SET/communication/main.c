#include <stdio.h>

typedef struct
{
    //for future : int date;
    char message[50];
}Mail;

typedef struct 
{
    char first_name[20];
    char last_name[20];
    int phone_number;
    Mail mailbox[10];
}User;

int create_user(User users[100],int count)
{
    printf("First Name? ");
    scanf("%s",users[count].first_name);
    printf("Last Name? ");
    scanf("%s",users[count].last_name);
    printf("Phone Number? ");
    scanf("%d",&users[count].phone_number);

    printf("User Created!\n");

    return 1;
}

void find_user(User users[100],int count)
{
    
}

int main()
{
    printf("=================\n");
    printf("1.Create new user\n");
    printf("2.Leave a message\n");
    printf("3.Exit\n");

    User users[100];
    int count = 0;

    char choice;
    scanf("%c",&choice);
    if(choice == '1')
    {
        if(create_user(users,count))
        {
            count++;
        }
    }
} 