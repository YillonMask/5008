#include <stdio.h>
#include <stdlib.h>

typedef struct node{
        int data;
        struct node* next;
	struct node* prev;//also create prev pointer
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
	newNode->prev = NULL; //intialize the prev to NULL
	newNode->next = NULL; //initialize the next to NULL
        return newNode;
}

void printForwNode(node_t* node){
        const node_t* itr = node;//itr = &node1;
        while (itr != NULL){
                //(&node1)->data
                printf("%d->", itr->data);
                itr = itr->next;
                //itr = (&node1)->next;
        }
        printf("NULL\n");
}

void printBackNode(node_t* node){
	const node_t* itr = node;//itr = &node1;
	while (itr != NULL){
		//(&node1)->data
		printf("%d->", itr->data);
		itr = itr->prev;
		//itr = (&node1)->prev;
	}
	printf("NULL\n");
}

int main(){
        node_t* node1;
        node_t node2;
        node_t node3;

        //initialize node w/o creatNode function
        node2.data = 20;
        node3.data = 30;

        //initialize node w/h createNode function
        node1 = createNode(10);

        //node1 is pointer. so we need to use -> to dereference
        //pointer -> next = pointer     
        node1->next = &node2;
	node1->prev = NULL;
        node2.next = &node3;
	node2.prev = node1;
        node3.next = NULL;
	node3.prev = &node2;

        //since the node1 is pointer, we can use node1 itself as argument
        printForwNode(node1);
	printBackNode(&node3);
	

        free(node1);

        return 0;
}
