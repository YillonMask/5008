#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}
node_t;

typedef struct slist{
	node_t* head;
	node_t* tail;
	int size;
}
slist_t;

slist_t* makeSList(){
	slist_t* newList = (slist_t*)malloc(sizeof(slist_t));
	if(newList != NULL){
		return NULL;
	}

	newList->head = NULL;
	newList->tail = NULL;
	newList->size = 0;
	return newList;
}

node_t* makeNode(int data);

int push_front(slist_t* slist, int value){
	if(slist == NULL){
		return 0;
	}
	node_t* newNode = makeNode(value);
	if(newNode == NULL){
		return 0;
	}
	if ( slist->head == NULL){
		slist->head = newNode;
		slist->tail = newNode; //newNode is both head and tail
	}
	else{
		newNode->next = slist->head;
		slist->head = newNode;
	}
	slist->size++;
	return 1;
}	

void printNodes(node_t* node){
	const node_t* itr = node;//itr = &node1;
	while (itr != NULL){
		//(&node1)->data
		printf("%d ", itr->data);
		itr = itr->next;
		//itr = (&node1)->next;
	}
	printf("\n");
}

node_t* makeNode(int data){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	if(newNode == NULL){
		return NULL;
	}
	
	newNode->data = data;
	return newNode;
}

void freeNode(node_t* node){
	if(node == NULL){
		return;
	}

	free(node);
}

int main(){
	/*
	node_t node1;
	node_t node2;
	node_t node3;
	
	//initial the data
	node1.data = 1;
	node2.data = 2;
	node3.data = 3;
	
	//makeNode method to initial the data
	node_t* node1 = makeNode(1);
        node_t* node2 = makeNode(2);
        node_t* node3 = makeNode(3);
	

	//link the node
	//since the node is pointer, we need to use arrow to access its next
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	
	printNodes(node1);
	
	freeNode(node1);
	freeNode(node2);
	freeNode(node3);
	*/
	// Create a new singly linked list
    	slist_t* myList = makeSList();

    	// Add elements to the list
	if (!push_front(myList, 3) || !push_front(myList, 2) || !push_front(myList, 1)) {
        fprintf(stderr, "Failed to add elements to the list.\n");
		return 1;
    }
	printNodes(myList->head);
	
	return 0;
}
