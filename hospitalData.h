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
    char patientID[20];
    int patientAge;
    int triageLevel;
    int wardStatus;
    int daysAdmitted;
    int specialtyID;
    int wardID;
    int bedID;
    int waitingTime;
} patientData;


extern doctorSpecialtyData doctor[4];
extern wardsData wards[4];

extern patientData patients[100];
extern int patientCount;
extern int queueCount[4];

void savePatients(void);
void loadPatients(void);
void deletePatientData(patientData patients[], int *patientCount);

#endif
