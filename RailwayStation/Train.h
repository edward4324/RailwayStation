#pragma once
#include <iostream>
#include "Time.h"

using namespace std;

class Train {

public:
	string
		* depart,//���� ������������
		* arrival;//������ ���������

	Time
		* arrivalTime,//����� ��������
		* departTime;//����� �����������

	int
		* num,//����� ������
		* railwayNum;//����� ���� (��������������� ���������� �������������)
	//��� ������� ����� ���������� ����������� ����������� ���������� �� ������ �� ������������� �����(1 �� ��������),
	//�� � �� ���� �������(2-� �� ��������)

	//�������������, �� ����� �����������:
	//Train* nextEl;
	//Train* prevEl;

	Train();
	Train(const Train& train);
	~Train();

	friend std::istream& operator>> (std::istream& in, Train& train);

};

class PassengerTrain : public Train {



};

class ElectricTrain : public Train {



};

class FrieghtTrain : public Train {



};


