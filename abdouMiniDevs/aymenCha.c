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
    void playRound(bool *input1 , bool *input2){
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
                                printf("u lost Computer chose: %s\n", cmpChoice);
                        }else{
                            humanWin = true;
                            printf("u win Computer chose: %s\n", cmpChoice);
                        }
                    break;
                    case 'S':
                            if(cmpChoice[0] == 'R'){
                                printf("u lost Computer chose: %s\n", cmpChoice);
                            }else{
                                humanWin = true;
                                printf("u win Computer chose: %s\n", cmpChoice);
                        }
                    break;
                    case 'P':
                            if(cmpChoice[0] == 'S'){
                                printf("u lost Computer chose: %s\n", cmpChoice);
                            }else{
                                humanWin = true;
                                printf("u win Computer chose: %s\n", cmpChoice);
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
        while (true)
        {
            printf("Welcome to Rock Paper Scissors Game\n");
            printf("if you want to play again, press 'y' or 'Y'\n");
            char choise;
            scanf("%c",&choise);
            getchar();
            if(choise == 'y' || choise =='Y'){
                break;
            }else{
                printf("Goodbye!\n");
                exit(0);
            }
        }
        int  humanConWin = 0;
        int  cmpConWin = 0;
        int i = 1;
        int roundToWin;
        bool draw;
        bool humanWins;
        while (true)
        {
            printf("Enter the number of rounds to win: ");
            scanf("%d", &roundToWin);
            getchar();
            if (roundToWin > 0)
            {
                break;
            }
            printf("Please enter a valid number of rounds.\n");
        }
        
        
        while (true )
            {
                printf("================\n");
                printf("u are in Round %d\n",i);
                printf("================\n");
                playRound(&draw,&humanWins);
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
                if(humanConWin == roundToWin ||cmpConWin == roundToWin){
                    break;
                }
                i++;
        }
        printf("Final Score => You: %d | Computer: %d\n",
        humanConWin, cmpConWin);
}
    int main(){
        srand(time(NULL));
        playGame();
}