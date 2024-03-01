// name: Xinrui Yi
// email: yi.xin@northeastern.edu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 50

// build the hashtable,each bucket contains the word and its frequency
typedef struct
{
    char *word;
    int frequency;
} HashItem;

// create an array of pointers to HashItem objects. The array is of size TABLE_SIZE
HashItem *hashTable[TABLE_SIZE];

unsigned int hash(const char *word)
{
    unsigned long int value = 0;
    unsigned int i = 0;
    // here we hash each word inside the array of words
    unsigned int word_len = strlen(word);

    // insert your code below to implement your hashing logic
    //  .....
    for (int i = 0; i < word_len; i++)
    {
        //"polynomial trolling hash function"
        value = (value * 128 + word[i]) % TABLE_SIZE;
    }
    return value;
    // insert your code above
}

void insert(const char *word)
{
    unsigned int index = hash(word);

    // insert you code to implement 'insert' function
    //  ....
    // if that bucket is empty
    if (hashTable[index] == NULL)
    {
        // allocate momory for that bucket
        hashTable[index] = (HashItem *)malloc(sizeof(HashItem));
        // set the word to be the give word
        hashTable[index]->word = strdup(word);
        // set the frequency to be 1
        hashTable[index]->frequency = 1;
    }
    else
    {
        // if not, increment the frequency by 1
        hashTable[index]->frequency++;
    }
    // insert your code above
}

// comparator function
int cmp(const void *a, const void *b)
{
    // insert your code to to sort hash items by frequency in ascending order
    //.....
    int int_a = *((int *)a);
    int int_b = *((int *)b);
    return int_a - int_b;
    // insert your code above
}

void printFrequencies()
{
    printf("Word Frequencies:\n");

    // Temporary array to sort items by frequency
    HashItem *sortedItems[TABLE_SIZE];
    int sortedIndex = 0;

    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        if (hashTable[i] != NULL)
        {
            sortedItems[sortedIndex++] = hashTable[i];
        }
    }

    qsort(sortedItems, sortedIndex, sizeof(HashItem *), cmp);

    for (int i = 0; i < sortedIndex; ++i)
    {
        printf("%s: %d\n", sortedItems[i]->word, sortedItems[i]->frequency);
    }
}

int main()
{
    char *words[] = {"apple", "banana", "apple", "orange", "banana", "apple"};
    int wordsCount = 6;

    for (int i = 0; i < wordsCount; ++i)
    {
        insert(words[i]);
    }

    printFrequencies();

    // Cleanup
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        if (hashTable[i] != NULL)
        {
            free(hashTable[i]->word);
            free(hashTable[i]);
        }
    }

    return 0;
}