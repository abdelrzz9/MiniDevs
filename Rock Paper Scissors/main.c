#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>



int getComputerChoice(bool num, char *RPS) {

    int choice = (rand() % 3) + 1;

    if (num) {
        return choice;
    }

    if (choice == 1){
        strcpy(RPS, "Rock");
    }
    else if (choice == 2){
        strcpy(RPS, "Paper");
    } 
    else{
        strcpy(RPS, "Scissors");
    } 
    return 0;
}

int getHumanChoice(bool num, char *RPS) {

    if (num) {
        int input;
        do {
            printf("--> Please Choose: 1 = ROCK, 2 = PAPER, 3 = SCISSORS\n");
            printf("please enter your choice !\n");
            scanf("%d", &input);
        } while (input < 1 || input > 3);

        return input;
    }

    char input[20];

    while (1) {
        printf("Please Enter Your Choice !\n");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        for (int i = 0; input[i]; i++)
            input[i] = tolower(input[i]);

        input[0] = toupper(input[0]);

        if (strcmp(input, "Rock") == 0||
            strcmp(input, "Paper") == 0||
            strcmp(input, "Scissors")== 0) {

            strcpy(RPS, input);
            return 0;
        }

        printf("Invalid Input!\n");
    }
}

void getRoundNumber(int *rounds){
  
    do{
        printf("--> Please enter number of rounds:\n");
        scanf("%d", rounds);

        getchar();

    }while (*rounds < 1);

}

int PlayRound(bool num) {

    if (num) {
        int computerChoice = getComputerChoice(num, NULL);
        int humanChoice = getHumanChoice(num, NULL);

        printf("You chose ");
        if (humanChoice == 1){printf("ROCK\n");} 
        else if (humanChoice == 2){printf("PAPER\n");} 
        else {printf("SCISSORS\n");}

        printf("Computer chose ");
        if (computerChoice == 1){printf("ROCK\n");} 
        else if (computerChoice == 2){ printf("PAPER\n");}
        else {printf("SCISSORS\n");}

        if (humanChoice == computerChoice){
            printf("It's a tie.\n");
            return 0;
        }
        if ((humanChoice == 1 && computerChoice == 3) ||
            (humanChoice == 2 && computerChoice == 1) ||
            (humanChoice == 3 && computerChoice == 2)){
            printf("you win this round.\n");
            return 1;
        }else{
            printf("You lose this round.\n");
            return -1;
        } 
    }

    char human[20], computer[20];

    getComputerChoice(false, computer);
    getHumanChoice(false, human);
    printf("Computer chose: %s\n", computer);
    if (strcmp(human, computer)== 0){
        printf("It's a tie.\n");
        return 0;
    }
    if ((strcmp(human, "Rock") == 0 && strcmp(computer, "Scissors")== 0) ||
        (strcmp(human, "Paper") == 0 && strcmp(computer, "Rock")== 0) ||
        (strcmp(human, "Scissors") == 0 && strcmp(computer, "Paper")== 0))
        {
            printf("you win this round.\n");
            return 1;
    }else {
        printf("You lose this round.\n");
        return -1;
    }
    
}

void MultiRounds(bool num, int *rounds, int humanScore, int computerScore){
    
    getRoundNumber(rounds);
    for (int i = 1; i <= *rounds; i++)
    {
        printf("\n --- ROUND %d --- \n", i);
        int result = PlayRound(num);
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

int main() {

    printf("    || ROCK PAPER SCISSORS ||    \n");
    printf("           ----MENU----\n");
    printf("       1. NUMERIC INPUT\n");
    printf("       2. CHARACTER INPUT\n");
    printf("       3. QUIT\n");

    srand(time(NULL));

    int menu;
    bool num;
    int rounds;
    int humanScore = 0;
    int computerScore = 0;

    printf("\nEnter your choice: ");
    scanf("%d", &menu);
    getchar(); 

    if (menu == 1) {
        num = true;
    }
    else if (menu == 2) {
        num = false;
    }
    else if (menu == 3) {
        exit(0);
    }
    else {
        printf("Invalid input\n");
        return 0;
    }

    MultiRounds(num, &rounds, humanScore, computerScore);

    return 0;
}
