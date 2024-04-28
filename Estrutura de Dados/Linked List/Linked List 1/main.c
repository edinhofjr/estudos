#include <stdio.h>
#include <malloc.h>


typedef struct Node{
    int id;
    struct Node *nextNode;
}Node;
Node *head;

void insertInBeginning(int value) {
    Node *newNode = (Node *) malloc (sizeof(Node));

    newNode->id = value;
    newNode->nextNode = head;
    head = newNode;
}

void checarLista(Node *no) {
    if (no == NULL) {
        printf("Lista vazia.");
    }
}

void printList(Node *headNode) {
    Node *nAux = headNode;
    while (nAux != NULL) {
        printf("%d\t", nAux->id );
        nAux = nAux->nextNode;
    }
}

int main() {
    head = NULL;

    insertInBeginning(1);
    insertInBeginning(2);
    printList(head);
}

