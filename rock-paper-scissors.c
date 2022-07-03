#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <time.h>
#include<math.h>

int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int greater(char char1,char char2)
{
    //FOR ROCK,PAPER,SCISSORS-RETURNS 1 IF char1>char2 AND 0 OTHERWISE
    if(char1==char2)
    {
        return -1;
    }
    else if((char1=='R')&&(char2=='S'))
    {
        return 1;
    }
  
    else if((char1=='S')&&(char2=='R'))
    {
        return 0;
    }
    else if((char1=='R')&&(char2=='P'))
    {
        return 1;
    }
    else if((char1=='P')&&(char2=='R'))
    {
        return 0;
    }
}
int main()
{
    char Player[34];
    char playerchar, compchar;
    int playerscore=0,compscore = 0, temp;
    char dict[]= {'R', 'P', 'S'};
    printf("-------------------------------------------------\n");
    printf("-----WELCOME TO ROCK,PAPER,SCISSORS GAMME----\n");
    printf("-------------------------------------------------\n");
    printf("CHOOSE 1 FOR ROCK,2 FOR PAPER,3 FOR SCISSORS\n");
    printf("\nEnter the name of the player1:");
    scanf("%s", Player);
    getchar();
    for (int i = 0; i < 3; i++)
    {
        // PLAYER'S TURN AND TAKING THE INPUT
        printf("%s TURN'S\n", Player);
        printf("CHOOSE 1 FOR ROCK,2 FOR PAPER,3 FOR SCISSORS\n");
        scanf("%d", &temp);
        getchar();
        playerchar = dict[temp - 1];
        printf("%s CHOOSE %c\n",Player,playerchar);

        //GENERATE THE COMPUTER'S INPUT
        printf("\nCOMPUTER'S TURN'S:\n");
        printf("CHOOSE 1 FOR ROCK,2 FOR PAPER,3 FOR SCISSORS\n");
        temp=generateRandomNumber(3)+1;
        compchar = dict[temp - 1];
        printf("CPU CHOOSE %c\n",compchar);

        //COMPARING THE SCORE BETWEEN THE PLAYER AND CPU
        if(greater(compchar,playerchar)==1)
        {
            compscore +=1;
            printf("CPU GOT A POINT\n\n");
        }
        else if(greater(compchar,playerchar)==-1)
        {
            playerscore+=1;
            compscore+=1;
            printf("IT'S A DRAW!.BOTH GOT 1 POINT\n\n");
        }
        else
        {
             playerscore+=1;
            printf(" PLAYER %s GOT A POINT\n\n",Player);
        }
        printf("%s SCORE:%d\nCPU SCORE:%d\n\n",Player,playerscore,compscore);
    }
    printf(" -----------------\n");
    printf("|   Final Score   |\n");
    printf(" -----------------\n");
    printf("|  You | Computer |\n");
    printf("|------|----------|\n");
    printf("|   %d  |    %d     |\n", playerscore, compscore);
    printf(" -----------------\n\n");
    if(playerscore>compscore)
    {
        printf("PLAYER %s win the game\n",Player);
    }
    else if(playerscore<compscore)
    {
        printf("CPU  win the game\n");
    }
    else{
        printf("GAME ENDED WITH A DRAW\n");
    }
    
    return 0;
}
