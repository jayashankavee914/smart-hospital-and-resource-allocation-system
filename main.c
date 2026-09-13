#include <stdio.h>
#include <stdlib.h>
#include "hospitaldata.h"

void patientDetails(patientData *patient);

int main()
{

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
    return 0;
}
