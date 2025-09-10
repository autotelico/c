#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct HashMap HashMap;

HashMap *create_hashmap();
int get_hashmap_size(HashMap *hashmap);
int get_hashmap_capacity(HashMap *hashmap);
int hash(char *s, size_t arraySize);
char *hashmap_get(HashMap *hashmap, char *key);
void hashmap_put(HashMap *hashmap, char *key, char *value);
//int resize(HashMap *hashmap);
void printBuckets(HashMap *hashmap);

#endif
