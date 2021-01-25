#ifndef DATALOGGER_H
#define DATALOGGER_H
#include "linkedList.h"

class datalogger {
private: 
linkedList list;

public:
void addData(int sector, int exposure, int speed);
bool isEmpty();
void printSectorList();
void printExposureList();
void printSpeedList();
bool containsSector(int sector);
void removeSector(int sector);
void printReport();
};
#endif
