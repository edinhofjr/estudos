#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int id;
    struct Node *next;
}Node;

typedef struct Queue{
    Node *head;
}Queue;

void queuing(Queue *que, int value) {
    Node *newNode = (Node *) malloc(sizeof(Node));

    if (que->head == NULL) {
        que->head = newNode;
        newNode->next = NULL;
        newNode->id = value;
    } else {
        Node *no = que->head;

        while ( no->next != NULL ) {
            no = no->next;
        }
        no->next = newNode;
        newNode->next = NULL;
        newNode->id = value;
    }
}

void dequeue(Queue *que) {
    if ( que->head == NULL) {
        printf("Lista vazia.\n");
    } else {
        printf("Item %d foi removido", que->head->id );
        que->head = que->head->next;
    }
}
int main() {
    Queue queue;
    queue.head = NULL;

    queuing(&queue, 1);
    queuing(&queue,2);
    queuing(&queue, 3);
    dequeue(&queue);
}
