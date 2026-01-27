#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h> 
    void getComCho(char *chcpCho){
        const char *name;
        int random = rand() % 3 +1;
        switch(random){
            case 1:
                name ="paper";
            break;
            case 2:
                name ="scissors";
            break;
            case 3:
                name ="rock";
            break;
        }
        strcpy(chcpCho,name);
    }
    void getHumanCho(char *input){
        char name[9];
        // int test ;
        // printf("%d",(sizeof(name)/sizeof(name[1])));
        while(1){
            printf("Enter ur chois \n");
            fgets(name,sizeof(name),stdin);
            int i =sizeof(name);
            printf("%d",i);
            for(int i = 1 ; name[i];i++){
                name[i] = tolower(name[i]);
            }
            name[0] = toupper(name[0]);
            // printf("%s",name);
            // test = strcmp(name,"Rock");
            // printf("%d\n",test);
            if(strcmp(name,"Rock") == 1|| strcmp(name,"Paper") == 1 ||strcmp(name,"Scissors") == 1){
                strcpy(input,name);
                break;
            }else{
                printf("bro !!!\n");
            }
        }    
}
    void playRaond(){
        char compChois[9] ;
        char humanChois[9] ;
        getComCho(compChois);
        getHumanCho(humanChois);
        printf("%s",humanChois);
        printf("%s",compChois);
        
    }
    int main(){
        char name[9];
        // printf("Enter ur chois\n");
        // fgets(name,sizeof(name),stdin);
        // printf("%s",name);
        // int i = strcmp(name,"ahmde");
        // printf("%d",i);
        // // stcmp tcompaer sizeof name == 9 and sizeof ahmde == 4 ;
        // char name[9];
        // getHumanCho(name);
        // printf("%s",name);
        getHumanCho(name);
        printf("%d",name);
}