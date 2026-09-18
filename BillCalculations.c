#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospitalData.h"
#include "bedOccupancy.h"
#include "printBill.h"


float totalWardStayCost (float dailyBedRate, int daysAdmitted, int wardStatus)
{
    float totalWardCost;
    if (wardStatus == 1)
        totalWardCost = dailyBedRate * daysAdmitted;
    else
        totalWardCost = 0;
    return totalWardCost;
}

float emergencySurcharge (float baseConsultationFee, int triageLevel)
{
    float surcharge;
    if (triageLevel == 1)
        surcharge = 0;
    else if (triageLevel == 2)
        surcharge = baseConsultationFee * 0.20;
    else if (triageLevel == 3)
        surcharge = baseConsultationFee * 0.50;
    return surcharge;
}

float grossTotalBill (float baseConsultationFee, float totalWardCost, float surcharge)
{
    float grossTotal;
    grossTotal = baseConsultationFee + surcharge + totalWardCost;
    return grossTotal;
}

float ageSubsidyDiscount (float grossTotal, int patientAge)
{
    float discount;
    if (patientAge < 5 || patientAge > 65)
        discount = grossTotal * 0.15;
    else
        discount = 0;
    return discount;
}

float finalAmountPayable(float grossTotal, float discount)
{
    float finalAmount;
    finalAmount = grossTotal - discount;
    return finalAmount;
}









