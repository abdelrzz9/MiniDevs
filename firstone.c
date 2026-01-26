#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
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
        while(1){
            fgets(name,sizeof(name),stdin);
            for(int i =1 ; name[i];i++){
                name[i] = tolower(name[i]);
            }
            name[0] = toupper(name[0]);
            if(strcmp(name,"Rock") == 0 || strcmp(name,"Paper")==0,strcmp(name,"Scissors")==0){
                strcpy(input,name);
            }else{
                printf("bro !!!\n");
            }
        }    
}
 void playRaond();