#include <stdio.h>
#include <stdlib.h>

int main() {
    int jour, mois, annee ;
    char nom[50];

    FILE *fp = fopen("test_perso.txt", "r");

    fscanf(fp, "%d %d %d", &jour, &mois, &annee);
    fscanf(fp, "%s", nom);

    fclose(fp);

    printf("%d/%d/%d\n", jour, mois, annee);
    printf("Nom : %s\n", nom);

    return 0;
}