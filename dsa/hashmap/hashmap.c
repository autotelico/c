#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LOAD_FACTOR 0.25

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

	int i = 0;
	while (i < hashmap->capacity) {
		hashmap->buckets[i] = NULL;
		i++;
	}

	return hashmap;
}

// getters
char *hashmap_get(HashMap *hashmap, char *key) {
	int index = hash(key, hashmap->capacity);
	return hashmap->buckets[index]->value;
}

int get_hashmap_capacity(HashMap *hashmap) {
	return hashmap->capacity;
}

int get_hashmap_size(HashMap *hashmap) {
	return hashmap->size;
} // end getters

int resize(HashMap *hashmap) {
	int new_capacity = hashmap->capacity * 2;
	Entry **new_buckets = malloc(sizeof(Entry *) * new_capacity);
	if (!new_buckets) {
		perror("Failed resizing hashmap");
		return 1;
	}
	// recalculate bucket hashes
	for (int i = 0; i < hashmap->capacity; i++) {
		Entry *originalEntry = hashmap->buckets[i];
		if (originalEntry == NULL) continue;
		int index = hash(hashmap_get(hashmap, originalEntry->key), new_capacity);
		new_buckets[index] = originalEntry;
	}

	// free memory of previous array
	free(hashmap->buckets);
	hashmap->buckets = new_buckets;
	hashmap->capacity = new_capacity;

	printf("New hashmap capacity is %d\n", hashmap->capacity);
	return 0;
}

int must_resize(HashMap *hashmap) {
	printf("%d * %d <= %d? %s\n", LOAD_FACTOR, hashmap->capacity, hashmap->size + 1, LOAD_FACTOR * hashmap->capacity <= (hashmap->size + 1) ? "true" : "false");
	return LOAD_FACTOR * hashmap->capacity <= (hashmap->size + 1);
}


// setters
void hashmap_put(HashMap *hashmap, char *key, char *value) {
	int resize_needed = must_resize(hashmap);
	printf("resize_needed = %d\n", resize_needed);
	
	if (resize_needed) {
		resize(hashmap);
	}

	Entry *entry = (Entry*)malloc(sizeof(Entry));
	size_t keyLen = strlen(key);
	size_t valueLen = strlen(value);

	entry->key = malloc(sizeof(entry->key));
	entry->value = malloc(sizeof(entry->value));
	
	strcpy(entry->key, key);
	strcpy(entry->value, value);

	int key_hash = hash(key, get_hashmap_capacity(hashmap));

	hashmap->buckets[key_hash] = entry;
	hashmap->size++;
} // end setters


void printBuckets(HashMap *hashmap) {
	for (int i = 0; i < hashmap->capacity; i++) {
		if (hashmap->buckets[i] == NULL) continue;
		printf("Key: %s, Value: %s\n", hashmap->buckets[i]->key, hashmap->buckets[i]->value);
	}
	printf("\n");
}
