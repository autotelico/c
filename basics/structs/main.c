
#include <stdio.h>

enum Gender {
    MALE,
    FEMALE
};

struct Student {
    char name[50];
    int age;
    float gpa;
    enum Gender gender;
};

int main()
{
    struct Student carlos = {"Carlos", 12, 3.9, MALE};
    printf("%s, %d, %f, %s", carlos.name, carlos.age, carlos.gpa, carlos.gender == MALE ? "Male" : "Female");
    return 0;
}