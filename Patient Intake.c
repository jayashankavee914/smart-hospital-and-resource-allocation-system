#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospitalData.h"

//Patient Registration
void patientDetails(patientData *patient){

    printf("Enter Patient Name: ");
    fgets(patient->patientName, sizeof(patient->patientName), stdin);
    patient->patientName[strcspn(patient->patientName, "\n")] = '\0';

    printf("Enter Patient Age: ");
    scanf("%d/n", &patient->patientAge);

    printf("Enter Triage Level(1 = Normal, 2 = Urgent, 3 = Critical): ");
    scanf("%d", &patient->triageLevel);

    printf("Enter Specialty ID: ");
    scanf("%d", &patient->specialtyID);

    printf("Is admitted to Ward(1 = Yes, 0 = No): ");
    scanf("%d", &patient->wardStatus);

    //Checking ward status
    if (patient->wardStatus == 1){
            printf("Enter Ward ID: ");
            scanf("%d", &patient->wardID);
            printf("Number of days admitted: ");
            scanf("%d", &patient->daysAdmitted);
        }
    else{
            patient->daysAdmitted = 0;
        }

}
