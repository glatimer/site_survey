#include "linkedList.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// constructor
linkedList::linkedList() {	
	head_sector = NULL;
	head_exposure = NULL;
	head_speed = NULL;
}
// check if the list is empty
bool linkedList::isEmpty() {
	if (head_sector == NULL) {
		return true;
	} else {
		return false;
	}
}
// add an item to the list
void linkedList::add(int sector, int exposure, int speed) {
	node *temp = new node;	// initialize new node
	temp->next_sector = NULL;
	temp->next_exposure = NULL;
	temp->next_speed = NULL;
	temp->data.setSector(sector);
	temp->data.setExposure(exposure);
	temp->data.setSpeed(speed);
	sector_insert(head_sector, temp);
	exposure_insert(head_exposure, temp);
	speed_insert(head_speed, temp);
}
// inster sorted by sector
void linkedList::sector_insert(node *curr, node *temp) {
	// add first node to list
	if (head_sector == NULL) {
		head_sector = temp;
	// smallest first
	} else if (head_sector->data.getSector() >= temp->data.getSector()) {
		temp->next_sector = head_sector;
		head_sector = temp;
	// add nodes from smallest to largest
	} else {
		while (curr->next_sector != NULL && curr->next_sector->data.getSector() < temp->data.getSector()) {
			curr = curr->next_sector;
		} 
		temp->next_sector = curr->next_sector;
		curr->next_sector = temp;
		return;
	}
}
// insert sorted by exposure
void linkedList::exposure_insert(node *curr, node *temp) {
	// add first node to list
	if (head_exposure == NULL) {
		head_exposure = temp;
	// smallest first
	} else if (head_exposure->data.getExposure() >= temp->data.getExposure()) {
		temp->next_exposure = head_exposure;
		head_exposure = temp;
	// add nodes from smallest to largest
	} else {
		while (curr->next_exposure != NULL && curr->next_exposure->data.getExposure() < temp->data.getExposure()) {
			curr = curr->next_exposure;
		} 
		temp->next_exposure = curr->next_exposure;
		curr->next_exposure = temp;
		return;
	}
}
// insert sorted by speed
void linkedList::speed_insert(node *curr, node *temp) {
	// add first node to list
	if (head_speed == NULL) {
		head_speed = temp;
	// smallest first
	} else if (head_speed->data.getSpeed() >= temp->data.getSpeed()) {
		temp->next_speed = head_speed;
		head_speed = temp;
	// add nodes from smallest to largest
	} else {
		while (curr->next_speed != NULL && curr->next_speed->data.getSpeed() < temp->data.getSpeed()) {
			curr = curr->next_speed;
		} 
		temp->next_speed = curr->next_speed;
		curr->next_speed = temp;
		return;
	}
}
// print sorted by sector
void linkedList::printSectorList() {
	node *temp = head_sector;
	while (temp != NULL) {
		cout << "Sector: #" << temp->data.getSector() << " "
			 << temp->data.getExposure() << "\% exposure, " 
			 << temp->data.getSpeed() << "kh/hr windspeed" << endl;
		temp = temp->next_sector;
	}
}
// print sorted by exposure
void linkedList::printExposureList() {
	node *temp = head_exposure;
	while (temp != NULL) {
		cout << "Sector: #" << temp->data.getSector() << " "
			 << temp->data.getExposure() << "\% exposure, " 
			 << temp->data.getSpeed() << "kh/hr windspeed" << endl;
		temp = temp->next_exposure;
	}
}
// print sorted by speed
void linkedList::printSpeedList() { 
	node *temp = head_speed;
	while (temp != NULL) {
		cout << "Sector: #" << temp->data.getSector() << " "
			 << temp->data.getExposure() << "\% exposure, " 
			 << temp->data.getSpeed() << "kh/hr windspeed" << endl;
		temp = temp->next_speed;
	}
}
// search by sector
bool linkedList::findSector(node *curr, int sector) {
	if (curr == NULL) {
		return false;
	} else if (curr->data.getSector() == sector) {
		return true;
	} else {
		return findSector(curr->next_sector, sector);
	}
}
// find a particular sector in the list
bool linkedList::containsSector(int sector) {
	return findSector(head_sector, sector);
}
// skip exposure from bad sector
void linkedList::moveExposure(int sector, node *curr) {
	if (curr->next_exposure == NULL) {
		return;
	} else if (head_exposure->data.getSector() == sector) {
		head_exposure = curr->next_exposure;
		return moveExposure(sector, curr);
	} else if (curr->next_exposure->data.getSector() == sector) {
		node *temp = curr->next_exposure;
		curr->next_exposure = temp->next_exposure;
		return moveExposure(sector, curr);
	} else {
		return moveExposure(sector, curr->next_exposure);
	}
}
// skip speed from bad sector
void linkedList::moveSpeed(int sector, node *curr) {
	if (curr->next_speed == NULL) {
		return;
	} else if (head_speed->data.getSector() == sector) {
		head_speed = curr->next_speed;
		return moveSpeed(sector, curr);
	} else if (curr->next_speed->data.getSector() == sector) {
		node *temp = curr->next_speed;
		curr->next_speed = temp->next_speed;
		return moveSpeed(sector, curr);
	} else {
		return moveSpeed(sector, curr->next_speed);
	}
}
// identify bad sector
void linkedList::remove(int sector, node *curr) {
	if(curr->next_sector == NULL) {
		return;
	} else if (head_sector->data.getSector() == sector) { //remove a head node
		node *temp = head_sector;
		head_sector = temp->next_sector;
		moveExposure(sector, head_exposure);
		moveSpeed(sector, head_speed);
		delete(temp);
		return remove(sector, head_sector);
	} else if (curr->next_sector->data.getSector() == sector) { //remove other
		node *temp = curr->next_sector;
		curr->next_sector = temp->next_sector;
		moveExposure(sector, head_exposure);
		moveSpeed(sector, head_speed);
		delete(temp);
		return remove(sector, curr);
	} else {
		return remove(sector, curr->next_sector);
	}
}
// remove bad sector
void linkedList::removeSector(int sector) {
	remove(sector, head_sector);
}
// print conclusive report
void printReport() {

}
