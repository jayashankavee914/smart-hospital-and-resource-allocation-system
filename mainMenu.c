#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospitalData.h"
#include "bedOccupancy.h"
#include "printBill.h"
#include "patientDisplay.h"
#include "patientSearch.h"
#include "patientSort.h"
#include "performanceReports.h"
#include "fileHandling.h"
#include "PatientIntake.h"

void mainMenu(int bedOccupancy[4][20])
{
    int choice;
    do {
        printf("\n====== WELCOME TO SMART HOSPITAL ======\n");
        printf("\n===== MENU =====\n");
        printf("1. Patient Intake\n");
        printf("2. Bed Occupancy\n");
        printf("3. Search Patient Details\n");
        printf("4. Print Bill\n");
        printf("5. Display Patients by Priority\n");
        printf("6. Performance Reports & Analytics\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1 :
            loadPatients();
            printf("Current patients: %d\n\n", patientCount);
            if (patientCount < 100)
            {
                patientDetails(&patients[patientCount], bedOccupancy);;
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
            saveBedOccupiedStatus(bedOccupancy);

        break;
        case 3 :
            loadPatients();
            searchAndDisplayPatient(patients, patientCount);
        break;
        case 4 :
            loadPatients();
            printBill(patients, patientCount);
        break;
        case 5 :
            loadPatients();
            displayPatientsByPriority(patients, patientCount);
        break;
        case 6:
            loadPatients();
            int choice1;
                printf("\n===============================================\n");
                printf("       PERFORMANCE REPORTS & ANALYTICS\n");
                printf("===============================================\n");
                printf("1. Total patients registered and categorized by Urgency Level.\n");
                printf("2. Total revenue earned and total discounts granted.\n");
                printf("3. Bed occupancy percentage per ward.\n");
                printf("4. Name and total bill of the highest-paying patient.\n");
                printf("5. Delete Patients Data\n");
                printf("6. Display Patients Data\n");

                printf("Enter your choice: ");
                scanf("%d", &choice1);
                switch (choice1)
                {
                    case 1 :
                        displayUrgencyReport(patients, patientCount);
                    break;
                    case 2 :
                        displayRevenueReport(patients, patientCount);
                    break;
                    case 3 :
                        displayBedOccupancyReport(bedOccupancy);
                    break;
                    case 4 :
                        displayHighestPayingPatient(patients, patientCount);
                    break;
                    case 5 :
                        deletePatientData(patients, &patientCount);
                    break;
                    case 6 :
                        displayPatients(patients, patientCount);
                    break;
                }
        break;
        }
    } while (choice != 7);
}
