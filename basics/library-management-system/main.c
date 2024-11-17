#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utils/char-utils.h"

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

struct Book *findBookByTitle(char bookTitle[], struct Book bookArray[], int bookArraySize)
{
    char bookTitleCopy[50];
    strcpy(bookTitleCopy, bookTitle);

    for (int i = 0; i < bookArraySize; i++)
    {
        char bookArrayTitleCopy[50];
        strcpy(bookArrayTitleCopy, bookArray[i].title);
        char *lcBookArrayTitleCopy = toLowercase(bookArrayTitleCopy);
        char *lcBookTitleCopy = toLowercase(bookTitleCopy);

        printf("[%s | %s]\n", bookArrayTitleCopy, bookTitleCopy);
        if (strcmp(lcBookArrayTitleCopy, lcBookTitleCopy) == 0)
        {
            printf("Book found!!!\n");
            return &bookArray[i];
        }
    }
}

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
    if (bookToBorrow->available == false)
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

int main()
{
    struct Book book1 = {"Harry Potter", "JK Rowling", 120, true};
    struct Book book2 = {"Nice Bookus", "John Smith", 50, true};
    struct User charlotte = {"Charlotte", {{0}}, {false, false, false, false, false}};

    struct Book allBooks[] = {{{0}}, book1, book2};
    int allBooksSize = sizeof(allBooks) / sizeof(allBooks[0]);

    while (true)
    {
        char selectedOption;
        printf("Select your command:\n");
        printf("1 - View borrowed books\n");
        printf("2 - Borrow book\n");
        printf("3 - Return book\n");
        printf("4 - Quit\n");

        scanf("%s", &selectedOption);

        switch (selectedOption)
        {
        case '1':
            viewBorrowedBooks(charlotte);
            break;
        case '2':
            char bookTitle[50];
            printf("Which book will you borrow?\n");
            getchar();
            fgets(bookTitle, sizeof(bookTitle), stdin);
            // Remove \n from string
            size_t bookTitleLen = strlen(bookTitle);
            if (bookTitleLen > 0 && bookTitle[bookTitleLen - 1] == '\n')
            {
                bookTitle[bookTitleLen - 1] = '\0';
            }

            struct Book *foundBook = findBookByTitle(bookTitle, allBooks, allBooksSize);
            if (foundBook == NULL)
            {
                printf("The book '%s' could not be found.\n", bookTitle);
                break;
            }
            borrowBook(foundBook, &charlotte);
            break;
        case '3':
            int bookToReturnIndex;
            int borrowedBooksLen = sizeof(charlotte.booksBorrowed) / sizeof(charlotte.booksBorrowed[0]);
            printf("Which book do you want to return?\n");
            for (int i = 0; i < borrowedBooksLen; i++)
            {
                printf("%d. %s\n", i, charlotte.booksBorrowed[i]);
            }
            printf("\n");
            getchar();
            scanf("%d", &bookToReturnIndex);
            bookToReturnIndex = 49 - bookToReturnIndex - 1;
            printf("The index of the book you want to return is %c.\n", bookToReturnIndex);
            // returnBook(bookTitle, &charlotte);
            break;
        case '4':
            printf("Program ended.\n");
            return 0;
        }
    }

    return 0;
}