#include "opengl.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  creation_fenetre(COIN_HAUT_GAUCHE_X, COIN_HAUT_GAUCHE_Y, TAILLE_X, TAILLE_Y);
  //printf("Appuyez sur les touches du pavé numérique de 1 à 5 pour voir des points apparaître\n");
  //printf("Appuyez sur la touche 6 pour entrer les coordonnées d'un point à afficher\n");
  //printf("Appuyez sur la touche 7 pour reinitialiser la fenêtre\n");
  //printf("Appuyez sur la touche 8 pour tout effacer\n");
  //printf("Ou cliquez dans la fenêtre avec la souris\n");
  printf("\n__________________________________________\n");
  printf("\nBienvenue sur  Paintoo, le nouveau PAINT version 2.0\n");
  printf("\n################RACCOURCIS################\n");
  printf("1 : Rectangle\n");
  printf("2 : Droite\n");
  printf("3 : Cercle\n");
  printf("4 : Retour en arrière\n");
  printf("5 : Avancer\n");
  printf("6 : Faire apparaître une nouvelle feuille\n");
  printf("7 : Sauvegarder Liste dans le fichier Sauvegarde.c\n");
  printf("8 : Grossir le trait de la dernière figure\n");
  printf("Clic droit : Zoomer\n");
  lancer_application();

  return 0;
}
