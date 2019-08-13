#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define TAILLE_MAX 1000 // Tableau de taille 1000



/**
* Retourne une nouvelle Liste
* @return Une liste vide
*/
List new_list(void)
{
	return NULL;
}

/*---------------------------------------------------------------------*/

/**
* Vérifie si une List est vide
* @param li La liste à tester
* @return true si elle est vide, faux sinon
*/
Bool is_empty_list(List li)
{
	if(li == NULL)
		return true;

	return false;
}

/*---------------------------------------------------------------------*/

/**
* Affiche une Liste
* @param li La liste à afficher
*/
void print_list(List li)
{
	if(is_empty_list(li))
	{
		//printf("Rien a afficher, la Liste est vide.\n");
		return;
	}
		//printf("############ LISTE CHAINEE ############\n");
		while(li != NULL)
		{
			if (li->type == 1)
			{
				//printf("Carre : origine:%d,%d largeur:%d longueur:%d plein:%d,r:%d,g:%d,b:%d\n", li->x_rect,li->y_rect,li->largeur,li->longueur,li->plein,li->red,li->green,li->blue);
				li = li->next;
			}
			else if (li->type == 2)
			{
				//printf("Cercle : centre:%d,%d rayon:%d plein:%d,r:%d,g:%d,b:%d\n", li->x_centre,li->y_centre,li->rayon,li->plein,li->red,li->green,li->blue);
				li = li->next;
			}
			else if (li->type == 3)
			{
				//printf("Droite : coeffDir:%d ordOrigine:%d,r:%d,g:%d,b:%d\n", li->coeffDir,li->ordOrigine,li->red,li->green,li->blue);
				li = li->next;
			}
			else if (li->type == 4)
			{
				//printf("Point : x:%d y:%d,r:%d,g:%d,b:%d\n", li->x,li->y,li->red,li->green,li->blue);
				li = li->next;
			}
		}
		
		while(li != NULL)
		{
			if (li->next==NULL)
			{
				//printf("%d\n", li->type);
			}
			
		}


	//printf("\n");
}

/*---------------------------------------------------------------------*/

/**
* Retourne la taille de la Liste
* @param li La liste
* @return Le nombre d'élements de la Liste
*/
int list_length(List li)
{
	int size = 0;

	if(is_empty_list(li))
		return size;

	while(li != NULL)
	{
		size++;
		li = li->next;
	}

	return size;
}

/*---------------------------------------------------------------------*/

/**
* Ajoute un entier en fin de Liste
* @param li La liste
* @param x L'entier à insérer
* @return La liste avec le nouvel élement ajouté
*/

List push_back_list_chainee(List li, int element1, int element2, int element3, int element4, int element5, int element6, int element7, int element8, int element9)
{
	//Si l'élément est un rectangle
	if (element1 == 1)
	{
		ListElement *element;

		element = malloc(sizeof(*element));

		if(element == NULL)
		{
			fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
			exit(EXIT_FAILURE);
		}


		element->x_rect = element2;
		element->y_rect = element3;
		element->largeur = element4;
		element->longueur = element5;
		element->plein = element6;
		element->type = element1;
		element->red = element7;
		element->green = element8;
		element->blue = element9;
		element->next = NULL;

		if(is_empty_list(li))
			return element;

		ListElement *temp;
		temp = li;

		while(temp->next != NULL)
			temp = temp->next;

		temp->next = element;

		return li;

	}

	//Si l'élément est un cercle

	if (element1 == 2)
	{
		ListElement *element;

		element = malloc(sizeof(*element));

		if(element == NULL)
		{
			fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
			exit(EXIT_FAILURE);
		}

		

		element->x_centre = element2;
		element->y_centre = element3;
		element->rayon = element4;
		element->plein = element5;
		element->type = element1;
		element->red = element7;
		element->green = element8;
		element->blue = element9;
		element->next = NULL;

		if(is_empty_list(li))
			return element;

		ListElement *temp;
		temp = li;

		while(temp->next != NULL)
			temp = temp->next;

		temp->next = element;

		return li;

	}

	//Si l'élement est une droite

	if (element1 == 3)
	{
		ListElement *element;

		element = malloc(sizeof(*element));

		if(element == NULL)
		{
			fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
			exit(EXIT_FAILURE);
		}

		

		element->coeffDir = element2;
		element->ordOrigine = element3;
		element->type = element1;
		element->red = element7;
		element->green = element8;
		element->blue = element9;
		element->next = NULL;

		if(is_empty_list(li))
			return element;

		ListElement *temp;
		temp = li;

		while(temp->next != NULL)
			temp = temp->next;

		temp->next = element;

		return li;

	}


	
	if (element1 == 4)
	{
		ListElement *element;

		element = malloc(sizeof(*element));

		if(element == NULL)
		{
			fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
			exit(EXIT_FAILURE);
		}

		

		element->x = element2;
		element->y = element3;
		element->type = element1;
		element->red = element7;
		element->green = element8;
		element->blue = element9;
		element->next = NULL;

		if(is_empty_list(li))
			return element;

		ListElement *temp;
		temp = li;

		while(temp->next != NULL)
			temp = temp->next;

		temp->next = element;

		return li;

	}

}


/*---------------------------------------------------------------------*/

/**
* Ajoute un entier en début de Liste
* @param li La liste
* @param x L'entier à insérer
* @return La liste avec le nouvel élement ajouté
*/
List push_front_list(List li, int x)
{
	ListElement *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->value = x;
	element->largeur = x;

	if(is_empty_list(li))
		element->next = NULL;
	else
		element->next = li;

	return element;
}

/*---------------------------------------------------------------------*/

/**
* Supprime un entier de la fin de la Liste
* @param li La liste
* @return La liste sans l'élément retiré
*/
List pop_back_list(List li)
{
	if(is_empty_list(li))
		return new_list();

	//Si la liste n'a qu'un seul élément
	if(li->next == NULL)
	{
		free(li);
		li = NULL;

		return new_list();
	}

	ListElement *temp = li;
	ListElement *before = li;

	while(temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}

	before->next = NULL;

	free(temp);
	temp = NULL;

	return li;
}

/*---------------------------------------------------------------------*/

/**
* Supprime un entier de la tête de la Liste
* @param li La liste
* @return La liste sans l'élément retiré
*/
List pop_front_list(List li)
{
	ListElement *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	if(is_empty_list(li))
		return new_list();

	element = li->next;

	free(li);
	li = NULL;

	return element;
}

/*---------------------------------------------------------------------*/

/**
* Supprime tous les éléments d'une Liste
* @param li La liste
* @return Une Liste vide
*/
List clear_list(List li)
{
	if(is_empty_list(li))
		return new_list();

	while(li != NULL)
		li = pop_front_list(li);
}


/*---------------------------------------------------------------------*/

/**
* Prendre element i de la Liste
* @param li La liste
*/

int ListeChainee;
int x_rect;
int y_rect;
int width_rect;
int height_rect;
int res;

List element_i(List li, List li2, int indice)
{
    int i;
    /* On se déplace de i cases, tant que c'est possible */
    for(i=0; i<indice && li != NULL; i++)
    {
        li = li->next;
    }

    /* Si l'élément est NULL, c'est que la liste contient moins de i éléments */
    if(li == NULL)
    {
        return NULL;
    }
    else
    {
        /* Sinon on renvoie l'adresse de l'élément i */
        //return li->x_rect;
		if (li->type==1)
		{
			return push_back_list_chainee(li2,1,li->x_rect,li->y_rect,li->largeur,li->longueur,li->plein,li->red,li->green,li->blue);
		}
		if (li->type==2)
		{
			return push_back_list_chainee(li2,2,li->x_centre,li->y_centre,li->rayon,li->plein,0,li->red,li->green,li->blue);
		}
		if (li->type==3)
		{
			return push_back_list_chainee(li2,3,li->coeffDir,li->ordOrigine,0,0,0,li->red,li->green,li->blue);
		}
		if (li->type==4)
		{
			return push_back_list_chainee(li2,4,li->x,li->y,0,0,0,li->red,li->green,li->blue);
		}
    }
}




void dessiner_liste(List li, int echelle)
{
	if(is_empty_list(li))
	{
		printf("Rien a afficher, la Liste est vide.\n");
		return;
	}
		while(li != NULL)
		{
			if (li->type == 1)
			{
				dessiner_rect(li->x_rect, li->y_rect, li->largeur*echelle, li->longueur*echelle, li->plein, li->red, li->green, li->blue);
				li = li->next;
			}
			else if (li->type == 2)
			{
				//printf("Cercle : centre:%d,%d rayon:%d plein:%d\n", li->x_centre,li->y_centre,li->rayon,li->plein);
				dessiner_cercle(li->x_centre,li->y_centre,li->rayon*echelle,li->plein, li->red, li->green, li->blue);
				li = li->next;
			}
			else if (li->type == 3)
			{
				//printf("Droite : coeffDir:%d ordOrigine:%d\n", li->coeffDir,li->ordOrigine);
				dessiner_droite(li->coeffDir,li->ordOrigine,li->red,li->green,li->blue);
				li = li->next;
			}
			else if (li->type == 4)
			{
				//printf("Point : x:%d y:%d\n", li->x,li->y);
				dessiner_point(li->x,li->y,li->red,li->green,li->blue);
				li = li->next;
			}
		}

		while(li != NULL)
		{
			if (li->next==NULL)
			{
				//printf("%d\n", li->type);
			}
		}


	//printf("\n");
}



/*---------------------------------------------------------------------*/

/**
* Prendre element i de la Liste
* @param li La liste
*/

int ListeChainee;
int x_rect;
int y_rect;
int width_rect;
int height_rect;
int res;

List obtenir_element(List li, int indice)
{
    int i;
    /* On se déplace de i cases, tant que c'est possible */
    for(i=0; i<indice && li != NULL; i++)
    {
        li = li->next;
    }

    /* Si l'élément est NULL, c'est que la liste contient moins de i éléments */
    if(li == NULL)
    {
        return NULL;
    }
    else
    {
        /* Sinon on renvoie l'adresse de l'élément i */
        //return li->x_rect;
		if (li->type==1)
		{
			//printf("\n%d\n",li->x_rect);
			dessiner_rect(li->x_rect-1, li->y_rect-1, li->largeur+2, li->longueur+2, li->plein, li->red, li->green, li->blue);
			push_back_list_chainee(ListeChainee,1,li->x_rect-1,li->y_rect-1,li->largeur+2,li->longueur+2,li->plein,li->red,li->green,li->blue);
		}
		if (li->type==2)
		{
			dessiner_cercle(li->x_centre,li->y_centre,li->rayon+2,li->plein, li->red, li->green, li->blue);
			push_back_list_chainee(ListeChainee,2,li->x_centre,li->y_centre,li->rayon+2,li->plein,0,li->red,li->green,li->blue);
		}
		if (li->type==3)
		{
			
		}
		if (li->type==4)
		{
			
		}
    }
}



void avoir_element(List li, int indice)
{
    int i;
    /* On se déplace de i cases, tant que c'est possible */
    for(i=0; i<indice && li != NULL; i++)
    {
        li = li->next;
    }

    /* Si l'élément est NULL, c'est que la liste contient moins de i éléments */
    if(li == NULL)
    {
        return NULL;
    }
    else
    {
        /* Sinon on renvoie l'adresse de l'élément i */
        //return li->x_rect;

		
			int i;
			FILE* fichier = NULL;
			fichier = fopen("sauvegarde.c", "a");
			

		
		if (li->type==1)
		{
			
			if (fichier != NULL)
			{
				fprintf(fichier,"%d %d %d %d %d %d %d %d %d\n",li->type,li->x_rect,li->y_rect,li->largeur,li->longueur,li->plein,li->red,li->green,li->blue);
				
				fclose(fichier);
				
			}
			
		}
		if (li->type==2)
		{
			dessiner_cercle(li->x_centre,li->y_centre,li->rayon+2,li->plein, li->red, li->green, li->blue);
			push_back_list_chainee(ListeChainee,2,li->x_centre,li->y_centre,li->rayon+2,li->plein,0,li->red,li->green,li->blue);
		}
		if (li->type==3)
		{
			
		}
		if (li->type==4)
		{
			
		}
		
    }
}




int sauvegarder(List li)
{
	int i;
	FILE* fichier = NULL;
	fichier = fopen("sauvegarde.c", "w");
	fclose(fichier);
	
	  for (i=0;i<list_length(ListeChainee);i++)
	  {
		  avoir_element(ListeChainee,i);
	  }
        
 
    
}

int lire_sauvegarde()
{
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
 
    fichier = fopen("sauvegarde.c", "r");
 
    if (fichier != NULL)
    {
        fgets(chaine, TAILLE_MAX, fichier); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans "chaine"
        printf("%s", chaine); // On affiche la chaîne
 
        fclose(fichier);
    }
 
}
    