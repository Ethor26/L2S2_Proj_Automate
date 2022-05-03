//
// Created by ethan on 29/04/2022.
//

#include "Tools.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// **************************************************************
// FONCTIONS OUTILS utilisées dans le reste du programme saisie sécurisée (empêche le problème de saisie de caractère.

// --------------------------------------------------------------
//FONCTION permettant de vider le buffer (emplacement de stockage en mémoire, par exemple de caractère) pour éviter les
// débordements
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

// --------------------------------------------------------------
//FONCTION permettant de lire une chaine de caractère plus ou moins longue de manière sécurisée.
int Lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;

    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            viderBuffer();
        }
        return 1;
    }
    else
    {
        viderBuffer();
        return 0;
    }
}


// --------------------------------------------------------------
//FONCTION permettant de lire un entier avec le fonction lire de manière sécurisée
void LireInt(int * valeur)
{
    char nombreTexte[100] = {0}; // 100 cases devraient suffire
    do{
        Lire(nombreTexte, 100);
        *valeur = strtol(nombreTexte, NULL, 10);
    }while(*valeur == 0 && strcmp(nombreTexte, "0") != 0);
}

// **************************************************************
// FONCTIONS OUTILS pour les tableaux

// --------------------------------------------------------------
// FONCTION retournant la longueur d'un tableau de char*
int len_tab_charEt(size_t size_tab, const char* tab[]){
    // size_t n  = (int) sizeof(tab)/sizeof(tab[0]);
    // Division de la taille mémoire du tableau sur la taille mémoire d'un élément

    return size_tab/sizeof(tab[0]);
}

// --------------------------------------------------------------
// FONCTION recherchant un élément char* dans un tableau
int find_charEt_in_tab(const char* value, const char* tab[]){

    //La recherche commence à partir de zéro
    int i = 0;
    while (i < len_tab_charEt(sizeof(tab), tab) && value != tab[i]) {
        i++;
    }

    if (i < len_tab_charEt(sizeof(tab), tab)) {
        //printf("L'élément se trouve dans la position = %d", i + 1);
        //int El_in_tab[] = {value, i+1};
        return i + 1;
    }
    /*else {
        // printf("Elément non trouvé");
     } */

    return -1;
}

// TEST :
// int Testab[] = {1, 2, 3};
//            int Testab2[5];
//            printf("longueur : %d   position de la valeur %d : %d\n", len_tab_charEt(sizeof(Testab2), Testab2), 2, find_int_in_tab(2, Testab));

// --------------------------------------------------------------
// FONCTION recherchant un élément char dans un tableau
int find_char_in_tab(const char value, const char tab[]){

    //La recherche commence à partir de zéro
    int i = 0;
    while (i < strlen(tab) && value != tab[i]) {
        i++;
    }

    if (i < strlen(tab)) {
        //printf("L'élément se trouve dans la position = %d", i + 1);
        //int El_in_tab[] = {value, i+1};
        return i + 1;
    }
    /*else {
        // printf("Elément non trouvé");
     } */

    return -1;
}