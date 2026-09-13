#ifndef HOSPITALDATA_H
#define HOSPITALDATA_H

//Declaration Specialty Data Variables
typedef struct {
    int specialtyID;
    char specialtyName[100];
    float baseConsultationFee;
    float consultationTimePerPatient;
    int dailyPatientCap;
} doctorSpecialtyData;

//Declaration Ward Data Variables
typedef struct {
    int wardID;
    char wardName[100];
    float dailyBedRate;
    int totalBedCapacity;
} wardsData;

//Declaration Patient Data Variables
typedef struct {
    char patientName[100];
    int patientAge;
    int triageLevel;
    int wardStatus;
    int daysAdmitted;
    int specialtyID;
    int wardID;
} patientData;


extern doctorSpecialtyData doctor[4];
extern wardsData wards[4];

extern patientData patients[100];
extern int patientCount;

void savePatients(void);
void loadPatients(void);

#endif
