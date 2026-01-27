#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h> 
#include<stdbool.h>
    // it work
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
    // problam
    void getHumanCho(char *input){
        char name[9];
        while(1){
            printf("Enter ur chois \n");
            fgets(name,sizeof(name),stdin);
            name[strcspn(name,"\n")] = '\0';
            for(int i = 1 ; name[i];i++){
                name[i] = tolower(name[i]);
            }
            name[0] = toupper(name[0]);
            if(strcmp(name,"Rock") == 0|| strcmp(name,"Paper") == 0 ||strcmp(name,"Scissors") == 0){
                strcpy(input,name);
                break;
            }else{
                printf("bro !!!\n");
            }
        }    
}
    // it work 
    void playRaond(bool *input1 , bool *input2){
        char humanChoice[9];
        char cmpChoice[9];
        bool humanWin = false;
        bool Tie = false;
        getHumanCho(humanChoice);
        getComCho(cmpChoice);
        if (strcmp(humanChoice,cmpChoice) == 0){
            Tie = true;
            printf("tie !!!\n");
        }else{
            switch (humanChoice[0])
                {
                    case 'R':
                            if(cmpChoice[0] == 'P'){
                                printf("u lost paper wins\n");
                        }else{
                            humanWin = true;
                            printf("u win sissors lost\n");
                        }
                    break;
                    case 'S':
                            if(cmpChoice[0] == 'R'){
                                printf("u lost rock wins\n");
                            }else{
                                humanWin = true;
                                printf("u win paper lost\n");
                        }
                    break;
                    case 'P':
                            if(cmpChoice[0] == 'S'){
                                printf("u lost sissors wins\n");
                            }else{
                                humanWin = true;
                                printf("u win\n");
                            }
                    break;
                    default:
                    printf("error\n");
                    break;
                }
        }
        *input1 = Tie;
        *input2 = humanWin;
}


    int main(){
        bool human_isWin;
        bool draw;


        playRaond(&draw,&human_isWin);
}



