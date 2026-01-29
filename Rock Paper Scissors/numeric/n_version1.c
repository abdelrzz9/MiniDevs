#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void getComputerChoice(int *input){

    *input = (rand() % 3) + 1; 

}

void getHumanChoice(int *input){
      
    do
    {
        printf("Please enter your choice. ^^\n");
        printf("Choose: 1 = Rock, 2 = Paper, 3 = Scissors\n");
        scanf("%d", input);  
    } while (*input < 1 || *input > 3);
    

}

void PlayRound(int human, int computer){

   if (human == computer){
    printf("TIE!!\n");
   }else if (
    (human == 2 && computer == 1) ||
    (human == 1 && computer == 3) ||
    (human == 3 && computer == 2)
   ){
    printf("YOU WIN !!! \n");
   }else{
    printf("Computer WINS !!! \n");
   }

}


int main(){

    srand(time(NULL));

    int humanChoice;
    int computerChoice;

    getHumanChoice(&humanChoice);
    getComputerChoice(&computerChoice);

    printf("YOU chose: %d\n", humanChoice);
    printf("Computer chose: %d\n", computerChoice);


    PlayRound(humanChoice, computerChoice);

    return 0;

}