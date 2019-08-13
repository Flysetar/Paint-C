#include "figure.h"

void afficher_texte(int x, int y, char *string, double r, double v, double b){
  glColor4f(r,v,b,1.0);
  texte(x, y, string);
}

void afficher_point(int x, int y, double r, double v, double b)
{
  /* r, v et b sont trois reels entre 0 et 1 correspondant aux trois composantes rouge, vert et bleu de la couleur*/
  glColor4f(r,v,b,1.0);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}
