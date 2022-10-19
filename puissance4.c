#include <stdio.h>
#include <stdlib.h>

showBoard();   // affiche le tableau de jeux
showWinner();  // affiche le gagnan (joueur 1 ou 2)
checkWinner(); // vérifie si un des deux joueurs à gagner 
playerMove();  // retient en mémoire le mouvement du joueur pour l'afficher sur le tableau

char Player1 = 'X';
char Player2 = 'O';

char board [7];
int nbRangee;
char winner = ' ';


int main(){

    int espaceRestant = 42;    /* équivaut au nombre de case vide 
                                  au départ du jeux. */
   while (espaceRestant != 0 && winner = ' ')
   {
    showBoard();
   }
   return EXIT_SUCCESS;
}


showBoard(){
    printf("    V \n");
    printf("|%c   | %c  | %c  | %c  | %c  | %c  | %c  |", board[0], board[0], board[0], board[0], board[0], board[0], board[0]);
    printf("\n|---|---|---|---|---|---|---|\n");
    printf("|%c   | %c  | %c  | %c  | %c  | %c  | %c  |", board[1], board[1], board[1], board[1], board[1], board[1], board[1]);
    printf("\n|---|---|---|---|---|---|---|\n");
    printf("|%c   | %c  | %c  | %c  | %c  | %c  | %c  |", board[2], board[2], board[2], board[2], board[2], board[2], board[2]);
    printf("\n|---|---|---|---|---|---|---|\n");
    printf("|%c   | %c  | %c  | %c  | %c  | %c  | %c  |", board[3], board[3], board[3], board[3], board[3], board[3], board[3]);
    printf("\n|---|---|---|---|---|---|---|\n");
    printf("|%c   | %c  | %c  | %c  | %c  | %c  | %c  |", board[4], board[4], board[4], board[4], board[4], board[4], board[4]);
    printf("\n|---|---|---|---|---|---|---|\n");
    printf("|%c   | %c  | %c  | %c  | %c  | %c  | %c  |", board[5], board[5], board[5], board[5], board[5], board[5], board[5]);
    printf("\n|---|---|---|---|---|---|---|\n");
   playerMove();
}

playerMove(){
    printf("Joueur 1 : Choisissez une rangée avec le curseur");
    scanf("%d", &nbRangee);

    board [nbRangee] = Player1;
    espaceRestant --;


    printf("Joueur 2 : Choisissez une rangée avec le curseur");
    scanf("%d", &nbRangee);

    board[nbRangee] = Player2;        
    espaceRestant --;

}

checkWinner(){
}


showWinner(){
}