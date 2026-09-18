#include <stdio.h>
#include "hospitalData.h"
#include "patientDisplay.h"

void displayPatients(patientData patients[], int patientCount)
{
    if (patientCount == 0)
    {
        printf("\nNo patients registered.\n");
        return;
    }

    printf("\n========== REGISTERED PATIENTS ==========\n");

    for (int i = 0; i < patientCount; i++)
    {
        printf("\nPatient %d\n", i + 1);
        printf("-----------------------------------------\n");
        printf("Patient Name     : %s\n", patients[i].patientName);
        printf("Patient ID       : %s\n", patients[i].patientID);
        printf("Patient Age      : %d\n", patients[i].patientAge);
        printf("Triage Level     : %d\n", patients[i].triageLevel);
        printf("Specialty ID     : %d\n", patients[i].specialtyID);
        printf("Ward Status      : %d\n", patients[i].wardStatus);
        printf("Ward ID          : %d\n", patients[i].wardID);
    }

    printf("\n=========================================\n");
}
