#include <stdio.h>
#include <stdlib.h>

char Player1 = 'X';
char Player2 = 'O';

char board [7][6];
int nbRangee;
char winner = ' ';
int espaceRestant = 42;

void showBoard();   // affiche le tableau de jeux
showWinner();  // affiche le gagnan (joueur 1 ou 2)
checkWinner(); // vérifie si un des deux joueurs à gagner 
playerMove();  // retient en mémoire le mouvement du joueur pour l'afficher sur le tableau

 /* équivaut au nombre de case vide 
                                  au départ du jeux. */


int main(){

   while (espaceRestant != 0 && winner == ' ')
   {
    showBoard();
   }
   return EXIT_SUCCESS;
}


void showBoard(){
     

    for (int i = 0; i < 6; i++)
    {
        printf("|%c   | %c  | %c  | %c  | %c  | %c  | %c  |", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4], board[i][5], board[i][6]);
        printf("\n|---|---|---|---|---|---|---|\n");
    }
    playerMove();
}

playerMove(){
    printf("Joueur 1 : Choisissez une rangée avec le curseur");
    scanf("%d", &nbRangee);

    board [nbRangee][nbRangee] = Player1;
    espaceRestant --;


    printf("Joueur 2 : Choisissez une rangée avec le curseur");
    scanf("%d", &nbRangee);

    board[nbRangee][nbRangee] = Player2;        
    espaceRestant --;

}

checkWinner(){
}


showWinner(){
}