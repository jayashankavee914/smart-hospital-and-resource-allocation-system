#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include "hospitalData.h"

void saveBedOccupiedStatus(int bedOccupancy[4][20]);
void loadBedStatus(int bedOccupancy[4][20]);

void savePatientBillingRecord(patientData patients[], int foundIndex,
                              float grossTotal, float discount,
                              float finalAmount);

#endif
