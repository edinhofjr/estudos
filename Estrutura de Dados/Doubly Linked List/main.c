#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    struct Node *antNode;
    struct Node *nextNode;
}Node;

typedef struct DoubleLinkedList {
    Node *head;
}DoubleLinkedList;

bool isListEmpty(DoubleLinkedList *list);
void insertStart(DoubleLinkedList *list);
void insertEnd(DoubleLinkedList *list);
int LinkedListLength(DoubleLinkedList *list);
void printList(DoubleLinkedList *list);
void removeById(DoubleLinkedList *list, int id);

int main() {
    DoubleLinkedList doublelinkedlist;
    doublelinkedlist.head = NULL;

    insertStart(&doublelinkedlist);
    insertStart(&doublelinkedlist);
    insertEnd(&doublelinkedlist);
    removeById(&doublelinkedlist, 0);
    printList(&doublelinkedlist);
}

void removeById(DoubleLinkedList *list, int id) {
    Node *no = list->head;

    while( no != NULL) {
        if (no->id == id) {
            if (no->antNode == NULL) {
                Node *oldHead = no;
                list->head = oldHead->nextNode;
                no->nextNode->antNode = NULL;
                free(oldHead);
            } else if ( no->nextNode == NULL) {
                no->antNode->nextNode = NULL;
            } else {
                no->antNode->nextNode = no->nextNode;
                no->nextNode->antNode = no->antNode;
            }
        }
    no = no->nextNode;
    }
}
int LinkedListLength(DoubleLinkedList *list) {
    int c = 0;
    Node *no = list->head;

    while (no != NULL) {
        c++;
        no = no->nextNode;
    }
    return  c;
}

bool valueInLinkedList(DoubleLinkedList *list, int target) {
    Node *no = list->head;
    while(no != NULL) {
        if (no->id == target) {
            return true;
        }
        no = no->nextNode;
    }
    return false;
}

int findValue(DoubleLinkedList *list) {
    int c = 0;
    while(valueInLinkedList(list, c)) {
        c++;
    }
    return c;
}


void printList(DoubleLinkedList *list) {
    Node *no = list->head;
    while ( no != NULL){
        printf("%d\t", no->id);
        no = no->nextNode;
    }
}
void insertStart(DoubleLinkedList *list) {
    Node *newNode = (Node *) malloc(sizeof(Node));

    if (isListEmpty(list) == true) {
        newNode->id = 0;
        newNode->antNode = NULL;
        newNode->nextNode = NULL;
        list->head = newNode;
    } else {
        newNode->id = findValue(list);
        newNode->antNode = NULL;
        newNode->nextNode = list->head;
        newNode->nextNode->antNode = newNode;
        list->head = newNode;
    }
}

void insertEnd(DoubleLinkedList *list) {
    Node *newNode = (Node *) malloc(sizeof(Node));

    if (isListEmpty(list) == true) {
        newNode->id = 0;
        newNode->antNode = NULL;
        newNode->nextNode = NULL;
        list->head = newNode;
    } else {
        Node *no = list->head;
        while( no->nextNode != NULL ) {
            no = no->nextNode;
        }
        no->nextNode = newNode;
        newNode->antNode = no;
        newNode->nextNode = NULL;
        newNode->id = findValue(list);

    }

}

bool isListEmpty(DoubleLinkedList *list) {
    if ( list->head == NULL ) {
        return true;
    } else {
        return false;
    }
}