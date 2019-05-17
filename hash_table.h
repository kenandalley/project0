#ifndef CS165_HASH_TABLE // This is a header guard. It prevents the header from being included more than once.

#define CS165_HASH_TABLE

typedef int keyType;

typedef int valType;

typedef struct kvNode {
    keyType key;
    valType val;
    struct kvNode *next;
} kvNodeType;

typedef struct hashtable {
// define the components of the hash table here (e.g. the array, bookkeeping for number of elements, etc)
    int size;
    struct kvNode **list;
} hashtable;

int allocate(hashtable** ht, int size);

int put(hashtable* ht, keyType key, valType value);

int get(hashtable* ht, keyType key, valType *values, int num_values, int* num_results);

int erase(hashtable* ht, keyType key);

int deallocate(hashtable* ht);

#endif
