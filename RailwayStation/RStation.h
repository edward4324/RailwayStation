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

public:
	//доделать конструкторы класса
	RailwayStation();
	RailwayStation(const RailwayStation& station);
	~RailwayStation();
	//в классах поездов сделать потоковый ввод и вывод
	//сделать потоковый ввод/вывод и также сделать парочку дополнительных методов для получения информации по поездам
	//вводя какие-то определенные данные (сколько поездов будет через какое-то время на станции метод waitingForAmount)

	friend std::istream& operator>>(std::istream& in, RailwayStation& station);

};
