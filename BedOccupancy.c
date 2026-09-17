#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospitalData.h"
#include "bedOccupancy.h"

void updateBedOccupancy(int bedOccupancy[4][20])
{
    int i;
    //Start with all beds available
    for (i = 0; i < 4; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            bedOccupancy[i][j] = 0;
        }
    }
    //Mark beds occupied based on stored patients
    for (i = 0; i < patientCount; i++)
    {
        if (patients[i].wardStatus == 1)
        {
            int wardIndex = patients[i].wardID - 1;
            int bedIndex = patients[i].bedID - 1;

            if (wardIndex >= 0 && wardIndex < 4 &&
                bedIndex >= 0 && bedIndex < wards[wardIndex].totalBedCapacity)
            {
                bedOccupancy[wardIndex][bedIndex] = 1;
            }
        }
    }
}

void bedStatusTracking(int bedOccupancy[4][20], wardsData wards[4])
{
    for (int i = 0; i < 4; i++)
    {
        printf("\nWard: %s\n", wards[i].wardName);

        for (int j = 0; j < wards[i].totalBedCapacity; j++)
        {
            printf("Bed %02d: ", j + 1);

            if (bedOccupancy[i][j] == 0)
                printf("Available\n");
            else
                printf("Occupied\n");
        }
    }
}
