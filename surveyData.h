#ifndef SURVEY_DATA_H
#define SURVEY_DATA_H

class surveyData {
private:
	int sector;
	int exposure;
	int speed;
public:
	surveyData();
	void setSector(int sector_entry);
	int getSector();
	void setExposure(int exposure_entry);
	int getExposure();
	void setSpeed(int speed_entry);
	int getSpeed();
};
#endif
