#pragma once
#include "Train.h"

class FrieghtTrain : public Train {

	double
		* liftingCapacity;//������������ ����������������
	string
		* cargo,//����� ��� ����� ���������
		* typeOfWagon;//�������� ��� ������� ������

public:

	FrieghtTrain();
	FrieghtTrain(const FrieghtTrain& train);
	~FrieghtTrain();

	friend std::istream& operator>> (std::istream& in, FrieghtTrain& Ftrain);

};