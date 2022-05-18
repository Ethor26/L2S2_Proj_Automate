//
// Created by ethan on 29/04/2022.
//

#include "Tools.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>        // getcwd
#include <errno.h>

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
// Conversion charactère en chaine simple
char* char_to_str(char caract){
    char str[] = {caract, '\0'};
    return str;
}

// --------------------------------------------------------------
// Conversion charactère en chaine simple
char* int_to_str(int entier){
    char* convert_int_to_str = malloc(BUFSIZ*sizeof(char));
    itoa(entier, convert_int_to_str, 10);
    return  convert_int_to_str;
}

// Pour nbr : char str[] = { AF->numeros_etats_initiaux[i] + '0', '\0'}; // Conversion du int->char et du car->str
// #define BUFFER_SIZE 30

// --------------------------------------------------------------
// Comparaison Str : pas que la longueur
int Str_comp(char* str1, char * str2){
    if(strcmp(str1,str2) == 0){
        for(int i = 0; i<strlen(str1); i++){
            if (str1[i] != str2[i])
                return 0;
        }
        return 1;
    }
    else
        return 0;
}

// --------------------------------------------------------------
// Retourne le Path du répertoire courant : équivalent de os.getcwd
char* Return_Current_Path() {
    char* buffer = malloc(BUFSIZ * sizeof(char));
    if ( getcwd( buffer, BUFSIZ) == NULL ) {
        fprintf( stderr, "Cannot get current working directory path\n" );
        if ( errno == ERANGE ) {
            fprintf( stderr, "Buffer size is too small.\n" );
        }
        exit( EXIT_FAILURE );
    }

    delnword(buffer, "\\cmake-build-debug", -1);
    delnword(buffer, "\\cmake-build-default", -1);
    // delnword(buffer, "\\Projet Automates finis et Expressions rationnelles", -1);

    printf("Current working directory: %s\n", buffer );
    return buffer;


    //    return EXIT_SUCCESS;
}

// --------------------------------------------------------------
// Supprime une chaine ou un charactère
void delnword(char *t, char *c, int n)
{
    int i = 0, lenc = (int)strlen(c);

    while((t = strstr(t, c)) != NULL)
    {
        if(i == n || n == -1)
            memmove(t, t + lenc, strlen(t) - lenc + 1);
        else
            t += lenc; // On saute le mot, c'est pas lui qu'on enlève
        i++; // delnwords(chaine, " maison", 1);
    }
}

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