#pragma once
#include <iostream>
#include "Time.h"

using namespace std;

struct TrainNode {

	string
		*depart,//куда направляется
		*destin;//откуда прибывает

	Time
		*arrivalT,//время прибытия
		*departT;//время отправления

	int
		*num,//
		*railwayNum;//
	
	string *trainType;//

	//необязательно, но можно попробовать:
	//Train* nextEl;
	//Train* prevEl;

};

class Train {

private:
	TrainNode *_train;

public:


};

