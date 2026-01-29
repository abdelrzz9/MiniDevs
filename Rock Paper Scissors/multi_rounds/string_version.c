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

void getNumberofRounds(int *rounds){
    
    do{
        printf("--> Please enter number of rounds:\n");
        scanf("%d", rounds);

        getchar();

    }while (*rounds < 1);


} 
    
int PlayRound(){

    char humanChoice[20];
    char computerChoice[20];
    getComputerChoice(computerChoice);
    getHumanChoice(humanChoice);
    printf("You chose: %s\n", humanChoice);
    printf("Computer chose: %s\n", computerChoice);

    if (strcmp(humanChoice, computerChoice) == 0) {
    printf("It's a tie.\n");
    }else if (
    (strcmp(humanChoice, "Rock") == 0 && strcmp(computerChoice, "Scissors") == 0) ||
    (strcmp(humanChoice, "Paper") == 0 && strcmp(computerChoice, "Rock") == 0) ||
    (strcmp(humanChoice, "Scissors") == 0 && strcmp(computerChoice, "Paper") == 0)
    ) {
        printf("you win this round.\n");
        return 1;
    }
    else {
        printf("You lose this round.\n");
        return -1;
    }


}

void MultiRounds(int *rounds, int humanScore, int computerScore){

    getNumberofRounds(rounds);
    for (int i = 1; i <= *rounds; i++)
    {
        printf("\n --- ROUND %d --- \n", i);
        int result = PlayRound();
        if ( result == 1){
            humanScore++;
        }else if ( result == -1){
            computerScore++;
        }
    }
    
    printf("\nFinal Score:\n");
    printf("You: %d | Computer: %d\n", humanScore, computerScore);

    if (humanScore > computerScore){
        printf("YOU WON THE GAME!\n");
    }else if (computerScore > humanScore){
        printf("COMPUTER WON THE GAME!\n");
    }else{
         printf("IT'S A TIE!\n");
    }
    
}

int main(){

    srand(time(NULL));
    printf("           ||ROCK PAPER SCISSORS||    \n");

    int rounds;
    int humanScore = 0;
    int computerScore = 0;

    MultiRounds(&rounds, humanScore, computerScore);

       
    return 0;

}