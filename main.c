#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valeur;
    struct Node *next;
}Node;


Node *creer_noeud(int valeur){
    Node *node = malloc(sizeof(*node));

    if (node == NULL){
        return NULL;
    }
    node->valeur = valeur;
    node->next = NULL;

    return node;
}

int ajouter_debut(Node **tete, int valeur){
    if (tete == NULL){
        return 1;
    }
    Node *nouveau = creer_noeud(valeur);
    if (nouveau == NULL){
        return 1;
    }
    nouveau->next = *tete;
    *tete = nouveau;
    return 0;
}

void afficher(const Node *tete){
    const Node *temp = tete;
    while (temp != NULL){
        printf("%d\n", temp->valeur);
        temp = temp->next;
    }
}

int main()
{
    Node *tete = NULL;
    ajouter_debut(&tete, 2); // liste vide : crée [2 | NULL], tete le désigne
    ajouter_debut(&tete, 5);
    ajouter_debut(&tete, 9);

    afficher(tete);
    return 0;
}
