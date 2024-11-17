#include <stdbool.h>
#define MAX_BOOKS_TO_BORROW 5

struct Book
{
    char title[50];
    char author[50];
    int pages;
    bool available;
};

struct User
{
    char name[50];
    struct Book booksBorrowed[MAX_BOOKS_TO_BORROW];
    bool slotsUsed[MAX_BOOKS_TO_BORROW];
};

