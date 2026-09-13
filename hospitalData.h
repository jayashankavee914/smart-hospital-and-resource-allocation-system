#ifndef HOSPITALDATA_H
#define HOSPITALDATA_H
typedef struct {
    int specialtyID;
    char specialtyName[100];
    float baseConsultationFee;
    float consultationTimePerPatient;
    int dailyPatientCap;
} doctorSpecialtyData;

typedef struct {
    int wardID;
    char wardName[100];
    float dailyBedRate;
    int totalBedCapacity;
} wardsData;

extern doctorSpecialtyData doctor[4];
extern wardsData wards[4];
#endif // HOSPITALDATA_H
