#ifndef OPENGL__H
#define OPENGL__H

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#include "a_modifier.h"

#define  GLUT_WHEEL_MOUSE_UP                0x0003
#define  GLUT_WHEEL_MOUSE_DOWN              0x0004
#define  GLUT_CENTER_BUTTON                 0x0001

#define  TAILLE_X                           800
#define  TAILLE_Y                           600

#define  COIN_HAUT_GAUCHE_X                 100
#define  COIN_HAUT_GAUCHE_Y                 100

void creation_fenetre(int posX, int posY, int tailleX, int tailleY);
void lancer_application();
void effacer();
void texte(int x, int y, char *string);

#endif
