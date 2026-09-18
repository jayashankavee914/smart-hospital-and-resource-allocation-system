#ifndef BILLCALCULATIONS_H
#define BILLCALCULATIONS_H
#include "hospitalData.h"
#include "bedOccupancy.h"

float totalWardStayCost (float dailyBedRate, int daysAdmitted, int wardStatus);
float emergencySurcharge (float baseConsultationFee, int triageLevel);
float grossTotalBill (float baseConsultationFee, float totalWardCost, float surcharge);
float ageSubsidyDiscount (float grossTotal, int patientAge);
float finalAmountPayable(float grossTotal, float discount);

#endif
// BILLCALCULATIONS_H
