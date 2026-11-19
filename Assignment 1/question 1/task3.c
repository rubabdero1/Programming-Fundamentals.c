#include <stdio.h>

int main()
{
    int n, i, j;
    int marks, sum;
    int deficiency;
    float average;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        sum = 0;
        deficiency = 0;

        printf("\nStudent %d\n", i);

        for (j = 1; j <= 5; j++)
        {
            printf("Enter marks for subject %d: ", j);
            scanf("%d", &marks);

            if (marks < 0 || marks > 100)
            {
                printf("Invalid marks. Enter marks again.\n");
                j--;
                continue;
            }

            sum = sum + marks;

            if (marks < 33)
            {
                deficiency = 1;
            }
        }

        average = sum / 5.0;

        printf("\nTotal Marks: %d", sum);
        printf("\nAverage: %.2f\n", average);

        if (deficiency == 1)
        {
            printf("Result: Fail - Subject Deficiency\n");
        }
        else if (average >= 80)
        {
            printf("Result: Distinction\n");
        }
        else if (average >= 60)
        {
            printf("Result: Pass\n");
        }
        else
        {
            printf("Result: Fail\n");
        }
    }

    return 0;
}
