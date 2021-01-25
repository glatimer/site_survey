#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "surveyData.h"

struct node {
	node *next_sector;
	node *next_exposure;
	node *next_speed;
	surveyData data;
};

class linkedList {
private:
	node *head_sector;
	node *head_exposure;
	node *head_speed;
	void sector_insert(node *curr, node *temp); // insert ordered by sector
	void exposure_insert(node *curr, node *temp); // insert ordered by exposure
	void speed_insert(node *curr, node *temp); // insert ordered by speed
	bool findSector(node *curr, int sector); // search
	void remove(int sector, node *curr);	// remove node from list
	void moveExposure(int sector, node *curr);	// adjust exposure for remove
	void moveSpeed(int sector, node *curr);	// adjust speed for remove
public:
	linkedList();	// constructor
	bool isEmpty();	// check to see if list is empty
	void add(int sector, int exposure, int speed);	// add data to the list
	void printSectorList();	// print sorted by sector
	void printExposureList();	// print sorted by exposure
	void printSpeedList();	// print sorted by speed
	bool containsSector(int sector);	// sector already in the logger?
	void removeSector(int sector);	// remove all bad sector data
	void printReport();  // print a report
//	~linkedList(); // destructor

};
#endif
