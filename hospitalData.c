#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospitalData.h"
#include "printBill.h"
#include "mainMenu.h"
#include "patientSearch.h"

//Specialty Data
    doctorSpecialtyData doctor[4] = {
    {1, "General Practice", 1500.00, 15, 30},
    {2, "Paediatrics",      2500.00, 20, 20},
    {3, "Cardiology",       4500.00, 30, 12},
    {4, "Neurology",        5000.00, 30, 10}
};

//Ward Data
    wardsData wards[4] = {
    {1, "General Ward",     3000.00, 20},
    {2, "Paediatrics Ward", 6000.00, 10},
    {3, "Surgical Ward",   12000.00, 10},
    {4, "ICU",              25000.00, 5}
};

//Patient Data
    patientData patients[100];
    int patientCount = 0;
    int queueCount[4] = {0};

//Save Patient's Data in patients.dat
void savePatients(void)
{
    FILE *file;
    file = fopen("patients.dat", "wb");
    if (file == NULL)
    {
        printf("Error opening patient file.\n");
        return;
    }
    fwrite(&patientCount, sizeof(int), 1, file);
    fwrite(patients, sizeof(patientData), patientCount, file);
    fclose(file);
}

//Load Patient's Data from patients.dat
void loadPatients(void)
{
    FILE *file;
    file = fopen("patients.dat", "rb");
    if (file == NULL)
    {
        patientCount = 0;
        return;
    }
    fread(&patientCount, sizeof(int), 1, file);
    fread(patients, sizeof(patientData), patientCount, file);
    fclose(file);
}

void deletePatientData(patientData patients[], int *patientCount)
{
    char searchID[20];
    int foundIndex;

    printf("Enter Patient ID to delete: ");
    scanf("%19s", searchID);
    foundIndex = searchPatient(patients, *patientCount, searchID);
    if (foundIndex == -1)
    {
        printf("Patient not found.\n");
        return;
    }

    // Move all patients after the deleted patient one position forward
    for (int i = foundIndex; i < *patientCount - 1; i++)
    {
        patients[i] = patients[i + 1];
    }
    //Reduce patient count
    (*patientCount)--;
    savePatients();
    printf("Patient %s deleted successfully.\n", searchID);
}
