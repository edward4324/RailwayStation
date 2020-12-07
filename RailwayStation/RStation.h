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
	//типы поездов по путям://
	//1 - пассажирский		//
	//2 - эллектричка		//
	//3 - грузовой			//
	//////////////////////////
	//{ 1, 1, 1, 2, 2, 2, 3, 3, 3, 3 }
	//доработать систему хранения данных
	//сделать дополнительные методы классов для вывода информации и сбора этой-же информации
	vector<PassengerTrain>* Ptrain;
	vector<ElectricTrain>* Etrain;
	vector<FrieghtTrain>* Ftrain;

	void distribRW();
	//функции сортировки
	void Psort();
	void Esort();
	void Fsort();
	//функция для обращения к функциям сортировки
	void sort_vectors();

public:
	//доделать конструкторы класса
	RailwayStation();
	RailwayStation(const RailwayStation& station);
	~RailwayStation(); 

	void getDataFromFile(string FileName);	
	bool comparator(Time t1, Time t2);
	
	friend std::istream& operator>>(std::istream& in, RailwayStation& station);
	friend std::ostream& operator<<(std::ostream& out, const RailwayStation& station);

};

