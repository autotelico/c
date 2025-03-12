#include <stdio.h>
#include <math.h>

float getVolume(int height, int width, int length) {
    return height * width * length;
}

int main(void) {
    float volume = getVolume(200, 2, 2);
    printf("The volume is %.2f\n", volume);

    float proportion = volume / 166;
    printf("The proportion is %.2f\n", ceil(proportion));
    
    return 0;
}