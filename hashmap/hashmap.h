#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct HashMap HashMap;

HashMap *create_hashmap();
int hash(char *s, size_t arraySize);
void hashmap_put(HashMap *hashmap, char *key, char *value);
void printBucketKeys(HashMap *hashmap);

#endif
