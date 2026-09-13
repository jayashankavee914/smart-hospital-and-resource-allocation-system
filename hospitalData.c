#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char wardName;
    float dailyBedRate;
    int totalBedCapacity;
} wardsData;

int main()
{
    doctorSpecialtyData doctor[4];
    doctor[0].specialtyID = 1;
    strcpy(doctor[0].specialtyName, "General Practice");
    doctor[0].baseConsultationFee = 1500.00;
    doctor[0].consultationTimePerPatient = 15;
    doctor[0].dailyPatientCap = 30;

    doctor[1].specialtyID = 2;
    strcpy (doctor[0].specialtyName, "Paediatrics");
    doctor[1].baseConsultationFee = 2500.00;
    doctor[1].consultationTimePerPatient = 20;
    doctor[1].dailyPatientCap = 20;

    doctor[2].specialtyID = 3;
    strcpy (doctor[2].specialtyName, "Cardiology");
    doctor[2].baseConsultationFee = 4500.00;
    doctor[2].consultationTimePerPatient = 30;
    doctor[2].dailyPatientCap = 12;

    doctor[3].specialtyID = 4;
    strcpy (doctor[3].specialtyName, "Neurology");
    doctor[3].baseConsultationFee = 5000.00;
    doctor[3].consultationTimePerPatient = 30;
    doctor[3].dailyPatientCap = 10;


    wardsData wards[4];

    wards[0].wardID = 1;
    strcpy(wards[0].wardName, "General Ward");
    wards[0].dailyBedRate = 3000.00;
    wards[0].totalBedCapacity = 20;

    wards[1].wardID = 2;
    strcpy(wards[1].wardName, "Paediatrics Ward");
    wards[1].dailyBedRate = 6000.00;
    wards[1].totalBedCapacity = 10;

    wards[2].wardID = 3;
    strcpy(wards[2].wardName, "Surgical Ward");
    wards[2].dailyBedRate = 12000.00;
    wards[2].totalBedCapacity = 10;

    wards[3].wardID = 3;
    strcpy(wards[3].wardName, "ICU");
    wards[3].dailyBedRate = 25000.00;
    wards[3].totalBedCapacity = 5;

    return 0;
}

