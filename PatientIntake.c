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
    scanf("%d/n", &patient->patientAge);

    printf("Enter Triage Level(1 = Normal, 2 = Urgent, 3 = Critical): ");
    scanf("%d", &patient->triageLevel);

    printf("Enter Specialty ID: ");
    scanf("%d", &patient->specialtyID);
    patient->waitingTime = waitingTimeCalculate(doctor[patient->specialtyID - 1].consultationTimePerPatient,
                                            queueCount[patient->specialtyID - 1]);

    queueCount[patient->specialtyID - 1]++;

    printf("Is admitted to Ward(1 = Yes, 0 = No): ");
    scanf("%d", &patient->wardStatus);

    //Checking ward status
    if (patient->wardStatus == 1)
    {
        printf("Enter Ward ID: ");
        scanf("%d", &patient->wardID);

        printf("Enter Bed ID: ");
        scanf("%d", &patient->bedID);
    }
    else
    {
        patient->wardID = 0;
        patient->bedID = 0;
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
