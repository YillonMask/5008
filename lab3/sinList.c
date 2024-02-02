#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}
node_t;

//since the return of createNode function is address of newNode
//we need node_t* as function return
node_t* createNode(int data){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	if (newNode == NULL){
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL; //initialize the next to NULL
	return newNode;
}

void printNode(node_t* node){
	const node_t* itr = node;//itr = &node1;
	while (itr != NULL){
		//(&node1)->data
		printf("%d->", itr->data);
		itr = itr->next;
		//itr = (&node1)->next;
	}
	printf("NULL\n");
}

int main(){
	node_t* node1;
	node_t* node2;
	node_t* node3;
	node_t* node4;
	
	/**
	 * initialize node w/o creatNode function
	node1.data = 10;
	node2.data = 20;
	node3.data = 30;
	node4.data = 40;
	*/

	//initialize node w/h createNode function
	node1 = createNode(10);
	node2 = createNode(20);
	node3 = createNode(30);
	node4 = createNode(40);

	//node1 is pointer. so we need to use -> to dereference
	//pointer -> next = pointer	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	
	//since the node1 is pointer, we can use node1 itself as argument
	printNode(node1);

	free(node1);
	free(node2);
	free(node3);
	free(node4);

	return 0;
}
