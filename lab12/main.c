#include <stdio.h>
#include "my_hashmap.h"

int unitTest1()
{
    // Create our hashmap
    hashmap_t *myStocks = hashmap_create(5);
    // Insert a first key/value pair
    hashmap_insert(myStocks, "RY", 93);
    // Does hashmap contain key?
    printf("RY was added should be 1: %d\n", hashmap_hasKey(myStocks, "RY"));
    // Print out the keys
    hashmap_printKeys(myStocks);
    // Retrieve RYs value
    printf("RY's value is %d\n", hashmap_getValue(myStocks, "RY"));
    // Remove a key
    hashmap_removeKey(myStocks, "RY");
    // Does hashmap contain key?
    printf("have you implemented hashmap_removeKey?\n");
    printf("RY was removed should be 0: %d\n", hashmap_hasKey(myStocks, "RY"));
    // Finally terminate our hashmap
    hashmap_delete(myStocks);
    return 1;
}

int unitTest2()
{
    // Create our hashmap
    hashmap_t *myStocks = hashmap_create(5);
    // Insert a first key/value pair
    hashmap_insert(myStocks, "RY", 93);
    hashmap_insert(myStocks, "TD", 80);
    hashmap_insert(myStocks, "CNR", 154);
    hashmap_insert(myStocks, "ENB", 38);
    hashmap_insert(myStocks, "SHOP", 62);
    hashmap_insert(myStocks, "CP", 76);
    hashmap_insert(myStocks, "CNQ", 75);
    hashmap_insert(myStocks, "BMO", 116);
    hashmap_insert(myStocks, "BNS", 66);
    hashmap_insert(myStocks, "TRI", 112);
    // Print the keys
    hashmap_printKeys(myStocks);
    // Finally terminate our hashmap
    hashmap_delete(myStocks);
    return 1;
}
int unitTest3()
{
    // create our hashmap
    hashmap_t *myStocks = hashmap_create(5);
    // insert a first key/value pair
    hashmap_insert(myStocks, "SHOP", 93);
    hashmap_insert(myStocks, "CP", 80);
    hashmap_insert(myStocks, "CNQ", 154);
    hashmap_insert(myStocks, "BMO", 38);
    hashmap_insert(myStocks, "BNS", 62);
    hashmap_insert(myStocks, "TRI", 112);
    hashmap_insert(myStocks, "RY", 93);
    // print the keys
    hashmap_printKeys(myStocks);
    // finally terminate our hashmap
    hashmap_delete(myStocks);
    return 1;
}
int main()
{

    printf("============ unitTest1() ================\n");
    unitTest1();
    printf("============ unitTest2() ================\n");
    unitTest2();
    printf("============ unitTest3() ================\n");
    unitTest3();

    return 0;
}