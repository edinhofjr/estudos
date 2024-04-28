#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node {
    int id;
    struct Node *nextNode;
} Node;

typedef struct LinkedList{
    Node *head;
}LinkedList;

void printList(LinkedList *list) {
    Node *no = list->head;
    while (no != NULL) {
        printf("%d\t", no->id);
        no = no->nextNode;
    }
}

int LinkedListLength(LinkedList *list) {
    int c = 0;
    Node *no = list->head;

    while (no != NULL) {
        c++;
        no = no->nextNode;
    }
    return  c;
    printf("\nA lista tem %d itens.\n", c);
}

bool valueInLinkedList(LinkedList *list, int target) {
    Node *no = list->head;
    while(no != NULL) {
        if (no->id == target) {
            return true;
        }
        no = no->nextNode;
    }
}

void insertBeginning(LinkedList *list) {

    Node *newNode = (Node *) malloc(sizeof(Node));
    int value;

    if ( list->head != NULL) {
        newNode->id = list->head->id + 1;
    } else {
        newNode->id = 0;
    }
    newNode->nextNode = list->head;
    list->head = newNode;
}

void insertEnd(LinkedList *list) {
    Node *newNode = (Node *) malloc(sizeof(Node));

    newNode->id = LinkedListLength(list);

    Node *no = list->head;
    while(no->nextNode != NULL) {
        no = no->nextNode;
    }
    no->nextNode = newNode;
    newNode->nextNode = NULL;

}

void removeNodeByIndex(LinkedList *list, int index) {
    int i = 0;
    Node *no = list->head;


    if ( index == 0 ) {
        list->head = list->head->nextNode;
    } else {
        while (i != index) {
            if ( no->nextNode->nextNode == NULL ) {
                no->nextNode = NULL;
                i++;
            } else if ( i == index - 1 ) {
                Node *tempNode = no->nextNode;
                no->nextNode = no->nextNode->nextNode;
                free(tempNode);
                i++;
            } else {
                    no = no->nextNode;
                    i++;
                }
            }
        }


    }

int main() {
    LinkedList linkedList;
    linkedList.head = NULL;


    insertBeginning(&linkedList);
    insertBeginning(&linkedList);
    insertBeginning(&linkedList);
    insertEnd(&linkedList);
    insertEnd(&linkedList);
    printList(&linkedList);
    LinkedListLength(&linkedList);
    removeNodeByIndex(&linkedList,1);
    printf("\n");
    printList(&linkedList);
    printf("\n%d", valueInLinkedList(&linkedList, 5));
}
