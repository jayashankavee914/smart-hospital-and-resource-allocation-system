#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospitalData.h"
#include "bedOccupancy.h"
#include "waitingTime.h"

//Patient Registration
void patientDetails(patientData *patient, int bedOccupancy[4][20]){
    getchar();

    printf("Enter Patient Name: ");
    fgets(patient->patientName, sizeof(patient->patientName), stdin);
    patient->patientName[strcspn(patient->patientName, "\n")] = '\0';

    sprintf(patients[patientCount].patientID, "PAT-%d", 1001 + patientCount);
    printf("Patient ID: %s\n", patients[patientCount].patientID);

    printf("Enter Patient Age: ");
    scanf("%d", &patient->patientAge);

    printf("Enter Triage (1-3): ");
    scanf("%d", &patient->triageLevel);

    while (patient->triageLevel < 1 || patient->triageLevel > 3)
    {
        printf("Invalid triage level. Enter 1, 2, or 3: ");
        scanf("%d", &patient->triageLevel);
    }
    printf("Enter Specialty ID (1-4): ");
    scanf("%d", &patient->specialtyID);

    while (patient->specialtyID < 1 || patient->specialtyID > 4)
    {
        printf("Invalid Specialty ID. Enter 1-4: ");
        scanf("%d", &patient->specialtyID);
    }
    patient->waitingTime = waitingTimeCalculate(doctor[patient->specialtyID - 1].consultationTimePerPatient,
                                            queueCount[patient->specialtyID - 1]);
    queueCount[patient->specialtyID - 1]++;
    printf("Is admitted? (1=Yes, 0=No): ");
    scanf("%d", &patient->wardStatus);

    while (patient->wardStatus != 0 && patient->wardStatus != 1)
    {
        printf("Invalid Ward Status. Enter 1 for Yes or 0 for No: ");
        scanf("%d", &patient->wardStatus);
    }

    //Checking ward status
    if (patient->wardStatus == 1)
    {
        int validBed = 0;

        printf("Enter Ward ID (1-4): ");
        scanf("%d", &patient->wardID);

        while (patient->wardID < 1 || patient->wardID > 4)
        {
            printf("Invalid Ward ID. Enter Ward ID (1-4): ");
            scanf("%d", &patient->wardID);
        }

        printf("Enter Bed ID: ");
        scanf("%d", &patient->bedID);

        while (validBed == 0)
        {
            //Check whether bed number is within this ward's capacity
            if (patient->bedID < 1 ||
                patient->bedID > wards[patient->wardID - 1].totalBedCapacity)
            {
                printf("Invalid Bed ID. Ward %d has %d beds.\n",
                   patient->wardID,
                   wards[patient->wardID - 1].totalBedCapacity);

                printf("Enter Bed ID again: ");
                scanf("%d", &patient->bedID);
            }
            //Check whether the bed is already occupied
            else if (bedOccupancy[patient->wardID - 1][patient->bedID - 1] == 1)
            {
                printf("Bed %02d is already occupied.\n", patient->bedID);

                printf("Enter another Bed ID: ");
                scanf("%d", &patient->bedID);
            }
            else
            {
                validBed = 1;
            }
        }

        //Reserve the bed
        bedOccupancy[patient->wardID - 1][patient->bedID - 1] = 1;
        printf("Bed %02d allocated successfully.\n", patient->bedID);
    }
    else
    {
        patient->wardID = 0;
        patient->bedID = 0;
        patient->daysAdmitted = 0;
    }
}

void admittedDays(patientData *patient)
{
    if (patient->wardStatus == 1)
    {
        printf("Number of days admitted: ");
        scanf("%d", &patient->daysAdmitted);
    }
    else
    {
        patient->daysAdmitted = 0;
    }
}
