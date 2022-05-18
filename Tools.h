//
// Created by ethan on 29/04/2022.
//

#include <stddef.h>

#ifndef L2S2_PROJ_AUTOMATE_TOOLS_H
#define L2S2_PROJ_AUTOMATE_TOOLS_H

// **************************************************************
// STRUCTURE OUTILS pour fonctionnalités supplémentaire.

typedef struct Liste_dynamique{
    int list_int;
    char* list_charEt;
}list_dynam;

// **************************************************************
// FONCTIONS OUTILS pour fonctionnalités supplémentaire.

// --------------------------------------------------------------
//Fonction foreach

#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)

// **************************************************************
// FONCTIONS OUTILS pour saisie sécurisée (empêche le problème de saisie de caractère.

// --------------------------------------------------------------
//FONCTION permettant de vider le buffer (emplacement de stockage en mémoire, par exemple de caractère) pour éviter les
// débordements
void viderBuffer();

// --------------------------------------------------------------
//FONCTION permettant de lire une chaine de caractère plus ou moins longue de manière sécurisée.
int Lire(char *chaine, int longueur);

// --------------------------------------------------------------
//FONCTION permettant de lire un entier avec le fonction lire de manière sécurisée
void LireInt(int * valeur);

// **************************************************************
// FONCTIONS OUTILS pour les tableaux

char* char_to_str(char caract);

// --------------------------------------------------------------
// Conversion charactère en chaine simple
char* int_to_str(int entier);

char* Return_Current_Path();

// --------------------------------------------------------------
// Supprime une chaine ou un charactère
void delnword(char *t, char *c, int n);

// --------------------------------------------------------------
// FONCTION retournant la longueur d'un tableau
int len_tab_charEt(size_t size_tab, const char* tab[]);

// --------------------------------------------------------------
// FONCTION recherchant un élément dans un tableau
int find_charEt_in_tab(const char* value, const char* tab[]);

// --------------------------------------------------------------
// FONCTION recherchant un élément char dans un tableau
int find_char_in_tab(char value, const char tab[]);

#endif //L2S2_PROJ_AUTOMATE_TOOLS_H


