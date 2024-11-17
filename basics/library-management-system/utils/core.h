#include <stdio.h>
#include <string.h>
#include "../structs/structs.h"

void viewBorrowedBooks(struct User user)
{
    bool someBorrowedBook = false;
    for (int i = 0; i < MAX_BOOKS_TO_BORROW; i++)
    {
        if (user.slotsUsed[i])
        {
            printf("%s\n", user.booksBorrowed[i].title);
            someBorrowedBook = true;
        }
    }
    if (!someBorrowedBook)
    {
        printf("No books borrowed yet.\n");
        return;
    }
}

void borrowBook(struct Book *bookToBorrow, struct User *user)
{
    if (!bookToBorrow->available)
    {
        printf("The book %s is not available at the moment.\n", bookToBorrow->title);
        return;
    }

    for (int i = 0; i < MAX_BOOKS_TO_BORROW; i++)
    {
        if (strcmp(user->booksBorrowed[i].title, bookToBorrow->title) == 0)
        {
            printf("The book %s is already under your possession.\n", bookToBorrow->title);
            return;
        }

        if (!user->slotsUsed[i])
        {
            user->booksBorrowed[i] = *bookToBorrow;
            user->slotsUsed[i] = true;
            printf("The book %s has been successfully borrowed.\n", bookToBorrow->title);
            return;
        }
    }
}

void returnBook(struct Book* bookToReturn, struct User* user, int bookIndex)
{
    strcpy(user->booksBorrowed[bookIndex].title, "");
    strcpy(user->booksBorrowed[bookIndex].author, "");
    user->slotsUsed[bookIndex] = false;
    bookToReturn->available = true;
    printf("Book %s successfully returned.\n", bookToReturn->title);
}