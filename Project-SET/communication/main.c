#include <stdio.h>
#include <string.h>

typedef struct
{
    //for future : int date;
    char message[50];
}Mail;

typedef struct
{
    char first_name[20];
    char last_name[20];
    long int phone_number;
    Mail mailbox[10];
}User;

int create_user(User users[100],int count)
{
    printf("First Name? ");
    scanf("%s",users[count].first_name);
    printf("Last Name? ");
    scanf("%s",users[count].last_name);
    printf("Phone Number? ");
    scanf("%ld",&users[count].phone_number);

    printf("User Created!\n");

    return 1;
}

void update_file(User users[100],int count)
{
    FILE *F;
    F = fopen("phone-numbers.txt","w");
    for(int i = 0; i < count;i++)
    {
        fprintf(F,"%s %s %ld\n",users[i].first_name,users[i].last_name,users[i].phone_number);
    }
    fclose(F);
}

void read_file(User users[100],int count)
{
    char line[50];
    char new_first_name[50];
    char new_last_name[50];
    char new_phone_numer[50];

    FILE *F;
    F = fopen("phone-numbers.txt","r");
    while(fgets(line,sizeof(line),F))
    {
        strcpy(new_first_name,strtok(" ",line));
        strcpy(new_first_name,strtok(NULL,line));
        printf("%s",line);
        printf("%s",new_first_name);
        printf("%s",new_last_name);
    }
    fclose(F);
}

int find_user(User users[100],int count)
{
    int buffer;
    printf("What is the phone numer? ");
    scanf("%d",&buffer);
    for(int i = 0; i < count; i++)
    {
        if(users[i].phone_number == buffer)
        {
            printf("Number Found!");
            return i;
        }
    }

    printf("Number Not found!");
    return 0;
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
            update_file(users,count);
        }

        if(create_user(users,count))
        {
            count++;
            update_file(users,count);
        }

        if(create_user(users,count))
        {
            count++;
            update_file(users,count);
        }

        read_file(users,count);
    }
} 