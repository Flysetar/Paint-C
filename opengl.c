#include "opengl.h"
#include "figure.h"
#include <string.h>

int premierAffichage=0;

void lancer_application()
{
  glutMainLoop();
}

void rafraichir()
{
  glutPostRedisplay();
}

void effacer(){
  glClear (GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

}

void texte(int x, int y, char *string)
{
	int len,i; // len donne la longueur de la chaîne de caractères

	glRasterPos2f(x,y); // Positionne le premier caractère de la chaîne
	len = (int) strlen(string); // Calcule la longueur de la chaîne
	for (i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15,string[i]); // Affiche chaque caractère de la chaîne
}


void display()
{
  if(premierAffichage==0){
    effacer();
    initialisation_fenetre();
    premierAffichage=1;
  }	
  affichage();
  
  glFlush();
  glutSwapBuffers();
}

void foncSouris(int button, int state, int x, int y)
{
  switch (button){
  case GLUT_LEFT_BUTTON :
    if (state==GLUT_UP) clic_gauche(x,y);
    break;
    
  case GLUT_RIGHT_BUTTON :
    if (state==GLUT_UP) clic_droit(x,y);
    break;
  }
}

void foncClavier(unsigned char key, int x, int y)
{
  clavier(key,x,y);
}

void attente()
{
  rafraichir();
}

void reshape (int w, int h)
{
  w=h=0;
  glViewport (0, 0, TAILLE_X, TAILLE_Y); 
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluOrtho2D(0,TAILLE_X,0,TAILLE_Y);
  glMatrixMode(GL_MODELVIEW);
  rafraichir();
  }


void creation_fenetre(int posX, int posY, int tailleX, int tailleY) 
{
  int var=0;
  glutInit(&var, NULL);
  /*glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB);*/
  glutInitDisplayMode (GLUT_RGB);
  glutInitWindowSize (tailleX, tailleY); 
  glutInitWindowPosition (posX, posY);
  glutCreateWindow ("Paintoo - Le nouveau Paint 2.0");
  
  glClearColor (0.15, 0.15, 0.15, 1.0);

  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutIdleFunc(attente);
  glutMouseFunc(foncSouris);
  glutKeyboardFunc(foncClavier);

  glClear (GL_COLOR_BUFFER_BIT);
}
