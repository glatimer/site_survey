#include "surveyData.h"
#include <iostream>

using namespace std;

surveyData::surveyData() {
	sector = 0;
	exposure = 0;
	speed = 0;
}

void surveyData::setSector(int sector_entry) {
    sector = sector_entry;
}

int surveyData::getSector() {
	return sector;
}

void surveyData::setExposure(int exposure_entry) {
	exposure = exposure_entry;
}

int surveyData::getExposure() {
	return exposure;
}

void surveyData::setSpeed(int speed_entry) {
	speed = speed_entry;
}

int surveyData::getSpeed() {
	return speed;
}




