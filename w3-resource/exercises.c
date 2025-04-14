#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

void mergeSortedArrays() {
	int array1[] = {1, 2, 3};
	int array2[] = {1, 2, 3};
	int array1Size = sizeof(array1) / sizeof(array1[0]);
	int array2Size = sizeof(array2) / sizeof(array2[0]);

	int resultSize = array1Size + array2Size;
	int result[resultSize];
	int resultIndex = 0;

	// insert array1 values
	for (int h = resultIndex; h < array1Size; h++) {
		result[resultIndex++] = array1[h];
	}
	
	for (int j = 0; j < resultSize; j++) {
		result[resultIndex++] = array2[j];
	}

	// Sort array
	for (int i = 0; i < resultSize - 1; i++) {
		for (int j = 0; j < resultSize - i - 1; j++) {
			if (result[j] < result[j+1]) {
				int tmp = result[j];	
				result[j] = result[j+1];
				result[j+1] = tmp;
			}
		}
	}

	// Print values
	for (int i = 0; i < resultSize; i++) {
		printf("%d\n", result[i]);
	}
}

void printUniqueElements(int argc, char **argv) {	
	char *valuesToPrint[argc];
	for (int i = 0; i < argc; i++) {
		int isUnique = 1;
		for (int j = 0; j < argc; j++) {
			if (i == j) continue;
			if (strcmp(argv[i], argv[j]) == 0) {
				isUnique = 0;	
				break;
			}
		}
		if (!isUnique) {
			valuesToPrint[i] = "";
			continue;
		}
		valuesToPrint[i] = argv[i];
	}

	// Print the unique values
	printf("Printing unique values:\n");
	for (int h = 0; h < argc; h++) {
		if (!strcmp(valuesToPrint[h], "") == 0) {
			printf("%s\n", valuesToPrint[h]);
		}
	}
}

void findDuplicateElements(int argc, char** argv) {
	char *strings[argc];	
	int dupCounter = 0;

	// Start the array with null values
	for (int a = 0; a < argc; a++) {
		strings[a] = NULL;
	}

	for (int i = 0; i < argc; i++) {
		for (int j = 0; j < argc; j++) {
			if (strings[j] != NULL) {
				if (strcmp(argv[i], strings[j]) == 0) {
					dupCounter++;
					printf("Duplicate found: %s at index %d\n", strings[j], i);
				}	
			} else {
				strings[i] = argv[i];
			}
		}

	}
	printf("There are %d duplicates in the array.\n", dupCounter);

}

void addAndPrint(int argc, char **argv) {
	char *newArgs[100];
	
	for (int i = 0; i < argc; i++) {
		newArgs[i] = argv[i];
	}	

	for (int j = 0; j < argc; j++) {
		printf("%s\n", newArgs[j]);
	}
}

void reverseArray(int argc, char **argv) {
	for (int i = argc - 1; i >= 0; i--) {
		printf("%s\n", argv[i]);
	}
}

int main(int argc, char **argv) {
	mergeSortedArrays();

	return 0;
}
