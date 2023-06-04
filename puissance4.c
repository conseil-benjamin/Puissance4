#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define NBLIG 6 // nombre de ligne de la grille de jeu 
#define NBCOL 7 // nombre de colognne de la grille de jeu 

const int BORDER_RIGHT = 6; // limite grille de jeu superieur
const int BORDER_LEFT = 0; // limite grille de jeu inferieur
const char PION_A = 'X'; // correspond au pion du joueur 1
const char PION_B = 'O'; // correspond au pion du joueur 2
const char VIDE = ' '; 
const char INCONNU = ' '; // contient le gagnant soit PION_A soit PION_B ou ' ' si égalité 
const int COLONNE_DEBUT = NBCOL/2; // permet de placer le pion au debut de chaque coup au milieu de la grille de jeu
const char PIONV = 'V'; // Curseur 
const char S = 's'; // Caractere validation coup


typedef char tab[NBLIG][NBCOL];


void initGrille(tab); // initialise la grille de jeu avec des espaces vides

void afficher(tab, int, char, char); // affiche la grille de jeu avec les pions joués

bool grillePleine(tab, int); // retourne true si la grille est pleine, donc égalité

void jouer(tab, int*, int*, char, int*); // permet de placer les pions sur la grille de jeu

int choisirColonne(tab, int, char); // permet au deux joueurs de pouvoir choisir leur colonne

int trouverLigne(tab, int ); // permet de vérifier si la ligne est pleine ou non

char estVainqueur(tab, int, int, char); // vérifie si il y a un vainqueur en vertical, horizontal ou diagonale

void finDePartie(char); // affiche le gagnant ou égalité 


int main()
{

    char vainqueur = INCONNU;
 	int ligne, colonne;
	tab grille; 
	
	int espaceRestant = 42; // var nombre de case restante jouable 
    
    initGrille(grille); 
    vainqueur = INCONNU; 
    afficher(grille, COLONNE_DEBUT, PIONV, PION_A);

   	while (vainqueur == INCONNU && grillePleine(grille, espaceRestant) == false) // tant qu'il y a aucun vainqueur ou que la grille n'est pas pleine on joue
   	{
		jouer(grille, &colonne, &ligne, PION_A, &espaceRestant);
		afficher(grille, COLONNE_DEBUT, PIONV, PION_A);
		if (estVainqueur(grille, ligne, colonne, PION_A) == true) // si estvainqueur retourne true, PION_A a gagner la partie
		{
			vainqueur = PION_A;
		}
		else if (grillePleine(grille, espaceRestant) == false)
		{
			jouer(grille, &colonne, &ligne, PION_B, &espaceRestant);
			afficher(grille, COLONNE_DEBUT, PIONV, PION_B);
			if (estVainqueur(grille, ligne, colonne, PION_B) == true) // si estVainqueur retourne true, PION_B a gagner la partie
			{
				vainqueur = PION_B;
			}
		}
   	}
    finDePartie(vainqueur);  // on affiche le gagnant ou égalité
    return 0;
}


void initGrille(tab grille){
	int i;
	int j;
	for (i = 0; i < NBLIG; i++)
	{
		for (j = 0; j < NBCOL; j++)
		{
			grille[i][j] = VIDE; // on remplit chaque case de la grille de jeu par des caracteres vide
		}
	}
}

void afficher(tab grille, int colonne, char pionV, char pion){
	system("clear");  // permet de nettoyer le terminal pour avoir un affichage propre
    int i;
	int j;
	printf(" ");
	for (int x = 0; x < NBCOL; x++)    // boucle qui sert a déplacer le curseur au dessus de la grille de jeu
	{
		if (x == colonne)
		{
			printf(" %c  ", pionV);
		}
		else
		{
			printf("    ");
		}
	}
	printf("\n");

	for (i = 0; i < NBLIG; i++)     // boucle qui affiche au fur et a mesure de la partie les pions joués
	{
		printf("+---+---+---+---+---+---+---+\n");
		printf("|");
		for (j = 0; j < NBCOL; j++) {	
			printf(" %c |", grille[i][j]);
		}
		if (i == 1)
		{
			printf("     Commandes de Jeu : ");
		}

		if (i == 2)  // sert a afficher les commandes sur le coté droit de la grille de jeu
		{
			printf("     q : Aller a gauche   d : Aller a droite   S : Valider coup");
		}
		
		if (i == 3){ // affiche a qui c'est de jouer sur le cote droit de la grille de jeu
			printf("     Tour du joueur : %c", pion);
		}
		printf("\n");
	}
	printf("+---+---+---+---+---+---+---+\n");
}

bool grillePleine(tab grille, int espaceRestant){
	bool pleine;

	if (espaceRestant !=0){ // si espaceRestant != 0, grille pas pleine donc on continue de jouer
		pleine = false;
	}
	else
	{
		pleine = true;
	}
	
	return pleine;
}

void jouer(tab grille, int *colonne1,int *ligne, char pion, int *espaceRestant){
	*colonne1 = choisirColonne(grille, COLONNE_DEBUT, pion);
	*ligne = trouverLigne(grille, *colonne1);

	while(*ligne == -1){   // tant que *ligne renvoie -1 on redemande au joueur de choisir une autre colonne
		afficher(grille , *colonne1, PIONV, pion);
		printf("Choisir une autre colonne : \n");
	    *colonne1 = choisirColonne(grille, COLONNE_DEBUT, pion);
		*ligne = trouverLigne(grille, *colonne1);
	}

	grille[*ligne][*colonne1] = pion;  // on place le pion grace a l'indice colonne et ligne que renvoie les fonctions choisirColone et trouverLigne
	*espaceRestant = *espaceRestant -1;;  // on enleve une case jouable de la grille de jeu
}

int choisirColonne(tab grille, int colonne, char pion){
	char move = '?'; 
	char chaine[10];  
	
	int col = colonne;

	while (move != S){
		scanf(" %s", chaine); // sert a ne recuperer que le premier caractere d'une chaine,
        move = chaine[0];     // donc soit le q, le d ou le s est de ne pas conserver le deuxieme caractere qui est la touche 'entree'
		if (move == 'd' || move =='D'){ // permet de se déplacer a droite
			col++;
			if (col > BORDER_RIGHT){ // si il sort de la limite supérieur de la grille
				col--; // on le ramene dans la grille en enlevant -1 a col
				afficher(grille, col, PIONV, pion);
				printf("\nDebordement sur le tableau de jeu\n");
			}
			else {
				afficher(grille, col, PIONV, pion);
			}
	    }
		else if (move == 'q' || move == 'Q'){ // permet de se déplacer a gauche
			col--;
			if (col < BORDER_LEFT)	{ // si il sort de la limite inférieur de la grille
				col++;  //  on le ramene dans la grille en rajoutant +1 a col
				afficher(grille, col, PIONV, pion);
				printf("Debordement sur le tableau de jeu");
			}
			else{
			   afficher(grille, col, PIONV, pion);
			}
		}
		else {
			afficher(grille, col, PIONV, pion);
			printf("Mauvaise touche de déplacement, réassayer : \n");
		}
	}
	return col; // quand le joueur appuie sur s on renvoie l'indice de la colonne
 }

int trouverLigne(tab grille, int colonne){
    int res = -1;  // resultat si aucune ligne n'est vide dans la colonne
	for (int j = NBLIG - 1; j >= 0; j--){
		if (grille[j][colonne] == VIDE && res == -1){ // si la ligne a l'indice j est vide on remplace res = -1 par res = j, donc l'indice de la ligne
			res = j;
		}
	}
	return res;  // on retourne l'indice de la ligne
}

char estVainqueur(tab grille, int ligne, int colonne, char pion){
	char vainqueur = false;
		for (int i = 0; i < NBLIG; i++) {
			for (int j = 0; j < NBCOL; j++) {
                // condition victoire verticale 
				if ((grille[5][j] == pion && grille[4][j] == pion && grille[3][j] == pion && grille[2][j] == pion) || (grille[3][j] == pion && grille[2][j] == pion && grille[1][j] == pion && grille[0][j] == pion) || (grille[4][j] == pion && grille[3][j] == pion && grille[2][j] == pion && grille[1][j] == pion)){
				 vainqueur = true;				
				}

                // condition victoire horizontale
				else if ((grille[i][0] == pion && grille[i][1] == pion && grille[i][2] == pion && grille[i][3] == pion) || (grille[i][3] == pion && grille[i][4] == pion && grille[i][5] == pion && grille[i][6] == pion) || (grille[i][2] == pion && grille[i][3] == pion && grille[i][4] == pion && grille[i][5] == pion))  
				{
					vainqueur = true;
				}

				// condition victoire diagonale
				if ((grille[3][0] == pion && grille[2][1] == pion && grille[1][2] == pion && grille[0][3] == pion) || (grille[4][0] == pion && grille[3][1] == pion && grille[2][2] == pion && grille[1][3] == pion))
				{
					vainqueur = true;
				}
				else if ((grille[5][0] == pion && grille[4][1] == pion && grille[3][2] == pion && grille[2][3] == pion) || (grille[3][6] == pion && grille[2][5] == pion && grille[1][4] == pion && grille[0][3] == pion))
				{
					vainqueur = true;
				}
				else if ((grille[4][6] == pion && grille[3][5] == pion && grille[2][4] == pion && grille[1][3] == pion) || (grille[5][6] == pion && grille[4][5] == pion && grille[3][4] == pion && grille[2][3] == pion))
				{
					vainqueur = true;
				}
				else if ((grille[5][1] == pion && grille[4][2] == pion && grille[3][3] == pion && grille[2][4] == pion) || (grille[4][1] == pion && grille[3][2] == pion && grille[2][3] == pion && grille[1][4] == pion)){
					vainqueur = true;
				}
				else if ((grille[3][1] == pion && grille[2][2] == pion && grille[1][3] == pion && grille[0][3] == pion) || (grille[5][2] == pion && grille[4][3] == pion && grille[3][4] == pion && grille[2][5] == pion))
				{
					vainqueur = true;
				}
				else if ((grille[5][3] == pion && grille[4][4] == pion && grille[3][5] == pion && grille[2][6] == pion) || (grille[2][0] == pion && grille[3][1] == pion && grille[4][2] == pion && grille[5][3] == pion))
				{
					vainqueur = true;
				}
				else if ((grille[2][1] == pion && grille[3][2] == pion && grille[4][3] == pion && grille[5][4] == pion) || (grille[2][2] == pion && grille[3][3] == pion && grille[4][4] == pion && grille[5][5] == pion))
				{
					vainqueur = true;
				}
				else if ((grille[1][0] == pion && grille[2][1] == pion && grille[3][2] == pion && grille[4][3] == pion) || (grille[1][1] == pion && grille[2][2] == pion && grille[3][3] == pion && grille[4][4] == pion))
				{
					vainqueur = true;
				}
				else if ((grille[0][1] == pion && grille[1][2] == pion && grille[2][3] == pion && grille[3][4] == pion) || (grille[0][2] == pion && grille[1][3] == pion && grille[2][4] == pion && grille[3][5] == pion))
				{
					vainqueur = true;
				}
				else if ((grille[0][0] == pion && grille[1][1] == pion && grille[2][2] == pion && grille[3][3] == pion) || (grille[1][2] == pion && grille[2][3] == pion && grille[3][4] == pion && grille[4][5] == pion))
				{
					vainqueur = true;
				}
				else if (grille[4][3] == pion && grille[3][4] == pion && grille[2][5] == pion && grille[1][6] == pion)
				{
					vainqueur = true;
				}		
			}
		}
		return vainqueur; // retourne true si il y a un gagnant sinon false
	}


void finDePartie(char vainqueur){
	if(vainqueur == PION_A || vainqueur == PION_B){
		printf("Le vainqueur de la partie est : %c", vainqueur);
	}
	else{
		printf("Egalité !");
	}
}

