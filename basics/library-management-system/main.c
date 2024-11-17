#include <stdio.h>
#include <string.h>
#include "utils/index.h"

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
            char insertedIndexChar;
            int borrowedBooksLen = sizeof(charlotte.booksBorrowed) / sizeof(charlotte.booksBorrowed[0]);
            printf("Which book do you want to return?\n");
            for (int i = 0; i < borrowedBooksLen; i++)
            {
                printf("%d. %s\n", i, charlotte.booksBorrowed[i]);
            }
            printf("\n");
            getchar();
            scanf("%d", &insertedIndexChar);
            // Correct char value to int correspondent
            int bookToReturnIndex = insertedIndexChar - '0';
            printf("The index of the book you want to return is %c.\n", insertedIndexChar);
            struct Book foundBookReturnBook = charlotte.booksBorrowed[bookToReturnIndex];
            returnBook(&foundBookReturnBook, &charlotte, bookToReturnIndex);
            break;
        case '4':
            printf("Program ended.\n");
            return 0;
        }
    }

    return 0;
}