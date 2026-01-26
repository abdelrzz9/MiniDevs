#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    char name[9];
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

void PlayRound()
{   while(1)
    {
        char humanChoice[10];
        char computerChoice[10];

        getComputerChoice(computerChoice);
        getHumanChoice(humanChoice);

        if (strcmp(humanChoice,computerChoice) == 0)
        {
            printf("It's a tie!\n");
            continue;
        }

        switch(humanChoice[0])
        {
            case 'R':
                if(computerChoice == "Paper")
                {
                    printf("You Lose!Paper Beats Rock!");
                }else{ printf("You Win!Rock Beats Scissors!");}
                break;
            case 'S':
                if(computerChoice == "Paper")
                {
                    printf("You Win!Scissors Beats Paper!");
                }else{ printf("You Lose!Rock Beats Scissors!");}
                break;
            case 'P':
                if(computerChoice == "Rock")
                {
                    printf("You Win!Paper Beats Rock!");
                }else{ printf("You Lose!Scissors Beats Paper!");}
                break;
        }
    }
}

int main()
{
    srand(time(NULL));
    printf("Start now!");
    PlayRound();
}