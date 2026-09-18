#include <stdio.h>
#include <stdlib.h>
#include "hospitaldata.h"
#include "bedOccupancy.h"
#include "mainMenu.h"
#include "waitingTime.h"

void patientDetails(patientData *patient);
void mainMenu();

int main()
{
    mainMenu();
    return 0;
}
