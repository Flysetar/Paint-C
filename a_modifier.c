#include "opengl.h"
#include "figure.h"
#include "a_modifier.h"
#include "list.h"

#define TAILLE_MAX 1000 // Tableau de taille 1000

char choix = -1;

int dernier_x = 0;
int avant_dernier_x = 0;
int dernier_y = 0;
int avant_dernier_y = 0;
int ancien_choix = 0;
int choix_red = 0;
int choix_green = 0;
int choix_blue = 0;
int echelle = 1;

// Procédure appelée lors de la création de la fenêtre
// que vous pouvez réappeler de nouveau pour réinitilisation.
// Utile si vous voulez créer un menu ou une interface graphique...

void initialisation_fenetre()
{
  effacer();

  dessiner_rect(0, 0, 80, 600, 1, 0, 0, 0);                  // Noir à gauche
  dessiner_rect(0, TAILLE_Y - 80, TAILLE_X, 80, 1, 0, 0, 0); // Noir en haut
  dessiner_rect(647, 537, 115, 48, 1, 100, 100, 100);        // Blanc en haut droite

  dessiner_rect(650, 540, 20, 20, 1, 100, 0, 0);   // Rouge
  dessiner_rect(650, 562, 20, 20, 1, 0, 0, 100);   // Bleu
  dessiner_rect(672, 540, 20, 20, 1, 0, 0, 0);     // Noir
  dessiner_rect(672, 562, 20, 20, 1, 0, 100, 0);   // Vert
  dessiner_rect(694, 562, 20, 20, 1, 100, 100, 0); // Jaune
  dessiner_rect(694, 540, 20, 20, 1, 100, 0, 100); // Violet

  dessiner_rect(718, 540, 42, 42, 1, 0, 0, 0); // Actuelle

  //Fleche gauche
  afficher_texte(3 + 20, 20, "<", 1, 1, 1);
  afficher_texte(3 + 22, 25, "_", 1, 1, 1);
  afficher_texte(3 + 25, 25, "_", 1, 1, 1);
  //Fleche gauche
  afficher_texte(3 + 15 + 32, 20, ">", 1, 1, 1);
  afficher_texte(3 + 15 + 28, 25, "_", 1, 1, 1);
  afficher_texte(3 + 15 + 31, 25, "_", 1, 1, 1);

  dessiner_rect(10, 450, 60, 40, 1, 100, 100, 100); // Bouton Rectangle plein
  dessiner_rect(10, 370, 60, 40, 0, 100, 100, 100); // Bouton Rectangle vide
  dessiner_cercle(40, 310, 25, 1, 100, 100, 100);   // Bouton Cercle plein
  dessiner_cercle(40, 225, 25, 0, 100, 100, 100);   // Bouton Cercle vide
  dessiner_cercle(40, 150, 3, 1, 100, 100, 100);    // Bouton Point
  afficher_texte(20, 100, "Texte", 1, 1, 1);        // Bouton Texte

  int i;

  for (i = 0; i < 30; i++)
  {
    dessiner_point(i + 25, 50 + i, 1, 1, 1);
  }

  dessiner_rect(95, 20, 685, 480, 1, 100, 100, 100); // Feuille Blanche

  afficher_texte(20, 600 - 30, "Retour : 4", 1, 1, 1);
  afficher_texte(20, 600 - 50, "Revenir : 5", 1, 1, 1);
}

// Cette procédure est appelée lorsqu'aucun
// événement clavier/souris n'est détecté
// donc quasiment en continu.
// C'est cette procédure qui doit gèrer l'affichage.
int ListeChainee = 1;
int ListeChainee2 = 1;
int appel = 0;
int i;
int j;

int calculer_distance(int xa, int ya, int xb, int yb)
{
  return (sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya)));
}

double calculer_coeffDir(int xa, int ya, int xb, int yb)
{
  double calcul = ((yb - ya) / (xb - xa));
  return calcul;
}

void dessiner_rect(int x_rect, int y_rect, int width_rect, int height_rect, int res, int r, int g, int b)
{
  for (i = 0; i < width_rect; i++)
  {
    afficher_point(x_rect + i, y_rect, r, g, b);
    afficher_point(x_rect + i, y_rect + 1, r, g, b);
    afficher_point(x_rect + 1 + i, y_rect, r, g, b);
    afficher_point(x_rect + 1 + i, y_rect + 1, r, g, b);
  }
  for (i = 0; i < width_rect + 1; i++)
  {
    afficher_point(x_rect + i, y_rect + height_rect, r, g, b);
    afficher_point(x_rect + i, y_rect + 1 + height_rect, r, g, b);
    afficher_point(x_rect + 1 + i, y_rect + height_rect, r, g, b);
    afficher_point(x_rect + 1 + i, y_rect + 1 + height_rect, r, g, b);
  }

  if (res == 1)
  {
    for (j = 0; j <= width_rect; j++)
    {
      for (i = 0; i < height_rect; i++)
      {
        afficher_point(x_rect + j, y_rect + i, r, g, b);
        afficher_point(x_rect + j, y_rect + 1 + i, r, g, b);
        afficher_point(x_rect + j + 1, y_rect + i, r, g, b);
        afficher_point(x_rect + j + 1, y_rect + 1 + i, r, g, b);
      }
    }
  }
  else
  {
    for (i = 0; i < height_rect; i++)
    {
      afficher_point(x_rect, y_rect + i, r, g, b);
      afficher_point(x_rect, y_rect + 1 + i, r, g, b);
      afficher_point(x_rect + 1, y_rect + i, r, g, b);
      afficher_point(x_rect + 1, y_rect + 1 + i, r, g, b);
    }
  }

  for (i = 0; i < height_rect; i++)
  {
    afficher_point(x_rect + width_rect, y_rect + i, r, g, b);
    afficher_point(x_rect + width_rect, y_rect + 1 + i, r, g, b);
    afficher_point(x_rect + 1 + width_rect, y_rect + i, r, g, b);
    afficher_point(x_rect + 1 + width_rect, y_rect + 1 + i, r, g, b);
  }
}

void dessiner_cercle(int x_centre, int y_centre, int rayon, int res, int r, int g, int b)
{
  if (res == 1)
  {
    res = 0;
  }
  else
  {
    res = rayon;
  }

  for (i = res; i <= rayon; i++)
  {
    int x = 0;
    int y = i;
    int m = 5 - 4 * i;
    while (x <= y)
    {
      afficher_point(x + x_centre, y + y_centre, r, g, b);
      afficher_point(x + x_centre, y + y_centre + 1, r, g, b);
      afficher_point(x + x_centre + 1, y + y_centre, r, g, b);
      afficher_point(x + x_centre + 1, y + y_centre + 1, r, g, b);

      afficher_point(y + x_centre, x + y_centre, r, g, b);
      afficher_point(y + x_centre, x + y_centre + 1, r, g, b);
      afficher_point(y + x_centre + 1, x + y_centre, r, g, b);
      afficher_point(y + x_centre + 1, x + y_centre + 1, r, g, b);

      afficher_point(-x + x_centre, y + y_centre, r, g, b);
      afficher_point(-x + x_centre, y + y_centre + 1, r, g, b);
      afficher_point(-x + x_centre + 1, y + y_centre, r, g, b);
      afficher_point(-x + x_centre + 1, y + y_centre + 1, r, g, b);

      afficher_point(-y + x_centre, x + y_centre, r, g, b);
      afficher_point(-y + x_centre, x + y_centre + 1, r, g, b);
      afficher_point(-y + x_centre + 1, x + y_centre, r, g, b);
      afficher_point(-y + x_centre + 1, x + y_centre + 1, r, g, b);

      afficher_point(x + x_centre, -y + y_centre, r, g, b);
      afficher_point(x + x_centre, -y + y_centre + 1, r, g, b);
      afficher_point(x + x_centre + 1, -y + y_centre, r, g, b);
      afficher_point(x + x_centre + 1, -y + y_centre + 1, r, g, b);

      afficher_point(y + x_centre, -x + y_centre, r, g, b);
      afficher_point(y + x_centre, -x + y_centre + 1, r, g, b);
      afficher_point(y + x_centre + 1, -x + y_centre, r, g, b);
      afficher_point(y + x_centre + 1, -x + y_centre + 1, r, g, b);

      afficher_point(-x + x_centre, -y + y_centre, r, g, b);
      afficher_point(-x + x_centre, -y + y_centre + 1, r, g, b);
      afficher_point(-x + x_centre + 1, -y + y_centre, r, g, b);
      afficher_point(-x + x_centre + 1, -y + y_centre + 1, r, g, b);

      afficher_point(-y + x_centre, -x + y_centre, r, g, b);
      afficher_point(-y + x_centre, -x + y_centre + 1, r, g, b);
      afficher_point(-y + x_centre + 1, -x + y_centre, r, g, b);
      afficher_point(-y + x_centre + 1, -x + y_centre + 1, r, g, b);

      if (m > 0)
      {
        y = y - 1;
        m = m - 8 * y;
      }
      x = x + 1;
      m = m + 8 * x + 4;
    }
  }
}

dessiner_droite(int a, int b, int r, int g, int blue)
{
  for (i = 0; i < 100; i++)
  {
    afficher_point(i, a * i + b, r, g, blue);
    afficher_point(i, a * i + b + 1, r, g, blue);
    afficher_point(i + 1, a * i + b, r, g, blue);
    afficher_point(i + 1, a * i + b + 1, r, g, blue);
  }
}

int appeler_liste = 0;

void affichage()
{

  dessiner_rect(718, 540, 42, 42, 1, choix_red, choix_green, choix_blue); // Actuelle

  if (appeler_liste == 0)
  {
    ListeChainee = new_list();
    ListeChainee2 = new_list();

    ListeChainee = push_back_list_chainee(ListeChainee, 3, 0, 0, 0, 0, 0, 0, 0, 0);
    ////print_list(ListeChainee);

    ListeChainee2 = push_back_list_chainee(ListeChainee2, 3, 0, 0, 0, 0, 0, 0, 0, 0);
    ////print_list(ListeChainee2);
    appeler_liste = 1;
  }

  // L'affichage ne peut se faire que ici !
  // Utilisez des variables globales si vous avez besoin de faire communiquer
  // cette procédure et les autres.

  // On affiche 4 points à chaque fois pour que ce soit plus
  // visible qu'un seul pixel - juste plus de confort
  // pour ce programme de test.

  // FAIRE UN RECTANGLE

  if (choix == '1')
  {

    int width_rect;
    int height_rect;
    int x_rect;
    int y_rect;
    int i, j;
    int r, g, b;
    int res;

    dernier_x = 0;
    dernier_y = 0;
    avant_dernier_x = 0;
    avant_dernier_y = 0;

    ancien_choix = 1;

    choix = -1;
  }

  // FAIRE UNE DROITE

  if (choix == '2')
  {

    int a, b;
    int i, r, g, blue;

    dernier_x = 10;
    dernier_y = 10;
    avant_dernier_x = 0;
    avant_dernier_y = 0;

    choix = -1;

    ancien_choix = 2;
  }

  //FAIRE UN CERCLE
  if (choix == '3')
  {

    int x_centre, y_centre, rayon, m, x, y, r, g, b, i, res;

    dernier_x = 0;
    dernier_y = 0;
    avant_dernier_x = 0;
    avant_dernier_y = 0;

    choix = -1;

    ancien_choix = 3;
  }

  if (choix == '4')
  {

    if (list_length(ListeChainee) > 1)
    {
      element_i(ListeChainee, ListeChainee2, list_length(ListeChainee) - 1);

      pop_back_list(ListeChainee);

      effacer();

      initialisation_fenetre();

      dessiner_liste(ListeChainee, echelle);
    }

    choix = -1;
  }

  if (choix == '5')
  {

    // Ajouter le dernier element de ListeChainee2 à ListeChainee

    if (list_length(ListeChainee2) > 1)
    {
      element_i(ListeChainee2, ListeChainee, list_length(ListeChainee2) - 1);

      pop_back_list(ListeChainee2);

      effacer();

      initialisation_fenetre();

      dessiner_liste(ListeChainee, echelle);
    }

    choix = -1;
  }

  if (choix == '6')
  {
    dessiner_rect(95, 20, 685, 480, 1, 100, 100, 100); // Feuille Blanche
    choix = -1;
  }

  if (choix == '7')
  {
    sauvegarder(ListeChainee);

    choix = -1;
  }

  if (choix == '8')
  {

    obtenir_element(ListeChainee, list_length(ListeChainee) - 1);

    choix = -1;
  }

  if (choix == '9')
  {

    choix = -1;
  }
}

dessiner_point(x, y, r, g, b)
{
  afficher_point(x, y, r, g, b);
  afficher_point(x, y + 1, r, g, b);
  afficher_point(x + 1, y, r, g, b);
  afficher_point(x + 1, y + 1, r, g, b);
}

void clic_gauche(int x, int y)
{
  int width_rect;
  int height_rect;

  int x_centre;
  int y_centre;

  if (x < 80 && y < 160 && y > 100)
  {
    //Rectangle plein

    avant_dernier_x = 0;
    dernier_x = 0;
    avant_dernier_y = 0;
    dernier_y = 0;
    ancien_choix = 1;
  }
  else if (x < 80 && y < 250 && y > 170)
  {
    //Rectangle vide

    avant_dernier_x = 0;
    dernier_x = 0;
    avant_dernier_y = 0;
    dernier_y = 0;
    ancien_choix = 11;
  }
  else if (x < 80 && y < 330 && y > 250)
  {
    //Cercle plein

    avant_dernier_x = 0;
    dernier_x = 0;
    avant_dernier_y = 0;
    dernier_y = 0;
    ancien_choix = 3;
  }
  else if (x < 80 && y < 420 && y > 330)
  {
    //Cercle vide

    avant_dernier_x = 0;
    dernier_x = 0;
    avant_dernier_y = 0;
    dernier_y = 0;
    ancien_choix = 31;
  }
  else if (x < 80 && y < 490 && y > 420)
  {
    //Point

    avant_dernier_x = 0;
    dernier_x = 0;
    avant_dernier_y = 0;
    dernier_y = 0;
    ancien_choix = 12;
  }
  else if (x < 80 && y < 510 && y > 490)
  {
    //texte

    avant_dernier_x = 10;
    dernier_x = 10;
    avant_dernier_y = 10;
    dernier_y = 10;
    ancien_choix = 13;
  }
  else if (x < 80 && y < 570 && y > 510)
  {
    //droite

    avant_dernier_x = 10;
    dernier_x = 10;
    avant_dernier_y = 10;
    dernier_y = 10;
    ancien_choix = 2;
  }
  else if (x > 0 && x < 40 && y < 600 && y > 560) //Retour
  {

    if (list_length(ListeChainee) > 1)
    {
      element_i(ListeChainee, ListeChainee2, list_length(ListeChainee) - 1);

      pop_back_list(ListeChainee);

      effacer();

      initialisation_fenetre();

      dessiner_liste(ListeChainee, echelle);
    }
  }
  else if (x > 40 && x < 80 && y < 600 && y > 560) //Avancer
  {

    // Ajouter le dernier element de ListeChainee2 à ListeChainee

    if (list_length(ListeChainee2) > 1)
    {
      element_i(ListeChainee2, ListeChainee, list_length(ListeChainee2) - 1);

      pop_back_list(ListeChainee2);

      effacer();

      initialisation_fenetre();

      dessiner_liste(ListeChainee, echelle);
    }
  }

  if (x >= 650 && x <= 650 + 20 && y >= 600 - 540 - 20 && y <= 600 - 540)
  {
    choix_red = 100;
    choix_blue = 0;
    choix_green = 0;
    //ROUGE
    dessiner_rect(718, 540, 42, 42, 1, choix_red, choix_green, choix_blue); // Remplacer couleur Actuelle
  }
  else if (x >= 650 && x <= 650 + 20 && y >= 600 - 562 - 20 && y <= 600 - 562)
  {
    choix_red = 0;
    choix_blue = 100;
    choix_green = 0;
    //Bleu
    dessiner_rect(718, 540, 42, 42, 1, choix_red, choix_green, choix_blue); // Remplacer couleur Actuelle
  }
  else if (x >= 672 && x <= 672 + 20 && y >= 600 - 540 - 20 && y <= 600 - 540)
  {
    choix_red = 0;
    choix_blue = 0;
    choix_green = 0;
    //Noir
    dessiner_rect(718, 540, 42, 42, 1, choix_red, choix_green, choix_blue); // Remplacer couleur Actuelle
  }
  else if (x >= 672 && x <= 672 + 20 && y >= 600 - 562 - 20 && y <= 600 - 562)
  {
    choix_red = 0;
    choix_blue = 0;
    choix_green = 100;
    //Vert
    dessiner_rect(718, 540, 42, 42, 1, choix_red, choix_green, choix_blue); // Remplacer couleur Actuelle
  }
  else if (x >= 694 && x <= 694 + 20 && y >= 600 - 562 - 20 && y <= 600 - 562)
  {
    choix_red = 100;
    choix_blue = 0;
    choix_green = 100;
    //Jaune
    dessiner_rect(718, 540, 42, 42, 1, choix_red, choix_green, choix_blue); // Remplacer couleur Actuelle
  }
  else if (x >= 694 && x <= 694 + 20 && y >= 600 - 540 - 20 && y <= 600 - 540)
  {
    choix_red = 100;
    choix_blue = 100;
    choix_green = 0;
    //Violet
    dessiner_rect(718, 540, 42, 42, 1, choix_red, choix_green, choix_blue); // Remplacer couleur Actuelle
  }
  else
  {

    y = 600 - y;

    if (ancien_choix == 12)
    {
      dessiner_point(x, y, choix_red, choix_green, choix_blue);

      ListeChainee = push_back_list_chainee(ListeChainee, 1, x, y, 0, 0, 0, choix_red, choix_green, choix_blue);
    }

    if (dernier_x == 0 && avant_dernier_x == 0)
    {
      dernier_x = x;
      dernier_y = y;
    }
    else if (dernier_x != 0 && avant_dernier_x == 0)
    {
      avant_dernier_x = dernier_x;
      dernier_x = x;
      avant_dernier_y = dernier_y;
      dernier_y = y;
    }
    else if (dernier_x != 0 && avant_dernier_x != 0)
    {
      avant_dernier_x = dernier_x;
      dernier_x = x;
      avant_dernier_y = dernier_y;
      dernier_y = y;

      if (ancien_choix == 1)
      {

        if (avant_dernier_x < dernier_x && avant_dernier_y < dernier_y)
        {
          dessiner_rect(avant_dernier_x, avant_dernier_y, dernier_x - avant_dernier_x, dernier_y - avant_dernier_y, 1, choix_red, choix_green, choix_blue);

          ListeChainee = push_back_list_chainee(ListeChainee, 1, avant_dernier_x, avant_dernier_y, dernier_x - avant_dernier_x, dernier_y - avant_dernier_y, 1, choix_red, choix_green, choix_blue);
        }
        else if (avant_dernier_x > dernier_x && avant_dernier_y < dernier_y)
        {
          int largeur = avant_dernier_x - dernier_x;

          dessiner_rect(avant_dernier_x - largeur, avant_dernier_y, largeur, dernier_y - avant_dernier_y, 1, choix_red, choix_green, choix_blue);

          ListeChainee = push_back_list_chainee(ListeChainee, 1, avant_dernier_x - largeur, avant_dernier_y, largeur, dernier_y - avant_dernier_y, 1, choix_red, choix_green, choix_blue);
        }
        else if (avant_dernier_x < dernier_x && avant_dernier_y > dernier_y)
        {
          int largeur = dernier_x - avant_dernier_x;

          int hauteur = avant_dernier_y - dernier_y;

          dessiner_rect(avant_dernier_x, dernier_y, largeur, hauteur, 1, choix_red, choix_green, choix_blue);

          ListeChainee = push_back_list_chainee(ListeChainee, 1, avant_dernier_x, dernier_y, largeur, hauteur, 1, choix_red, choix_green, choix_blue);
        }
        else if (avant_dernier_x > dernier_x && avant_dernier_y > dernier_y)
        {
          int largeur = avant_dernier_x - dernier_x;

          int hauteur = avant_dernier_y - dernier_y;

          dessiner_rect(avant_dernier_x - largeur, dernier_y, largeur, hauteur, 1, choix_red, choix_green, choix_blue);

          ListeChainee = push_back_list_chainee(ListeChainee, 1, avant_dernier_x - largeur, dernier_y, largeur, hauteur, 1, choix_red, choix_green, choix_blue);
        }
      }
      if (ancien_choix == 11)
      {

        if (avant_dernier_x < dernier_x && avant_dernier_y < dernier_y)
        {
          dessiner_rect(avant_dernier_x, avant_dernier_y, dernier_x - avant_dernier_x, dernier_y - avant_dernier_y, 0, choix_red, choix_green, choix_blue);

          ListeChainee = push_back_list_chainee(ListeChainee, 1, avant_dernier_x, avant_dernier_y, dernier_x - avant_dernier_x, dernier_y - avant_dernier_y, 0, choix_red, choix_green, choix_blue);
        }
        else if (avant_dernier_x > dernier_x && avant_dernier_y < dernier_y)
        {
          int largeur = avant_dernier_x - dernier_x;

          dessiner_rect(avant_dernier_x - largeur, avant_dernier_y, largeur, dernier_y - avant_dernier_y, 0, choix_red, choix_green, choix_blue);

          ListeChainee = push_back_list_chainee(ListeChainee, 1, avant_dernier_x - largeur, avant_dernier_y, largeur, dernier_y - avant_dernier_y, 0, choix_red, choix_green, choix_blue);
        }
        else if (avant_dernier_x < dernier_x && avant_dernier_y > dernier_y)
        {
          int largeur = dernier_x - avant_dernier_x;

          int hauteur = avant_dernier_y - dernier_y;

          dessiner_rect(avant_dernier_x, dernier_y, largeur, hauteur, 0, choix_red, choix_green, choix_blue);

          ListeChainee = push_back_list_chainee(ListeChainee, 1, avant_dernier_x, dernier_y, largeur, hauteur, 0, choix_red, choix_green, choix_blue);
        }
        else if (avant_dernier_x > dernier_x && avant_dernier_y > dernier_y)
        {
          int largeur = avant_dernier_x - dernier_x;

          int hauteur = avant_dernier_y - dernier_y;

          dessiner_rect(avant_dernier_x - largeur, dernier_y, largeur, hauteur, 0, choix_red, choix_green, choix_blue);

          ListeChainee = push_back_list_chainee(ListeChainee, 1, avant_dernier_x - largeur, dernier_y, largeur, hauteur, 0, choix_red, choix_green, choix_blue);
        }
      }
      else if (ancien_choix == 2)
      {
        float distance = calculer_distance(avant_dernier_x, avant_dernier_y, dernier_x, dernier_y);

        double a_dernier_x = dernier_x;
        double a_dernier_y = dernier_y;
        double a_avant_dernier_x = avant_dernier_x;
        double a_avant_dernier_y = avant_dernier_y;
        double a = ((a_dernier_y - a_avant_dernier_y) / (a_dernier_x - a_avant_dernier_x));

        int x = 0;

        while (x < distance)
        {
          int result = a * x + avant_dernier_y;
          dessiner_point(x + avant_dernier_x, result, choix_red, choix_green, choix_blue);
          x = x + 1;
        }
      }
      else if (ancien_choix == 3)
      {

        int rayon = calculer_distance(avant_dernier_x, avant_dernier_y, dernier_x, dernier_y);

        dessiner_cercle(avant_dernier_x, avant_dernier_y, rayon, 1, choix_red, choix_green, choix_blue);

        ListeChainee = push_back_list_chainee(ListeChainee, 2, avant_dernier_x, avant_dernier_y, rayon, 1, 0, choix_red, choix_green, choix_blue);
      }
      else if (ancien_choix == 31)
      {

        int rayon = calculer_distance(avant_dernier_x, avant_dernier_y, dernier_x, dernier_y);

        dessiner_cercle(avant_dernier_x, avant_dernier_y, rayon, 0, choix_red, choix_green, choix_blue);

        ListeChainee = push_back_list_chainee(ListeChainee, 2, avant_dernier_x, avant_dernier_y, rayon, 0, 0, choix_red, choix_green, choix_blue);
      }
      else if (ancien_choix == 13)
      {
        char texte[100];
        int x, y, r, g, b;

        printf("Entre ton texte : ");
        scanf("%s", &texte);
        printf("X : ");
        scanf("%d", &x);
        printf("Y : ");
        scanf("%d", &y);
        printf("r : ");
        scanf("%d", &r);
        printf("g : ");
        scanf("%d", &g);
        printf("b : ");
        scanf("%d", &b);
        afficher_texte(x, 600 - y, texte, r, g, b);
      }

      avant_dernier_x = 0;
      avant_dernier_y = 0;
    }
  }
}

void clic_droit(int x, int y)
{
  // Code exécuté lors d'un clic droit
  // Attention ! Pas de dessin dans cette fonction/procédure
  // Utilisez des variables globales si vous avez besoin de faire communiquer
  // cette procédure et celles du dessous.
  //printf("Clic droit en %d %d\n", x, y);

  if (echelle == 1)
  {
    echelle = 2;
  }
  else
  {
    echelle = 1;
  }

  effacer();

  initialisation_fenetre();

  dessiner_liste(ListeChainee, echelle);
}

void clavier(unsigned char key, int x, int y)
{
  // Code exécuté lors d'un
  // Attention ! Pas de dessin dans cette fonction/procédure
  // Utilisez des variables globales si vous avez besoin de faire communiquer
  // cette procédure et celles du dessous.

  //printf("Appui sur la touche %c du clavier lorsque la souris est en %d %d\n", key, x, y);

  // Si la touche appuyée est un chiffre entre 1 et 6,
  // la case correspondante dans le tableau choix est mise à vrai.
  // Si une autre touche est appuyée, le programme se ferme.
  if (key >= '1' && key <= '8')
    choix = key;
  else
    exit(0);
}
