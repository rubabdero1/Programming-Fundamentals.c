#include <stdio.h>

int main()
{
    int n, i, nights;
    int rate;
    float price, discount, totalRevenue = 0;
    char season, room;

    printf("Enter number of guests: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("\nGuest %d\n", i);

        printf("Enter season (P = Peak, O = Off-Peak): ");
        scanf(" %c", &season);

        printf("Enter room type (S = Standard, D = Deluxe, U = Suite): ");
        scanf(" %c", &room);

        printf("Enter number of nights: ");
        scanf("%d", &nights);

        if (nights <= 0 || (season != 'P' && season != 'O') ||
            (room != 'S' && room != 'D' && room != 'U'))
        {
            printf("Invalid booking information.\n");
            continue;
        }

        if (season == 'P')
        {
            if (room == 'S')
                rate = 5000;
            else if (room == 'D')
                rate = 8000;
            else
                rate = 12000;
        }
        else
        {
            if (room == 'S')
                rate = 3000;
            else if (room == 'D')
                rate = 5000;
            else
                rate = 8000;
        }

        price = rate * nights;
        discount = 0;

        if (nights > 7)
        {
            discount = price * 0.15;
        }

        totalRevenue += price - discount;

        printf("Room Rate: Rs. %d\n", rate);
        printf("Total Price: Rs. %.2f\n", price);
        printf("Discount: Rs. %.2f\n", discount);
        printf("Final Price: Rs. %.2f\n", price - discount);
    }

    printf("\nHotel Total Revenue: Rs. %.2f\n", totalRevenue);

    return 0;
}
