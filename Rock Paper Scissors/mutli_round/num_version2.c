#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void getComputerChoice(int choice){
    choice = rand() % 3 +1; 
}

void getHumanChoice(int input){
    do
    {
        printf("please enter your choice ");
        printf("Choose: 1 = Rock, 2 = Paper, 3 = Scissors\n");
        scanf("%d", input);
    } while (input > 1 || input <3);
    
}

void getNumberofRounds(){
    int rounds;
    
    printf("Enter Number of Rounds you want to Play !");
    scanf("%d", &rounds);
}

void playRound(){

}

