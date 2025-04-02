#include <stdio.h>

int calculateArraySize(int array[]) {
  int result = sizeof(&array) / sizeof(int);
}

int main(void) {
  int array[] = {1, 2, 3, 4, 5};
  printf("Array's memory address: %p\n", &array); // same as array[0]'s address
  for (int i = 0; i < (sizeof(array) / sizeof(int)); i++) {
    printf("%p\n", &array[i]);
  }
  // That means, if we want to print out the first array value...
  printf("First array value: %d\n", *array); //... we can just dereference the array itself! Wow! Nice finding!

  int age = 23;
  int *agePtr = &age;
  printf("%p\n", agePtr);
  printf("%d\n", *agePtr);

  return 0;
}