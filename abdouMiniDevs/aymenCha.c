#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h> 
#include<stdbool.h>
    void getComCho(char *chcpCho){
        const char *name;
        int random = rand() % 3 +1;
        switch(random){
            case 1:
                name ="Paper";
            break;
            case 2:
                name ="Scissors";
            break;
            case 3:
                name ="Rock";
            break;
        }
        strcpy(chcpCho,name);
    }
    void getHumanCho(char *input){
        char name[9];
        while(1){
            printf("Enter ur chois \n");
            fgets(name,sizeof(name),stdin);
            int i =sizeof(name);
            printf("%d",i);
            for(int i = 1 ; name[i];i++){
                name[i] = tolower(name[i]);
            }
            name[0] = toupper(name[0]);
            if(strcmp(name,"Rock") == 1|| strcmp(name,"Paper") == 1 ||strcmp(name,"Scissors") == 1){
                strcpy(input,name);
                break;
            }else{
                printf("bro !!!\n");
            }
        }    
}
    void playRaond(){
        char humanChoice[9];
        char cmpChoice[9];
        bool humanWin = false;
        bool tel = false;
        getHumanCho(humanChoice);
        getComCho(cmpChoice);
        if (strcmp(humanChoice,cmpChoice) == 0){
            tel = true;
            printf("");
        }else{
            switch (humanChoice[1])
                {
                    case 'R':
                            if(cmpChoice[0] == 'P'){
                                printf("u lost paper wins");
                        }else{
                            humanWin = true;
                            printf("u win sissors lost");
                        }
                    break;
        
                    case 'S':
                            if(cmpChoice[0] == 'R'){
                                printf("u lost rock wins");
                            }else{
                                humanWin = true;
                                printf("u win paper lost");
                        }
                    break;
                    case 'P':
                            if(cmpChoice[0] == 'S'){
                                printf("u lost sissors wins");
                            }else{
                                humanWin = true;
                                printf("u win");
                            }
                    break;
                    default:
                    printf("error");
                    break;
                }
        }
}
    

    int main(){

}