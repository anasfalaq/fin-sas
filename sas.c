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