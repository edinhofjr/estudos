#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int id;
    struct Node *next;
}Node;

typedef struct Stack{
    Node *head;
}Stack;

void stacking(Stack *stk, int value) {
    Node *newNode = (Node *) malloc(sizeof(Node));

    if (stk->head == NULL) {
        stk->head = newNode;
        newNode->next = NULL;
        newNode->id = value;
    } else {
        newNode->next = stk->head;
        newNode->id = value;
        stk->head = newNode;
    }
}

void pop(Stack *stk) {
    if ( stk->head == NULL) {
        printf("Pilha vazia.\n");
    } else {
        printf("%d\n", stk->head->id);
        stk->head = stk->head->next;

    }
}

void peek(Stack *stk) {
    if (stk->head == NULL) {
        printf("Pilha vazia.\n");
    } else {
        printf("%d\n", stk->head->id);
    }
}
int main(void) {
    Stack stack;
    stack.head = NULL;
    stacking(&stack, 1);
    stacking(&stack, 2);
    pop(&stack);
    peek(&stack);
}
