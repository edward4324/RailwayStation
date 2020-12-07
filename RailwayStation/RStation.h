#pragma once
#include "ElectricTrain.h"
#include "FrieghtTrain.h"
#include "PassengerTrain.h"
#include "Train.h"
#include <vector>
#define PtrainRW 3
#define EtrainRW 3
#define FtrainRW 4

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
	int checkRW[10];

	void distribRW();
	//������� ����������
	void Psort();
	void Esort();
	void Fsort();
	//������� ��� ��������� � �������� ����������
	void sort_vectors();

public:
	//�������� ������������ ������
	RailwayStation();
	RailwayStation(const RailwayStation& station);
	~RailwayStation();

	void getDataFromFile(string FileName);	
	
	friend std::istream& operator>>(std::istream& in, RailwayStation& station);

	bool comparator(Time t1, Time t2);

};

