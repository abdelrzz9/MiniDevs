#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("    || ROCK PAPER SCISSORS ||    \n");
    printf("           ----MENU----\n");
    printf("\n1. NUMERIC INPUT\n");
    printf("2. CHARACTER INPUT\n");
    printf("3. QUIT\n");

    int menu;
    scanf("%d", menu);
    if( menu == 1){
        
    }else if (menu == 2){

    }else if (menu == 3){
        exit(1);
    }else {
        printf("Invalid input\n");
    }
    return 0;
}