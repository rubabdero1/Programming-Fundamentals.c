#include <stdio.h>
#include <string.h>
void displayMenu()
{  printf("1. Register Member\n");
    printf("2. Display Books\n");
    printf("3. Borrow Book\n");
    printf("4. Return Book\n");
    printf("5. Display Member Record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}
void registerMember(char name[], int *studentID, int *memberType)
{
    printf("\nEnter member name: ");
    scanf(" %[^\n]", name);
    printf("Enter student ID: ");
    scanf("%d", studentID);
    printf("Enter membership type (1 = Student, 2 = Faculty): ");
    scanf("%d", memberType);
    while (*memberType != 1 && *memberType != 2)
    {
        printf("Invalid type! Enter 1 for Student or 2 for Faculty: ");
        scanf("%d", memberType);
    }
    printf("Member registered successfully!\n");
}
void displayBooks(int bookIDs[], char bookTitles[][50],
                  int availableCopies[], int totalBooks)
{ printf("\n===== BOOKS =====\n");
    printf("ID\tTitle\t\t\tCopies\n");
    for (int i = 0; i < totalBooks; i++)
    {printf("%d\t%-20s\t%d\n",
               bookIDs[i],
               bookTitles[i],
               availableCopies[i]);
    }
}
void borrowBook(int bookIDs[], char bookTitles[][50],
                int availableCopies[], int totalBooks,
                int borrowedBookIDs[], int *borrowedCount,
                int memberType)
{
    if (*borrowedCount >= 3)
    {
        printf("You cannot borrow more than 3 books.\n");
        return;
    }
    int id;
    int found = 0;
    printf("Enter Book ID to borrow: ");
    scanf("%d", &id);
    for (int i = 0; i < totalBooks; i++)
    {
        if (bookIDs[i] == id)
        {
            found = 1;
            if (availableCopies[i] <= 0)
            {
                printf("Book is not available.\n");
                return;
            }
            availableCopies[i]--;
            borrowedBookIDs[*borrowedCount] = id;
            (*borrowedCount)++;
            printf("Book borrowed successfully!\n");
            printf("Book: %s\n", bookTitles[i]);
            if (memberType == 1)
                printf("Student borrowing period: 14 days\n");
            else
                printf("Faculty borrowing period: 30 days\n");

            return;
        }
    }
    if (found == 0)
    {
        printf("Invalid Book ID.\n");
    }
}
float returnBook(int bookIDs[], int availableCopies[],
                 int totalBooks,
                 int borrowedBookIDs[], int *borrowedCount,
                 int memberType, float *totalFine)
{  int id;
    int days;
    int found = 0;
    float fine = 0;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    int borrowedPosition = -1;
    for (int i = 0; i < *borrowedCount; i++)
    {if (borrowedBookIDs[i] == id)
        {
            borrowedPosition = i;
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("You have not borrowed this book.\n");
        return 0;
    }
    printf("Enter number of days book was kept: ");
    scanf("%d", &days);
    while (days <= 0)
    {
        printf("Days must be positive. Enter again: ");
        scanf("%d", &days);
    }
    int allowedDays;
    if (memberType == 1)
        allowedDays = 14;
    else
        allowedDays = 30;
    if (days > allowedDays)
    {
        int lateDays = days - allowedDays;
        if (memberType == 1)
            fine = lateDays * 20;
        else
            fine = lateDays * 10;
    }
    *totalFine = *totalFine + fine;
    for (int i = 0; i < totalBooks; i++)
    {if (bookIDs[i] == id)
        {
            availableCopies[i]++;
            break;
        }
    }
    for (int i = borrowedPosition; i < *borrowedCount - 1; i++)
    {
        borrowedBookIDs[i] = borrowedBookIDs[i + 1];
    }
    (*borrowedCount)--;
    printf("Book returned successfully!\n");
    printf("Fine for this return = %.2f\n", fine);
    return fine;
}
void displayMemberRecord(char name[], int studentID,
                         int memberType,
                         int borrowedBookIDs[], int borrowedCount,
                         float totalFine, float fineAfterWaiver)
{ printf("Name: %s\n", name);
    printf("Student ID: %d\n", studentID);
    if (memberType == 1)
        printf("Membership Type: Student\n");
    else
        printf("Membership Type: Faculty\n");
    printf("Borrowed Books: ");
    if (borrowedCount == 0)
    {
        printf("None");
    }
    else
    {for (int i = 0; i < borrowedCount; i++)
        {
            printf("%d ", borrowedBookIDs[i]);
        }
    }
    printf("\n");
    printf("Total Fine Before Waiver: %.2f\n", totalFine);
    printf("Final Fine Payable: %.2f\n", fineAfterWaiver);
}
int main()
{ int bookIDs[] = {101, 102, 103, 104, 105};
    char bookTitles[][50] =
    {
        "Programming in C",
        "Data Structures",
        "Database Systems",
        "Computer Networks",
        "Operating Systems"
    };
    int availableCopies[] = {3, 2, 4, 2, 5};
    int totalBooks = 5;
    char name[100] = "";
    int studentID = 0;
    int memberType = 0;
    int borrowedBookIDs[3];
    int borrowedCount = 0;
    float totalFine = 0;
    float fineAfterWaiver = 0;
    int registered = 0;
    int choice;
    do
    {
        displayMenu();
        scanf("%d", &choice);
        switch (choice)
        {case 1:
                registerMember(name, &studentID, &memberType);
                registered = 1;
                break;
            case 2:
                displayBooks(bookIDs, bookTitles,
                             availableCopies, totalBooks);
                break;
            case 3:
                if (registered == 0)
                {
                    printf("Please register as a member first.\n");
                }
                else
                {
                    borrowBook(bookIDs, bookTitles,
                               availableCopies, totalBooks,
                               borrowedBookIDs, &borrowedCount,
                               memberType);
                }
                break;
            case 4:
                if (registered == 0)
                {
                    printf("Please register as a member first.\n");
                }
                else
                {float currentFine;
                    currentFine = returnBook(
                        bookIDs,
                        availableCopies,
                        totalBooks,
                        borrowedBookIDs,
                        &borrowedCount,
                        memberType,
                        &totalFine
                    );
                    if (currentFine > 0)
                    {
                        char code[20];
                        printf("Enter membership code for 50%% waiver ");
                        printf("(or enter NONE): ");
                        scanf("%s", code);
                        if (strcmp(code, "LIB2026") == 0)
                        {
                            fineAfterWaiver = totalFine * 0.50;
                            printf("50%% waiver applied!\n");
                        }
                        else
                        {
                            fineAfterWaiver = totalFine;
                            printf("No waiver applied.\n");
                        }
                    }
                    else
                    {
                        fineAfterWaiver = totalFine;
                    }
                }
                break;
            case 5:
                if (registered == 0)
                {
                    printf("No member registered yet.\n");
                }
                else
                {
                    displayMemberRecord(
                        name,
                        studentID,
                        memberType,
                        borrowedBookIDs,
                        borrowedCount,
                        totalFine,
                        fineAfterWaiver
                    );
                }
                break;

            case 6:
                printf("Exiting library system...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}