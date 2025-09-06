#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char *key;
	char *value;	
} Entry;  

typedef struct {
	Entry **buckets;
	int capacity;
	int size;
} HashMap;

int hash(char* s, size_t arraySize) {
	size_t sLen = strlen(s);
	int hash = 0;
	int PRIME = 31;

	for (int i = 0; i < sLen; i++) {
		hash = hash * 31 + s[i];
	}

	return hash % arraySize;
}

HashMap *create_hashmap() {
	HashMap *hashmap = malloc(sizeof(HashMap));
	if (!hashmap) {
		fprintf(stderr, "Failed to create hashmap\n");
		return NULL;
	}
	hashmap->capacity = 16;
	hashmap->size = 0;
	hashmap->buckets = calloc(hashmap->capacity, sizeof(Entry *));
	return hashmap;
}

int get_hashmap_capacity(HashMap *hashmap) {
	return hashmap->capacity;
}

void hashmap_put(HashMap *hashmap, char *key, char *value) {
	Entry entry;
	size_t keyLen = strlen(key);
	size_t valueLen = strlen(value);
	
	char newKey[keyLen + 1];
	char newValue[valueLen + 1];
	strcpy(newValue, value);
	strcpy(newKey, key);

	entry.key = newKey;
	entry.value = newValue;

	int keyHash = hash(key, get_hashmap_capacity(hashmap));

	hashmap->buckets[hashmap->size++] = &entry;
}

void printBucketKeys(HashMap *hashmap) {
	for (int i = 0; i < hashmap->size; i++) {
		printf("Key: %s, Value: %s\n", hashmap->buckets[i]->key, hashmap->buckets[i]->value);
	}
	printf("\n");
}
