#pragma once
#include "ElectricTrain.h"
#include "FrieghtTrain.h"
#include "PassengerTrain.h"
#include <iostream>
#include <vector>

using namespace std;

class RailwayStation {

private:

	//////////////////////////
	//���� ������� �� �����://
	//1 - ������������		//
	//2 - �����������		//
	//3 - ��������			//
	//////////////////////////
	//{ 1, 1, 1, 2, 2, 2, 3, 3, 3, 3 }
	//���������� ������� �������� ������
	//������� �������������� ������ ������� ��� ������ ���������� � ����� ����-�� ����������
	vector<PassengerTrain>* Ptrain;
	vector<ElectricTrain>* Etrain;
	vector<FrieghtTrain>* Ftrain;

public:
	//�������� ������������ ������
	RailwayStation();
	RailwayStation(const RailwayStation& station);
	~RailwayStation();
	//� ������� ������� ������� ��������� ���� � �����
	//������� ��������� ����/����� � ����� ������� ������� �������������� ������� ��� ��������� ���������� �� �������
	//����� �����-�� ������������ ������ (������� ������� ����� ����� �����-�� ����� �� ������� ����� waitingForAmount)

	friend std::istream& operator>>(std::istream& in, RailwayStation& station);

};
