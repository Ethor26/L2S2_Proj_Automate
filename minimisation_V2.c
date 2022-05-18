
#include "minimisation_V2.h"


// ***********************************************
// INIT STRUCTURES

Etat_AF* Init_etat_AF(Automate* AF, int num_etat){
    Etat_AF* AF_etat = (Etat_AF*)malloc(sizeof(Etat_AF));
    AF_etat->num_etat_depart = int_to_str(num_etat);
    int nb_arriv = 0;
    for(int j = 0; j < AF->nb_etats; j++){
        if (AF->etats_depart[j] == num_etat){
            AF_etat->symboles_trans[nb_arriv] = AF->symboles[j];
            AF_etat->etats_arrivee[nb_arriv] = int_to_str(AF->etats_arrivee[j]);
            nb_arriv++;
        }
    }
    AF_etat->nb_etats_arrivee = nb_arriv;
    return AF_etat;
}

Etat_AF_minim* Init_etat_AF_min(Automate* AF, int num_etat){
    Etat_AF_minim* Etat_AF_min = malloc(sizeof(Etat_AF_minim));
    Etat_AF_min->Etat_AF = Init_etat_AF(AF, num_etat);
    for(int i = 0; i<BUFSIZ;i++){
        Etat_AF_min->list_gr_minim[i] = malloc(BUFSIZ*sizeof(char));
    }
    Etat_AF_min->len_list_gr_minim = 0;
    return Etat_AF_min;
}

gr_minim* Init_Gr(int num_part, int id_gr){
    gr_minim* Groupe = malloc(sizeof(gr_minim));
    //Groupe->name_Gr = "P" + num_part + "." + id_gr;
    //Groupe->name_Gr = malloc(20*sizeof(char));
    Groupe->name_Gr = malloc(sizeof(char));
    strcat(Groupe->name_Gr, "P");
    strcat(Groupe->name_Gr, int_to_str(num_part));
    strcat(Groupe->name_Gr, ".");
    strcat(Groupe->name_Gr, int_to_str(id_gr));

    for(int i = 0; i<BUFSIZ;i++){
        Groupe->etats_Gr[i] = malloc(sizeof(Etat_AF_minim*));
        Groupe->etats_Gr[i]->Etat_AF = malloc(sizeof(Etat_AF));
    }
    Groupe->nb_etats_Gr = 0;
    return Groupe ;
}

list_AF* Init_List_Gr(){
    list_AF* Liste_GR = malloc(sizeof(list_AF));
    for(int i = 0; i<BUFSIZ;i++){
        Liste_GR->list_Gr[i] = malloc(sizeof(gr_minim*));
    }

    //for (int i = 0; i<100; i++)
     //   Liste_GR->list_Gr[i] = malloc(sizeof(gr_minim));
    Liste_GR->len_list_gr_minim = 0;
    return Liste_GR;
}

// *****************************************************
// OUTILS MINIM

// -------------------------------------
// Affichage des etapes
void Aff_Pres_part(int num_part, FILE * fichier_trace){
    fprintf(fichier_trace, "\n- - - - - Fin Partition %d:\n ------------------\n - - - - - Debut Partition %d: Séparation des états en fonctions de leur types de transitions (T ou NT)\n", num_part, num_part +1);
    printf("\n- - - - - Fin Partition %d:"
           "\n ------------------"
           "\n - - - - - Debut Partition %d: Séparation des états en fonctions de leur types de transitions\n", num_part, num_part +1);
}

// -------------------------------------
// Affichage des résultats d'etapes
void Aff_res_part(list_AF* List_Gr, FILE * fichier_trace){
    // On parcours tous les groupes
    for (int id_Gr = 0; id_Gr<List_Gr->len_list_gr_minim ; id_Gr++){

        gr_minim* Groupe = List_Gr->list_Gr[id_Gr];
        printf("Groupe %s a pour etats :", Groupe->name_Gr);
        fprintf(fichier_trace, "Groupe %s a pour etats :", Groupe->name_Gr);

        // On parcours tous les etats de chaque groupe
        for(int Nbetat_Gr = 0; Nbetat_Gr<Groupe->nb_etats_Gr ; Nbetat_Gr++){
            Etat_AF_minim* Etat_etudie = Groupe->etats_Gr[Nbetat_Gr];
            printf("%s ", Etat_etudie->Etat_AF->num_etat_depart);
            fprintf(fichier_trace, "%s ", Etat_etudie->Etat_AF->num_etat_depart);
        }
        fprintf(fichier_trace, "\n");
        printf("\n");
    }
}

// -------------------------------------
// FONCTION trouve le groupe d'un état
gr_minim* find_Gr(Etat_AF* etat_rech, list_AF* List_Gr){
    // On parcours tous les groupes
    for (int id_Gr = 0; id_Gr<List_Gr->len_list_gr_minim ; id_Gr++){

        gr_minim* Groupe = List_Gr->list_Gr[id_Gr];

        // On parcours tous les etats de chaque groupe
        for(int Nbetat_Gr = 0; Nbetat_Gr<Groupe->nb_etats_Gr ; Nbetat_Gr++){
            Etat_AF_minim* Etat_etudie = Groupe->etats_Gr[Nbetat_Gr];
            // Si l'etat cherché correspond à celui d'un groupe, on renvoie ce groupe
            if(Str_comp(etat_rech->num_etat_depart,Etat_etudie->Etat_AF->num_etat_depart) != 0)
                return Groupe;
        }
    }
    return NULL;
}

// -------------------------------------
// Fonction retourne le (nouveau) groupe auquel appartient l'etat ou null en fonction des motifs de transitions
gr_minim* Verif_motifs(Etat_AF_minim * Etat_etudie, gr_minim* Groupe, list_AF* List_groupes){
    int MemeGr;

        // Boucle pour comparer chaque état par rapport aux autres
        for(int etat_cmp = 0; etat_cmp<Groupe->nb_etats_Gr; etat_cmp++){
            // Pour que l'etat ne soit pas comparé avec lui-même
            if (Str_comp(Groupe->etats_Gr[etat_cmp]->Etat_AF->num_etat_depart,Etat_etudie->Etat_AF->num_etat_depart) == 0){
                MemeGr = 1;
                // Comparaison des motifs
                for(int j = 0; j< Etat_etudie->len_list_gr_minim ; j++) {
                    if (Str_comp(Etat_etudie->list_gr_minim[j], Groupe->etats_Gr[etat_cmp]->list_gr_minim[j]) == 0) // Fonction de comparaison de str
                        MemeGr = 0;
                    if (MemeGr == 1)
                        return find_Gr(Groupe->etats_Gr[etat_cmp]->Etat_AF, List_groupes);
                }
            }
        }
    //}
    return NULL;
}

// -------------------------------------
// Convertie une liste de Etat_AF_minim** en Etat_AF**
Etat_AF** Minim_to_af(Etat_AF_minim ** list_Etat_minim){
    printf("Debut @Minim_to_af\n");
    Etat_AF ** etat_AF = malloc(2*sizeof(Etat_AF*));
    return etat_AF;
}

// -------------------------------------
// Fusionne des etats : additionne leur transition et noms
Etat_AF_minim** fusion_etats(Etat_AF** liste_etats_af){
    printf("Debut @fusion_etats\n");
    Etat_AF_minim ** etat_AF = malloc(2*sizeof(Etat_AF_minim*));
    return etat_AF;
}

// -------------------------------------
// Elimine les états en double après les partitions
Etat_AF_minim** Elimination_doublons(list_AF* List_Gr){
    // On parcours tous les groupes
    Etat_AF_minim* * List_Et_AFMIN = malloc(BUFSIZ*sizeof(Etat_AF_minim*));
    int Len_Etat_AF_minim = 0;
    Etat_AF_minim** liste_etats_AFMin;

    for (int id_Gr = 0; id_Gr<List_Gr->len_list_gr_minim ; id_Gr++){
        gr_minim* Groupe = List_Gr->list_Gr[id_Gr];

        if(Groupe->nb_etats_Gr > 1){
            // A ce niveau, tous groupes sont des singletons sauf ceux avec des doublons.
            Etat_AF** liste_etats_af = Minim_to_af(Groupe->etats_Gr);
            liste_etats_AFMin = fusion_etats(liste_etats_af); // Fonction commune avec la détermisation
        }

        foreach(Etat_AF_minim** etat, liste_etats_AFMin){
                // Attribution des etats minimaux à la liste finale : par pointeurs et foreach
                List_Et_AFMIN[Len_Etat_AF_minim] = *etat;
                Len_Etat_AF_minim++;
        }
    }
    return List_Et_AFMIN;
}

// -------------------------------------
// Assemble les etats minimisés dans l'automate
void Etat_AF_in_AF(Automate* AF, Etat_AF_minim** Etat_to_AF){
    printf("Debut @Etat_AF_in_AF");
}

// *******************************************************
// PRINCIPALES

// --------------------------------------------------
// FONCTION Principale de miminisation
void Minim_princ(Automate* AF, char* nom_Fichier_trace, int numero){
    // On suppose l'automate déterministe complet
    FILE * Fichier_trace = fopen(nom_Fichier_trace, "w"); // Réactiver après test
    afficher_automate(AF, nom_Fichier_trace, numero);

    //fprintf(fichier, "************** Debut de la minimisation ***************\n ------------------\n - - - - - Debut Partition 0: Séparation des états entre terminaux et non terminaux\n");
    printf("************** Debut de la minimisation ***************"
       "\n ------------------"
       "\n - - - - - Debut Partition 0: Séparation des états entre terminaux et non terminaux\n");

    int num_part = 0;
    gr_minim* Gr1 = Init_Gr(num_part, 1);
    gr_minim* Gr2 = Init_Gr(num_part, 2);

    printf("Groupe %s : Numeros des etats terminaux :", Gr1->name_Gr);
    fprintf(Fichier_trace, "Groupe %s :Numeros des etats terminaux :", Gr1->name_Gr);
    for (int j = 0; j < AF->nb_etats_terminaux; j++){
        printf(" %d",AF->numeros_etats_terminaux[j]);
        fprintf(Fichier_trace, " %d", AF->numeros_etats_terminaux[j]);
        Gr1->etats_Gr[Gr1->nb_etats_Gr] = Init_etat_AF_min(AF, AF->numeros_etats_terminaux[j]);
        Gr1->nb_etats_Gr++;
    }

    printf("\nGroupe %s : Numeros des etats non terminaux :", Gr2->name_Gr);
    fprintf(Fichier_trace, "\nGroupe %s : Numeros des etats non terminaux :",  Gr2->name_Gr);
    for (int k = 0; k < AF->nb_etats; k++){

        int Etat_Ninit = 0; int l = 0;
        while (l < AF->nb_etats_terminaux && Etat_Ninit != 1){
            if(AF->numeros_etats[k] == AF->numeros_etats_terminaux[l])
                Etat_Ninit = 1;
            l++;
        }

        if (Etat_Ninit != 1){
            printf(" %d",AF->numeros_etats[k]);
            fprintf(Fichier_trace, " %d", AF->numeros_etats[k]);
            Gr2->etats_Gr[Gr2->nb_etats_Gr] = Init_etat_AF_min(AF, AF->numeros_etats[k]);
            Gr2->nb_etats_Gr++;
        }
    }

    list_AF* Liste_Gr = Init_List_Gr();
    Liste_Gr->list_Gr[0] = Gr1;
    Liste_Gr->len_list_gr_minim++;
    Liste_Gr->list_Gr[Liste_Gr->len_list_gr_minim] = Gr2;
    Liste_Gr->len_list_gr_minim++;

    Aff_Pres_part(num_part, Fichier_trace);

    int Creation_gr = 1;
    do{
        num_part++;
        Liste_Gr = Partition(Liste_Gr, num_part, &Creation_gr); // le liste_gr à gauche est l'"ancien". AF au cas ou
        Aff_res_part(Liste_Gr, Fichier_trace);
        Aff_Pres_part(num_part, Fichier_trace);
    } while (Creation_gr == 1); // Partition exécutée tant que groupe crée

    Etat_AF_minim ** List_etat_AFminim = Elimination_doublons(Liste_Gr);
    Etat_AF_in_AF(AF, List_etat_AFminim); // Attribution des etats_af de l'automate minimisé dans AF
}

// --------------------------------------------------
// FONCTION Réalisant une partition à partir d'une liste de groupes d'états
list_AF * Partition(list_AF* List_Gr, int num_part, int * Creation_gr){

    // 1ere etape : parcours des automates de chaque groupe et association d'un groupe à leurs états d'arrivée.
    // Attention : pas de création de groupe à ce moment

    // On parcours tous les groupes
    for (int id_Gr = 0; id_Gr<List_Gr->len_list_gr_minim ; id_Gr++){
        gr_minim* Groupe = List_Gr->list_Gr[id_Gr];

        // On parcours tous les etats de chaque groupe
        for(int Nbetat_Gr = 0; Nbetat_Gr<Groupe->nb_etats_Gr ; Nbetat_Gr++){
            Etat_AF_minim* Etat_etudie = Groupe->etats_Gr[Nbetat_Gr];

            // On parcours tous les etats d'arrivée de chaque état du groupe
            for (int nb_Etat_ar=0; nb_Etat_ar < Etat_etudie->Etat_AF->nb_etats_arrivee; nb_Etat_ar++){
                // On obtient le numéro du groupe de l'etat d'arrivée. Si le numéro existe, le tableau des groupes de
                // l'etat prend le groupe. Sinon, on crée un nouveau groupe, que prend l'etat.

                // Creation d'un état factice pour la reccherche
                Etat_AF * Etat_ar = malloc(sizeof(Etat_AF));
                Etat_ar->num_etat_depart = Etat_etudie->Etat_AF->etats_arrivee[nb_Etat_ar];

                gr_minim* gr_etat_arr = find_Gr(Etat_ar, List_Gr);
                if (gr_etat_arr == NULL) {
                    printf("Erreur : pas de groupe attribué");
                    exit(EXIT_FAILURE);
                }
                else {
                    Etat_etudie->list_gr_minim[Etat_etudie->len_list_gr_minim] = gr_etat_arr->name_Gr;
                    Etat_etudie->len_list_gr_minim++;
                }
            }
        }
    }



    // 2e etape : répartition dans un groupe des états de départ en fonction des groupes des etats d'arrivées
    list_AF* List_new_gr = Init_List_Gr(); // stocke la liste des nouveaux groupes
    int id_new_gr = 0;

    // On parcours tous les groupes
    for (int id_Gr = 0; id_Gr<List_Gr->len_list_gr_minim ; id_Gr++){
        gr_minim* Groupe = List_Gr->list_Gr[id_Gr];

        // On parcours tous les etats de chaque groupe
        for(int Nbetat_Gr = 0; Nbetat_Gr<Groupe->nb_etats_Gr ; Nbetat_Gr++){
            Etat_AF_minim* Etat_etudie = Groupe->etats_Gr[Nbetat_Gr];
            // On connait le groupe initial de l'etat de départ, mais on l'attribue maintenant à un nouveau groupe.

            // Comparaison des motifs de l'etat étudiée avec ceux des etats de son groupe (motifs = tableau Gr_minim*):
            // Fonction retourne le (nouveau) groupe auquel appartient l'etat ou null en fonction des motifs de transitions
            gr_minim* new_Gr_corr = Verif_motifs(Etat_etudie, Groupe, List_new_gr);

            // Si l'état n'est pas dans un des nouveau groupes, on en crée 1.
                if (new_Gr_corr == NULL){ // && Groupe->nb_etats_Gr > 1
                    gr_minim* nouv_Gr = Init_Gr(num_part, id_new_gr);
                    id_new_gr++;
                    // Ajout du nouvel etat dans le groupe
                    nouv_Gr->etats_Gr[0] = Etat_etudie;
                    nouv_Gr->nb_etats_Gr++;

                    List_new_gr->list_Gr[List_new_gr->len_list_gr_minim] = (nouv_Gr);
                    List_new_gr->len_list_gr_minim++;
                    if (Groupe->nb_etats_Gr > 1)
                        *Creation_gr = 1;
                }
                else if (new_Gr_corr != NULL){
                    // Ajout d'Etat_etudié dans new_Gr_corr->etats_Gr
                    new_Gr_corr->etats_Gr[new_Gr_corr->nb_etats_Gr] = Etat_etudie;
                    new_Gr_corr->nb_etats_Gr++;
                }
            }
        }

    // 3e etape : on compare les 2 listes obtenues pour vérifier si on obtient une partition identique
    // On parcours tous les groupes
    if (List_Gr->len_list_gr_minim == List_new_gr->len_list_gr_minim){
        for (int id_Gr = 0; id_Gr<List_Gr->len_list_gr_minim ; id_Gr++){
            gr_minim* Groupe = List_Gr->list_Gr[id_Gr];
            gr_minim* Groupe_new = List_new_gr->list_Gr[id_Gr];

            // On parcours tous les etats de chaque groupe
            if(Groupe->nb_etats_Gr == Groupe_new->nb_etats_Gr){ // Vérification aussi que les groupes ont la même taille
                for(int Nbetat_Gr = 0; Nbetat_Gr<Groupe->nb_etats_Gr ; Nbetat_Gr++){
                    Etat_AF_minim* Etat_etudie = Groupe->etats_Gr[Nbetat_Gr];
                    Etat_AF_minim* Etat_new = Groupe_new->etats_Gr[Nbetat_Gr];
                    // Si les états sont différents, retour de la nouvelle liste uniquement, sinon supposition que pas
                    // de nouveau groupe crée
                    if(Str_comp(Etat_etudie->Etat_AF->num_etat_depart, Etat_new->Etat_AF->num_etat_depart) == 0)
                        return List_new_gr;
                    else
                        *Creation_gr = 0;
                }
            }
            else
                return List_new_gr;
        }
    }
    return List_new_gr;

}

//
// Created by ethan on 15/05/2022.
//


