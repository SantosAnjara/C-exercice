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
int ajouter_fin(Node **tete, int valeur){
    if (tete == NULL){
        return 0;
    }
    Node *nouveau = creer_noeud(valeur);
    if (nouveau == NULL){
        return 1;
    }
    if (*tete == NULL){
        *tete = nouveau;
        return 0;
    }

    Node *courant = *tete;
    while (courant->next != NULL) {
        courant = courant->next;
    }
    courant->next = nouveau;
    return 0;
}

void liberer(Node **tete){
    if (tete == NULL){
        return;
    }
    Node *courant = *tete;
    Node *suivant;

    while (courant != NULL){
        suivant = courant->next;
        free(courant);
        courant = suivant;
    }
    *tete = NULL;
}

int main()
{
    Node *tete = NULL;
    ajouter_fin(&tete, 4);
    ajouter_debut(&tete, 3);
    ajouter_debut(&tete, 2); // liste vide : crée [2 | NULL], tete le désigne
    ajouter_debut(&tete, 5);
    ajouter_debut(&tete, 9);
    ajouter_fin(&tete, 3);

    afficher(tete);
    liberer(&tete);
    return 0;
}
