#pragma once
#include <iostream>
#include "Time.h"

using namespace std;

class Train {

protected:
	string
		* depart,//куда направляется
		* arrival;//откуда прибывает

	Time
		* arrivalTime,//время прибытия
		* departTime;//время отправления

	int
		* num,//Номер поезда
		* railwayNum;//Номер пути (устанавливается программой автоматически)
	//для номеров путей желательно реализовать возможность сортировки не только по загруженности путей(1 по важности),
	//но и по типу поездов(2-е по важности)

	//необязательно, но можно попробовать:
	//Train* nextEl;
	//Train* prevEl;

public:

	Train();
	Train(const Train& train);
	~Train();

};


