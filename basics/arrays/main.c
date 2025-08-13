#include <stdio.h>
#include "array.h"

void printArr(int *array, int size) {
	printf("{ ");
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			printf("%d ", array[i]);
		} else {
			printf("%d, ", array[i]);
		}
	}	
	printf("}\n");
}

int main(void) {
	int myArr[] = {1, 2, 3, 4};
	int myArrSize = sizeof(myArr) / sizeof(int);
	int *myArrPtr = myArr;
	int **myArrPtrPtr = &myArrPtr;
	//push(5, myArrPtrPtr, &myArrSize);
	printArr(myArr, myArrSize);	

	return 0;
}
