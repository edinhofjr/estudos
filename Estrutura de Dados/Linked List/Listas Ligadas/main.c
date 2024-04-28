#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"

typedef struct Node{
    int id;
    struct Node *proximo;
}Node;

typedef struct LinkedList{
    Node *cabeca;
    int length;
}LinkedList;

int listavazia(LinkedList *list);
void criarLista(LinkedList *list);
void adicionarInicio(LinkedList *list);
void imprimirLista(LinkedList *list);
void liberarLista(LinkedList *list);
void lremover(LinkedList *list);
void rremover(LinkedList *list);
void adicionarFim(LinkedList *list);
Node* createNode();

int main(void) {
    LinkedList linkedlist;

    char op1[] = "1 - Adicionar Elemento no Inicio:";
    char op2[] = "2 - Adicionar Elementos no Fim:";
    char op3[] = "3 - Imprimir Lista:";
    char op4[] = "0 - Sair.";

    char *options[] = {op1,op2,op3,op4};

    linkedlist.cabeca = NULL;
    linkedlist.length = 0;

    int escolha = -1;

    while (escolha != 0) {
        system("cls");
        terminal("LISTA LIGADA", options, 4);
        scanf("%d", &escolha);
        system("cls");
        switch (escolha) {
            case 1:
                adicionarInicio(&linkedlist);
                system("cls");
                break;
            case 2:
                adicionarFim(&linkedlist);
                system("cls");
                break;
            case 3:
                imprimirLista(&linkedlist);
                system("pause");
                break;
            case 0:
                EXIT_SUCCESS;
        }
    }
}

int listavazia(LinkedList *list) {
    if (list->cabeca == NULL) {
        return 0;
    } else {
        return 1;
    }
}

void adicionarInicio(LinkedList *list) {
    Node *newNode = createNode();
    list->length++;

    if (listavazia(list) == 0) {
        list->cabeca = newNode;
        newNode->proximo = NULL;
    } else {
        newNode->proximo = list->cabeca;
        list->cabeca = newNode;
    }
}

void adicionarFim(LinkedList *list) {
    Node *newNode = createNode();
    list->length++;

    if (listavazia(list) == 0) {
        newNode->proximo = NULL;
        list->cabeca = newNode;
    } else {
        Node *auxNode = list->cabeca;
        while (auxNode->proximo != NULL) {
            auxNode = auxNode->proximo;
        }
        newNode->proximo = NULL;
        auxNode->proximo = newNode;
    }

}

void imprimirLista(LinkedList *list) {
    Node *auxNode = list->cabeca;
    while(auxNode != NULL) {
        printf("%d\n", auxNode->id);
        auxNode = auxNode->proximo;
    }
}

void liberarLista(LinkedList *list) {
    Node *auxNode = list->cabeca;
    Node *nextNode = NULL;
    while(auxNode != NULL) {
        nextNode = auxNode->proximo;
        free(auxNode);
        auxNode = nextNode;
    }
    list->cabeca = NULL;
}

void lremover(LinkedList *list) {
    int qtd = 0;
    printf("Insira quantos nodes deseja remover: ");
    scanf("%d",&qtd);

    Node *auxNode = list->cabeca;
    Node *nextNode = NULL;

    for ( int i = 0; i < qtd; i++) {
            nextNode = auxNode->proximo;
            free(auxNode);
            auxNode = nextNode;
    }
    list->cabeca = auxNode;
    list->length -= qtd;
}

void rremover(LinkedList *list) {
    int qtd = 0;
    printf("Insira quantos nodes deseja remover: ");
    scanf("%d",&qtd);

    Node *auxNode = list->cabeca;
    Node *nextNode = NULL;
    int targetNode = list->length - qtd - 1;

    for (int i = 0; i < targetNode; i++) {
        auxNode = auxNode->proximo;
        nextNode = auxNode->proximo;
        auxNode->proximo = NULL;
    }

    auxNode = nextNode;
    while (auxNode != NULL) {
        nextNode = auxNode->proximo;
        free(auxNode);
        auxNode = nextNode;
    }
    list->length -=2;
}

Node* createNode(){
    Node *newNode = (Node *) malloc(sizeof(Node));
    printf("Insira um ID para o novo nodo: ");
    scanf("%d", &newNode->id);
    return newNode;
}