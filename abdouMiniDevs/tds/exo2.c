#include<stdio.h>
#include<string.h>
struct Date {
    int Day, Month, Year;
};
struct Address {
    int Number;
    char Street[50];
    char City[20];
    char Provinc[20];
    int Pc;
};
struct Resident
{
    char First_Name[20], Last_Name[20];
    struct Date Date_Birth;
    struct Address Residence;
};
void ReadInput(char* buffer,int size){
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}
void read_A(struct Address *a){
    printf("Number: ");
    scanf("%d",&a->Number);
    printf("Street: ");
    ReadInput(a->Street,50);
    getchar();
    printf("City: ");
    ReadInput(a->City,20);
    getchar();
    printf("Provinc: ");
    ReadInput(a->Provinc,20);
    getchar();
    printf("Pc: ");
    scanf("%d",&a->Pc);
}
void read_D(struct Date *a){
    printf("entre day : ");
    scanf("%d",&a->Day);
    printf("entre month : ");
    scanf("%d",&a->Month);
    printf("entre year : ");
    scanf("%d",&a->Year);
}
void read_R(struct Resident *a){
    printf("Entre first name");
    ReadInput(a->First_Name,20);
    getchar();
    printf("Enter last name");
    ReadInput(a->Last_Name,20);
    getchar();
    read_D(&a->Date_Birth);
    read_A(&a->Residence);
}

int main(){
    struct Resident residents[100];
    int n ;
    do
    {
        scanf("%d",&n);
    } while (n <= 0 || n > 100);
    for(int i =0 ; i < 2 ;i++){
        read_R(&residents[i]);
    }
}