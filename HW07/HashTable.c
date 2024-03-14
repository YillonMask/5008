// name: Xinrui Yi
// email: yi.xin@northeastern.edu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 50

typedef struct {
    char *word;
    int frequency;
} HashItem;

HashItem* hashTable[TABLE_SIZE];

unsigned int hash(const char *word) {
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int word_len = strlen(word);

    //insert your code below to implement your hashing logic 
    // .....
    for(;i < word_len;i++){
        value = (value * 37 + word[i]) % TABLE_SIZE;
    }
    return value;
    //insert your code above
}

void insert(const char *word) {
    unsigned int index = hash(word);
    
    // Linear probing to find an empty slot or a slot with the same key
    // hashtable is not empty and the word is not the same as the word in the bucket
    while (hashTable[index] != NULL && strncmp(hashTable[index]->word, word, TABLE_SIZE) != 0) {
        // insert your code here
        index = (index + 1) % TABLE_SIZE;
    }
    
    // If the slot is occupied, update the frequency; otherwise, insert a new item
    if (hashTable[index] != NULL) {
        // insert your code here 
        hashTable[index]->frequency++;
    } else {    
    // Allocate memory for a new HashItem and copy the word
    //insert you code below
    // ....
    hashTable[index] = (HashItem*)malloc(sizeof(HashItem));
    hashTable[index]->word = strdup(word);
    hashTable[index]->frequency = 1;
    //insert your code above
    }
}

int cmp(const void *a, const void *b) {
    //insert your code to to sort hash items by frequency in ascending order
    //.....
    HashItem *item_a = *(HashItem **)a;
    HashItem *item_b = *(HashItem **)b;
    return item_b->frequency - item_a->frequency;
    //insert your code above
}

void printFrequencies() {
    printf("Word Frequencies:\n");

    // Temporary array to sort items by frequency
    HashItem *sortedItems[TABLE_SIZE];
    int sortedIndex = 0;

    // copy non-null hash table entries to the temporary array
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (hashTable[i] != NULL) {
            sortedItems[sortedIndex++] = hashTable[i];
        }
    }

    // we use qsort to sort the temporary array of hash items by frequency
    qsort(sortedItems, sortedIndex, sizeof(HashItem*), cmp);

    // print the sorted word frequencies
    for (int i = 0; i < sortedIndex; ++i) {
        printf("%s: %d\n", sortedItems[i]->word, sortedItems[i]->frequency);
    }
}

int main() {
    char *words[] = {"apple", "banana", "apple", "orange", "banana", "apple"};
    int wordsCount = 6;

    for (int i = 0; i < wordsCount; ++i) {
        insert(words[i]);
    }

    printFrequencies();

    // Cleanup
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (hashTable[i] != NULL) {
            free(hashTable[i]->word);
            free(hashTable[i]);
        }
    }

    return 0;
}