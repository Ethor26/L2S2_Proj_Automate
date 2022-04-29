#include "test_automates.h"

Status test_function_automate01(int numero){

    Automate* automate01 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate01 = lire_automate_sur_fichier("BN6-01.txt");

    afficher_automate(automate01, "BN6-trace01.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate01, "BN6-trace01.txt") == true){

        printf("\n--------------------------------------------\n\n");

        // Déterminisation et complétion asynchrone (AFDC)

        elimination_epsilon(automate01, "BN6-trace01.txt", numero);

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate01, "BN6-trace01.txt") == true){

            if (est_un_automate_complet(automate01, "BN6-trace01.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate01, "BN6-trace01.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate01, "BN6-trace01.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate01);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate01);
            afficher_automate_complementaire(automate01, "BN6-trace01.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate01);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate02(int numero){

    Automate* automate02 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate02 = lire_automate_sur_fichier("BN6-02.txt");

    afficher_automate(automate02, "BN6-trace02.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate02, "BN6-trace02.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate02, "BN6-trace02.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate02, "BN6-trace02.txt") == true){

            if (est_un_automate_complet(automate02, "BN6-trace02.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate02, "BN6-trace02.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate02, "BN6-trace02.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate02);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate02);
            afficher_automate_complementaire(automate02, "BN6-trace02.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate02);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate03(int numero){

    Automate* automate03 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate03 = lire_automate_sur_fichier("BN6-03.txt");

    afficher_automate(automate03, "BN6-trace03.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate03, "BN6-trace03.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate03, "BN6-trace03.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate03, "BN6-trace03.txt") == true){

            if (est_un_automate_complet(automate03, "BN6-trace03.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate03, "BN6-trace03.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate03, "BN6-trace03.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

   // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate03);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate03);
            afficher_automate_complementaire(automate03, "BN6-trace03.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate03);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate04(int numero){

    Automate* automate04 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate04 = lire_automate_sur_fichier("BN6-04.txt");

    afficher_automate(automate04, "BN6-trace04.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate04, "BN6-trace04.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate04, "BN6-trace04.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate04, "BN6-trace04.txt") == true){

            if (est_un_automate_complet(automate04, "BN6-trace04.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                 printf("\n--------------------------------------------\n");

                completion(automate04, "BN6-trace04.txt");

                 printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate04, "BN6-trace04.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate04);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate04);
            afficher_automate_complementaire(automate04, "BN6-trace04.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate04);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }
    return OK;

}

Status test_function_automate05(int numero){

    Automate* automate05 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate05 = lire_automate_sur_fichier("BN6-05.txt");

    afficher_automate(automate05, "BN6-trace05.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate05, "BN6-trace05.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate05, "BN6-trace05.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate05, "BN6-trace05.txt") == true){

            if (est_un_automate_complet(automate05, "BN6-trace05.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate05, "BN6-trace05.txt");

                 printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate05, "BN6-trace05.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

   // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate05);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate05);
            afficher_automate_complementaire(automate05, "BN6-trace05.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate05);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate06(int numero){

    Automate* automate06 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate06 = lire_automate_sur_fichier("BN6-06.txt");

    afficher_automate(automate06, "BN6-trace06.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate06, "BN6-trace06.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate06, "BN6-trace06.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate06, "BN6-trace06.txt") == true){

            if (est_un_automate_complet(automate06, "BN6-trace06.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate06, "BN6-trace06.txt");

                 printf("\n--------------------------------------------\n");


            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate06, "BN6-trace06.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate06);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate06);
            afficher_automate_complementaire(automate06, "BN6-trace06.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate06);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate07(int numero){

    Automate* automate07 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate07 = lire_automate_sur_fichier("BN6-07.txt");

    afficher_automate(automate07, "BN6-trace07.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate07, "BN6-trace07.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate07, "BN6-trace07.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate07, "BN6-trace07.txt") == true){

            if (est_un_automate_complet(automate07, "BN6-trace07.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate07, "BN6-trace07.txt");

                printf("\n--------------------------------------------\n");


            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate07, "BN6-trace07.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate07);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate07);
            afficher_automate_complementaire(automate07, "BN6-trace07.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate07);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate08(int numero){

    Automate* automate08 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate08 = lire_automate_sur_fichier("BN6-08.txt");

    afficher_automate(automate08, "BN6-trace08.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate08, "BN6-trace08.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate08, "BN6-trace08.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate08, "BN6-trace08.txt") == true){

            if (est_un_automate_complet(automate08, "BN6-trace08.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate08, "BN6-trace08.txt");

                 printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate08, "BN6-trace08.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

   // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate08);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate08);
            afficher_automate_complementaire(automate08, "BN6-trace08.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate08);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate09(int numero){

    Automate* automate09 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate09 = lire_automate_sur_fichier("BN6-09.txt");

    afficher_automate(automate09, "BN6-trace09.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate09, "BN6-trace09.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate09, "BN6-trace09.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate09, "BN6-trace09.txt") == true){

            if (est_un_automate_complet(automate09, "BN6-trace09.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate09, "BN6-trace09.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate09, "BN6-trace09.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate09);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate09);
            afficher_automate_complementaire(automate09, "BN6-trace09.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate09);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate10(int numero){

    Automate* automate10 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate10 = lire_automate_sur_fichier("BN6-10.txt");

    afficher_automate(automate10, "BN6-trace10.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate10, "BN6-trace10.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate10, "BN6-trace10.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate10, "BN6-trace10.txt") == true){

            if (est_un_automate_complet(automate10, "BN6-trace10.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate10, "BN6-trace10.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate10, "BN6-trace10.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate10);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate10);
            afficher_automate_complementaire(automate10, "BN6-trace10.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate10);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate11(int numero){

    Automate* automate11 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate11 = lire_automate_sur_fichier("BN6-11.txt");

    afficher_automate(automate11, "BN6-trace11.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate11, "BN6-trace11.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate11, "BN6-trace11.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate11, "BN6-trace11.txt") == true){

            if (est_un_automate_complet(automate11, "BN6-trace11.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate11, "BN6-trace11.txt");

                 printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate11, "BN6-trace11.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate11);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate11);
            afficher_automate_complementaire(automate11, "BN6-trace11.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate11);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate12(int numero){

    Automate* automate12 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate12 = lire_automate_sur_fichier("BN6-12.txt");

    afficher_automate(automate12, "BN6-trace12.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate12, "BN6-trace12.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate12, "BN6-trace12.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate12, "BN6-trace12.txt") == true){

            if (est_un_automate_complet(automate12, "BN6-trace12.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate12, "BN6-trace12.txt");

                printf("\n--------------------------------------------\n");
            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate12, "BN6-trace12.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate12);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate12);
            afficher_automate_complementaire(automate12, "BN6-trace12.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate12);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate13(int numero){

    Automate* automate13 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate13 = lire_automate_sur_fichier("BN6-13.txt");

    afficher_automate(automate13, "BN6-trace13.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate13, "BN6-trace13.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate13, "BN6-trace13.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate13, "BN6-trace13.txt") == true){

            if (est_un_automate_complet(automate13, "BN6-trace13.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate13, "BN6-trace13.txt");

                 printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate13, "BN6-trace13.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate13);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate13);
            afficher_automate_complementaire(automate13, "BN6-trace13.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate13);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }
    return OK;

}

Status test_function_automate14(int numero){

    Automate* automate14 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate14 = lire_automate_sur_fichier("BN6-14.txt");

    afficher_automate(automate14, "BN6-trace14.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate14, "BN6-trace14.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate14, "BN6-trace14.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate14, "BN6-trace14.txt") == true){

            if (est_un_automate_complet(automate14, "BN6-trace14.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate14, "BN6-trace14.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate14, "BN6-trace14.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate14);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate14);
            afficher_automate_complementaire(automate14, "BN6-trace14.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate14);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate15(int numero){

    Automate* automate15 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate15 = lire_automate_sur_fichier("BN6-15.txt");

    afficher_automate(automate15, "BN6-trace15.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate15, "BN6-trace15.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate15, "BN6-trace15.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate15, "BN6-trace15.txt") == true){

            if (est_un_automate_complet(automate15, "BN6-trace15.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                  printf("\n--------------------------------------------\n");

                  completion(automate15, "BN6-trace15.txt");

                  printf("\n--------------------------------------------\n");
            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate15, "BN6-trace15.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

   // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate15);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate15);
            afficher_automate_complementaire(automate15, "BN6-trace15.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate15);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate16(int numero){

    Automate* automate16 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate16 = lire_automate_sur_fichier("BN6-16.txt");

    afficher_automate(automate16, "BN6-trace16.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate16, "BN6-trace16.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate16, "BN6-trace16.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate16, "BN6-trace16.txt") == true){

            if (est_un_automate_complet(automate16, "BN6-trace16.txt") == 1){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                  printf("\n--------------------------------------------\n");

                  completion(automate16, "BN6-trace16.txt");

                  printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate16, "BN6-trace16.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate16);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate16);
            afficher_automate_complementaire(automate16, "BN6-trace16.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate16);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate17(int numero){

    Automate* automate17 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate17 = lire_automate_sur_fichier("BN6-17.txt");

    afficher_automate(automate17, "BN6-trace17.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate17, "BN6-trace17.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate17, "BN6-trace17.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate17, "BN6-trace17.txt") == true){

            if (est_un_automate_complet(automate17, "BN6-trace17.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                  printf("\n--------------------------------------------\n");

                  completion(automate17, "BN6-trace17.txt");

                  printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate17, "BN6-trace17.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

   // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate17);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate17);
            afficher_automate_complementaire(automate17, "BN6-trace17.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate17);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate18(int numero){

    Automate* automate18 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate18 = lire_automate_sur_fichier("BN6-18.txt");

    afficher_automate(automate18, "BN6-trace18.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate18, "BN6-trace18.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate18, "BN6-trace18.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate18, "BN6-trace18.txt") == true){

            if (est_un_automate_complet(automate18, "BN6-trace18.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate18, "BN6-trace18.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate18, "BN6-trace18.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate18);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate18);
            afficher_automate_complementaire(automate18, "BN6-trace18.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate18);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate19(int numero){

    Automate* automate19 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate19 = lire_automate_sur_fichier("BN6-19.txt");

    afficher_automate(automate19, "BN6-trace19.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate19, "BN6-trace19.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate19, "BN6-trace19.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate19, "BN6-trace19.txt") == true){

            if (est_un_automate_complet(automate19, "BN6-trace19.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate19, "BN6-trace19.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate19, "BN6-trace19.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate19);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate19);
            afficher_automate_complementaire(automate19, "BN6-trace19.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate19);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate20(int numero){

    Automate* automate20 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate20 = lire_automate_sur_fichier("BN6-20.txt");

    afficher_automate(automate20, "BN6-trace20.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate20, "BN6-trace20.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate20, "BN6-trace20.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate20, "BN6-trace20.txt") == true){

            if (est_un_automate_complet(automate20, "BN6-trace20.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate20, "BN6-trace20.txt");

                 printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate20, "BN6-trace20.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate20);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate20);
            afficher_automate_complementaire(automate20, "BN6-trace20.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate20);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate21(int numero){

    Automate* automate21 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate21 = lire_automate_sur_fichier("BN6-21.txt");

    afficher_automate(automate21, "BN6-trace21.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate21, "BN6-trace21.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate21, "BN6-trace21.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate21, "BN6-trace21.txt") == true){

            if (est_un_automate_complet(automate21, "BN6-trace21.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate21, "BN6-trace21.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate21, "BN6-trace21.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate21);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate21);
            afficher_automate_complementaire(automate21, "BN6-trace21.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate21);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate22(int numero){

    Automate* automate22 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate22 = lire_automate_sur_fichier("BN6-22.txt");

    afficher_automate(automate22, "BN6-trace22.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate22, "BN6-trace22.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate22, "BN6-trace22.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate22, "BN6-trace22.txt") == true){

            if (est_un_automate_complet(automate22, "BN6-trace22.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate22, "BN6-trace22.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate22, "BN6-trace22.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate22);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate22);
            afficher_automate_complementaire(automate22, "BN6-trace22.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate22);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate23(int numero){

    Automate* automate23 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate23 = lire_automate_sur_fichier("BN6-23.txt");

    afficher_automate(automate23, "BN6-trace23.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate23, "BN6-trace23.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate23, "BN6-trace23.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate23, "BN6-trace23.txt") == true){

            if (est_un_automate_complet(automate23, "BN6-trace23.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate23, "BN6-trace23.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate23, "BN6-trace23.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

   // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate23);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate23);
            afficher_automate_complementaire(automate23, "BN6-trace23.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate23);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate24(int numero){

    Automate* automate24 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate24 = lire_automate_sur_fichier("BN6-24.txt");

    afficher_automate(automate24, "BN6-trace24.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate24, "BN6-trace24.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate24, "BN6-trace24.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate24, "BN6-trace24.txt") == true){

            if (est_un_automate_complet(automate24, "BN6-trace24.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate24, "BN6-trace24.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate24, "BN6-trace24.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate24);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate24);
            afficher_automate_complementaire(automate24, "BN6-trace24.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate24);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate25(int numero){

    Automate* automate25 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate25 = lire_automate_sur_fichier("BN6-25.txt");

    afficher_automate(automate25, "BN6-trace25.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate25, "BN6-trace25.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate25, "BN6-trace25.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate25, "BN6-trace25.txt") == true){

            if (est_un_automate_complet(automate25, "BN6-trace25.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate25, "BN6-trace25.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate25, "BN6-trace25.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate25);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate25);
            afficher_automate_complementaire(automate25, "BN6-trace25.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate25);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate26(int numero){

    Automate* automate26 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate26 = lire_automate_sur_fichier("BN6-26.txt");

    afficher_automate(automate26, "BN6-trace26.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate26, "BN6-trace26.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate26, "BN6-trace26.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate26, "BN6-trace26.txt") == true){

            if (est_un_automate_complet(automate26, "BN6-trace26.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate26, "BN6-trace26.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate26, "BN6-trace26.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate26);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate26);
            afficher_automate_complementaire(automate26, "BN6-trace26.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate26);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate27(int numero){

    Automate* automate27 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate27 = lire_automate_sur_fichier("BN6-27.txt");

    afficher_automate(automate27, "BN6-trace27.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate27, "BN6-trace27.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate27, "BN6-trace27.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate27, "BN6-trace27.txt") == true){

            if (est_un_automate_complet(automate27, "BN6-trace27.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate27, "BN6-trace27.txt");

                 printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate27, "BN6-trace27.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate27);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate27);
            afficher_automate_complementaire(automate27, "BN6-trace27.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate27);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate28(int numero){

    Automate* automate28 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate28 = lire_automate_sur_fichier("BN6-28.txt");

    afficher_automate_complementaire(automate28, "BN6-trace28.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate28, "BN6-trace28.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate28, "BN6-trace28.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate28, "BN6-trace28.txt") == true){

            if (est_un_automate_complet(automate28, "BN6-trace28.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate28, "BN6-trace28.txt");

                 printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate28, "BN6-trace28.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate28);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate28);
            afficher_automate_complementaire(automate28, "BN6-trace28.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate28);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate29(int numero){

    Automate* automate29 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate29 = lire_automate_sur_fichier("BN6-29.txt");

    afficher_automate(automate29, "BN6-trace29.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate29, "BN6-trace29.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate29, "BN6-trace29.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{


        if (est_un_automate_deterministe(automate29, "BN6-trace29.txt") == true){

            if (est_un_automate_complet(automate29, "BN6-trace29.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate29, "BN6-trace29.txt");

                 printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate29, "BN6-trace29.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate29);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate29);
            afficher_automate_complementaire(automate29, "BN6-trace29.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate29);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate30(int numero){

    Automate* automate30 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate30 = lire_automate_sur_fichier("BN6-30.txt");

    afficher_automate(automate30, "BN6-trace30.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate30, "BN6-trace30.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate30, "BN6-trace30.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate30, "BN6-trace30.txt") == true){

            if (est_un_automate_complet(automate30, "BN6-trace30.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate30, "BN6-trace30.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate30, "BN6-trace30.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate30);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate30);
            afficher_automate_complementaire(automate30, "BN6-trace30.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate30);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate31(int numero){

    Automate* automate31 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate31 = lire_automate_sur_fichier("BN6-31.txt");

    afficher_automate(automate31, "BN6-trace31.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate31, "BN6-trace31.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate31, "BN6-trace31.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate31, "BN6-trace31.txt") == true){

            if (est_un_automate_complet(automate31, "BN6-trace31.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate31, "BN6-trace31.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate31, "BN6-trace31.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate31);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate31);
            afficher_automate_complementaire(automate31, "BN6-trace31.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate31);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate32(int numero){

    Automate* automate32 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate32 = lire_automate_sur_fichier("BN6-32.txt");

    afficher_automate(automate32, "BN6-trace32.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate32, "BN6-trace32.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate32, "BN6-trace32.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate32, "BN6-trace32.txt") == true){

            if (est_un_automate_complet(automate32, "BN6-trace32.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate32, "BN6-trace32.txt");

                 printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate32, "BN6-trace32.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

   // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate32);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate32);
            afficher_automate_complementaire(automate32, "BN6-trace32.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate32);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate33(int numero){

    Automate* automate33 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate33 = lire_automate_sur_fichier("BN6-33.txt");

    afficher_automate(automate33, "BN6-trace33.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate33, "BN6-trace33.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate33, "BN6-trace33.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate33, "BN6-trace33.txt") == true){

            if (est_un_automate_complet(automate33, "BN6-trace33.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate33, "BN6-trace33.txt");

                printf("\n--------------------------------------------\n");


            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate33, "BN6-trace33.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate33);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate33);
            afficher_automate_complementaire(automate33, "BN6-trace33.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate33);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate34(int numero){

    Automate* automate34 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate34 = lire_automate_sur_fichier("BN6-34.txt");

    afficher_automate(automate34, "BN6-trace34.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate34, "BN6-trace34.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate34, "BN6-trace34.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate34, "BN6-trace34.txt") == true){

            if (est_un_automate_complet(automate34, "BN6-trace34.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate34, "BN6-trace34.txt");

                printf("\n--------------------------------------------\n");


            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate34, "BN6-trace34.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate34);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate34);
            afficher_automate_complementaire(automate34, "BN6-trace34.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate34);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate35(int numero){

    Automate* automate35 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate35 = lire_automate_sur_fichier("BN6-35.txt");

    afficher_automate(automate35, "BN6-trace35.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate35, "BN6-trace35.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate35, "BN6-trace35.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate35, "BN6-trace35.txt") == true){

            if (est_un_automate_complet(automate35, "BN6-trace35.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate35, "BN6-trace35.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate35, "BN6-trace35.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate35);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate35);
            afficher_automate_complementaire(automate35, "BN6-trace35.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate35);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate36(int numero){

    Automate* automate36 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate36 = lire_automate_sur_fichier("BN6-36.txt");

    afficher_automate(automate36, "BN6-trace36.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate36, "BN6-trace36.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate36, "BN6-trace36.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate36, "BN6-trace36.txt") == true){

            if (est_un_automate_complet(automate36, "BN6-trace36.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate36, "BN6-trace36.txt");

                 printf("\n--------------------------------------------\n");


            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate36, "BN6-trace36.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate36);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate36);
            afficher_automate_complementaire(automate36, "BN6-trace36.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate36);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate37(int numero){

    Automate* automate37 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate37 = lire_automate_sur_fichier("BN6-37.txt");

    afficher_automate(automate37, "BN6-trace37.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate37, "BN6-trace37.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate37, "BN6-trace37.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate37, "BN6-trace37.txt") == true){

            if (est_un_automate_complet(automate37, "BN6-trace37.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate37, "BN6-trace37.txt");

                 printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate37, "BN6-trace37.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate37);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate37);
            afficher_automate_complementaire(automate37, "BN6-trace37.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate37);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate38(int numero){

    Automate* automate38 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate38 = lire_automate_sur_fichier("BN6-38.txt");

    afficher_automate(automate38, "BN6-trace38.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate38, "BN6-trace38.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate38, "BN6-trace38.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate38, "BN6-trace38.txt") == true){

            if (est_un_automate_complet(automate38, "BN6-trace38.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate38, "BN6-trace38.txt");

                 printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate38, "BN6-trace38.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate38);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate38);
            afficher_automate_complementaire(automate38, "BN6-trace38.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate38);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate39(int numero){

    Automate* automate39 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate39 = lire_automate_sur_fichier("BN6-39.txt");

    afficher_automate(automate39, "BN6-trace39.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate39, "BN6-trace39.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate39, "BN6-trace39.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate39, "BN6-trace39.txt") == true){

            if (est_un_automate_complet(automate39, "BN6-trace39.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate39, "BN6-trace39.txt");

                printf("\n--------------------------------------------\n");


            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate39, "BN6-trace39.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate39);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate39);
            afficher_automate_complementaire(automate39, "BN6-trace39.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate39);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate40(int numero){

    Automate* automate40 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate40 = lire_automate_sur_fichier("BN6-40.txt");

    afficher_automate(automate40, "BN6-trace40.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate40, "BN6-trace40.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate40, "BN6-trace40.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate40, "BN6-trace40.txt") == true){

            if (est_un_automate_complet(automate40, "BN6-trace40.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate40, "BN6-trace40.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate40,  "BN6-trace40.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate40);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate40);
            afficher_automate_complementaire(automate40, "BN6-trace40.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate40);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate41(int numero){

    Automate* automate41 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate41 = lire_automate_sur_fichier("BN6-41.txt");

    afficher_automate(automate41, "BN6-trace41.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate41, "BN6-trace41.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate41, "BN6-trace41.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate41, "BN6-trace41.txt") == true){

            if (est_un_automate_complet(automate41, "BN6-trace41.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate41, "BN6-trace41.txt");

                printf("\n--------------------------------------------\n");


            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate41, "BN6-trace41.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate41);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate41);
            afficher_automate_complementaire(automate41, "BN6-trace41.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate41);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate42(int numero){

    Automate* automate42 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate42 = lire_automate_sur_fichier("BN6-42.txt");

    afficher_automate(automate42, "BN6-trace42.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate42, "BN6-trace42.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate42, "BN6-trace42.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate42, "BN6-trace42.txt") == true){

            if (est_un_automate_complet(automate42, "BN6-trace42.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate42, "BN6-trace42.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate42, "BN6-trace42.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

   // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate42);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate42);
            afficher_automate_complementaire(automate42, "BN6-trace42.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate42);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate43(int numero){

    Automate* automate43 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate43 = lire_automate_sur_fichier("BN6-43.txt");

    afficher_automate(automate43, "BN6-trace43.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate43, "BN6-trace43.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate43, "BN6-trace43.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate43, "BN6-trace43.txt") == true){

            if (est_un_automate_complet(automate43, "BN6-trace43.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate43, "BN6-trace43.txt");

                printf("\n--------------------------------------------\n");

            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate43, "BN6-trace43.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

    // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate43);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate43);
            afficher_automate_complementaire(automate43, "BN6-trace43.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate43);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}

Status test_function_automate44(int numero){

    Automate* automate44 = NULL;
    char mot[BUFSIZ];

    printf("\nVous avez choisi l'automate %d.\n\n", numero);

    automate44 = lire_automate_sur_fichier("BN6-44.txt");

    afficher_automate(automate44, "BN6-trace44.txt", numero);

    printf("\n--------------------------------------------\n\n");

    if (est_un_automate_asynchrone(automate44, "BN6-trace44.txt") == true){

        printf("\n--------------------------------------------\n\n");

        elimination_epsilon(automate44, "BN6-trace44.txt", numero);

        // Déterminisation et complétion asynchrone (AFDC)

        printf("\n--------------------------------------------\n");
    }

    else{

        if (est_un_automate_deterministe(automate44, "BN6-trace44.txt") == true){

            if (est_un_automate_complet(automate44, "BN6-trace44.txt") == true){

                // Afficher de l'AFDC
            }

            else{

                // Complétion AF

                printf("\n--------------------------------------------\n");

                completion(automate44, "BN6-trace44.txt");


                printf("\n--------------------------------------------\n");


            }
        }

        else{

            // Déterminisation et complétion synchrone
        }

        // Standardisation

        standardisation(automate44, "BN6-trace44.txt");

        printf("\n--------------------------------------------\n");

    }

    // Afficher AFDC

    // Minimisation (AFDCM)

   // Reconnaissance de mots (automate initial)

    printf("\nReconnaissance de mots par l'automate initial\n");

    lire_mot(mot);

    while (mot != "fin"){

        reconnaitre_mot(mot, automate44);

        if  (lire_mot(mot) == 1){

            printf("\n--------------------------------------------\n");

            // Automate complémentaire (Acomp)

            printf("\nAutomate complementaire\n\n");

            automate_complementaire(automate44);
            afficher_automate_complementaire(automate44, "BN6-trace44.txt", numero);

            // Reconnaissance de mots (automate complementaire)
            printf("\n--------------------------------------------\n");

            printf("\nReconnaissance de mots par l'automate complementaire\n");

            lire_mot(mot);

            while (mot != "fin"){

                reconnaitre_mot(mot, automate44);

                if (lire_mot(mot) == 1){

                    exit(EXIT_FAILURE);
                }

            }

            printf("\n--------------------------------------------\n");

        }

    }

    return OK;

}











