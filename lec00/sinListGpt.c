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

slist_t* makeSList(){
    slist_t* newList = (slist_t*)malloc(sizeof(slist_t));
    if(newList == NULL){
        return NULL; // If allocation fails, return NULL
    }

    newList->head = NULL;
    newList->tail = NULL;
    newList->size = 0;
    return newList; // Return the new list
}

node_t* makeNode(int data){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if(newNode == NULL){
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL; // Initialize next to NULL
    return newNode;
}

int push_front(slist_t* slist, int value){
    if(slist == NULL){
        return 0; // If the list doesn't exist, return 0
    }
    node_t* newNode = makeNode(value);
    if(newNode == NULL){
        return 0; // If node creation fails, return 0
    }
    if (slist->head == NULL){ // If the list is empty
        slist->head = newNode;
        slist->tail = newNode; // New node is now both head and tail
    } else { // If the list is not empty
        newNode->next = slist->head; // Point new node to the current head
        slist->head = newNode; // Update head to the new node
    }
    slist->size++; // Increment the size of the list
    return 1; // Success
}

void printNodes(node_t* node){
    node_t* itr = node;
    while (itr != NULL){
        printf("%d ", itr->data);
        itr = itr->next;
    }
    printf("\n");
}

void freeNode(node_t* node){
    if(node == NULL){
        return;
    }
    free(node);
}

void freeSList(slist_t* slist){
    if(slist == NULL){
        return;
    }

    node_t* current = slist->head;
    while(current != NULL){
        node_t* temp = current;
        current = current->next;
        free(temp); // Free each node
    }
    free(slist); // Finally, free the list structure itself
}

int main(){
    // Create a new singly linked list
    slist_t* myList = makeSList();

    // Add elements to the list
    push_front(myList, 3);
    push_front(myList, 2);
    push_front(myList, 1);

    // Print the list
    printNodes(myList->head);

    // Free all nodes and the singly linked list
    freeSList(myList);

    return 0;
}
