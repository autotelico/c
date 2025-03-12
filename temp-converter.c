#include <stdio.h>

#define FREEZING_POINT 32.0f
#define SCALE_FACTOR 5.0f / 9.0f

enum Measurement {
    CELSIUS,
    FAHRENHEIT
};

int main(void) {
    printf("Temperature in Celsius is: %.1f", (212 - FREEZING_POINT) * SCALE_FACTOR);    
    return 0;
}

/*
float convertTo(enum Measurement m, float temperature) {
    if (m == Measurement.CELSIUS) {

    }
}
//*/