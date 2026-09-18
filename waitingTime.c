#include <stdio.h>

#include "PatientIntake.h"

int waitingTimeCalculate(int consultationTimePerPatient, int queueCount)
{
    int waitTime;
    waitTime = queueCount * consultationTimePerPatient;
    return waitTime;
}
