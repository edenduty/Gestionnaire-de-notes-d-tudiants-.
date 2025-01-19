#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int nombre_aleatoire(int min, int max) {
    return rand() % (max - min + 1) + min;}
void identification_age(double input) {
    double conservateur, a;
    conservateur = input;
    input = getchar();
    while(input != 10 || floor(conservateur) != conservateur || conservateur <= 0) {
        printf("Entrez un entier non nul sans lettre, ni signe. Reessayez.\n");
        while(getchar() != '\n');
        scanf("%lf", &input);
        conservateur = input;
        input = getchar();
    }
    input = conservateur;
}

void identification_entier_lettre(double input) {
    double conservateur, a;
    conservateur = input;
    input = getchar();
    if(input != 10) {
        while(input != 10) {
            printf("Entrez un nombre sans lettre, ni signe. Reessayez.\n");
            while(getchar() != '\n');
            scanf("%lf", &input);
            a = input;
            input = getchar();
        }
    } else {
        input = conservateur;
    }
}

void lecture_fichier(char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "r");
    char ligne[200];
    while(fgets(ligne, sizeof(ligne), fichier)) {
        printf("%s", ligne);
    }
    fclose(fichier);
}

void menu1() {
    printf("  1)Ajout des informations.   2)Liste des etudiants et leur moyenne   3)Affichage de la moyenne d'un etudiant \n\n		        4)Informations des etudiants.   5)Informations d'un etudiant.\n");
}

void ajouter_informations_etudiant(char *classe1a, char *moyenne_classe1a) {
    double age[200], moyenne[200], som_notes, note[200];
    char nom[200][200], nom_matiere[200];
    int identifiant[200], debut_for = 0, yu = 0;
    double nombre_matieres, coef, som_coef = 0, nombre_notes, moy_matieres, som_moy_matieres = 0;
    char arret_informations1[] = "oui";
    int debut_for1 = 0;
    char arret_informations2[] = "oui";

    while (strcmp(arret_informations1, arret_informations2) == 0) {
        for (int i = debut_for1; i < debut_for1 + 1; i++) {
            	srand(time(NULL));
            printf("Saississez les informations de l'étudiant.\n");
            printf("Age: ");
            scanf("%lf", &age[i]);
            identification_age(age[i]);
            printf("Nom et prénoms: ");
            fgets(nom[i], 200, stdin);
            identifiant[i] = nombre_aleatoire(i,10000)+i+age[i]+debut_for+100000;
            FILE *fichier = fopen(classe1a, "a");
            fprintf(fichier, "Age:%lf   ", age[i]);
            fprintf(fichier, "ID:%d   ", identifiant[i]);
            fprintf(fichier, "Nom:%s\n", nom[i]);
            fclose(fichier);

            printf("Combien de matieres appliquees a cet utilisateur.\n");
            scanf("%lf", &nombre_matieres);
            identification_age(nombre_matieres);

            for (int a = 0; a < nombre_matieres; a++) {
                printf("Nom de la matière.\n");
                fgets(nom_matiere, 200, stdin);
                printf("Quelle est son coefficient.\n");
                scanf("%lf", &coef);
                identification_age(coef);
                som_coef += coef;
                printf("Combien de notes pour cette matiere.\n");
                scanf("%lf", &nombre_notes);
                identification_age(nombre_notes);

                printf("Entrez vos notes.\n");
                debut_for = yu;
                som_notes = 0;
                for (yu; yu < debut_for + nombre_notes; yu++) {
                    scanf("%lf", &note[yu]);
                    identification_entier_lettre(note[yu]);
                    while (!(note[yu] <= 20 && note[yu] >= 0)) {
                        printf("Note non comprise. Reessayez.\n");
                        scanf("%lf", &note[yu]);
                    }
                    som_notes += note[yu];
                }
                yu = yu + nombre_notes;
                moy_matieres = som_notes * coef / nombre_notes;
                som_moy_matieres += moy_matieres;
            }

            moyenne[i] = som_moy_matieres / som_coef;
            FILE *fi2chier = fopen(moyenne_classe1a, "a");
            fprintf(fi2chier, "Moyenne:%lf   ", moyenne[i]);
            fprintf(fi2chier, "ID:%d   ", identifiant[i]);
            fprintf(fi2chier, "Nom:%s\n", nom[i]);
            fclose(fi2chier);
        }
        debut_for1 += 1;
        printf("Voulez-vous enregistrer un autre étudiant ?\n Entrez 'oui' pour confirmer. Toute autre réponse sera considérée comme une confirmation.\n");
        scanf("%s", arret_informations1);
    }
}

void rechercher_etudiant(char *moyenne_classe1a, char *non) {
    FILE *fi2chier = fopen(moyenne_classe1a, "r");
    if (fi2chier == NULL) {
        printf("Erreur lors de l'ouverture du fichier des moyennes.\n");
        return;
    }

    int v, b, compteur = 0;
    char ligne[100];
    while (fgets(ligne, sizeof(ligne), fi2chier)) {
        for (int i = 0; i < strlen(ligne); i++) {
            v = 0;
            if (ligne[i] == 'N' && ligne[i + 1] == 'o' && ligne[i + 2] == 'm') {
                for (int x = i + 4; x < strlen(non) + i + 5; x++) {
                    b = x - i - 4;
                    if (ligne[x] == non[b]) {
                        v += 1;
                    }
                }
                if (v == strlen(non)) {
                    printf("%s", ligne);
                    compteur += 1;
                }
            }
        }
    }

    if (compteur == 0) {
        printf("Nom inexistant\n");
    }
    fclose(fi2chier);
}

void gerer_classe(char *classe1a, char *moyenne_classe1a) {
    menu1();
    int choix_fonctions;
    scanf("%d", &choix_fonctions);

    switch (choix_fonctions) {
        case 1: {
            ajouter_informations_etudiant(classe1a, moyenne_classe1a);
            break;
        }
        case 2: {
            lecture_fichier(moyenne_classe1a);
            break;
        }
        case 3: {
            char non[200];
            printf("Entrez le nom de l'etudiant à rechercher: ");
            scanf("%s", non);
            rechercher_etudiant(moyenne_classe1a, non);
            break;
        }
        case 4: {
            lecture_fichier(classe1a);
            break;
        }
        case 5: {
            char non[200];
            printf("Entrez le nom de l'etudiant à rechercher: ");
            scanf("%s", non);
            rechercher_etudiant(classe1a, non);
            break;
        }
    }
}

int main() {
    double arret_class = 1;
    while (arret_class == 1) {
        int choix_class;
        double arret_programm1 = 1;
        while (arret_programm1 == 1) {
            printf("Vous etes en mesure d'entrer un nombre correspondant a une classe d'eleves.\n");
            printf("Veuillez choisir le numero correspondant a la classe d'eleves souhaitee.\n");
            scanf("%d", &choix_class);

            switch (choix_class) {
                case 1: {
                    FILE *fichier = fopen("classe1a", "a");
                    fclose(fichier);
                    FILE *fi2chier = fopen("moyenne_classe1a", "a");
                    fclose(fi2chier);
                    gerer_classe("classe1a", "moyenne_classe1a");
                    break;
                }
                case 2: {
                    FILE *fichier = fopen("classe2a", "a");
                    fclose(fichier);
                    FILE *fi2chier = fopen("moyenne_classe2a", "a");
                    fclose(fi2chier);
                    gerer_classe("classe2a", "moyenne_classe2a");
                    break;
                }
                case 3: {
                    FILE *fichier = fopen("classe3a", "a");
                    fclose(fichier);
                    FILE *fi2chier = fopen("moyenne_classe3a", "a");
                    fclose(fi2chier);
                    gerer_classe("classe3a", "moyenne_classe3a");
                    break;
                }
                default: {
                    printf("Choississez entre 1 et 3.\n");
                    break;
                }
            }
            printf("Voulez-vous continuer le programme ?\nVeuillez entrer '1' pour confirmer, toute différence sera prise comme une affirmation.\n");
            scanf("%lf", &arret_programm1);
            identification_age(arret_programm1);
        }

        printf("Etes-vous sur ?\nVeuillez entrer '1' pour infirmer, toute différence sera prise comme une confirmation.\n");
        scanf("%lf", &arret_class);
        identification_age(arret_programm1);
    }
    return 0;
}
