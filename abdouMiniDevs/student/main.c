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
void accept_stuedent( struct student students){
    struct student studentLocal;
    int i = 0;
    printf("Enter u student name\n");
    fgets(studentLocal.name,sizeof(studentLocal.name),stdin);
    studentLocal.name[strcspn(studentLocal.name,"\n")] = '\0';
    printf("Enter u student major\n");
    fgets(studentLocal.major,sizeof(studentLocal.major),stdin);
    studentLocal.major[strcspn(studentLocal.major,"\n")] = '\0';
        do
    {
        printf("Enter u student age\n");
        scanf("%d",&studentLocal.age);
        getchar();
    } while (studentLocal.age <= 16 ||studentLocal.age >= 80);
    students.age = studentLocal.age;
    strcpy(students.name,studentLocal.name);
    strcpy(students.major,studentLocal.major);
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
    accept_stuedent(students[iLaSt]);
}


// void sw(int fi_ind,int la_ind,struct student students[1000]){
//     char name[50], major[50], id[16];
//     int age;
//     for (int i = fi_ind ; i < la_ind ;i++){
//         strcpy(name,students[i+1].name);
//         strcpy(students[i+1].name,students[i].name);
//         strcpy(students[i].name,name);
//         strcpy(id,students[i+1].id);
//         strcmp(students[i+1].id,students[i].id);
//         strcmp(students[i].id,id);
//         strcmp(major,students[i+1].major);
//         strcmp(students[i+1].major,students[i].major);
//         strcmp(students[i].major,major);
//         age =students[i+1].age;
//         students[i+1].age = students[i].age;
//         students[i].age = age ;
//     }
// }

void swap(int fiInd,int laInd,struct student students[1000]){
struct student tempStudent;
for ( int i =fiInd ; i < fiInd ;i++){
    tempStudent = students[i];
    students[i] = students[i+1];
    students[i+1] = tempStudent;
}

}
// find student func
void delete_student(struct student students[1000]){
    int iLast , i =0;
    struct student studentLoc;
    accept_stuedent(studentLoc);
    find_last_student(&iLast,students);
    for ( ; i < iLast ;i++){
        if( studentLoc.age == students[i].age && strcmp(studentLoc.name,students[i].name) == 0) {
            break;
        }
    }
    swap(i,iLast,students);
    students[iLast-1].age = 0 ;
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
    struct student students[1000];
        for(int i = 0 ;i<19;i++){
        students[i]=(struct student){
            .age = 24,
            .name ="abderzz9",
            .major = "ing"
        };
    }
        add_student(students);
    for (int i = 0 ; i< 20 ; i++){
        printf("==============");
        displaying_students(students);
        printf("==============");
    }
        for(int i = 20 ;i<25;i++){
        students[i]=(struct student){
            .age = 24,
            .name ="abderzz9",
            .major = "ing"
        };
    }
    delete_student(students);
    displaying_students(students);
}