#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int nom_arret;
    struct Node *prochain_arret;
    struct Node *prochain_arret2;
} Node;

Node* createNode(int nom_arret) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->nom_arret = nom_arret;
        newNode->prochain_arret = NULL;
        newNode->prochain_arret2 = NULL;
    }
    return newNode;
}

void insert_end(Node* head[], int nom_arret) {
    Node* newNode = createNode(nom_arret);
    if (newNode != NULL) {
        if (*head == NULL) {
            *head = newNode;
        } else {
            Node* current_node = *head;
            while (current_node->prochain_arret != NULL) {
                current_node = current_node->prochain_arret;
            }
            current_node->prochain_arret = newNode;
        }
    } else {
        printf("Error : Create a new node is impossible.\n");
    }
}


void afficherListe(Node* head) {
    Node* current_node = head;
    printf("Values of the linked list :\n");
    while (current_node != NULL) {
        printf("%d, %d\n", current_node->nom_arret, current_node->prochain_arret2);
        current_node = current_node->prochain_arret;
    }
    printf("NULL\n");
}

int main() {
    // creation de 4 lignes principales
    Node* ligne1 = NULL;
    Node* ligne2 = NULL;
    Node* ligne3 = NULL;
    Node* ligne4 = NULL;

    for (int i = 0; i < 2; ++i) {
        insert_end(&ligne1, i+1);
        insert_end(&ligne2, i+3);
    }
    for (int i = 0; i < 3; ++i) {
        insert_end(&ligne3, i+5);
    }
    for (int i = 0; i < 4; ++i) {
        insert_end(&ligne4, i+8);
    }

    afficherListe(ligne1);
    afficherListe(ligne2);
    afficherListe(ligne3);
    afficherListe(ligne4);

    //creation de la ligne 5 à partir des arrets des 4 lignes principales sauf que ca modifie les prochains arrets des
    //lignes principales à partir de la 2, donc j'ai essayé de creer 2 arrets suivant au lieu d'un

    //premiere méthode pour creer une ligne 5 mais en changeant les autres lignes
    /* Node* current_node = ligne1;
    current_node = current_node->prochain_arret2;
    Node *ligne5 = createNode(current_node->nom_arret);
    current_node =ligne2;
    current_node = current_node->prochain_arret2;
    ligne5->prochain_arret2 = current_node;
    current_node =ligne3;
    current_node = current_node->prochain_arret2;
    ligne5->prochain_arret2->prochain_arret2 = current_node;
    current_node =ligne4;
    ligne5->prochain_arret2->prochain_arret2->prochain_arret2 = current_node;
    current_node = NULL;
    ligne5->prochain_arret2->prochain_arret2->prochain_arret2->prochain_arret2 = current_node;
    afficherListe(ligne5);

    //deuxieme méthode pour creer une ligne 5 mais toujours en changeant les autres lignes
    Node *ligne5 = createNode(ligne1->prochain_arret->nom_arret);
    ligne5->prochain_arret = ligne2->prochain_arret;
    ligne5->prochain_arret->prochain_arret2= ligne3->prochain_arret;
    /*ligne5->prochain_arret->prochain_arret->prochain_arret= ligne4;
    ligne5->prochain_arret->prochain_arret->prochain_arret->prochain_arret =NULL;

    //creation de la ligne 6 à partir des arrets des 4 lignes principales
    Node* current_node2 = ligne2;
    Node *ligne6 = createNode(current_node2->nom_arret);

    current_node2 =ligne3;
    current_node2 = current_node2->prochain_arret2;
    ligne6->prochain_arret2 = current_node2;

    /*current_node2 =ligne4;
    current_node2 = current_node2->prochain_arret;


    ligne6->prochain_arret->prochain_arret = current_node2;
    current_node2 = NULL;
    ligne6->prochain_arret->prochain_arret->prochain_arret = current_node2;*/


    //afficherListe(ligne5);
    afficherListe(ligne2);







    return 0;
}
