#include "determinisation_completion.h"

bool est_un_automate_asynchrone(Automate* AF, const char* nom_fichier_trace_execution){

    FILE* fichier = NULL;

    // Ouverture du fichier en mode "aw" mode (ajout à la fin du fichier)
    fichier = fopen(nom_fichier_trace_execution, "a");

    int i = 0;


    if (fichier != NULL){

        for (i = 0; i < AF->nb_transitions; i++){

            if (AF->symboles[i] == '*'){

                printf("L'automate contient au moins une transition epsilon : %d%c%d\n", AF->etats_depart[i], AF->symboles[i], AF->etats_arrivee[i]);
                fprintf(fichier, "\nL'automate contient au moins une transition epsilon : %d%c%d\n", AF->etats_depart[i], AF->symboles[i], AF->etats_arrivee[i]);

                printf("L'automate est asynchrone.\n");
                fprintf(fichier, "L'automate est asynchrone.\n");

                // Fermeture du fichier
                fclose(fichier);

                return true;

            }

        }

    }

    else{

        printf("Impossible d'ouvrir le fichier %s\n", nom_fichier_trace_execution);
        exit(EXIT_FAILURE);

    }


    return false;

}

void elimination_epsilon(Automate* AF, const char* nom_fichier_trace_execution, int numero){

    FILE* fichier = NULL;

    // Ouverture du fichier en mode "a" mode (ajout à la fin du fichier)
    fichier = fopen(nom_fichier_trace_execution, "a");

    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int numero_etat[BUFSIZ] = {0};
    int etat_initial_transition_epsilon[BUFSIZ] = {0};
    int etat_final_transition_epsilon[BUFSIZ] = {0};
    int compteur1 = 0; // Nombre de transitions epsilon
    int epsilon_clotures_utilisees[BUFSIZ] = {0};
    int taille = 0;

    // Déterminer et afficher les epsilon clotures

    if (fichier != NULL){

        printf("Epsilon clotures\n\n");
        fprintf(fichier, "\nEpsilon clotures\n\n");

        for (i = 0; i < AF->nb_etats; i++){

            numero_etat[i] = AF->numeros_etats[i];

        }

        for (j = 0; j < AF->nb_transitions; j++){

            if (AF->symboles[j] == '*'){

                etat_initial_transition_epsilon[m] = AF->etats_depart[j];
                etat_final_transition_epsilon[m] = AF->etats_arrivee[j];

                m++;
                compteur1++;
            }
        }

        for (k = 0; k < AF->nb_etats; k++){

            printf("%d' = %d ", AF->numeros_etats[k], numero_etat[k]);
            fprintf(fichier, "%d' = %d ", AF->numeros_etats[k], numero_etat[k]);

            for (m = 0; m < compteur1; m++){

                if (etat_initial_transition_epsilon[m] == numero_etat[k]){

                    printf("%d ", etat_final_transition_epsilon[m]);
                    fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);
                }
            }

            printf("\n");
            fprintf(fichier, "\n");

        }

        // Déterminer les epsilon clotures utilisees

        for (i = 0, j = 0; i < AF->nb_transitions; i++){

            if(AF->symboles[i] != '*'){

                epsilon_clotures_utilisees[j] = AF->etats_arrivee[i];
                j++;

            }

        }

        // Suppression des epsilons clotures dupliques
        for (i = 0; i < AF->nb_transitions; i++){

            for (j = i + 1; j < AF->nb_transitions;){

                if (epsilon_clotures_utilisees[j] == epsilon_clotures_utilisees[i]){

                    for (k = j; k < AF->nb_transitions; k++){

                        epsilon_clotures_utilisees[k] = epsilon_clotures_utilisees[k+1];

                    }

                    AF->nb_transitions--;

                }

                else{

                    j++;
                }
            }

            taille++;

        }

        printf("\nEpsilons clotures utilisees : ");
        fprintf(fichier, "\nEpsilons clotures utilisees : ");

        for (i = 0; i < taille; i++){

            printf("%d' ", epsilon_clotures_utilisees[i]);
            fprintf(fichier, "%d' ", epsilon_clotures_utilisees[i]);

        }

        // Affichage de l'automate synchrone non deterministe
        printf("\n\nAutomate synchrone non deterministe\n\n");
        fprintf(fichier, "\n\nAutomate synchrone non deterministe\n\n");

        // Automate 31
        if (numero == 31){

            AND_synchrone_31(AF, fichier, etat_initial_transition_epsilon, etat_final_transition_epsilon, numero_etat, compteur1);

        }

        // Automate 32
        else if (numero == 32){

            AND_synchrone_32(AF, fichier, etat_initial_transition_epsilon, etat_final_transition_epsilon, numero_etat, compteur1);

        }

        // Automate 33
        else if (numero == 33){

            AND_synchrone_33(AF, fichier, etat_initial_transition_epsilon, etat_final_transition_epsilon, numero_etat, compteur1);

        }

        // Automate 34
        else if (numero == 34){

            AND_synchrone_34(AF, fichier, etat_initial_transition_epsilon, etat_final_transition_epsilon, numero_etat, compteur1);

        }

        // Automate 35
        else if (numero == 35){

            AND_synchrone_35(AF, fichier, etat_initial_transition_epsilon, etat_final_transition_epsilon, numero_etat, compteur1);

        }

        printf("\n");
        fprintf(fichier, "\n");

         // Fermeture du fichier
        fclose(fichier);
    }

     else{

        printf("Impossible d'ouvrir le fichier %s\n", nom_fichier_trace_execution);
        exit(EXIT_FAILURE);

    }

}

void AND_synchrone_31(Automate* AF, FILE* fichier, int etat_initial_transition_epsilon[], int etat_final_transition_epsilon[], int numero_etat[], int compteur1){

    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int a[BUFSIZ] = {0};
    int b[BUFSIZ] = {0};


    if (fichier != NULL){

        printf("E/S ");
        fprintf(fichier, "E/S ");

        // Cloture de 0'
       for (k = 0; k < 1; k++){

            printf(" %d ", AF->numeros_etats[k]);
            fprintf(fichier, " %d ", AF->numeros_etats[k]);

            for (m = 0; m < compteur1; m++){

                if (etat_initial_transition_epsilon[m] == numero_etat[k]){

                    printf("%d ", etat_final_transition_epsilon[m]);
                    fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);
                }
            }
        }

        printf("\n");
        fprintf(fichier, "\n");
       for (i = 0, j = 0; i < BUFSIZ; i++){

            for (k = 0; k < 4 ; k++){


                if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                        if (AF->symboles[i] == 'a'){

                            a[j] = AF->etats_arrivee[i];
                            printf("\ta : %d\n", a[j]);
                            fprintf(fichier, "\ta : %d\n", a[j]);
                            j++;


                        }


                        else if (AF->symboles[i] == 'b'){

                            b[j] = AF->etats_arrivee[i];
                            printf("\t\tb : %d\n", b[j]);
                            fprintf(fichier, "\t\tb : %d\n", b[j]);
                            j++;

                        }

                 }

            }
       }

        printf("\n____________________________\n\n");
        fprintf(fichier, "\n____________________________\n\n");

        // Cloture de 1'

        printf("S ");

        for (k = 0; k < 1; k++){

            printf(" %d ", AF->numeros_etats[1]);
            fprintf(fichier, " %d ", AF->numeros_etats[1]);

            for (m = 0; m < compteur1; m++){

                if (etat_initial_transition_epsilon[m] == numero_etat[1]){

                    printf("%d ", etat_final_transition_epsilon[m]);
                    fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

                }
            }
        }

       printf("\n");
       fprintf(fichier, "\n");

       for (i = 0, j = 0; i < BUFSIZ; i++){

            for (k = 4; k < 5 ; k++){

                if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                        if (AF->symboles[i] == 'a'){

                            a[j] = AF->etats_arrivee[i];
                            printf("\ta : %d\n", a[j]);
                            fprintf(fichier, "\ta : %d\n", a[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'b'){

                            b[j] = AF->etats_arrivee[i];
                            printf("\t\tb : %d\n", b[j]);
                            fprintf(fichier, "\t\tb : %d\n", b[j]);
                            j++;

                        }

                 }

                 else if (numero_etat[1] == AF->etats_depart[i]){

                        if (AF->symboles[i] == 'a'){

                            a[j] = AF->etats_arrivee[i];
                            printf("\ta : %d\n", a[j]);
                            fprintf(fichier, "\ta : %d\n", a[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'b'){

                            b[j] = AF->etats_arrivee[i];
                            printf("\t\tb : %d\n", b[j]);
                            fprintf(fichier, "\t\tb : %d\n", b[j]);
                            j++;

                        }

                 }

            }
       }

       printf("\n____________________________\n\n");
       fprintf(fichier, "\n____________________________\n\n");

       // Cloture de 2'

        for (k = 0; k < 1; k++){

            printf("\n%d ", AF->numeros_etats[2]);
            fprintf(fichier, "\n%d ", AF->numeros_etats[2]);

            for (m = 0; m < compteur1; m++){

                if (etat_initial_transition_epsilon[m] == numero_etat[2]){

                    printf("%d ", etat_final_transition_epsilon[m]);
                    fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

                }
            }
        }

       printf("\n");
       fprintf(fichier, "\n");

       for (i = 0, j = 0; i < BUFSIZ; i++){

            for (k = numero_etat[2]; k < 3 ; k++){

                if (numero_etat[2] == AF->etats_depart[i]){

                        if (AF->symboles[i] == 'a'){

                            a[j] = AF->etats_arrivee[i];
                            printf("\ta : %d\n", a[j]);
                            fprintf(fichier, "\ta : %d\n", a[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'b'){

                            b[j] = AF->etats_arrivee[i];
                            printf("\t\tb : %d\n", b[j]);
                            fprintf(fichier, "\t\tb : %d\n", b[j]);
                            j++;

                        }

                 }

            }
       }

       printf("\n____________________________\n\n");
       fprintf(fichier, "\n____________________________\n\n");

       // Cloture de 3'

       printf("S ");
       fprintf(fichier, "S ");

       for (k = 0; k < 1; k++){

            printf(" %d ", AF->numeros_etats[3]);
            fprintf(fichier, " %d ", AF->numeros_etats[3]);

            for (m = 0; m < compteur1; m++){

                if (etat_initial_transition_epsilon[m] == numero_etat[3]){

                    printf("%d ", etat_final_transition_epsilon[m]);
                    fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

                }
            }
        }

        printf("\n");
        fprintf(fichier, "\n");

       for (i = 0, j = 0; i < BUFSIZ; i++){

            for (k = numero_etat[3]; k < 4 ; k++){

                if (numero_etat[3] == AF->etats_depart[i]){

                        if (AF->symboles[i] == 'a'){

                            a[j] = AF->etats_arrivee[i];
                            printf("\ta : %d\n", a[j]);
                            fprintf(fichier, "\ta : %d\n", a[j]);
                            j++;


                        }


                        else if (AF->symboles[i] == 'b'){

                            b[j] = AF->etats_arrivee[i];
                            printf("\t\tb : %d\n", b[j]);
                            fprintf(fichier, "\t\tb : %d\n", b[j]);
                            j++;

                        }

                 }

            }
       }

        printf("\n____________________________\n\n");
        fprintf(fichier, "\n____________________________\n\n");

        // Cloture de 5'

        for (k = 0; k < 1; k++){

            printf("\n%d ", AF->numeros_etats[5]);
            fprintf(fichier, "\n%d ", AF->numeros_etats[5]);

            for (m = 0; m < compteur1; m++){

                if (etat_initial_transition_epsilon[m] == numero_etat[5]){

                    printf("%d ", etat_final_transition_epsilon[m]);
                    fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

                }
            }
        }

       printf("\n");
       fprintf(fichier, "\n");

       for (i = 0, j = 0; i < BUFSIZ; i++){

            for (k = numero_etat[5]; k < 6 ; k++){

                if (numero_etat[5] == AF->etats_depart[i]){

                        if (AF->symboles[i] == 'a'){

                            a[j] = AF->etats_arrivee[i];
                            printf("\ta : %d\n", a[j]);
                            fprintf(fichier, "\ta : %d\n", a[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'b'){

                            b[j] = AF->etats_arrivee[i];
                            printf("\t\tb : %d\n", b[j]);
                            fprintf(fichier, "\t\tb : %d\n", b[j]);
                            j++;

                        }

                 }

            }
       }

        printf("\n____________________________\n\n");
        fprintf(fichier, "\n____________________________\n\n");

        // Cloture de 6'

       printf("S ");
       fprintf(fichier, "S ");


       for (k = 0; k < 1; k++){

            printf(" %d ", AF->numeros_etats[6]);
            fprintf(fichier, " %d ", AF->numeros_etats[6]);

            for (m = 0; m < compteur1; m++){

                if (etat_initial_transition_epsilon[m] == numero_etat[6]){

                    printf("%d ", etat_final_transition_epsilon[m]);
                    fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);
                }
            }
        }

        printf("\n");
        fprintf(fichier, "\n");
       for (i = 0, j = 0; i < BUFSIZ; i++){

            for (k = 7; k < 9; k++){


                if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                        if (AF->symboles[i] == 'a'){

                            a[j] = AF->etats_arrivee[i];
                            printf("\ta : %d\n", a[j]);
                            fprintf(fichier, "\ta : %d\n", a[j]);
                            j++;


                        }


                        else if (AF->symboles[i] == 'b'){

                            b[j] = AF->etats_arrivee[i];
                            printf("\t\tb : %d\n", b[j]);
                            fprintf(fichier, "\t\tb : %d\n", b[j]);
                            j++;

                        }

                 }

            }
       }

        printf("\n____________________________\n\n");
        fprintf(fichier, "\n____________________________\n\n");

    }
}

void AND_synchrone_32(Automate* AF, FILE* fichier, int etat_initial_transition_epsilon[], int etat_final_transition_epsilon[], int numero_etat[], int compteur1){

    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int a[BUFSIZ] = {0};
    int b[BUFSIZ] = {0};
    int c[BUFSIZ] = {0};

        // Cloture de 0'

       printf("E/S ");
       fprintf(fichier, "E/S ");

       for (k = 0; k < 1; k++){

            printf(" %d ", AF->numeros_etats[k]);
            fprintf(fichier, " %d ", AF->numeros_etats[k]);

            for (m = 0; m < compteur1; m++){

                if (etat_initial_transition_epsilon[m] == numero_etat[k]){

                    printf("%d ", etat_final_transition_epsilon[m]);
                    fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

                }
            }
        }

       printf("\n");
       fprintf(fichier, "\n");

       for (i = 0, j = 0; i < BUFSIZ; i++){

            for (k = 0; k < 15; k++){


                if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                        if (AF->symboles[i] == 'a'){

                            a[j] = AF->etats_arrivee[i];
                            printf("\ta : %d\n", a[j]);
                            fprintf(fichier, "\ta : %d\n", a[j]);
                            j++;


                        }

                        else if (AF->symboles[i] == 'b'){

                            b[j] = AF->etats_arrivee[i];
                            printf("\t\tb : %d\n", b[j]);
                            fprintf(fichier, "\t\tb : %d\n", b[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'c'){

                            c[j] = AF->etats_arrivee[i];
                            printf("\t\t\tc : %d\n", c[j]);
                            fprintf(fichier, "\t\t\tc : %d\n", c[j]);
                            j++;

                        }

                 }

            }
       }

        printf("\n____________________________\n\n");
        fprintf(fichier, "\n____________________________\n\n");

        // Cloture de 4'
        for (k = 0; k < 1; k++){

            printf("\n%d ", AF->numeros_etats[4]);
            fprintf(fichier, "\n%d ", AF->numeros_etats[4]);

            for (m = 0; m < compteur1; m++){

                if (etat_initial_transition_epsilon[m] == numero_etat[4]){

                    printf("%d ", etat_final_transition_epsilon[m]);
                    fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

                }
            }
        }

       printf("\n");
       fprintf(fichier, "\n");

       for (i = 0, j = 0; i < BUFSIZ; i++){

            for (k = 23; k < 26 ; k++){

                if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                        if (AF->symboles[i] == 'a'){

                            a[j] = AF->etats_arrivee[i];
                            printf("\ta : %d\n", a[j]);
                            fprintf(fichier, "\ta : %d\n", a[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'b'){

                            b[j] = AF->etats_arrivee[i];
                            printf("\t\tb : %d\n", b[j]);
                            fprintf(fichier, "\t\tb : %d\n", b[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'c'){

                            c[j] = AF->etats_arrivee[i];
                            printf("\t\t\tc : %d\n", c[j]);
                            fprintf(fichier, "\t\t\tc : %d\n", c[j]);
                            j++;

                        }

                 }

            }
       }

       printf("\n____________________________\n\n");
       fprintf(fichier, "\n____________________________\n\n");

       // Cloture de 7'
        for (k = 0; k < 1; k++){

            printf("\n%d ", AF->numeros_etats[7]);
            fprintf(fichier, "\n%d ", AF->numeros_etats[7]);

            for (m = 0; m < compteur1; m++){

                if (etat_initial_transition_epsilon[m] == numero_etat[7]){

                    printf("%d ", etat_final_transition_epsilon[m]);
                    fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

                }
            }
        }

       printf("\n");
       fprintf(fichier, "\n");

       for (i = 0, j = 0; i < BUFSIZ; i++){

            for (k = 27; k < 28 ; k++){

                if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                        if (AF->symboles[i] == 'a'){

                            a[j] = AF->etats_arrivee[i];
                            printf("\ta : %d\n", a[j]);
                            fprintf(fichier, "\ta : %d\n", a[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'b'){

                            b[j] = AF->etats_arrivee[i];
                            printf("\t\tb : %d\n", b[j]);
                            fprintf(fichier, "\t\tb : %d\n", b[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'c'){

                            c[j] = AF->etats_arrivee[i];
                            printf("\t\t\tc : %d\n", c[j]);
                            fprintf(fichier, "\t\t\tc : %d\n", c[j]);
                            j++;

                        }

                 }


            }
       }

       printf("\n____________________________\n\n");
       fprintf(fichier, "\n____________________________\n\n");

        // Cloture de 9'

        printf("S ");
        fprintf(fichier, "S ");

        for (k = 0; k < 1; k++){

            printf(" %d ", AF->numeros_etats[9]);
            fprintf(fichier, " %d ", AF->numeros_etats[9]);

            for (m = 0; m < compteur1; m++){

                if (etat_initial_transition_epsilon[m] == numero_etat[9]){

                    printf("%d ", etat_final_transition_epsilon[m]);
                    fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

                }
            }
        }

       printf("\n");
       fprintf(fichier, "\n");

       for (i = 0, j = 0; i < BUFSIZ; i++){

            for (k = 28; k < 29 ; k++){

                if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                        if (AF->symboles[i] == 'a'){

                            a[j] = AF->etats_arrivee[i];
                            printf("\ta : %d\n", a[j]);
                            fprintf(fichier, "\ta : %d\n", a[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'b'){

                            b[j] = AF->etats_arrivee[i];
                            printf("\t\tb : %d\n", b[j]);
                            fprintf(fichier, "\t\tb : %d\n", b[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'c'){

                            c[j] = AF->etats_arrivee[i];
                            printf("\t\t\tc : %d\n", c[j]);
                            fprintf(fichier, "\t\t\tc : %d\n", c[j]);
                            j++;

                        }

                 }

            }
       }

       printf("\n____________________________\n\n");
       fprintf(fichier, "\n____________________________\n\n");

       // Cloture de 13'

        printf("S ");
        fprintf(fichier, "S ");

        for (k = 0; k < 1; k++){

            printf(" %d ", AF->numeros_etats[13]);
            fprintf(fichier, " %d ", AF->numeros_etats[13]);

            for (m = 0; m < compteur1; m++){

                if (etat_initial_transition_epsilon[m] == numero_etat[13]){

                    printf("%d ", etat_final_transition_epsilon[m]);
                    fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

                }
            }
        }

       printf("\n");
       fprintf(fichier, "\n");

       for (i = 0, j = 0; i < BUFSIZ; i++){

            for (k = 43; k < 49; k++){

                if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                        if (AF->symboles[i] == 'a'){

                            a[j] = AF->etats_arrivee[i];
                            printf("\ta : %d\n", a[j]);
                            fprintf(fichier, "\ta : %d\n", a[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'b'){

                            b[j] = AF->etats_arrivee[i];
                            printf("\t\tb : %d\n", b[j]);
                            fprintf(fichier, "\t\tb : %d\n", b[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'c'){

                            c[j] = AF->etats_arrivee[i];
                            printf("\t\t\tc : %d\n", c[j]);
                            fprintf(fichier, "\t\t\tc : %d\n", c[j]);
                            j++;

                        }

                 }


            }
       }

       printf("\n____________________________\n\n");
       fprintf(fichier, "\n____________________________\n\n");

       // Cloture de 16'

        printf("S ");
        fprintf(fichier, "S ");

        for (k = 0; k < 1; k++){

            printf(" %d ", AF->numeros_etats[16]);
            fprintf(fichier, " %d ", AF->numeros_etats[16]);

            for (m = 0; m < compteur1; m++){

                if (etat_initial_transition_epsilon[m] == numero_etat[16]){

                    printf("%d ", etat_final_transition_epsilon[m]);
                    fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);
                }
            }
        }

       printf("\n");
       fprintf(fichier, "\n");

       for (i = 0, j = 0; i < BUFSIZ; i++){

            for (k = 53; k < 57 ; k++){

                if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                        if (AF->symboles[i] == 'a'){

                            a[j] = AF->etats_arrivee[i];
                            printf("\ta : %d\n", a[j]);
                            fprintf(fichier, "\ta : %d\n", a[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'b'){

                            b[j] = AF->etats_arrivee[i];
                            printf("\t\tb : %d\n", b[j]);
                            fprintf(fichier, "\t\tb : %d\n", b[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'c'){

                            c[j] = AF->etats_arrivee[i];
                            printf("\t\t\tc : %d\n", c[j]);
                            fprintf(fichier, "\t\t\tc : %d\n", c[j]);
                            j++;

                        }

                 }

            }
       }

       printf("\n____________________________\n\n");
       fprintf(fichier, "\n____________________________\n\n");

         // Cloture de 19'

        printf("S ");
        fprintf(fichier, "S ");

        for (k = 0; k < 1; k++){

            printf(" %d ", AF->numeros_etats[19]);
            fprintf(fichier, " %d ", AF->numeros_etats[19]);

            for (m = 0; m < compteur1; m++){

                if (etat_initial_transition_epsilon[m] == numero_etat[19]){

                    printf("%d ", etat_final_transition_epsilon[m]);
                    fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

                }
            }
        }

       printf("\n");
       fprintf(fichier, "\n");

       for (i = 0, j = 0; i < BUFSIZ; i++){

            for (k = 60; k < 63; k++){

             if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                        if (AF->symboles[i] == 'a'){

                            a[j] = AF->etats_arrivee[i];
                            printf("\ta : %d\n", a[j]);
                            fprintf(fichier, "\ta : %d\n", a[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'b'){

                            b[j] = AF->etats_arrivee[i];
                            printf("\t\tb : %d\n", b[j]);
                            fprintf(fichier, "\t\tb : %d\n", b[j]);
                            j++;

                        }

                        else if (AF->symboles[i] == 'c'){

                            c[j] = AF->etats_arrivee[i];
                            printf("\t\t\tc : %d\n", c[j]);
                            fprintf(fichier, "\t\t\tc : %d\n", c[j]);
                            j++;

                        }

                 }



            }
       }

       printf("\n____________________________\n\n");
       fprintf(fichier, "\n____________________________\n\n");

}

void AND_synchrone_33(Automate* AF, FILE* fichier, int etat_initial_transition_epsilon[], int etat_final_transition_epsilon[], int numero_etat[], int compteur1){

    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int a[BUFSIZ] = {0};
    int b[BUFSIZ] = {0};
    int c[BUFSIZ] = {0};

   // Cloture de 0'

   printf("E/S ");
   fprintf(fichier, "E/S ");

   for (k = 0; k < 1; k++){

        printf(" %d ", AF->numeros_etats[k]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[k]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

            }
        }
    }

   printf("\n");
   fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = 0; k < 9; k++){

            if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;


                    }

                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'c'){

                        c[j] = AF->etats_arrivee[i];
                        printf("\t\t\tc : %d\n", c[j]);
                        fprintf(fichier, "\t\t\tc : %d\n", c[j]);
                        j++;

                    }

             }

        }
   }

    printf("\n____________________________\n\n");
    fprintf(fichier, "\n____________________________\n\n");

    // Cloture de 3'
    for (k = 0; k < 1; k++){

        printf("\n%d ", AF->numeros_etats[3]);
        fprintf(fichier, "\n%d ", AF->numeros_etats[3]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[3]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

            }
        }
    }

   printf("\n");
   fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = 12; k < 13 ; k++){

            if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'c'){

                        c[j] = AF->etats_arrivee[i];
                        printf("\t\t\tc : %d\n", c[j]);
                        fprintf(fichier, "\t\t\tc : %d\n", c[j]);
                        j++;

                    }

             }

        }
   }

   printf("\n____________________________\n\n");
   fprintf(fichier, "\n____________________________\n\n");

   // Cloture de 4'
    for (k = 0; k < 1; k++){

        printf("\n%d ", AF->numeros_etats[4]);
        fprintf(fichier, "\n%d ", AF->numeros_etats[4]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[4]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

            }
        }
    }

   printf("\n");
   fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = 13; k < 14 ; k++){

            if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'c'){

                        c[j] = AF->etats_arrivee[i];
                        printf("\t\t\tc : %d\n", c[j]);
                        fprintf(fichier, "\t\t\tc : %d\n", c[j]);
                        j++;

                    }

             }

             else if (numero_etat[4] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'c'){

                        c[j] = AF->etats_arrivee[i];
                        printf("\t\t\tc : %d\n", c[j]);
                        fprintf(fichier, "\t\t\tc : %d\n", c[j]);
                        j++;

                    }

             }

        }
   }

   printf("\n____________________________\n\n");
   fprintf(fichier, "\n____________________________\n\n");

    // Cloture de 6'

    printf("S ");
    fprintf(fichier, "S ");

    for (k = 0; k < 1; k++){

        printf(" %d ", AF->numeros_etats[6]);
        fprintf(fichier, " %d ", AF->numeros_etats[6]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[6]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

            }
        }
    }

   printf("\n");
   fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = 14; k < 15 ; k++){

            if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'c'){

                        c[j] = AF->etats_arrivee[i];
                        printf("\t\t\tc : %d\n", c[j]);
                        fprintf(fichier, "\t\t\tc : %d\n", c[j]);
                        j++;

                    }

             }

        }
   }

   printf("\n____________________________\n\n");
   fprintf(fichier, "\n____________________________\n\n");

   // Cloture de 8'

   printf("S ");
   fprintf(fichier, "S ");

    for (k = 0; k < 1; k++){

        printf(" %d ", AF->numeros_etats[8]);
        fprintf(fichier, " %d ", AF->numeros_etats[8]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[8]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

            }
        }
    }

   printf("\n");
   fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = 19; k < 20 ; k++){

            if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'c'){

                        c[j] = AF->etats_arrivee[i];
                        printf("\t\t\tc : %d\n", c[j]);
                        fprintf(fichier, "\t\t\tc : %d\n", c[j]);
                        j++;

                    }

             }

             else if (numero_etat[8] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'c'){

                        c[j] = AF->etats_arrivee[i];
                        printf("\t\t\tc : %d\n", c[j]);
                        fprintf(fichier, "\t\t\tc : %d\n", c[j]);
                        j++;

                    }

             }

        }
   }

   printf("\n____________________________\n\n");
   fprintf(fichier, "\n____________________________\n\n");

   // Cloture de 10'

   printf("S ");
   fprintf(fichier, "S ");

    for (k = 0; k < 1; k++){

        printf(" %d ", AF->numeros_etats[10]);
        fprintf(fichier, " %d ", AF->numeros_etats[10]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[10]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

            }
        }
    }

   printf("\n");
   fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = 21; k < 23 ; k++){

            if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'c'){

                        c[j] = AF->etats_arrivee[i];
                        printf("\t\t\tc : %d\n", c[j]);
                        fprintf(fichier, "\t\t\tc : %d\n", c[j]);
                        j++;

                    }

             }

        }
   }

   printf("\n____________________________\n\n");
   fprintf(fichier, "\n____________________________\n\n");

     // Cloture de 11'

     printf("S ");
     fprintf(fichier, "S ");

    for (k = 0; k < 1; k++){

        printf(" %d ", AF->numeros_etats[11]);
        fprintf(fichier, " %d ", AF->numeros_etats[11]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[11]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier,"%d ", etat_final_transition_epsilon[m]);

            }
        }
    }

   printf("\n");
   fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = 23; k < 24 ; k++){

             if (numero_etat[11] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'c'){

                        c[j] = AF->etats_arrivee[i];
                        printf("\t\t\tc : %d\n", c[j]);
                        fprintf(fichier, "\t\t\tc : %d\n", c[j]);
                        j++;

                    }

             }

        }
   }

   printf("\n____________________________\n\n");
   fprintf(fichier, "\n____________________________\n\n");

}

void AND_synchrone_34(Automate* AF, FILE* fichier, int etat_initial_transition_epsilon[], int etat_final_transition_epsilon[], int numero_etat[], int compteur1){

    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int a[BUFSIZ] = {0};
    int b[BUFSIZ] = {0};

    // Cloture de 0'

    printf("E ");
    fprintf(fichier, "E ");

   for (k = 0; k < 1; k++){

        printf(" %d ", AF->numeros_etats[k]);
        fprintf(fichier, " %d ", AF->numeros_etats[k]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[k]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

            }
        }
    }

    printf("\n");
    fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = 0; k < 3 ; k++){


            if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;


                    }


                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

             }

        }
   }

    printf("\n____________________________\n\n");
    fprintf(fichier, "\n____________________________\n\n");

    // Cloture de 2'
    for (k = 0; k < 1; k++){

        printf("\n%d ", AF->numeros_etats[2]);
        fprintf(fichier, "\n%d ", AF->numeros_etats[2]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[2]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

            }
        }
    }

   printf("\n");
   fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = numero_etat[2]; k < 3 ; k++){

             if(numero_etat[k] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;


                    }


                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }


             }


        }
   }

    printf("\n____________________________\n\n");
    fprintf(fichier, "\n____________________________\n\n");

   // Cloture de 3'

   printf("S ");
   fprintf(fichier, "S ");

   for (k = 0; k < 1; k++){

        printf(" %d ", AF->numeros_etats[3]);
        fprintf(fichier, " %d ", AF->numeros_etats[3]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[3]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

            }
        }
    }

    printf("\n");
    fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = 4; k < 6 ; k++){


            if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;


                    }


                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

             }

        }
   }

    printf("\n____________________________\n\n");
    fprintf(fichier, "\n____________________________\n\n");

    // Cloture de 5'

   printf("S ");
   fprintf(fichier, "S ");

   for (k = 0; k < 1; k++){

        printf(" %d ", AF->numeros_etats[5]);
        fprintf(fichier, " %d ", AF->numeros_etats[5]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[5]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

            }
        }
    }

    printf("\n");
    fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = 6; k < 8; k++){


            if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;


                    }


                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

             }

        }
   }

    printf("\n____________________________\n\n");
    fprintf(fichier, "\n____________________________\n\n");

}

void AND_synchrone_35(Automate* AF, FILE* fichier, int etat_initial_transition_epsilon[], int etat_final_transition_epsilon[], int numero_etat[], int compteur1){

    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int a[BUFSIZ] = {0};
    int b[BUFSIZ] = {0};

    // Cloture de 0'

    printf("E ");
    fprintf(fichier, "E ");

   for (k = 0; k < 1; k++){

        printf(" %d ", AF->numeros_etats[k]);
        fprintf(fichier, " %d ", AF->numeros_etats[k]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[k]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

            }
        }
    }

    printf("\n");
    fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = 0; k < 4 ; k++){


            if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;


                    }


                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

             }

        }
   }

    printf("\n____________________________\n\n");
    fprintf(fichier, "\n____________________________\n\n");

    // Cloture de 2'
    for (k = 0; k < 1; k++){

        printf("\n%d ", AF->numeros_etats[2]);
        fprintf(fichier, "\n%d ", AF->numeros_etats[2]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[2]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

            }
        }
    }

   printf("\n");
   fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = numero_etat[2]; k < 3 ; k++){

             if(numero_etat[k] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;


                    }


                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }


             }


        }
   }

    printf("\n____________________________\n\n");
    fprintf(fichier, "\n____________________________\n\n");

   // Cloture de 3'

   printf("S ");
   fprintf(fichier, "S ");

   for (k = 0; k < 1; k++){

        printf(" %d ", AF->numeros_etats[3]);
        fprintf(fichier, " %d ", AF->numeros_etats[3]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[3]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

            }
        }
    }

    printf("\n");
    fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = 4; k < 5 ; k++){


            if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;


                    }


                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

             }

        }
   }

    printf("\n____________________________\n\n");
    fprintf(fichier, "\n____________________________\n\n");

    // Cloture de 6'
    for (k = 0; k < 1; k++){

        printf("\n%d ", AF->numeros_etats[6]);
        fprintf(fichier, "\n%d ", AF->numeros_etats[6]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[6]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

            }
        }
    }

   printf("\n");
   fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = numero_etat[6]; k < 7 ; k++){

             if (numero_etat[6] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;

                    }

                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

             }

        }
   }

   printf("\n____________________________\n\n");
   fprintf(fichier, "\n____________________________\n\n");

   // Cloture de 7'
   for (k = 0; k < 1; k++){

        printf("\n%d ", AF->numeros_etats[7]);
        fprintf(fichier, "\n%d ", AF->numeros_etats[7]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[7]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);
            }
        }
    }

    printf("\n");
    fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = 7; k < 9 ; k++){

            if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;


                    }


                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

             }

        }
   }

    printf("\n____________________________\n\n");
    fprintf(fichier, "\n____________________________\n\n");

    // Cloture de 9'

    printf("S ");
    fprintf(fichier, "S ");

   for (k = 0; k < 1; k++){

        printf(" %d ", AF->numeros_etats[9]);
        fprintf(fichier, " %d ", AF->numeros_etats[9]);

        for (m = 0; m < compteur1; m++){

            if (etat_initial_transition_epsilon[m] == numero_etat[9]){

                printf("%d ", etat_final_transition_epsilon[m]);
                fprintf(fichier, "%d ", etat_final_transition_epsilon[m]);

            }
        }
    }

    printf("\n");
    fprintf(fichier, "\n");

   for (i = 0, j = 0; i < BUFSIZ; i++){

        for (k = 10; k < 11 ; k++){


            if (etat_final_transition_epsilon[k] == AF->etats_depart[i]){

                    if (AF->symboles[i] == 'a'){

                        a[j] = AF->etats_arrivee[i];
                        printf("\ta : %d\n", a[j]);
                        fprintf(fichier, "\ta : %d\n", a[j]);
                        j++;


                    }


                    else if (AF->symboles[i] == 'b'){

                        b[j] = AF->etats_arrivee[i];
                        printf("\t\tb : %d\n", b[j]);
                        fprintf(fichier, "\t\tb : %d\n", b[j]);
                        j++;

                    }

             }

        }
   }

    printf("\n____________________________\n\n");
    fprintf(fichier, "\n____________________________\n\n");

}

bool est_un_automate_deterministe(Automate* AF, const char* nom_fichier_trace_execution){

    FILE* fichier = NULL;

    // Ouverture du fichier en mode "a" (ajout à la fin du fichier)
    fichier = fopen(nom_fichier_trace_execution, "a");

    int courant = 0; // variable de stockage
    char symb_courant = 0; // variable de stockage
    int i = 0;

    if (fichier != NULL){

        //Tester si on a plus d'un état initial => Si > 1 => PAS DETERMINISTE
        if (AF->nb_etats_initiaux > 1){

            printf("L'automate n'est pas deterministe car il y a plus d'un etat initial\n");

            return false;
        }

        else if (AF->nb_etats_initiaux == 1){ // 1 état initial première règle vérifiée

            courant = AF->etats_depart[0];
            symb_courant = AF->symboles[0];

            //Recherche des transitions partant de l'état de départ
            for (i = 1; i < AF->nb_transitions;i++){

                if (AF->etats_depart[i] == courant){

                    if (symb_courant == AF->symboles[i]){

                        printf("L'automate n'est pas deterministe car il y a plus d'une transition libellee par le meme caractere\n");

                        return false;

                    }

                    else{

                        courant = AF->etats_depart[i];
                        symb_courant = AF->symboles[i];

                    }
                }

                courant = AF->etats_depart[i];
                symb_courant = AF->symboles[i];

            }
        }

        printf("L'automate est deterministe\n");

    }

    else{

        printf("Impossible d'ouvrir le fichier %s\n", nom_fichier_trace_execution);
        exit(EXIT_FAILURE);

    }

    return true;
}

bool est_un_automate_complet(Automate* AF, const char* nom_fichier_trace_execution){

    FILE* fichier = NULL;

    // Ouverture du fichier en mode "a" mode (ajout à la fin du fichier)
    fichier = fopen(nom_fichier_trace_execution, "a");

    int x = 1;
    int y = 0;
    int i = 0;
    int j = 0;
    char tab[BUFSIZ];

    if (fichier != NULL){

        if (est_un_automate_deterministe(AF, nom_fichier_trace_execution) == true){

            //Pour qu'il soit complet, il faut que de chaque état sortent toutes les flèches avec toutes les étiquettes possibles.
            while(i <= AF->nb_transitions){

                //Je regarde toutes les transitions partant du même état pour récuperer les symboles de chaque transition
                while(AF->etats_depart[j] == AF->etats_depart[x]){

                    tab[y] = AF->symboles[y];
                    y++;
                    x++;
                }
                i++;

                //Verifier si chaque caractere a une transition avec cet etat de départ
                if(nb_de_symbole_different(tab) != AF->nb_symboles){

                       printf("L'automate n'est pas complet : de chaque etat ne sortent pas toutes les fleches avec toutes les etiquettes possibles\n");
                       fprintf(fichier, "L'automate n'est pas complet : de chaque etat ne sortent pas toutes les fleches avec toutes les etiquettes possibles\n");

                       // Fermeture du fichier
                       fclose(fichier);

                       return false;
                 }
             }

            //BON NOMBRE DE TRANSITION PAR CARACTERE POUR CHAQUE ETAT
            printf("L'automate est complet\n");
            fprintf(fichier, "L'automate est complet\n");


            // Fermeture du fichier
            fclose(fichier);


            return true;
        }

        else{

            printf("PAS COMPLET : L'automate n'est pas deterministe");
            fprintf(fichier, "PAS COMPLET  : L'automate n'est pas deterministe");


            // Fermeture du fichier
            fclose(fichier);


            return false;
        }
    }


     else{

        printf("Impossible d'ouvrir le fichier %s\n", nom_fichier_trace_execution);
        exit(EXIT_FAILURE);

    }

}

int nb_de_symbole_different(char tab[]){

    int i = 0;
    int j = 0;
    int difference = 0;

    for(i = 0, j = 0; tab[i] != '\0'; ++i){

       if(tab[j] != tab[i+1])
           ++difference;
    }

  return difference;

}

void completion(Automate* AF, const char* nom_fichier_trace_execution){

    FILE* fichier = NULL;

    // Ouverture du fichier en mode "a" mode (ajout à la fin du fichier)
    fichier = fopen(nom_fichier_trace_execution, "a");

    int tampon_symbole[BUFSIZ];
    int taille_tab_tampon = 0;
    int memoriser_nb_transition = AF->nb_transitions;
    int compteur_nb_transition_rajoutee = 0;
    int type_symbole[BUFSIZ];
    int tampon_type_symbole[BUFSIZ];
    int nb_transition = AF->nb_transitions;
    int nb_symbole = AF->nb_symboles;
    int tampon_nb_symbole = AF->nb_symboles;
    int symbole = 97; //97 correspond au code ascii de 'a'
    char Poubelle = 80; // 80 correspond au code ascii de 'P'
    int i,j,z,m,n,n1,n2,z1,z2,a,x;

     if (fichier != NULL){

        printf("\nCompletion de l'automate\n\n");
        fprintf(fichier, "\nCompletion de l'automate\n\n");

        for(x = 0; x < nb_symbole; x++)
        {
            tampon_type_symbole[x]=symbole;
            symbole++;
        }

        //L'automate doit être synchrone
        if(est_un_automate_asynchrone(AF, nom_fichier_trace_execution) == 0)
        {

                //Pour chaque état
                for(i = 0; i < AF->nb_etats; i++)
                {
                    symbole = 97;
                    nb_symbole = tampon_nb_symbole;

                    //Lister les différents caracteres dans un tableau symbole
                    for(x = 0; x < nb_symbole; x++)
                    {
                        type_symbole[x] = symbole;
                        symbole++;
                    }
                    taille_tab_tampon = 0;
                    m = 0;

                    //Parcourir les transitions
                    for(j = 0; j < nb_transition; j++)
                    {
                        //Chercher les transitions d'un etat i
                        if(i == AF->etats_depart[j])
                        {
                            //Mettre la transition dans les tableaux tampon de transition
                            tampon_symbole[m] = AF->symboles[j];
                            taille_tab_tampon++;
                            m++;
                        }
                    }

                // Supprimer les transitions ayant le même symbole
                 for (z = 0; z< taille_tab_tampon; z++)
                 {
                    for (z1 = z + 1; z1 < taille_tab_tampon;z1++)
                    {
                        if (tampon_symbole[z1] == tampon_symbole[z])
                        {
                            for (z2 = z1; z2 < taille_tab_tampon; z2++)
                            {
                                tampon_symbole[z2] = tampon_symbole[z2 + 1];
                            }
                            taille_tab_tampon--;
                        }
                        else
                        z1++;
                    }
                }
                //Comparer les symboles du tableau tampon_symbole avec le tableau symbole => Trouver la transiion avec le caractere manquant
                //Supprimer les symboles ayant deja une transitions
                for(n =0; n < taille_tab_tampon; n++)
                {
                    for(n1 = 0; n1 <= nb_symbole;n1++)
                    {
                        if(type_symbole[n1] == tampon_symbole[n])
                        {
                            for(n2 = n1; n2 < nb_symbole;n2++)
                            {
                                type_symbole[n2] = type_symbole[n2+1];
                            }
                            n2--;
                            nb_symbole--;
                        }
                    }
                }

                for(a = 0; a < nb_symbole; a++)
                {
                    AF->etats_depart[AF->nb_transitions] = i;
                    AF->symboles[AF->nb_transitions] = type_symbole[a];
                    AF->etats_arrivee[AF->nb_transitions] = Poubelle;
                    printf("Transition ajoutee : %d%c%c\n",AF->etats_depart[AF->nb_transitions], AF->symboles[AF->nb_transitions], AF->etats_arrivee[AF->nb_transitions]);
                    fprintf(fichier, "Transition ajoutee : %d%c%c\n",AF->etats_depart[AF->nb_transitions], AF->symboles[AF->nb_transitions], AF->etats_arrivee[AF->nb_transitions]);
                    compteur_nb_transition_rajoutee++;
                    AF->nb_transitions++;
                }
                }

                int c;

                //Boucle sur l'etat P
                for(c = 0; c < tampon_nb_symbole; c++)
                {
                    AF->etats_depart[AF->nb_transitions] = Poubelle;
                    AF->symboles[AF->nb_transitions] = tampon_type_symbole[c];
                    AF->etats_arrivee[AF->nb_transitions] = Poubelle;
                    printf("Transition ajoutee : %c%c%c\n",AF->etats_depart[AF->nb_transitions], AF->symboles[AF->nb_transitions], AF->etats_arrivee[AF->nb_transitions]);
                    fprintf(fichier, "Transition ajoutee : %c%c%c\n",AF->etats_depart[AF->nb_transitions], AF->symboles[AF->nb_transitions], AF->etats_arrivee[AF->nb_transitions]);
                    compteur_nb_transition_rajoutee++;
                    AF->nb_transitions++;
                }

                AF->nb_transitions = memoriser_nb_transition +  compteur_nb_transition_rajoutee;

        }

        else
        {
            printf("L'automate n'est pas synchrone");
            fprintf(fichier, "L'automate n'est pas synchrone");
        }

        // Fermeture du fichier
        fclose(fichier);

     }

        else{

        printf("Impossible d'ouvrir le fichier %s\n", nom_fichier_trace_execution);
        exit(EXIT_FAILURE);

    }
}

/*int presence_etat(Automate* AF, char* arrivee){
    int presence=1;
    while ((AF->next!=NULL)&&presence!=0){
        presence=strcmp((AF->etat_d),arrivee);
    }
    return presence;
}

void remplissage_initial(Automate* AF){
    if (AF->nb_etats_initiaux>1) {
        ajout_etat(AF->numeros_etats_initiaux,(new_AF->etat_d),AF->nb_etats_initiaux);
    }
    while (new_AF->etat_d[i]!='\0') {
        for (k=0;k<AF->nb_symboles;k++){
            for (j=0;j<(AF->nb_transitions);j++){
                if (int_to_char(etats_depart[j])==new_AF->etat_d[i]){
                    if (AF->symboles[j]==symb_pos[k]){
                        if (est_present(new_AF->etat_f,int_to_char(AF->etats_arrivee[i]))==0) new_AF->etat_f[j]=int_to_char(AF->etats_arrivee[i]);
                    }
                }

            }
        strcpy((new_AF->next)->etat_d,new_AF->etat_d);
        new_AF=new_AF->next;
        }
        i++;
    }
}


Automate* determinisation(Automate* AF,char* symb_pos){
    Automate* new_AF=(Automate*)malloc(sizeof(Automate2));
    int i=0;
    int j;
    int k=0;
    Automate2* first=new_AF;


    if (AF->nb_etats_initiaux>1) {
        ajout_etat(AF->numeros_etats_initiaux,(new_AF->etat_d),AF->nb_etats_initiaux);
    }

    if(presence_etat(first)!=0) ((new_AF->next->etat_d)=(new_AF->etat_f));



    return first;
}*/

/*void afficher_automate_deterministe_complet(Automate* AF){

    if ((est_deterministe() == true)&&(est_complet() == true)){

    int i =0;
    int j = 0;
    int k = 0;
    int m = 0;

    printf("Nombre de symboles dans l'alphabet de l'automate : %d\n\n", AF->nb_symboles2);
    printf("Nombre des etats : %d\n",AF->nb_etats2);

    for(i=0; i<AF->nb_etats2; i++){

        printf("Numéros de l'états : %d\n",AF->num_etats2[i]); //nouveau tab deterministe
    }


    printf("\nNombre d'etats initiaux : %d\n\n", AF->nb_etats_initiaux2);

    for (j = 0; j < AF->nb_etats_initiaux2; j++){

        printf("Numeros des etats initiaux : %d\n", AF->numeros_etats_initiaux2[j]);

    }

    printf("\nNombre d'etats terminaux : %d\n\n", AF->nb_etats_terminaux2);

    for (k = 0; k < AF->nb_etats_terminaux2; k++){

        printf("Numeros des etats terminaux : %d\n", AF->numeros_etats_terminaux2[k]);
    }

    printf("\nNombre de transitions : %d\n\n", AF->nb_transitions2);

    for (m = 0; m < AF->nb_transitions; m++){

        printf("Transition : %d%c%d\n", AF->etats_depart2[m], AF->symboles2[m], AF->etats_arrivee2[m]);
    }
    }

    else{

        printf("ERREUR \n");
    }
}*/

