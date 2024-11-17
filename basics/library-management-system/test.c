#include <stdio.h>
#include <string.h>

void main() {
    char names[][10] = {"Carl", "Daniel", "Jones"};
    strcpy(*(names + 1), "Hannan");
    for (int i = 0; i < (sizeof(names) / sizeof(names[i])); i++) {
        printf("%s\n", *(names + i));
    }
    
}