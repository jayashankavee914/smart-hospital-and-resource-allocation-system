#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospitalData.h"
#include "bedOccupancy.h"

void patientDetails(patientData *patient);

void mainMenu()
{
    int choice;
    do {

        int bedOccupancy[4][20] = {0};
        printf("\n===== MENU =====\n");
        printf("1. Patient Intake\n");
        printf("2. Bed Occupancy\n");
        printf("3. Performance Reports & Analytics\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1 :
            loadPatients();
            printf("Current patients: %d\n\n", patientCount);
            if (patientCount < 100)
            {
                patientDetails(&patients[patientCount]);
                patientCount++;
                savePatients();
            }
            else
            {
                printf("Patient limit reached.\n");
            }

        break;
        case 2 :
            loadPatients();
            updateBedOccupancy(bedOccupancy);
            bedStatusTracking(bedOccupancy, wards);
        break;
        case 3 :
        break;

        }
    } while (choice != 4);
}
