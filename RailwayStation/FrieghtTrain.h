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

	bool operator>(const FrieghtTrain& train);

	friend std::istream& operator>> (std::istream& in, FrieghtTrain& Ftrain);
	friend std::ostream& operator<< (std::ostream& out, const FrieghtTrain& Ftrain);

};