#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *array;
	int capacity;
	int size;
} DynamicArray;

int resize(DynamicArray *da) {
	int *temp = realloc(da->array, sizeof(int) * da->capacity * 2);
	if (!temp) {
		perror("Failed to resize");
		return 0;
	}
	da->array = temp;
	
	da->capacity = da->capacity * 2;
	return 1;
}

void da_push(DynamicArray *da, int value) {
	if (da->size + 1 > da->capacity) {
		int resized = resize(da);
		if (!resized) {
			perror("Insufficient space for reallocating dynamic array");
			exit(1);
		}
	}

	da->array[da->size++] = value;
}

void da_pop()

void da_print(DynamicArray *da) {
	int counter = 0;
	
	while (counter < da->size) {
		printf("%d\n", da->array[counter]);
		counter++;
	}
}

int main(int argc, char **argv) {
	DynamicArray *da = malloc(sizeof(DynamicArray *));
	da->capacity = 16;
	da->size = 0;
	da->array = (int*) calloc(da->capacity, sizeof(int));

	da_push(da, 1);
	da_push(da, 47);
	
	da_print(da);
	
	return 0;
}
