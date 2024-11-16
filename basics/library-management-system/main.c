#include <stdio.h>
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

struct Book findBookByTitle(char bookTitle[], struct Book bookArray[], int bookArraySize) {
    for (int i = 0; i < bookArraySize; i++) {
        if (bookArray[i].title == bookTitle) {
            return bookArray[i];
        }
    }
}

void viewBorrowedBooks(struct User user) {
    for (int i = 0; i < MAX_BOOKS_TO_BORROW; i++) {
        if (user.slotsUsed[i]) {
            printf("%s", user.booksBorrowed[i].title);
        }
    }
}

void borrowBook(struct Book bookToBorrow, struct User* user)
{
    if (!bookToBorrow.available) {
        printf("The book %s is not available at the moment.\n", bookToBorrow.title);
        return;
    }
    
    for (int i = 0; i < MAX_BOOKS_TO_BORROW; i++)
    {
        if (user->booksBorrowed[i].title == bookToBorrow.title) {
            printf("The book %s is already under your possession.", bookToBorrow.title);
            return;
        }

        if (!user->slotsUsed[i]) {
            user->booksBorrowed[i] = bookToBorrow;
            user->slotsUsed[i] = true;
            printf("The book %s has been successfully borrowed.", bookToBorrow.title);
            return;
        }
    }
}

int main()
{
    struct Book book1 = {"Harry Potter", "JK Rowling", 120, true};
    struct Book book2 = {"Nice Bookus", "John Smith", 50, true};
    struct User charlotte = {"Charlotte", {{0}}, {false, false, false, false, false}};

    struct Book allBooks[] = {book1, book2};
    int allBooksSize = sizeof(allBooks) / sizeof(allBooks[0]);

    while (true) {
        char selectedOption;
        printf("Select your command:\n");
        printf("1 - View borrowed books\n");
        printf("2 - Borrow book\n");
        printf("3 - Return book\n");
        printf("4 - Quit\n");

        scanf("%s", &selectedOption);

        switch (selectedOption) {
            case '1':
                viewBorrowedBooks(charlotte);
                break;
            case '2':
                char bookTitle[50];
                printf("Which book will you borrow?\n");
                scanf("%s", &bookTitle);
                struct Book foundBook = findBookByTitle(bookTitle, allBooks, allBooksSize);
                borrowBook(foundBook, &charlotte);
                break;
            case '3':

                break;
            case '4':
                printf("Program ended.\n");
                return 0;
        }

    }

    return 0;
}