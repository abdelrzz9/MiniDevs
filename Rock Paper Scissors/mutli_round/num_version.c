#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int getComputerChoice(){

    int choice = (rand() % 3) + 1;
    return choice;
}

int getHumanChoice(){

    int input;

    do
    {
        printf("please enter your choice !\n");
        scanf("%d", &input);
        
    } while (input < 1 || input > 3);

    return input;
    
}

void getNumberofRounds(int *rounds){
    
    do{
        printf("--> Please enter number of rounds:\n");
        scanf("%d", rounds);

        getchar();

    }while (*rounds < 1);


} 

int playRound(){
    int computerChoice = getComputerChoice();
    int humanChoice = getHumanChoice();

    switch (humanChoice)
    {
        case 1: printf ("You chose ROCK !\n"); break;
        case 2: printf("You chose PAPER !\n"); break;
        case 3: printf("You chose SCISSORS !\n"); break;
    }
    switch (computerChoice)
    {
        case 1: printf ("Computer chose ROCK !\n"); break;
        case 2: printf("Computer chose PAPER !\n"); break;
        case 3: printf("Computer chose SCISSORS !\n"); break;
    }

    if (humanChoice == computerChoice){
        printf("Tie !!\n");
    }else if ((humanChoice == 1 && computerChoice == 3) ||
              (humanChoice == 2 && computerChoice == 1) || 
              (humanChoice == 3 && computerChoice == 2)){
        printf("You won this round.\n");
        return 1;
    }else {
        printf("You lose this round.\n");
        return-1;
    }
}

void MultiRounds(int *rounds, int humanScore, int computerScore){

    getNumberofRounds(rounds);
    for (int i = 0; i < *rounds; i++)
    {
        printf("\n --- ROUND %d --- \n", i);
        int result = playRound();
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
    printf("--> Please Choose: 1 = ROCK, 2 = PAPER, 3 = SCISSORS\n");

    int rounds;
    int humanScore = 0;
    int computerScore = 0;

    MultiRounds(&rounds, humanScore, computerScore);
    return 0;
}