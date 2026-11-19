#include <stdio.h>

int main()
{
    int N, i;
    int A = 0, B = 0, C = 0;
    int cars = 0, bikes = 0, vans = 0;
    int accepted = 0, rejected = 0;
    int zone, spaces;
    int capacity;
    int emergency;
    int highest;

    char vehicle, category, permit;

    printf("Enter expected number of vehicles: ");
    scanf("%d", &N);

    if (N <= 0)
    {
        printf("Invalid number of vehicles.\n");
        return 0;
    }

    for (i = 1; i <= N; i++)
    {
        printf("\n========== VEHICLE %d ==========\n", i);

        // Validate vehicle type

        do
        {
            printf("Enter vehicle type (C/B/V): ");
            scanf(" %c", &vehicle);

            if (vehicle != 'C' && vehicle != 'B' && vehicle != 'V')
                printf("Invalid vehicle type. Try again.\n");

        } while (vehicle != 'C' && vehicle != 'B' && vehicle != 'V');

        // Validate user category

        do
        {
            printf("Enter category (F/S/G): ");
            scanf(" %c", &category);

            if (category != 'F' && category != 'S' && category != 'G')
                printf("Invalid category. Try again.\n");

        } while (category != 'F' && category != 'S' && category != 'G');

        // Validate parking permit

        do
        {
            printf("Valid parking permit? (Y/N): ");
            scanf(" %c", &permit);

            if (permit != 'Y' && permit != 'N')
                printf("Invalid permit value. Try again.\n");

        } while (permit != 'Y' && permit != 'N');

        emergency = 0;

        // Ask emergency status if no permit

        if (permit == 'N')
        {
            char e;

            do
            {
                printf("Is it an emergency vehicle? (Y/N): ");
                scanf(" %c", &e);

                if (e != 'Y' && e != 'N')
                    printf("Invalid input. Try again.\n");

            } while (e != 'Y' && e != 'N');

            if (e == 'Y')
                emergency = 1;
        }

        // Reject vehicles without permit and emergency status

        if (permit == 'N' && emergency == 0)
        {
            printf("Rejected: Invalid parking permit.\n");
            rejected++;
            continue;
        }

        // Determine preferred zone

        zone = -1;

        if (category == 'F')
        {
            zone = 0;
        }
        else if (category == 'S')
        {
            if (vehicle == 'V')
                zone = 2;
            else
                zone = 1;
        }
        else if (category == 'G')
        {
            zone = 2;
        }

        // Determine required parking spaces

        spaces = 1;

        if (vehicle == 'V' && zone == 2)
        {
            spaces = 2;
        }

        // Check zone capacity

        if (zone == 0)
        {
            capacity = 20 - A;

            if (capacity >= spaces)
            {
                A += spaces;
                printf("Vehicle Accepted: Zone A (Faculty)\n");
                accepted++;
            }
            else
            {
                printf("Rejected: No available space in Zone A.\n");
                rejected++;
                continue;
            }
        }

        else if (zone == 1)
        {
            capacity = 40 - B;

            if (capacity >= spaces)
            {
                B += spaces;
                printf("Vehicle Accepted: Zone B (Students)\n");
                accepted++;
            }
            else
            {
                printf("Rejected: No available space in Zone B.\n");
                rejected++;
                continue;
            }
        }

        else if (zone == 2)
        {
            capacity = 15 - C;

            if (capacity >= spaces)
            {
                C += spaces;

                if (category == 'S')
                    printf("Student Van Redirected to Zone C.\n");

                printf("Vehicle Accepted: Zone C (Visitors)\n");
                accepted++;
            }
            else
            {
                printf("Rejected: No available space in Zone C.\n");
                rejected++;
                continue;
            }
        }

        // Count successfully parked vehicle types

        if (vehicle == 'C')
            cars++;
        else if (vehicle == 'B')
            bikes++;
        else if (vehicle == 'V')
            vans++;

        // Display remaining capacity

        if (zone == 0)
            printf("Remaining Zone A Capacity: %d\n", 20 - A);

        else if (zone == 1)
            printf("Remaining Zone B Capacity: %d\n", 40 - B);

        else if (zone == 2)
            printf("Remaining Zone C Capacity: %d\n", 15 - C);
    }

    // Final Parking Summary

    printf("\n========== PARKING SUMMARY ==========\n");

    printf("Total Vehicles Processed: %d\n", N);
    printf("Accepted Vehicles: %d\n", accepted);
    printf("Rejected Vehicles: %d\n", rejected);

    printf("Cars Parked: %d\n", cars);
    printf("Bikes Parked: %d\n", bikes);
    printf("Vans Parked: %d\n", vans);

    printf("\nZONE A (FACULTY)\n");
    printf("Occupied Spaces: %d\n", A);
    printf("Remaining Spaces: %d\n", 20 - A);

    printf("\nZONE B (STUDENTS)\n");
    printf("Occupied Spaces: %d\n", B);
    printf("Remaining Spaces: %d\n", 40 - B);

    printf("\nZONE C (VISITORS)\n");
    printf("Occupied Spaces: %d\n", C);
    printf("Remaining Spaces: %d\n", 15 - C);

    // Find zone with highest occupancy

    highest = A;

    if (B > highest)
        highest = B;

    if (C > highest)
        highest = C;

    printf("\nHighest Occupancy Zone(s): ");

    if (A == highest)
        printf("Zone A ");

    if (B == highest)
        printf("Zone B ");

    if (C == highest)
        printf("Zone C ");

    printf("\n");

    // Check whether entire parking is full

    if (A == 20 && B == 40 && C == 15)
        printf("Entire Campus Parking is FULL.\n");
    else
        printf("Parking Spaces are Available.\n");

    return 0;
}
