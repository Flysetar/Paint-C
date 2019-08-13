#ifndef __LIST__H__
#define __LIST__H__

	/* Définition d'un Booléen */
	typedef enum
	{
		false,
		true
	}Bool;

	/* Définition d'une Liste */
	typedef struct ListElement
	{
		int value;
		int x;
		int y;
		int type;
		int x_rect;
		int y_rect;
		int largeur;
		int longueur;
		int plein;
		int x_centre;
		int y_centre;
		int rayon;
		int coeffDir;
		int ordOrigine;
		int red;
		int green;
		int blue;
		struct ListElement *next;
	}ListElement, *List;

	/* Prototypes */
	List new_list(void);
	Bool is_empty_list(List li);
	void print_list(List li);
	int list_length(List li);
	List push_back_list(List li, int x);
	List push_front_list(List li, int x);
	List pop_back_list(List li);
	List pop_front_list(List li);
	List clear_list(List li);
	List element_i(List li, List li2, int indice);
	void dessiner_liste(List li, int echelle);
	List obtenir_element(List li, int indice);
	int sauvegarder(List li);
	int lire_sauvegarde();
	


#endif