#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h> 
#include<stdbool.h>
struct student{
    char id[16] ;
    char name[50];
    int age ;
    char major[50];

};
// it works
void accept_stuedent(char *name , char *major , int *age){
    int iLaSt;
    char name_local[50];
    int age_local ;
    char major_local[50];
    int i = 0;
    printf("Enter u student name\n");
    fgets(name_local,sizeof(name_local),stdin);
    name_local[strcspn(name_local,"\n")] = '\0';
    printf("Enter u student major\n");
    fgets(major_local,sizeof(major_local),stdin);
    major_local[strcspn(major_local,"\n")] = '\0';
        do
    {
        printf("Enter u student age\n");
        scanf("%d",&age_local);
        getchar();
    } while (age_local <= 16 ||age_local >= 80);
    *age = age_local;
    strcpy(name,name_local);
    strcpy(major,major_local);
}
// it works
void  id_student(char *id){
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!@#$^&*qwertyuioplkjhgfdasxcvbnm";
    for(int i = 0;i<15;i++ ){
        id[i] = chars[rand() % (sizeof(chars)-1)];
    }
    id[15] = '\0';
    
} 
// it works
void find_last_student(int *index_void ,struct student students[1000] ){
    int i =0;
    while(i < 1000){
        if(students[i].age == 0){
            *index_void = i;
            break;
        }
        i++;
    }
}
// it work
void add_student(struct student students[1000]){
    int iLaSt;
    find_last_student(&iLaSt,students);
    accept_stuedent(students[iLaSt].name,students[iLaSt].major,&students[iLaSt].age);
}
void sw(struct student students[1000]){


}
// find student func
void delete_student(struct student students[1000]){
    int iLast ,age, i =0;
    char name[50];
    char major[50];
    accept_stuedent(name,major,&age);
    for ( ; i < iLast ;i++){
        if( name == students[i].name && age == students[i].age && major == students[i].major ){
            break;
        }
    }

}

// it work
void  displaying_students(struct student students[1000]){
    int iLaSt;
    find_last_student(&iLaSt,students);
        printf("====================\n");
    for(int i = 0 ; i < iLaSt ; i++){
        printf("student number : %d\n",i + 1);
        printf("%s\n",students[i].name);
        printf("%s\n",students[i].major);
        printf("%d\n",students[i].age);
        printf("%s\n",students[i].id);
        printf("====================\n");
    }
}



int main(){
    srand(time(NULL));


}