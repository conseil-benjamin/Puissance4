#include <stdio.h>
#include <stdlib.h>

showBoard();
showWinner();
checkWinner();
playerMove();

char board [6][7];
int nbRangee;


int main(){

    int espaceRestant = 42;    /* équivaut au nombre de case vide 
                                  au départ du jeux. */
   while (espaceRestant != 0)
   {
    showBoard();
    espaceRestant --;
   }
   
}


showBoard(){
    printf("|%c   | %c  | %c  | %c  | %c  | %c  | %c  |", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6]);
    printf("\n|---|---|---|---|---|---|---|\n");
    printf("|%c   | %c  | %c  | %c  | %c  | %c  | %c  |", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6]);
    printf("\n|---|---|---|---|---|---|---|\n");
    printf("|%c   | %c  | %c  | %c  | %c  | %c  | %c  |", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6]);
    printf("\n|---|---|---|---|---|---|---|\n");
    printf("|%c   | %c  | %c  | %c  | %c  | %c  | %c  |", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6]);
    printf("\n|---|---|---|---|---|---|---|\n");
    printf("|%c   | %c  | %c  | %c  | %c  | %c  | %c  |", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5], board[4][6]);
    printf("\n|---|---|---|---|---|---|---|\n");
    printf("|%c   | %c  | %c  | %c  | %c  | %c  | %c  |", board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5], board[5][6]);
    printf("\n|---|---|---|---|---|---|---|\n");
   playerMove();
}

playerMove(){
    printf("Joueur 1 : Choisissez une rangée avec le curseur");
    scanf("%d", &nbRangee);


    printf("Joueur 2 : Choisissez une rangée avec le curseur");
    scanf("%d", &nbRangee);

}

checkWinner(){
    
}


showWinner(){

}