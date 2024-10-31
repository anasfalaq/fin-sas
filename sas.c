#include <stdio.h>
#include <string.h>

#define MAX_TACHES 100

typedef struct {
    char titre[50];
    char description[200];
    char date_echeance[11]; 
    char priorite[5]; 
} Tache;

Tache liste_taches[MAX_TACHES];
int nombre_taches = 0;


// Fonction pour afficher le menu
void afficher_menu() {
    printf("\n=== Menu de Gestion des Taches ===\n");
    printf("1. Ajouter une Tache\n");
    printf("2. Afficher la Liste des Taches\n");
    printf("3. Modifier une Tache\n");
    printf("4. Supprimer une Tache\n");
    printf("5. Filtrer les Taches par Priorite\n");
    printf("0. Quitter\n");
    printf("Choisissez une option : ");
}

// Fonction pour ajouter une tache
void ajouter_tache() {
    if (nombre_taches >= MAX_TACHES) {
        printf("La liste des taches est pleine.\n");
        return;
    }
    printf("Titre : ");
    scanf(" %[^\n]", liste_taches[nombre_taches].titre);
    printf("Description : ");
    scanf(" %[^\n]", liste_taches[nombre_taches].description);
    printf("Date d'echeance (YYYY-MM-DD) : ");
    scanf(" %[^\n]", liste_taches[nombre_taches].date_echeance);

    while (1) {
        printf("Priorite (High/Low) : ");
        scanf(" %[^\n]", liste_taches[nombre_taches].priorite);
        
        
        if (strcmp(liste_taches[nombre_taches].priorite, "High") == 0 || 
            strcmp(liste_taches[nombre_taches].priorite, "Low") == 0) {
            break; 
        } else {
            printf("Entrée invalide. Veuillez saisir 'High' ou 'Low'.\n");
        }
    }
    

    nombre_taches++;
    printf("Tache ajoutee avec succès !\n");
}

// Fonction pour afficher toutes les taches
void afficher_taches() {
    printf("\n=== Liste des Taches ===\n");
    for (int i = 0; i < nombre_taches; i++) {
        printf("Tache %d :\n", i + 1);
        printf("Titre : %s\n", liste_taches[i].titre);
        printf("Description : %s\n", liste_taches[i].description);
        printf("Date d'echeance : %s\n", liste_taches[i].date_echeance);
        printf("Priorite : %s\n", liste_taches[i].priorite);
        printf("----------------------\n");
    }
}