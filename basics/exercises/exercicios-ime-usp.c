#include <stdio.h>
#include <stdlib.h>

char byteToChar(short b)
{
    return (char)b;
}

// Exercício 1
int *primos(void)
{
    int *v;
    v = malloc(3 * sizeof(int));
    v[0] = 1009;
    v[1] = 1013;
    v[2] = 1019;
    return v;
}

// Exercício 2
typedef struct
{
    int valor;
    Celula proxima;
} Celula;

Celula *acrescentaCabeca(Celula *lst)
{
    Celula cabeca;
    cabeca.proxima = lst;
    return &cabeca;
}

int main()
{

    // int *result = primos();
    // printf("%d", result[0]);
    // free(result);
    // printf("%d", result[0]);

    Celula cel1 = {1, NULL};
    Celula cel2 = {2, NULL};

    acrescentaCabeca(&cel1);
    printf("%d", cel1);
    return 0;
}
