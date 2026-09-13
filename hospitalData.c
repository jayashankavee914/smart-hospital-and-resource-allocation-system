#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospitalData.h"

//define doctor specialty
typedef struct {
    int specialtyID;
    char specialtyName[100];
    float baseConsultationFee;
    float consultationTimePerPatient;
    int dailyPatientCap;
} doctorSpecialtyData;

//define wards
typedef struct {
    int wardID;
    char wardName[100];
    float dailyBedRate;
    int totalBedCapacity;
} wardsData;

int main()
{

    doctorSpecialtyData doctor[4] = {
    {1, "General Practice", 1500.00, 15, 30},
    {2, "Paediatrics",      2500.00, 20, 20},
    {3, "Cardiology",       4500.00, 30, 12},
    {4, "Neurology",        5000.00, 30, 10}
};

    wardsData wards[4] = {
    {1, "General Ward",     3000.00, 20},
    {2, "Paediatrics Ward", 6000.00, 10},
    {3, "Surgical Ward",   12000.00, 8},
    {4, "ICU",              25000.00, 5}
};

    return 0;
}

