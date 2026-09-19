#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hospitalData.h"
#include "performanceReports.h"
#include "BillCalculations.h"

void displayUrgencyReport(patientData patients[], int patientCount)
{
    int normalCount = 0;
    int urgentCount = 0;
    int criticalCount = 0;

    for (int i = 0; i < patientCount; i++)
    {
        if (patients[i].triageLevel == 1)
        {
            normalCount++;
        }
        else if (patients[i].triageLevel == 2)
        {
            urgentCount++;
        }
        else if (patients[i].triageLevel == 3)
        {
            criticalCount++;
        }
    }

    printf("\n1. PATIENTS BY URGENCY\n");
    printf("-----------------------------------------------\n");
    printf("Normal   (Level 1) : %d\n", normalCount);
    printf("Urgent   (Level 2) : %d\n", urgentCount);
    printf("Critical (Level 3) : %d\n", criticalCount);
    printf("Total Patients     : %d\n", patientCount);
}

void displayRevenueReport(patientData patients[], int patientCount)
{
    float totalRevenue = 0.0;
    float totalDiscount = 0.0;

    for (int i = 0; i < patientCount; i++)
    {
        int specialtyIndex = -1;
        int wardIndex = -1;

        float baseFee = 0.0;
        float surcharge = 0.0;
        float wardCost = 0.0;
        float grossTotal = 0.0;
        float discount = 0.0;
        float finalAmount = 0.0;

        //Find specialty
        for (int j = 0; j < 4; j++)
        {
            if (doctor[j].specialtyID == patients[i].specialtyID)
            {
                specialtyIndex = j;
                break;
            }
        }

        if (specialtyIndex == -1)
        {
            continue;
        }

        baseFee = doctor[specialtyIndex].baseConsultationFee;

        surcharge = emergencySurcharge(
            baseFee,
            patients[i].triageLevel
        );

        //Find ward
        if (patients[i].wardStatus == 1)
        {
            for (int j = 0; j < 4; j++)
            {
                if (wards[j].wardID == patients[i].wardID)
                {
                    wardIndex = j;
                    break;
                }
            }

            if (wardIndex != -1)
            {
                wardCost = totalWardStayCost(wards[wardIndex].dailyBedRate, patients[i].daysAdmitted, patients[i].wardStatus
                );
            }
        }

        grossTotal = grossTotalBill(baseFee, wardCost, surcharge);
        discount = ageSubsidyDiscount(grossTotal, patients[i].patientAge);
        finalAmount = finalAmountPayable(grossTotal, discount);
        totalRevenue += finalAmount;
        totalDiscount += discount;
    }

    printf("\n2. REVENUE & DISCOUNTS\n");
    printf("-----------------------------------------------\n");
    printf("Total Revenue   : LKR %.2f\n", totalRevenue);
    printf("Total Discounts : LKR %.2f\n", totalDiscount);
}

void displayBedOccupancyReport(int bedOccupancy[4][20])
{
    printf("\n3. BED OCCUPANCY\n");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < 4; i++)
    {
        int occupiedBeds = 0;

        for (int j = 0; j < wards[i].totalBedCapacity; j++)
        {
            if (bedOccupancy[i][j] == 1)
            {
                occupiedBeds++;
            }
        }

        float occupancyPercentage =
            ((float)occupiedBeds / wards[i].totalBedCapacity) * 100;

        printf("%-20s : %d/%d beds (%.2f%%)\n", wards[i].wardName,occupiedBeds, wards[i].totalBedCapacity, occupancyPercentage);
    }
}

void displayHighestPayingPatient(patientData patients[], int patientCount)
{
    int highestPatientIndex = -1;
    float highestBill = 0.0;

    for (int i = 0; i < patientCount; i++)
    {
        int specialtyIndex = -1;
        int wardIndex = -1;

        float baseFee = 0.0;
        float surcharge = 0.0;
        float wardCost = 0.0;
        float grossTotal = 0.0;
        float discount = 0.0;
        float finalAmount = 0.0;

        //Find specialty
        for (int j = 0; j < 4; j++)
        {
            if (doctor[j].specialtyID == patients[i].specialtyID)
            {
                specialtyIndex = j;
                break;
            }
        }

        if (specialtyIndex == -1)
        {
            continue;
        }

        baseFee = doctor[specialtyIndex].baseConsultationFee;

        surcharge = emergencySurcharge(baseFee, patients[i].triageLevel);

        //Find ward
        if (patients[i].wardStatus == 1)
        {
            for (int j = 0; j < 4; j++)
            {
                if (wards[j].wardID == patients[i].wardID)
                {
                    wardIndex = j;
                    break;
                }
            }

            if (wardIndex != -1)
            {
                wardCost = totalWardStayCost(wards[wardIndex].dailyBedRate, patients[i].daysAdmitted, patients[i].wardStatus);
            }
        }

        grossTotal = grossTotalBill(baseFee, wardCost, surcharge);

        discount = ageSubsidyDiscount(grossTotal, patients[i].patientAge);

        finalAmount = finalAmountPayable(grossTotal, discount);

        if (finalAmount > highestBill)
        {
            highestBill = finalAmount;
            highestPatientIndex = i;
        }
    }

    printf("\n4. HIGHEST-PAYING PATIENT\n");
    printf("-----------------------------------------------\n");

    if (highestPatientIndex != -1)
    {
        printf("Patient ID   : %s\n", patients[highestPatientIndex].patientID);
        printf("Patient Name : %s\n", patients[highestPatientIndex].patientName);
        printf("Total Bill   : LKR %.2f\n", highestBill);
    }
    else
    {
        printf("No patient records available.\n");
    }
}
