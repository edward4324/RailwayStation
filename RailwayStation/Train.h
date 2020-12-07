#pragma once
#include <iostream>
#include "Time.h"

using namespace std;

class Train {

protected:
	string
		* depart,//куда направляется
		* arrival;//откуда прибывает

	int
		* railwayNum;//Номер пути (устанавливается программой автоматически)
	//для номеров путей желательно реализовать возможность сортировки не только по загруженности путей(1 по важности),
	//но и по типу поездов(2-е по важности)

	//необязательно, но можно попробовать:
	//Train* nextEl;
	//Train* prevEl;

public:

	Time
		* arrivalTime,//время прибытия
		* departTime;//время отправления

	Train();
	Train(const Train& train);

	void setRWnum(int rwnum);
	int getRWnum();

	~Train();

};


