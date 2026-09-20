#include <stdio.h>
#include <stdlib.h>
#include "hospitaldata.h"
#include "bedOccupancy.h"
#include "mainMenu.h"
#include "waitingTime.h"
#include "fileHandling.h"

int main()
{
    int bedOccupancy[4][20] = {0};

    loadPatients();
    loadBedStatus(bedOccupancy);

    mainMenu(bedOccupancy);

    return 0;
}
