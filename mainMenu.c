#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospitalData.h"
#include "bedOccupancy.h"
#include "printBill.h"
#include "patientDisplay.h"
#include "patientSearch.h"



void patientDetails(patientData *patient);

void mainMenu()
{
    int choice;
    do {

        int bedOccupancy[4][20] = {0};
        printf("\n===== MENU =====\n");
        printf("1. Patient Intake\n");
        printf("2. Bed Occupancy\n");
        //printf("3. Performance Reports & Analytics\n");
        printf("3. Search Patient Details\n");
        printf("4. Delete Patients Data\n");
        printf("5. Display Patients Data\n");
        printf("6. Print Bill\n");

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
            loadPatients();
            searchAndDisplayPatient(patients, patientCount);
        break;
        case 4 :
            loadPatients();
            deletePatientData(patients, &patientCount);
        break;
        case 5 :
            loadPatients();
            displayPatients(patients, patientCount);
        break;
        case 6 :
            loadPatients();
            printBill(patients, patientCount);
        }
    } while (choice != 7);
}
