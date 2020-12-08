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
	vector<PassengerTrain>* Ptrain;
	vector<ElectricTrain>* Etrain;
	vector<FrieghtTrain>* Ftrain;

	void distribRW();
	//������� ����������
	void Psort();
	void Esort();
	void Fsort();

	void Pswap(PassengerTrain& p1, PassengerTrain& p2);
	void Eswap(ElectricTrain& e1, ElectricTrain& e2);
	void Fswap(FrieghtTrain& f1, FrieghtTrain& f2);

	//������� ��� ��������� � �������� ����������
	void sort_vectors();

public:
	//�������� ������������ ������
	RailwayStation();
	RailwayStation(const RailwayStation& station);
	~RailwayStation(); 

	void getDataFromFile(string FileName);	
	bool comparator(Time t1, Time t2);
	
	friend std::istream& operator>>(std::istream& in, RailwayStation& station);
	friend std::ostream& operator<<(std::ostream& out, const RailwayStation& station);

};

