#include <stdio.h>

int main()
{
    int n, i;
    int currentFloor = 0;
    int requestedFloor;

    printf("Enter number of floor requests: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("\nEnter requested floor: ");
        scanf("%d", &requestedFloor);

        if (requestedFloor > currentFloor)
        {
            printf("Moving Up\n");
        }
        else if (requestedFloor < currentFloor)
        {
            printf("Moving Down\n");
        }
        else
        {
            printf("Doors Opening\n");
        }

        currentFloor = requestedFloor;

        printf("Current Floor: %d\n", currentFloor);
    }

    return 0;
}
