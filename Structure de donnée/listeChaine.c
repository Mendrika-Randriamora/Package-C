#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data; //Donnee
    struct Node* next; // Pour pointee au 2e element
};

struct Node* head = NULL;//tete de Node

void createList(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    head = newNode;
}

//insere un element au debut de la liste
void insertAtBeginning(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(int value, int position){
    if(position == 0){
        insertAtBeginning(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* current = head;//pour ne pas perdre head
    for(int i = 0; (i < position - 1) && (current != NULL); i++){
        current = current->next;
    }

    if(current == NULL){
        printf("Erreur : position %d invalide !\n", position);
        return;
    }
    //chainage
    newNode->next = current->next;//pour liee l'element derriere
    current->next = newNode;//pour le lie a l'element
}

void deleteNode(int value){
    struct Node* current = head;
    struct Node* previous = NULL;

    if(current != NULL && current->data == value){
        head = current->next;
        free(current); // liberer l'element
        return;
    }

    while(current != NULL && current->data != value){
        previous = current;
        current = current->next;
    }

    if(current == NULL){
        printf("Erreur : valeur %d introuvable\n", value);
        return;
    }

    // Chainage
    previous->next = current->next; //mandingana anle elem supprimer
    free(current);
}

void deleteAtPosition(int position){
    struct Node* current = head;
    if(position == 0)
    {
        head = current->next;
        free(current);
        return;     
    }

    for(int i = 0; (i < position - 1) && (current != NULL); i++){
        current = current->next;
    }

    if(current == NULL){
        printf("Erreur : position %d invalide ! \n", position - 1);
    }

    struct Node* delNode = current->next;
    if(delNode == NULL){
        printf("Aucun element dans la position %d\n", position);
    }

    //chainage
    current->next = delNode->next;
    free(delNode);

}

int main(){

    createList(10);
    insertAtBeginning(20);
    insertAtPosition(30, 1);

    //deleteNode(30);
    deleteAtPosition(1);

    printf("donnee de la tete = %d\n", head->data);
    printf("Donnee suivant = %d\n", head->next->data);

    return 0;
}
