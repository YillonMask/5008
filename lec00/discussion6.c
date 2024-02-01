#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node_t;

typedef struct slist{
    node_t* head;
    node_t* tail;
    int size;
} slist_t;

void printNodes(node_t* node){
    node_t* itr = node;
    while (itr != NULL){
        printf("%d ", itr->data);
        itr = itr->next;
    }
    printf("\n");
}


int main(){
    slist_t* newList = (slist_t*)malloc(sizeof(slist_t));
    newList->head = NULL;
    newList->tail = NULL;

    node_t node1;
	node_t node2;
	node_t node3;
    newList->head = &node1;


    node1.data = 4;
	node2.data = 5;
	node3.data = 6;

    newList->head->next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = newList->tail;

    printNodes(newList->head);
}