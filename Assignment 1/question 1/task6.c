#include <stdio.h>

int main()
{
    char vehicle, membership, disabled, available;

    float battery, required;
    float chargingUnits, chargingRate;
    float chargingCost, chargingDiscount;
    float parkingCost, parkingDiscount;
    float finalBill, totalDiscount;
    float duration;

    int time;

    printf("========== EV CHARGING SYSTEM ==========\n");

    // Input vehicle type

    printf("Enter Vehicle Type (E = Electric, H = Hybrid): ");
    scanf(" %c", &vehicle);

    if (vehicle != 'E' && vehicle != 'H')
    {
        printf("Invalid Vehicle Type.\n");
        return 0;
    }

    // Input battery level

    printf("Enter Current Battery Level (0-100): ");
    scanf("%f", &battery);

    printf("Enter Required Charging Level (0-100): ");
    scanf("%f", &required);

    if (battery < 0 || battery > 100 ||
        required < 0 || required > 100)
    {
        printf("Invalid Battery Percentage.\n");
        return 0;
    }

    // Input parking duration

    printf("Enter Expected Parking Duration (hours): ");
    scanf("%f", &duration);

    if (duration <= 0)
    {
        printf("Invalid Parking Duration.\n");
        return 0;
    }

    // Input current time

    printf("Enter Current Time (HHMM): ");
    scanf("%d", &time);

    if (time < 0 || time > 2359 ||
        time % 100 >= 60)
    {
        printf("Invalid Time.\n");
        return 0;
    }

    // Membership status

    printf("Parking Membership? (Y/N): ");
    scanf(" %c", &membership);

    if (membership != 'Y' && membership != 'N')
    {
        printf("Invalid Membership Status.\n");
        return 0;
    }

    // Disabled priority status

    printf("Disabled-Person Priority? (Y/N): ");
    scanf(" %c", &disabled);

    if (disabled != 'Y' && disabled != 'N')
    {
        printf("Invalid Priority Status.\n");
        return 0;
    }

    // Charging station availability

    printf("Charging Station Available? (Y/N): ");
    scanf(" %c", &available);

    if (available != 'Y' && available != 'N')
    {
        printf("Invalid Station Status.\n");
        return 0;
    }

    // Check station availability

    if (available == 'N')
    {
        if (vehicle == 'H')
        {
            printf("Charging unavailable - Parking only.\n");
        }
        else
        {
            printf("No charging slot available.\n");
        }

        return 0;
    }

    // Check vehicle eligibility

    if (vehicle == 'H')
    {
        if (battery >= 40)
        {
            printf("Vehicle does not qualify for EV charging.\n");
            return 0;
        }
    }

    // Calculate required charging

    chargingUnits = required - battery;

    if (chargingUnits <= 0)
    {
        printf("No charging required.\n");
        return 0;
    }

    // Determine charging priority

    int priority;

    if (battery <= 15 && required >= 80)
    {
        priority = 1;
        printf("\nPriority: Emergency Charging Priority\n");
    }
    else if (disabled == 'Y' ||
             (membership == 'Y' && battery <= 30))
    {
        priority = 2;
        printf("\nPriority: Priority Charging\n");
    }
    else
    {
        priority = 3;
        printf("\nPriority: Normal Charging\n");
    }

    // Determine peak or off-peak status

    if (time >= 1700 && time <= 2200)
    {
        chargingRate = 50;

        printf("Charging Period: Peak\n");
    }
    else
    {
        chargingRate = 35;

        printf("Charging Period: Off-Peak\n");
    }

    // Calculate charging cost

    chargingCost = chargingUnits * chargingRate;

    chargingDiscount = 0;

    if (priority != 1)
    {
        if (time >= 1700 && time <= 2200)
        {
            chargingDiscount = chargingCost * 0.10;
        }
        else if (membership == 'Y')
        {
            chargingDiscount = chargingCost * 0.20;
        }
    }

    chargingCost = chargingCost - chargingDiscount;

    // Calculate parking charges

    if (duration <= 2)
    {
        parkingCost = 200;
    }
    else if (duration <= 5)
    {
        parkingCost = 400;
    }
    else
    {
        parkingCost = 700;
    }

    // Calculate parking discount

    parkingDiscount = 0;

    if (disabled == 'Y')
    {
        parkingDiscount = parkingCost;
    }
    else if (membership == 'Y')
    {
        parkingDiscount = parkingCost * 0.20;
    }

    parkingCost = parkingCost - parkingDiscount;

    // Calculate final bill

    finalBill = chargingCost + parkingCost;

    totalDiscount = chargingDiscount + parkingDiscount;

    // Display final bill

    printf("\n========== CUSTOMER BILL ==========\n");

    printf("Vehicle Type: %c\n", vehicle);

    printf("Current Battery: %.2f%%\n", battery);

    printf("Required Charging Level: %.2f%%\n", required);

    printf("Required Charging Units: %.2f\n", chargingUnits);

    if (priority == 1)
        printf("Charging Priority: Emergency\n");
    else if (priority == 2)
        printf("Charging Priority: Priority Customer\n");
    else
        printf("Charging Priority: Normal\n");

    printf("Charging Rate: Rs. %.2f\n", chargingRate);

    printf("Charging Discount: Rs. %.2f\n", chargingDiscount);

    printf("Charging Cost: Rs. %.2f\n", chargingCost);

    printf("Parking Discount: Rs. %.2f\n", parkingDiscount);

    printf("Parking Cost: Rs. %.2f\n", parkingCost);

    printf("Total Discount: Rs. %.2f\n", totalDiscount);

    printf("-----------------------------------\n");

    printf("FINAL PAYABLE AMOUNT: Rs. %.2f\n", finalBill);

    printf("-----------------------------------\n");

    // Long-stay warning

    if (duration > 8)
    {
        printf("Long-stay warning: Please relocate your vehicle after charging.\n");
    }
    else
    {
        printf("Standard parking duration.\n");
    }

    printf("===================================\n");

    return 0;
}
