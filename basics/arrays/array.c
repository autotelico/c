#include <stdio.h>
#include <stdlib.h>

int push(int value, int **array, int *size) {
	(*size)++;
	int *temp = realloc(*array, sizeof(int) * (*size));
	if (temp == NULL) {
		perror("Reallocation failed");
		return 1;
	}
	/*
	for (int i = 0; i < (*size) - 1; i++) {
		temp[i] = *array[i];
	}
	*/
	temp[*size] = value;
	*array = temp;

	return 0;
}

int pop(int **array, int *size) {
	(*size)--;
	int *temp = realloc(*array, sizeof(int) * (*size));
	if (temp == NULL) {
		perror("Reallocation failed");
		return 1;
	}
	
	for (int i = 0; i < *size; i++) {
		temp[i] = *array[i];
	}
	*array = temp;
	
	return 0;
}
