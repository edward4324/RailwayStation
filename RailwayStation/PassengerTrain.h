#pragma once
#include "Train.h"

class PassengerTrain : public Train {

	int
		* passengerNum;//Количество пассажиров в поезде
	bool
		* coupe,//Есть купе или нет
		* restourant,//Есть вагон ресторан или нет
		* carriagesForAnimals;//Есть ли вагоны в которых можно перевозить животных

public:

	PassengerTrain();
	PassengerTrain(const PassengerTrain& train);
	~PassengerTrain();

	bool operator>(const PassengerTrain& train);
	PassengerTrain& operator=(const PassengerTrain& obj);

	friend std::istream& operator>> (std::istream& in, PassengerTrain& Ptrain);
	friend std::ostream& operator<< (std::ostream& out,const PassengerTrain& Ptrain);

};