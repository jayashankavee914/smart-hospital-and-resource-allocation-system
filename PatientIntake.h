#ifndef PATIENTINTAKE_H
#define PATIENTINTAKE_H

#include "hospitalData.h"

void patientDetails(patientData *patient, int bedOccupancy[4][20]);
void admittedDays(patientData *patient);

#endif // PATIENTINTAKE_H
