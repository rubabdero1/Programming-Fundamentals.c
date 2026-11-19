#include <stdio.h>
void inputReadings(int temp[][100], int sensors, int readings)
{
    for (int i = 0; i < sensors; i++)
    {
        printf("Enter readings for Sensor %d:\n", i);

        for (int j = 0; j < readings; j++)
        {
            scanf("%d", &temp[i][j]);
        }
    }
}
void analyzeSensor(int temp[], int readings,
                   int *total, float *average,
                   int *highest, int *lowest,
                   int *critical, int *warning,
                   int *longestStreak)
{
    *total = 0;
    *critical = 0;
    *warning = 0;
    *longestStreak = 0;
    int currentStreak = 0;
    *highest = temp[0];
    *lowest = temp[0];
    for (int j = 0; j < readings; j++)
    {*total = *total + temp[j];
        if (temp[j] > *highest)
        {
            *highest = temp[j];
        }
        if (temp[j] < *lowest)
        {
            *lowest = temp[j];
        }
        if (temp[j] >= 40)
        {
            (*critical)++;
        }
        if (temp[j] >= 35 && temp[j] <= 39)
        {
            (*warning)++;
        }
        if (temp[j] >= 35)
        {
            currentStreak++;
            if (currentStreak > *longestStreak)
            {
                *longestStreak = currentStreak;
            }
        }
        else
        {
            currentStreak = 0;
        }
    }
    *average = (float)*total / readings;
}
int highestAverageSensor(float averages[], int sensors)
{int highestSensor = 0;
    for (int i = 1; i < sensors; i++)
    {
        if (averages[i] > averages[highestSensor])
        {
            highestSensor = i;
        }
    }
    return highestSensor;
}
int main()
{ int temp[100][100];
    int sensors;
    int readings;
    printf("Enter number of sensors: ");
    scanf("%d", &sensors);
    printf("Enter number of hourly readings: ");
    scanf("%d", &readings);
    inputReadings(temp, sensors, readings);
    float averages[100];
    for (int i = 0; i < sensors; i++)
    {  int total;
        float average;
        int highest;
        int lowest;
        int critical;
        int warning;
        int longestStreak;
        analyzeSensor(temp[i], readings,
                      &total, &average,
                      &highest, &lowest,
                      &critical, &warning,
                      &longestStreak);

        averages[i] = average;
        printf("\n--- Sensor %d Report ---\n", i);
        printf("Total: %d\n", total);
        printf("Average: %.2f\n", average);
        printf("Highest: %d\n", highest);
        printf("Lowest: %d\n", lowest);
        printf("Critical readings: %d\n", critical);
        printf("Warning readings: %d\n", warning);
        printf("Longest streak >= 35: %d hours\n", longestStreak);
    }
    int bestSensor = highestAverageSensor(averages, sensors);
    printf("\n--- Final Report ---\n");
    printf("Sensor with highest average: %d\n", bestSensor);
    printf("Highest average temperature: %.2f\n", averages[bestSensor]);

    return 0;
}