#include <stdio.h>
#include <string.h>

int main() {
    char title[] = "Lord of the Rings";
    int titleSize = strlen(title);
    printf("titleSize: %d\n", titleSize);
    for (int i = 0; i < titleSize; i++) {
        printf("%c", title[i]);
    }
    
    return 0;
}