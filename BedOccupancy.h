#ifndef BEDSTATUS_H
#define BEDSTATUS_H

#include "hospitalData.h"

void updateBedOccupancy(int bedOccupancy[4][20]);
void bedStatusTracking(int bedOccupancy[4][20], wardsData wards[4]);

#endif
