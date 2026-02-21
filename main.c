#include <stdio.h>

typedef struct 
{
    int age,day,month,year;
}Student;

int main()
{
    Student students[100];

    for(int i = 0;i<=2;i++)
    {
        scanf("%d",&students[i].age);
        scanf("%d",&students[i].day);
        scanf("%d",&students[i].month);
        scanf("%d",&students[i].year);
    }
}