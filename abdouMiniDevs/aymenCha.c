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
        char name[16];
        while(true){
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
    void playRaond(bool *input1 , bool *input2){
        char humanChoice[16];
        char cmpChoice[16];
        bool humanWin = false;
        bool Tie = false;
        getHumanCho(humanChoice);
        getComCho(cmpChoice);
        if (strcmp(humanChoice,cmpChoice) == 0){
            Tie = true;
            printf("tie\n");
        }else{
            switch (humanChoice[0])
                {
                    case 'R':
                            if(cmpChoice[0] == 'P'){
                                printf("computer choise is a paper u lost\n");
                        }else{
                            humanWin = true;
                            printf("u win cmputer choise ia a scissors\n");
                        }
                    break;
                    case 'S':
                            if(cmpChoice[0] == 'R'){
                                printf("u lost computer chois is a rock\n");
                            }else{
                                humanWin = true;
                                printf("u win computer choise is a paper \n");
                        }
                    break;
                    case 'P':
                            if(cmpChoice[0] == 'S'){
                                printf("u lost computer chois is a scissors\n");
                            }else{
                                humanWin = true;
                                printf("u win computer chois is a rock\n");
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
    void playGame(){
    int  humanConWin = 0;
    int  cmpConWin = 0;
    int i = 1;
    bool draw;
    bool humanWins;
    while (true )
        {
            printf("================\n");
            printf("u are in raond %d\n",i);
            printf("================\n");
            playRaond(&draw,&humanWins);
            if(draw){
                i++;
                continue;
            }else{
                if(humanWins){
                    humanConWin++;
                }else{
                    cmpConWin++;
                }
                
            }
            if(humanConWin == 3 ||cmpConWin ==3){
                break;
            }
            i++;
    }
}
    int main(){
        playGame();
}



