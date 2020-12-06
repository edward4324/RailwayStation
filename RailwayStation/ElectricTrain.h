#pragma once
#include "Train.h"

class ElectricTrain : public Train {

	int
		* passengerNum,//���������� ���������� � ������
		* numOfStops;//���������� ���������
	bool
		* IsHigh_speed;//���������� ����� ��� ���

public:

	ElectricTrain();
	ElectricTrain(const ElectricTrain& train);
	~ElectricTrain();

	friend std::istream& operator>> (std::istream& in, ElectricTrain& Etrain);

};