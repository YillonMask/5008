#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// to store key-value pairs ,key is the string of name, value is the integer which is the size of the name
typedef struct pair
{
    char *name;
    int size;
} pair_t;

// Structure for each node in the linked list:node_t
typedef struct node
{
    pair_t *kv; // linkedlist if key-value pairs
    struct node *next;
} node_t;

typedef int (*hashFunPtr)(char *, int);
// Structure for the hash table:hashmap_t
// It contains an array of pointers to node_t*
// the size of array is no. of buckets
typedef struct hashmap
{
    int buckets;
    node_t **arrayOfNodes; // dynamic array of pointers to node_t*
    hashFunPtr hashFun;
} hashmap_t;

// hash function that return the size of the string
int StringHash(char *key, int buckets)
{
    return strlen(key) % buckets; // make sure the index is within the range of the array
}

// to create a hashmap that has specified number of buckets
// allocate memory for the hashmap and its array of nodes
// initialize the array of nodes to NULL
// set the hash function to StringHash
hashmap_t *createHashMap(int buckets)
{
    hashmap_t *map = (hashmap_t *)malloc(sizeof(hashmap_t));
    map->buckets = buckets;
    // the map contains the array of pointers to node_t*
    map->arrayOfNodes = (node_t **)malloc(buckets * sizeof(node_t *));
    for (int i = 0; i < buckets; i++)
    {
        map->arrayOfNodes[i] = NULL;
    }
    map->hashFun = StringHash;
    return map;
}

// to insert a key-value pair into the hashmap
// copies the key and assigns the value to the new pair
// calculates the buckets using the hash function
// handles the collision by adding the new pair to the head of linked list
void insert(hashmap_t *map, char *key, int value)
{
    pair_t *newPair = (pair_t *)malloc(sizeof(pair_t));
    newPair->name = key;
    newPair->size = value;
    int index = map->hashFun(key, map->buckets);
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->kv = newPair;
    newNode->next = map->arrayOfNodes[index];
    map->arrayOfNodes[index] = newNode;
}
// print the key-value pairs in the hashmap organized by the buckets
void printHashMap(hashmap_t *map)
{
    for (int i = 0; i < map->buckets; i++)
    {
        node_t *current = map->arrayOfNodes[i];
        printf("Bucket %d: ", i);
        while (current != NULL)
        {
            printf("(%s,%d) ", current->kv->name, current->kv->size);
            current = current->next;
        }
        printf("\n");
    }
}
// to free the memory allocated for the hashmap

void freeHashMap(hashmap_t *map)
{
    for (int i = 0; i < map->buckets; i++)
    {
        node_t *current = map->arrayOfNodes[i];
        while (current != NULL)
        {
            node_t *temp = current;
            current = current->next;
            free(temp->kv->name);
            free(temp->kv);
            free(temp);
        }
    }
    free(map->arrayOfNodes);
    free(map);
}

int main()
{
    hashmap_t *map = createHashMap(5);
    insert(map, "John", 4);
    insert(map, "Doe", 3);
    insert(map, "Jane", 5);
    insert(map, "Smith", 5);
    insert(map, "Doe", 3);
    insert(map, "Jane", 5);
    insert(map, "Smith", 5);
    insert(map, "Doe", 3);
    insert(map, "Jane", 5);
    insert(map, "Smith", 5);
    printHashMap(map);
    freeHashMap(map);
    return 0;
}
