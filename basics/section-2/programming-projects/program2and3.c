#include <stdio.h>
#include <math.h>

#define PI 3.14f

float getSphereVolume(float radius) {
    return 4/(3 * PI * pow(radius, 3));
}

int main(void) {
    float result = getSphereVolume(10);
    printf("The radius is: %f\n", result);
    return 0;
}