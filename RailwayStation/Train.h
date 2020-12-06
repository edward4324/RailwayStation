#pragma once
#include <iostream>
#include "Time.h"

using namespace std;

class Train {

protected:
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

public:

	Train();
	Train(const Train& train);
	~Train();

};


