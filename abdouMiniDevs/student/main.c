#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h> 
#include<stdbool.h>
struct student{
    double id ;
    char name[50];
    int age ;
    char major[50];

};
// last student func it work
void find_last_student(int *index_of_last_student ,struct student students[1000] ){
    int i =0;
    while(i < 1000){
        if(students[i].age == 0){
            *index_of_last_student = i;
            break;
        }
        i++;
    }
}


void add_student(int *age , char *name ,char *major){
    char name_local[50];
    char mjor_local[50];
    int age_local;
    printf("Enter u student name\n");
    fgets(name_local,sizeof(name_local),stdin);
    name_local[strcspn(name_local,"\n")] = '\0';
    printf("Enter u student major\n");
    fgets(mjor_local,sizeof(mjor_local),stdin);
    mjor_local[strcspn(mjor_local,"\n")] = '\0';
    strcpy(name,name_local);
    strcpy(major,mjor_local);
    printf("Enter u student age\n");
    scanf("%d",&age_local);
    getchar();
    *age = age_local;
}

// find student func
void delete_student(){

}












int main(){
    struct student students[1000]; 
    int last_index = 0; 
    for(int i = 0 ;i<19;i++){
        students[i]=(struct student){
            .age = 24,
            .name ="abderzz9",
            .major = "ing"
        };
    }
    for(int i = 0 ; i < 19 ;i++){
        printf("%s\n",students[i].name);
        printf("%s\n",students[i].major);
        printf("%d\n",students[i].age);
    }
    printf("=====================\n");
    printf("%d\n",students[19].age);
    printf("=====================\n");
    find_last_student(&last_index, students);
    printf("%d",last_index);
}