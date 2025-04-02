#include <stdio.h>
#include <string.h>

int main() {
  /*
  char title[] = "Lord of the Rings";
  int titleSize = strlen(title);
  printf("titleSize: %d\n", titleSize);
  for (int i = 0; i < titleSize; i++) {
      printf("%c", title[i]);
  }
*/

  char favAnimal[] = "dogs,are,quite,fun";
  char favAnimalCopy[strlen(favAnimal)];
  strcpy(favAnimalCopy, favAnimal);
  char *token;
  token = strtok(favAnimalCopy, ",");
  printf("%s\n", token);

  while ((token = strtok(NULL, ",")) != NULL) {
    printf("%s\n", token);
  }

  return 0;
}