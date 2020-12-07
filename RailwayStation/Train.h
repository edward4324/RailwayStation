#pragma once
#include <iostream>
#include "Time.h"

using namespace std;

class Train {

protected:
	string
		* depart,//���� ������������
		* arrival;//������ ���������

	int
		* railwayNum;//����� ���� (��������������� ���������� �������������)
	//��� ������� ����� ���������� ����������� ����������� ���������� �� ������ �� ������������� �����(1 �� ��������),
	//�� � �� ���� �������(2-� �� ��������)

	//�������������, �� ����� �����������:
	//Train* nextEl;
	//Train* prevEl;

public:

	Time
		* arrivalTime,//����� ��������
		* departTime;//����� �����������

	Train();
	Train(const Train& train);

	void setRWnum(int rwnum);
	int getRWnum();

	~Train();

};


