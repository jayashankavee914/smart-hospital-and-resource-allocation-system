#ifndef PERFORMANCE_REPORTS_H
#define PERFORMANCE_REPORTS_H

#include "hospitalData.h"

void displayUrgencyReport(patientData patients[], int patientCount);

void displayRevenueReport(patientData patients[], int patientCount);

void displayBedOccupancyReport(int bedOccupancy[4][20]);

void displayHighestPayingPatient(patientData patients[], int patientCount);

#endif
