#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct 
{
    char move[10];
    char beats[10];
}Rule;


void getComputerChoice(char *input)
{
    char *name = "";
    //random choice from 1 to 3, 3 inclusive
    int choice = (rand() % 3) + 1;

    //Second Method using IF
    /*if(choice == 1)
    {
        name = "Paper";
    }else if(choice == 2)
    {
        name = "Rock";
    }else
    {
        name = "Scissors";
    }*/

    switch(choice)
    {
        case 1:
            name = "Paper";
            break;
        case 2:
            name = "Rock";
            break;
        case 3:
            name = "Scissors";
            break;
    }

    strcpy(input,name);
}

void getHumanChoice(char *input)
{
    char name[16];
    while(1)
    {
        //get user input
        printf("Enter your choice: ");
        fgets(name,sizeof(name),stdin);

        //lowercase each letter manually
        for(int i = 0;name[i];i++)
        {
            name[i] = tolower(name[i]);
        }

        //uppercase the first letter and remove newline
        name[0] = toupper(name[0]);
        name[strcspn(name,"\n")] = '\0';

        if (strcmp(name,"Rock") == 0 || strcmp(name,"Paper") == 0 || strcmp(name,"Scissors") == 0)
        {
            strcpy(input,name);
            break;
        }else
        {
            printf("Invalid Input!\n");
        }
     }
}

int PlayRound()
{          
    char humanChoice[16];
    char computerChoice[16];

    int humanWon;

    Rule rules[] =
    {
        {"Rock","Scissors"},{"Paper","Rock"},{"Scissors","Paper"}
    };
    
    while(1)
    {
        humanWon = 0;

        getComputerChoice(computerChoice);
        getHumanChoice(humanChoice);


        if (strcmp(humanChoice,computerChoice) == 0)
        {
            printf("It's a tie!\n");
            continue;
        }

        for (int i = 0; i <= 2;i++)
        {
            if(strcmp(rules[i].move,humanChoice) == 0 && strcmp(rules[i].beats,computerChoice) == 0)
            {
                humanWon++;
            }
        }

        if (humanWon)
        {
            printf("You won! %s beats %s!\n",humanChoice,computerChoice);
            return 1;
        }else
        {
            printf("You lose! %s beats %s!\n",computerChoice,humanChoice);
            return -1;
        }

        /*switch(humanChoice[0])
        {
            case 'R':
                if(strcmp(computerChoice,"Paper"))
                {
                    printf("You Lose!Paper Beats Rock!");
                }else{ printf("You Win!Rock Beats Scissors!");}
                break;
            case 'S':
                if(strcmp(computerChoice,"Paper"))
                {
                    printf("You Win!Scissors Beats Paper!");
                }else{ printf("You Lose!Rock Beats Scissors!");}
                break;
            case 'P':
                if(strcmp(computerChoice,"Rock"))
                {
                    printf("You Win!Paper Beats Rock!");
                }else{ printf("You Lose!Scissors Beats Paper!");}
                break;
        }*/
    }
}

void playGame()
{
    int score = 0;
    for(int i = 1;i <=5;++i){
        PlayRound();
    }
    if (score > 0){
        printf("Human Won!");
    }else {
        printf("Human Lost!\n");
    }
}

int main()
{
    srand(time(NULL));
    playGame();
}