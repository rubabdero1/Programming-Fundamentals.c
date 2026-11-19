#include <stdio.h>
int main()
{int rows, seats;
    int cinema[100][100];
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of seats per row: ");
    scanf("%d", &seats);
    printf("Enter seating status (0 = available, 1 = booked):\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < seats; j++)
        {
            scanf("%d", &cinema[i][j]);
        }
    }
    printf("\nSeating Arrangement:\n");
    printf("    ");
    for (int j = 0; j < seats; j++)
    {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        printf("%d:  ", i);

        for (int j = 0; j < seats; j++)
        {
            if (cinema[i][j] == 0)
                printf("_ ");
            else
                printf("X ");
        }
        printf("\n");
    }
    int totalAvailable = 0;
    printf("\nAvailable seats in each row:\n");
    for (int i = 0; i < rows; i++)
    {
        int rowAvailable = 0;
        for (int j = 0; j < seats; j++)
        {
            if (cinema[i][j] == 0)
            {
                rowAvailable++;
                totalAvailable++;
            }
        }
        printf("Row %d: %d available seats\n", i, rowAvailable);
    }
    printf("Total available seats = %d\n", totalAvailable);
    int k;
    printf("\nEnter number of customers: ");
    scanf("%d", &k);

    while (k <= 0 || k > seats)
    {
        printf("Invalid group size. Enter again: ");
        scanf("%d", &k);
    }
    int middle = rows / 2;
    int found = 0;
    int bookingRow = -1;
    int bookingStart = -1;
    for (int distance = 0; distance < rows && found == 0; distance++)
    {int row1 = middle - distance;
        if (row1 >= 0)
        {int consecutive = 0;
            for (int j = 0; j < seats; j++)
            {if (cinema[row1][j] == 0)
                {consecutive++;
                    if (consecutive == k)
                    {bookingRow = row1;
                        bookingStart = j - k + 1;
                        found = 1;
                        break;
                    }
                }
                else
                {
                    consecutive = 0;
                }
            }
        }
        if (found == 0)
        {
            int row2 = middle + distance;
            if (row2 < rows && row2 != row1)
            {
                int consecutive = 0;

                for (int j = 0; j < seats; j++)
                {
                    if (cinema[row2][j] == 0)
                    {
                        consecutive++;

                        if (consecutive == k)
                        {
                            bookingRow = row2;
                            bookingStart = j - k + 1;
                            found = 1;
                            break;
                        }
                    }
                    else
                    {
                        consecutive = 0;
                    }
                }
            }
        }
    }
    if (found == 1)
    {         
        for (int j = bookingStart; j < bookingStart + k; j++)
        {
            cinema[bookingRow][j] = 1;
        }
        printf("\nBooking successful!\n");
        printf("Allocated row: %d\n", bookingRow);
        printf("Allocated seats: ");
        for (int j = bookingStart; j < bookingStart + k; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
        printf("\nUpdated Seating Arrangement:\n");
        printf("    ");
        for (int j = 0; j < seats; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
        for (int i = 0; i < rows; i++)
        {
            printf("%d:  ", i);

            for (int j = 0; j < seats; j++)
            {
                if (cinema[i][j] == 0)
                    printf("_ ");
                else
                    printf("X ");
            }
            printf("\n");
        }
        int remaining = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < seats; j++)
            {
                if (cinema[i][j] == 0)
                {
                    remaining++;
                }
            }
        }
        printf("\nRemaining available seats = %d\n", remaining);
    }
    else
    {
        printf("\nNo suitable block of %d consecutive seats found.\n", k);
    }
    return 0;
}