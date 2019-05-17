#include "hash_table.h"
#include "stdlib.h"


static int ARY_MULTIPLIER = 2;

// Initialize the components of a hashtable.

// The size parameter is the expected number of elements to be inserted.

// This method returns an error code, 0 for success and -1 otherwise (e.g., if the parameter passed to the method is not null, if malloc fails, etc).

int allocate(hashtable** ht, int size) {
    if (size < 1) {
        return -1;
    }

    if (!ht) {
        return -1;
    }

    hashtable * ht_temp;
    ht_temp = malloc(sizeof (struct hashtable));
    if (ht_temp == NULL) {
        return -1;
    }
    ht_temp->size = size * ARY_MULTIPLIER;
    ht_temp->list = malloc(sizeof(struct list*) * (ulong)(size * ARY_MULTIPLIER));
    for (int idx = 0; idx < size * ARY_MULTIPLIER; idx++) {
        ht_temp->list[idx] = NULL;
    }

    *ht = ht_temp;

    return 0;

}

// This method inserts a key-value pair into the hash table.

// It returns an error code, 0 for success and -1 otherwise (e.g., if malloc is called and fails).

int put(hashtable* ht, keyType key, valType value) {

//    (void) ht;

//    (void) key;

//    (void) value;

    if (!ht) {
        return -1;
    }

    // Modular Hash
    int hash = key % ht->size;

    kvNodeType *hash_node = ht->list[hash];

    kvNodeType *new_node;
    new_node = malloc(sizeof(kvNodeType));
    new_node->key = key;
    new_node->val = value;
    new_node->next = NULL;

    if (hash_node) {
        kvNodeType * list_node;
        list_node = hash_node;
        while (list_node->next != NULL) {
            list_node = list_node->next;
        }
        list_node->next = new_node;
        ht->list[hash] = list_node;
    } else {
        ht->list[hash] = new_node;
    }

    return 0;

}


// This method retrieves entries with a matching key and stores the corresponding values in the

// values array. The size of the values array is given by the parameter

// num_values. If there are more matching entries than num_values, they are not

// stored in the values array to avoid a buffer overflow. The function returns

// the number of matching entries using the num_results pointer. If the value of num_results is greater than

// num_values, the caller can invoke this function again (with a larger buffer)

// to get values that it missed during the first call.

// This method returns an error code, 0 for success and -1 otherwise (e.g., if the hashtable is not allocated).

int get(hashtable* ht, keyType key, valType *values, int num_values, int* num_results) {

    (void) ht;

    (void) key;

    (void) values;

    (void) num_values;

    (void) num_results;

    if (!ht) {
        return -1;
    }



    return 0;

}

// This method erases all key-value pairs with a given key from the hash table.

// It returns an error code, 0 for success and -1 otherwise (e.g., if the hashtable is not allocated).

int erase(hashtable* ht, keyType key) {

    (void) ht;

    (void) key;

    return 0;

}

// This method frees all memory occupied by the hash table.

// It returns an error code, 0 for success and -1 otherwise.

int deallocate(hashtable* ht) {
    if (!ht) {
        return -1;
    }

    for (int i = 0; i < ht->size; i++) {
        kvNodeType *kvNode = ht->list[i];
        kvNodeType *currNode = kvNode;
        kvNodeType *tempNode;
        if (currNode) {
            while(currNode->next != NULL) {
                tempNode = currNode;
                currNode = kvNode->next;
                free(tempNode);
            }
            free(currNode);
        }
    }
    free(ht->list);
    free(ht);
    ht = NULL;

    return 0;
}
