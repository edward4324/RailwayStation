#pragma once
#include "Train.h"

class FrieghtTrain : public Train {

	double
		* liftingCapacity;//Максимальная грузоподъемность
	string
		* cargo,//Какой тип груза перевозит
		* typeOfWagon;//Основной тип вагонов поезда

public:

	FrieghtTrain();
	FrieghtTrain(const FrieghtTrain& train);
	~FrieghtTrain();

	bool operator>(const FrieghtTrain& train);

	friend std::istream& operator>> (std::istream& in, FrieghtTrain& Ftrain);
	friend std::ostream& operator<< (std::ostream& out, const FrieghtTrain& Ftrain);

};