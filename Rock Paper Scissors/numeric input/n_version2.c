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

void playRound(){
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
        printf("YOU WON !!\n");
    }else {
        printf("COMPUTER WONS !!\n");
    }
}




int main(){

    srand(time(NULL));

    

    printf("           ||ROCK PAPER SCISSORS||    \n");
    printf("Please Choose: 1 = ROCK, 2 = PAPER, 3 = SCISSORS\n");
    playRound();

    return 0;
    
}