/*
    Conception du code : 
        but : - gérer les produits stockés pour un magasin
              - simple à utiliser
              - Ajustable
               
    Manière de fonctionnement : 
       - Pile de produit (produit tout attaché par des pointeurs)

    Contenu du code en général :
        - Une structure permettant de définir un produit
        - La liste de tous les produits disponibles
        - Des fontions pour les actions faisable    
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCT 2
int idCount = 0;
int nbrProduct = 0;

//Pour les vérifications
typedef enum {
    false,
    true
}Bool;

//Un produit
typedef struct {
    int id;
    char name[50];
    float price;
} Product;

//Liste des produits
typedef struct __LIST__{
    Product p;
    struct __LIST__ *next;
} listeProduct, *List;

//Les prototypes des actions
void menu();
Bool listIsEmpty(List);
Product *defineProduct(int);
List insertProduct(List, Product);
List deleteProduct(List, char[]);
void printOneProduct(List, char[]);
void printAllProduct(List);
void soldeProduct(List);

//----------------------------------------------------------------

int main() {
    listeProduct *list = NULL;
    Product tableProduct[MAX_PRODUCT];
    char nameProduct[] = {'\0'};
    
    Bool runCode = true;
    int choice;
    while(runCode) {
        menu();
        printf("Votre choix : ");
        scanf("%d", &choice);
        
        //Pour éviter si l'utilisateur à bien inserer une chiffre
        if(isalnum(choice))
            exit(1);

        switch(choice) {
            case 1 :
                //Recupérer tous les produits
                for(int i = 0; i < MAX_PRODUCT; i++) 
                    tableProduct[i] = *defineProduct(i + 1);
                
                printf("stock plein\n");

                //Mettre les produits dans une seule liste
                for(int i = 0; i < MAX_PRODUCT; i++) 
                    list = insertProduct(list, tableProduct[i]);

                    break;
            case 2 :
                list = deleteProduct(list, nameProduct);
                    break;
            case 3 :
                printOneProduct(list, nameProduct);
                    break;
            case 4 :
                printAllProduct(list);
                    break;
            case 5 :
                soldeProduct(list);
                    break;
            case 6 :
                runCode = false;
                printf("\nBye !!\n");
                    break;
            
            default :
                printf("Lisez bien !!\n");
                    break;
        }
    }
    
    //Pour stocker les données
    FILE *fp1; 
    fp1 = fopen("stockage.txt", "w"); //write

    fprintf(fp1, "%d %d\n", idCount, nbrProduct);
    

    while(list != NULL) {
        fprintf(fp1, "%2d %10s %10.2f\n", list->p.id, list->p.name, list->p.price);
        list = list->next;
    }

    fclose(fp1);

    return 0;
}

//----------------------------------------------------------------

void menu() {
    printf("\n");
    printf("\t");
    printf("1 - Inserer un nouveau produit\n");
    printf("\t");
    printf("2 - Supprimer un produit\n");
    printf("\t");
    printf("3 - Afficher un produit en particulier\n");
    printf("\t");
    printf("4 - Afficher tous les produits\n");
    printf("\t");
    printf("5 - Afficher total solde\n");
    printf("\t");
    printf("6 - Quitter la session\n");
    printf("\n");
}

Bool listIsEmpty(List list) {
    if(list == NULL)
        return true;

    return false;
}

//Définition d'un produit
Product *defineProduct(int index) {
    Product *temp = malloc(sizeof(*temp));

    temp->id = idCount;
    printf("Enter le nom du produit %d : ", index);
    scanf("%s", temp->name);

    printf("\nSon prix : ");
    scanf("%f", &temp->price);
    printf("\n"); 

    idCount++;
    nbrProduct++;

    return temp;
}

//Insertion du produit dans la liste
List insertProduct(List list, Product p) {
    listeProduct *newList = malloc(sizeof(*newList));

        newList->p = p;
        newList->next = NULL;

        if(!listIsEmpty(list)) {
           newList->next = list;
        }

    return newList;
}

// Supprimer un produit en particulier
List deleteProduct(List list, char nameProduct[]) {
    if (listIsEmpty(list)) {
        printf("Le stock est deja vide !\n");
        return list;
    }

    listeProduct *temp = list;
    listeProduct *prev = NULL;

    printf("Entrer le nom du produit a supprimer : ");
    scanf("%s", nameProduct);

    while (temp != NULL && strcmp(temp->p.name, nameProduct) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Produit non trouve !\n");
        return list;
    }

    if (prev == NULL) {
        // Le produit a supprimer est le premier de la liste
        list = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    nbrProduct--;

    printf("Produit supprime avec succes !\n");
    return list;
}


//Afficher tous les produits
void printAllProduct(List list) {

    if(listIsEmpty(list)) {
        printf("Rien a afficher, le stock est vide !\n");
        return ;
    }
    
    while(list != NULL) {
        printf("+----------+-------------------+--------------------+\n");
        printf("| ID : %2d  | NOM = %10s  | PRIX = %10.2f  |\n", list->p.id, list->p.name, list->p.price);
        list = list->next;
    }
    printf("+----------+-------------------+--------------------+\n");

    printf("\nNombre de produit = %d\n\n", nbrProduct);
}    

//Afficher seulement un produit
void printOneProduct(List list, char nameProduct[]) {

    if(listIsEmpty(list)) {
        printf("Rien a afficher, le stock est vide !\n");
        return ;
    }

    listeProduct *temp = list;
    listeProduct *prev = NULL;

    printf("Entrer le nom du produit a afficher : ");
    scanf("%s", nameProduct);

    while (temp != NULL && strcmp(temp->p.name, nameProduct) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Produit non trouve !\n");
        return;
    }

    if (prev == NULL) {
        // Le produit a supprimer est le premier de la liste
        list = temp->next;
    } else {
        prev->next = temp->next;
    }

    printf("+----------+-------------------+--------------------+\n");
    printf("| ID : %2d  | NOM = %10s  | PRIX = %10.2f  |\n", temp->p.id, temp->p.name, temp->p.price);
    printf("+----------+-------------------+--------------------+\n");
}

//Les prix de tous les prduits
void soldeProduct(List list) {
    float totalPrice = 0;

    if(listIsEmpty(list)) {
        printf("Pas de produit, solde 0\n");
        return ;
    }
    
    while(list != NULL) {
        totalPrice += list->p.price;
        list = list->next;   
    }

    printf("\n+-------------+--------------+\n");
    printf("| Solde total | %12.2f |\n", totalPrice);
    printf("+-------------+--------------+\n");
}