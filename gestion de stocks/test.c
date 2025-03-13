#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fichier;
    char ligne[256]; // Tampon pour stocker chaque ligne lue

    // Ouvrir le fichier en mode lecture
    fichier = fopen("monfichier.txt", "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    // Lire le fichier ligne par ligne
    while (fgets(ligne, sizeof(ligne), fichier)) {
        // Afficher la ligne lue
        printf("%s", ligne);
    }

    // Fermer le fichier
    fclose(fichier);

    return EXIT_SUCCESS;
}