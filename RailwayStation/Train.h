#pragma once
#include <iostream>
#include "Time.h"

using namespace std;

struct TrainNode {

	string
		*depart,//���� ������������
		*destin;//������ ���������

	Time
		*arrivalT,//����� ��������
		*departT;//����� �����������

	int
		*num,//
		*railwayNum;//
	
	string *trainType;//

	//�������������, �� ����� �����������:
	//Train* nextEl;
	//Train* prevEl;

};

class Train {

private:
	TrainNode *_train;

public:


};

