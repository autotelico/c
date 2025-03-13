#include <stdio.h>

int main(int argc, char** argv) {
    printf("argc: %d\n", argc);
    printf("~argv~ \n");

    int argSize = sizeof(argv) / sizeof(argv[0]);
    for (int i = 0; i < argSize; i++) {
        printf("  arg%d: %s\n", i, argv[i]);
    }

    return 0;
}