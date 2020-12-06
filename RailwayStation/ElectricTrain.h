#pragma once
#include "Train.h"

class ElectricTrain : public Train {

	int
		* passengerNum,//Количество пассажиров в поезде
		* numOfStops;//Количество остановок
	bool
		* IsHigh_speed;//Скоростной поезд или нет

public:

	ElectricTrain();
	ElectricTrain(const ElectricTrain& train);
	~ElectricTrain();

	friend std::istream& operator>> (std::istream& in, ElectricTrain& Etrain);

};