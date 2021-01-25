#include "datalogger.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void datalogger::addData(int sector, int exposure, int speed) {
	list.add(sector, exposure, speed);
}

void datalogger::printSectorList() {
	list.printSectorList();
}

void datalogger::printExposureList() {
	list.printExposureList();
}

void datalogger::printSpeedList() {
	list.printSpeedList();
}
bool datalogger::containsSector(int sector) {
	return list.containsSector(sector);
}

void datalogger::removeSector(int sector) {
	list.removeSector(sector);
}
void datalogger::printReport() {
	list.printReport();
}
