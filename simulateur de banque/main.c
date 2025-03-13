#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPTES 100

typedef struct {
    int id;
    char nom[50];
    double solde;
} CompteBancaire;

CompteBancaire comptes[MAX_COMPTES];
int nombreComptes = 0;

void creerCompte() {
    if (nombreComptes >= MAX_COMPTES) {
        printf("\nLimite de comptes atteinte.\n");
        return;
    }
    printf("\nCreation d'un nouveau compte:\n");
    comptes[nombreComptes].id = nombreComptes + 1;
    printf("Nom du titulaire: ");
    scanf("%s", comptes[nombreComptes].nom);
    comptes[nombreComptes].solde = 0;
    printf("Compte cree avec succes! ID: %d\n", comptes[nombreComptes].id);
    nombreComptes++;
}

void afficherComptes() {
    printf("\nListe des comptes:\n");
    for (int i = 0; i < nombreComptes; i++) {
        printf("ID: %d | Nom: %s | Solde: %.2f\n", comptes[i].id, comptes[i].nom, comptes[i].solde);
    }
}

void depot() {
    int id;
    double montant;
    printf("\nID du compte: ");
    scanf("%d", &id);
    if (id < 1 || id > nombreComptes) {
        printf("Compte invalide.\n");
        return;
    }
    printf("Montant du depot: ");
    scanf("%lf", &montant);
    comptes[id - 1].solde += montant;
    printf("Depot reussi! Nouveau solde: %.2f\n", comptes[id - 1].solde);
}

void retrait() {
    int id;
    double montant;
    printf("\nID du compte: ");
    scanf("%d", &id);
    if (id < 1 || id > nombreComptes) {
        printf("Compte invalide.\n");
        return;
    }
    printf("Montant du retrait: ");
    scanf("%lf", &montant);
    if (montant > comptes[id - 1].solde) {
        printf("Fonds insuffisants.\n");
        return;
    }
    comptes[id - 1].solde -= montant;
    printf("Retrait reussi! Nouveau solde: %.2f\n", comptes[id - 1].solde);
}

void virement() {
    int idSource, idCible;
    double montant;
    printf("\nID du compte source: ");
    scanf("%d", &idSource);
    printf("ID du compte cible: ");
    scanf("%d", &idCible);
    if (idSource < 1 || idSource > nombreComptes || idCible < 1 || idCible > nombreComptes) {
        printf("Compte invalide.\n");
        return;
    }
    printf("Montant du virement: ");
    scanf("%lf", &montant);
    if (montant > comptes[idSource - 1].solde) {
        printf("Fonds insuffisants.\n");
        return;
    }
    comptes[idSource - 1].solde -= montant;
    comptes[idCible - 1].solde += montant;
    printf("Virement reussi! Nouveau solde: %.2f\n", comptes[idSource - 1].solde);
}

int main() {
    int choix;
    do {
        printf("\n=== Banque Simulator ===\n");
        printf("1. Creer un compte\n");
        printf("2. Afficher les comptes\n");
        printf("3. Depot\n");
        printf("4. Retrait\n");
        printf("5. Virement\n");
        printf("6. Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: creerCompte(); break;
            case 2: afficherComptes(); break;
            case 3: depot(); break;
            case 4: retrait(); break;
            case 5: virement(); break;
            case 6: printf("Au revoir!\n"); break;
            default: printf("Option invalide.\n");
        }
    } while (choix != 6);
    return 0;
}
