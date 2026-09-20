#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BillCalculations.h"
#include "hospitalData.h"
#include "patientSearch.h"
#include "printBill.h"
#include "waitingTime.h"
#include "PatientIntake.h"
#include "fileHandling.h"


void printBill(patientData patients[], int patientCount)
{
    char patientID[20];
    int foundIndex;
    int specialtyIndex = -1;
    int wardIndex = -1;
    float baseFee;
    float totalWardCost;
    float surcharge;
    float grossTotal;
    float discount;
    float finalAmount;


    //Search for patient
    printf("\nEnter Patient ID: ");
    scanf("%19s", patientID);
    foundIndex = searchPatient(patients, patientCount, patientID);
    if (foundIndex == -1)
    {
        printf("\nPatient not found.\n");
        return;
    }

    //Find patient's specialty
    for (int i = 0; i < 4; i++)
    {
        if (doctor[i].specialtyID == patients[foundIndex].specialtyID)
        {
            specialtyIndex = i;
            break;
        }
    }

    if (specialtyIndex == -1)
    {
        printf("\nSpecialty not found.\n");
        return;
    }
    //Find patient's ward
    if (patients[foundIndex].wardStatus == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            if (wards[i].wardID == patients[foundIndex].wardID)
            {
                wardIndex = i;
                break;
            }
        }
        if (wardIndex == -1)
        {
            printf("\nWard not found.\n");
            return;
        }
    }

    if (patients[foundIndex].wardStatus == 1)
    {
        admittedDays(&patients[foundIndex]);
        savePatients();
    }

    if (patients[foundIndex].wardStatus == 1)
    {
        totalWardCost = totalWardStayCost(wards[wardIndex].dailyBedRate,
        patients[foundIndex].daysAdmitted, patients[foundIndex].wardStatus);
    }
    else
    {
        totalWardCost = 0;
    }

    //Get Base Consultation Fee
    baseFee = doctor[specialtyIndex].baseConsultationFee;

    //Calculate Emergency Surcharge
    surcharge = emergencySurcharge(baseFee, patients[foundIndex].triageLevel);
    //Calculate Ward Cost
    if (patients[foundIndex].wardStatus == 1)
    {
        totalWardCost = totalWardStayCost(wards[wardIndex].dailyBedRate, patients[foundIndex].daysAdmitted,
                                          patients[foundIndex].wardStatus);
    }
    else
    {
        totalWardCost = 0;
    }
    //Calculate Gross Total
    grossTotal = grossTotalBill(baseFee, totalWardCost, surcharge);

    //Calculate Age Discount
    discount = ageSubsidyDiscount(grossTotal, patients[foundIndex].patientAge);

    //Calculate Final Amount
    finalAmount = finalAmountPayable(grossTotal, discount);


    savePatientBillingRecord(
    patients,
    foundIndex,
    grossTotal,
    discount,
    finalAmount
);

    //Print Bill
    printf("\n");
    printf("===============================================\n");
    printf("           SMART HOSPITAL BILL\n");
    printf("===============================================\n");
    printf("Patient ID        : %s\n", patients[foundIndex].patientID);
    printf("Patient Name      : %s\n", patients[foundIndex].patientName);
    printf("Age               : %d\n", patients[foundIndex].patientAge);
    printf("Emergency Level   : %d\n", patients[foundIndex].triageLevel);
    printf("Specialty         : %s\n", doctor[specialtyIndex].specialtyName);
    printf("Base Fee          : LKR %.2f\n", baseFee);
    printf("Emergency Charge  : LKR %.2f\n", surcharge);
    if (patients[foundIndex].wardStatus == 1)
    {
        printf("Ward             : %s\n", wards[wardIndex].wardName);
        printf("Bed ID           : %d\n", patients[foundIndex].bedID);
        printf("Days Admitted    : %d\n", patients[foundIndex].daysAdmitted);
        printf("Ward Cost        : LKR %.2f\n", totalWardCost);
    }
    else
    {
        printf("Ward             : Not Admitted\n");
        printf("Ward Cost        : LKR 0.00\n");
    }
    printf("-----------------------------------------------\n");
    printf("Gross Total      : LKR %.2f\n", grossTotal);
    printf("Age Discount     : LKR %.2f\n", discount);
    printf("Final Amount     : LKR %.2f\n", finalAmount);
    printf("Waiting Time     : %d mins\n", patients[foundIndex].waitingTime);
    printf("===============================================\n");
}
