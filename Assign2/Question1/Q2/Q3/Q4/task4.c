#include <stdio.h>
int getValidDays()
{ int days;
    printf("Enter number of festival days (1-7): ");
    scanf("%d", &days);
    while (days < 1 || days > 7)
    {
        printf("Invalid! Enter days again (1-7): ");
        scanf("%d", &days);
    }
    return days;
}
float calculateDailySales(int dayNumber)
{  int orders;
    float amount;
    float total = 0;
    printf("\nDay %d\n", dayNumber);
    printf("Enter number of orders: ");
    scanf("%d", &orders);
    while (orders < 1)
    {
        printf("Invalid! Enter at least 1 order: ");
        scanf("%d", &orders);
    }
    for (int i = 1; i <= orders; i++)
    { printf("Enter amount for order %d: ", i);
        scanf("%f", &amount);
        while (amount <= 0)
        {
            printf("Invalid! Enter amount again: ");
            scanf("%f", &amount);
        }
        total = total + amount;
    }
    float average = total / orders;
    printf("Total sales = %.2f\n", total);
    printf("Average order amount = %.2f\n", average);
    return total;
}
int findHighestSalesDay(float dailySales[], int numberOfDays)
{int highestDay = 0;
    for (int i = 1; i < numberOfDays; i++)
    {
        if (dailySales[i] > dailySales[highestDay])
        {
            highestDay = i;
        }
    }
    return highestDay;
}
void displayBarChart(float dailySales[], int numberOfDays)
{  printf("\n--- Daily Sales Bar Chart ---\n");
    for (int i = 0; i < numberOfDays; i++)
    {
        int stars = (int)(dailySales[i] / 100);
        printf("Day %d: ", i + 1);
        for (int j = 0; j < stars; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
int main()
{int numberOfDays;
    float dailySales[7];
    numberOfDays = getValidDays();
    for (int i = 0; i < numberOfDays; i++)
    {
        dailySales[i] = calculateDailySales(i + 1);
    }
    float festivalTotal = 0;
    for (int i = 0; i < numberOfDays; i++)
    {
        festivalTotal = festivalTotal + dailySales[i];
    }
    int highestDay = findHighestSalesDay(dailySales, numberOfDays);
    printf("\n--- Festival Summary ---\n");
    printf("Total festival sales = %.2f\n", festivalTotal);
    printf("Day with highest sales = Day %d\n", highestDay + 1);
    printf("Highest sales = %.2f\n", dailySales[highestDay]);
    displayBarChart(dailySales, numberOfDays);
    return 0;
}