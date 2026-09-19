#include <stdio.h>
#include "patientSort.h"

void displayPatientsByPriority(patientData patients[], int patientCount)
{
    patientData sortedPatients[100];
    patientData temp;
    //Copy original patient records
    for (int i = 0; i < patientCount; i++)
    {
        sortedPatients[i] = patients[i];
    }
    /* Bubble Sort
       Level 3 = Critical
       Level 2 = Urgent
       Level 1 = Normal
    */
    for (int i = 0; i < patientCount - 1; i++)
    {
        for (int j = 0; j < patientCount - 1 - i; j++)
        {
            if (sortedPatients[j].triageLevel < sortedPatients[j + 1].triageLevel)
            {
                temp = sortedPatients[j];
                sortedPatients[j] = sortedPatients[j + 1];
                sortedPatients[j + 1] = temp;
            }
        }
    }
    printf("\n===============================================\n");
    printf("       PATIENTS BY PRIORITY\n");
    printf("===============================================\n");
    for (int i = 0; i < patientCount; i++)
    {
        printf("\nPatient ID      : %s\n", sortedPatients[i].patientID);
        printf("Patient Name    : %s\n", sortedPatients[i].patientName);
        printf("Age             : %d\n", sortedPatients[i].patientAge);
        printf("Triage Level    : %d\n", sortedPatients[i].triageLevel);
        printf("Specialty ID    : %d\n", sortedPatients[i].specialtyID);
        printf("-----------------------------------------------\n");
    }
}
