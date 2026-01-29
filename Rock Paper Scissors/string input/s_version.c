#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void getComputerChoice(char *RPS)
{
    int choice = (rand() % 3) + 1;  

    if (choice == 1){
         strcpy(RPS, "Rock");
    }else if (choice == 2){
        strcpy(RPS, "Paper");
    } else{
        strcpy(RPS, "Scissors");
    }
}

void getHumanChoice(char *RPS){

    char input[20];

    while(1){

        printf("Please Enter Your Choise !\n");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input,"\n")] = '\0';

        for (int i = 0; input[i] ; i++)
        {
            input[i] = tolower(input[i]);
        }
        input[0] = toupper(input[0]);
        

        if (strcmp(input,"Rock") == 0|| strcmp(input,"Paper") == 0|| strcmp(input,"Scissors") == 0)
        {
            strcpy(RPS,input);
            //printf("%s", RPS);
            break;
        }else
        {
            printf("Invalid Input!\n");
        }
    }
}

void PlayRound(){

    char humanChoice[20];
    char computerChoice[20];

    getComputerChoice(computerChoice);
    getHumanChoice(humanChoice);
    printf("You chose: %s\n", humanChoice);
    printf("Computer chose: %s\n", computerChoice);

    if (strcmp(humanChoice, computerChoice) == 0) {
        printf("It's a TIE!!\n");
    }else if (
    (strcmp(humanChoice, "Rock") == 0 && strcmp(computerChoice, "Scissors") == 0) ||
    (strcmp(humanChoice, "Paper") == 0 && strcmp(computerChoice, "Rock") == 0) ||
    (strcmp(humanChoice, "Scissors") == 0 && strcmp(computerChoice, "Paper") == 0)
    ) {
        printf("You WIN!!! \n");
    }
    else {
        printf("You LOSE \n");
    }


}



int main(){


    srand(time(NULL));
    printf("           ||ROCK PAPER SCISSORS||    \n");
    PlayRound();
    return 0;

}