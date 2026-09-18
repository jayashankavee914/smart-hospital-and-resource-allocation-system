#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospitalData.h"
#include "printBill.h"
#include "patientSearch.h"

int searchPatient(patientData patients[], int patientCount, char patientID[])
{
    for (int i = 0; i < patientCount; i++)
    {
        if (strcmp(patients[i].patientID, patientID) == 0)
            return i;
    }
    return -1;
}

int searchAndDisplayPatient(patientData patients[], int patientCount)
{
    char patientID[20];
    int foundIndex;

    printf("Enter Patient ID: ");
    scanf("%19s", patientID);

    foundIndex = searchPatient(patients, patientCount, patientID);

    if (foundIndex == -1)
    {
        printf("Patient not found.\n");
    }
    else
    {
        printf("Patient found!\n");
        printf("Patient Name: %s\n", patients[foundIndex].patientName);
        printf("Patient ID: %s\n", patients[foundIndex].patientID);
        printf("Age: %d\n", patients[foundIndex].patientAge);
        printf("Triage Level: %d\n", patients[foundIndex].triageLevel);
    }

    return foundIndex;
}



