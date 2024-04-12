// =================== Support Code =================
// Hashmap
//
// - Implement each of the functions to create a working hashmap.
// - Do not change any of the function declarations
//   - (i.e. hashmap_t* hashmap_create() should not have additional arguments)
// - You should not have any 'printf' statements in your functions other
//   than functions that explicitly ask for printf  output.
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// - You may add any helper functions that you think you need (if any, or otherwise for debugging)
// ==================================================
#ifndef MY_HASHMAP_T
#define MY_HASHMAP_T

#include <stdlib.h>
#include <string.h>

// A key value pair
// This is specifically for a (char*, int) key value pair
typedef struct pair
{
    char *key;
    int value;
} pair_t;

// Each node holds a key and a value
typedef struct node
{
    struct node *next;
    pair_t *kv; // 'kv' stands for key/value pair
} node_t;

// Simple hash function that will put a key into a bucket
// is this a good hash function?
int stringHash(char *myKey, int numberOfBuckets)
{
    return strlen(myKey) % numberOfBuckets;
}

// Your hash function goes here
//  you can rename it and change the signature if you need to
//      but make sure your hash function starts on line 42 of this file
int yourHash(char *myKey, int numberOfBuckets)
{
    // using djb2 algorithm
    unsigned long hash = 5381;
    int c;
    while ((c = *myKey++))
    // the *myKey++ syntax is a compact way of accessing the current character
    // and then incrementing the pointer.
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % numberOfBuckets;
}

// Create a function prototype to a function that takes
// in a char* and an int.
typedef int (*hashFunctionPointer)(char *, int);

// Chained implementation of a hashmap
typedef struct hashmap
{
    unsigned int buckets;  // i.e. size of the hashmap
    node_t **arrayOfLists; // An array of linked lists for our buckets
    // Read another way
    //      - an array of node_t*

    // A function pointer to a hash function
    // The hash_function must take in a 'char*' as a key, and have a
    // second parameter specifying the number of buckets.
    hashFunctionPointer hashFunction;
} hashmap_t;

// A helper function to free the given node.
static void free_node(node_t *node);

// A helper function to return a copy of the given string.
static char *my_strcpy(const char *str);

// Creates a new hashmap
// Allocates memory for a new hashmap.
// Initializes the capacity(i.e. number of buckets)
hashmap_t *hashmap_create(unsigned int _buckets)
{
    // Checks the given capacity.
    if (_buckets == 0)
    {
        return NULL;
    }
    // Allocates memory for our hashmap.
    hashmap_t *map = (hashmap_t *)malloc(sizeof(hashmap_t));
    if (map == NULL)
    {
        return NULL;
    }

    // Sets the number of buckets.
    map->buckets = _buckets;

    // Creates the array of lists for each bucket.
    map->arrayOfLists = (node_t **)malloc(sizeof(node_t *) * _buckets);
    if (map->arrayOfLists == NULL)
    {
        free(map);

        return NULL;
    }

    // Initializes the array of lists for each bucket.
    for (int i = 0; i < _buckets; i++)
    {
        map->arrayOfLists[i] = NULL;
    }

    // Setups our hashFunction to point to our stringHash function.
    map->hashFunction = yourHash;

    // Returns the new map that we have created
    return map;
}

// Frees a hashmap
// Responsibility to free a hashmap that has been previously allocated.
// Must also free all of the chains in the hashmap
// This function should run in O(n) time
void hashmap_delete(hashmap_t *_hashmap)
{
    if (_hashmap == NULL)
    {
        return;
    }

    for (int i = 0; i < _hashmap->buckets; i++)
    {
        node_t *iterator = _hashmap->arrayOfLists[i];

        while (iterator != NULL)
        {
            node_t *next_node = iterator->next;
            free_node(iterator);
            iterator = next_node;
        }
    }

    free(_hashmap->arrayOfLists);
    free(_hashmap);
}

// Returns a boolean value if a key has been put into
// the hashmap
//  - Returns a '1' if a key exists already
//  - Returns a '0' if the key does not exist
//  - Returns a '-9999' if the hashmap is NULL
// The algorithm is:
//  - Call the _hashmap's hash function on the key
//  - Search that bucket to see if the key exists.
// This function should run in average-case constant time
int hashmap_hasKey(hashmap_t *_hashmap, char *key)
{
    if (_hashmap == NULL)
    {
        return -9999;
    }

    unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);

    node_t *iterator = _hashmap->arrayOfLists[bucket];
    while (iterator != NULL)
    {
        if (strcmp(iterator->kv->key, key) == 0)
        {
            return 1;
        }

        iterator = iterator->next;
    }

    return 0;
}

// Insert a new key/value pair into a hashmap
// The algorithm is:
//  - If a key already exists, do not add it--return
//  - Call the _hashmap's hash function on the key
//  - Store the key/value pair at the end of the buckets chain
//      - You should malloc the key/value in this function
// This function should run in average-case constant time
void hashmap_insert(hashmap_t *_hashmap, char *key, int value)
{
    if (_hashmap == NULL)
    {
        exit(1);
    }

    // If a key already exists, does nothing and returns.
    if (hashmap_hasKey(_hashmap, key))
    {
        return;
    }

    // Creates the new pair.
    pair_t *new_pair = (pair_t *)malloc(sizeof(pair_t));
    if (new_pair == NULL)
    {
        exit(1);
    }

    // Copies the new key.
    new_pair->key = my_strcpy(key);
    if (new_pair->key == NULL)
    {
        exit(1);
    }

    new_pair->value = value;

    // Creates the new node.
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL)
    {
        exit(1);
    }
    new_node->kv = new_pair;
    new_node->next = NULL;

    // Locates the bucket.
    unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);

    // Adds the new node.
    node_t *iterator = _hashmap->arrayOfLists[bucket];
    if (iterator == NULL)
    {
        _hashmap->arrayOfLists[bucket] = new_node;
    }
    else
    {
        while (iterator->next != NULL)
        {
            iterator = iterator->next;
        }

        iterator->next = new_node;
    }
}

// Return a value from a key
// Returns 99999 if the key is not found
// The algorithm is:
//  - If the key does not exist, then--return 99999 if not found.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and return the value
// This function should run in average-case constant time
int hashmap_getValue(hashmap_t *_hashmap, char *key)
{
    if (_hashmap == NULL)
    {
        return -9999;
    }

    // May first use hashmap_hasKey() here, but the following way may be more efficient.

    unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);

    node_t *iterator = _hashmap->arrayOfLists[bucket];
    while (iterator != NULL)
    {
        if (strcmp(iterator->kv->key, key) == 0)
        {
            return iterator->kv->value;
        }

        iterator = iterator->next;
    }

    return 99999;
}

// Remove a key from a hashmap
// The algorithm is:
//  - Determine if the key exists--return if it does not.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and then remove it
// This function should run in average-case constant time
void hashmap_removeKey(hashmap_t *_hashmap, char *key)
{
    // calculates the hash value of the key
    int bucketIndex = _hashmap->hashFunction(key, _hashmap->buckets);
    // get the head node of the linked list at the calculated bucket index
    node_t *head = _hashmap->arrayOfLists[bucketIndex];
    node_t *prev = NULL;
    // traverse the linked list to find the node with the given key
    while (head != NULL && strcmp(head->kv->key, key) != 0)
    {
        prev = head;
        head = head->next;
    }
    // if the key was not found in the linked list
    if (head == NULL)
    {
        return;
    }
    // Case 1: the node that needs to be removed is the head node.
    if (head == _hashmap->arrayOfLists[bucketIndex])
    {
        _hashmap->arrayOfLists[bucketIndex] = head->next;
    }
    else
    {
        // Case 2: the node that needs to be removed is not the head node.
        prev->next = head->next;
    }
    // free the memory allocated for the key and the node
    free(head->kv->key);
    return;
}

// Prints all of the keys in a hashmap
// The algorithm is:
//  - Iterate through every bucket and print out the keys
// This function should run in O(n) time
void hashmap_printKeys(hashmap_t *_hashmap)
{
    if (_hashmap == NULL)
    {
        return;
    }

    for (int i = 0; i < _hashmap->buckets; i++)
    {
        printf("Bucket# %d\n", i);

        node_t *iterator = _hashmap->arrayOfLists[i];
        while (iterator != NULL)
        {
            printf("\tKey=%s\tValue=%d\n", iterator->kv->key, iterator->kv->value);
            iterator = iterator->next;
        }
    }
}

// A helper function to free the given node.
static void free_node(node_t *node)
{
    if (node == NULL)
    {
        return;
    }

    free(node->kv->key);
    free(node->kv);
    free(node);
}

static char *my_strcpy(const char *str)
{
    char *new_str = (char *)malloc(strlen(str) * sizeof(char) + 1);
    if (new_str == NULL)
    {
        return NULL;
    }

    strcpy(new_str, str);

    return new_str;
}

#endif