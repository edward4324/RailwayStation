#pragma once
#include "Train.h"

class PassengerTrain : public Train {

	int
		* passengerNum;//���������� ���������� � ������
	bool
		* coupe,//���� ���� ��� ���
		* restourant,//���� ����� �������� ��� ���
		* carriagesForAnimals;//���� �� ������ � ������� ����� ���������� ��������

public:

	PassengerTrain();
	PassengerTrain(const PassengerTrain& train);
	~PassengerTrain();

	bool operator>(const PassengerTrain& train);

	friend std::istream& operator>> (std::istream& in, PassengerTrain& Ptrain);
	friend std::ostream& operator<< (std::ostream& out,const PassengerTrain& Ptrain);

};