#include <stdio.h>
#include "fileHandling.h"

// Save bed occupancy to beds_status.txt
void saveBedOccupiedStatus(int bedOccupancy[4][20])
{
    FILE *file;
    file = fopen("beds_status.txt", "w");
    if (file == NULL)
    {
        printf("Error opening beds_status.txt\n");
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < wards[i].totalBedCapacity; j++)
        {
            fprintf(file, "%d %d %d\n",i, j, bedOccupancy[i][j]);
        }
    }
    fclose(file);
}

void loadBedStatus(int bedOccupancy[4][20])
{
    FILE *file;
    int wardIndex;
    int bedIndex;
    int status;

    file = fopen("beds_status.txt", "r");

    if (file == NULL)
    {
        return;
    }

    while (fscanf(file, "%d %d %d", &wardIndex, &bedIndex, &status) == 3)
    {
        if (wardIndex >= 0 && wardIndex < 4 && bedIndex >= 0 && bedIndex < 20)
        {
            bedOccupancy[wardIndex][bedIndex] = status;
        }
    }

    fclose(file);
}

void savePatientBillingRecord(patientData patients[], int foundIndex, float grossTotal, float discount,
                              float finalAmount)
{
    FILE *file;
    file = fopen("patient_records.txt", "a");
    if (file == NULL)
    {
        printf("Error opening patient_records.txt\n");
        return;
    }
    fprintf(file, "===============================================\n");
    fprintf(file, "SMART HOSPITAL BILL\n");
    fprintf(file, "Patient ID       : %s\n", patients[foundIndex].patientID);
    fprintf(file, "Patient Name     : %s\n", patients[foundIndex].patientName);
    fprintf(file, "Age              : %d\n", patients[foundIndex].patientAge);
    fprintf(file, "Triage Level     : %d\n", patients[foundIndex].triageLevel);
    fprintf(file, "Specialty ID     : %d\n", patients[foundIndex].specialtyID);
    fprintf(file, "Ward ID          : %d\n", patients[foundIndex].wardID);
    fprintf(file, "Days Admitted    : %d\n", patients[foundIndex].daysAdmitted);
    fprintf(file, "Gross Total      : LKR %.2f\n", grossTotal);
    fprintf(file, "Discount         : LKR %.2f\n", discount);
    fprintf(file, "Final Amount     : LKR %.2f\n", finalAmount);
    fprintf(file, "===============================================\n\n");
    fclose(file);
}
