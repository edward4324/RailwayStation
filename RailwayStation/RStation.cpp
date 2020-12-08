#include "RStation.h"
#include <fstream>

RailwayStation::RailwayStation()
{

	Ptrain = new vector<PassengerTrain>;
	Etrain = new vector<ElectricTrain>;
	Ftrain = new vector<FrieghtTrain>;
	
}

RailwayStation::RailwayStation(const RailwayStation& station)
{

	Ptrain = new vector<PassengerTrain>(*station.Ptrain);
	Etrain = new vector<ElectricTrain>(*station.Etrain);
	Ftrain = new vector<FrieghtTrain>(*station.Ftrain);

}

RailwayStation::~RailwayStation()
{

	delete Ptrain;
	delete Etrain;
	delete Ftrain;

}

void RailwayStation::getDataFromFile(string FileName)
{

	fstream in(FileName);
	while (!in.eof())
	in >> *this;

	in.close();

	distribRW();

}

void RailwayStation::distribRW()
{

	size_t i,
		j,
		k;

	i = Ptrain->size();
	j = Etrain->size();
	k = Ftrain->size();

	size_t it1 = 0;

	sort_vectors();
	if (i > 1) {
		//определение номера пути  по времени для пассажирских поездов
		
		//расставляем для первых трех поездов номера платформ в порядке возразстания, 
		//чтобы основываясь на этом дальше работать с другими поездами
		for (; it1 < PtrainRW; it1++)
			Ptrain->at(it1).setRWnum(it1+1);
		
		for (; it1 < i; it1++) {
			if (Ptrain->at(it1-1).getRWnum() + 1 <= PtrainRW)
				//установим значение, прибавив к номеру пути пред. поезда единицу
				Ptrain->at(it1).setRWnum(Ptrain->at(it1-1).getRWnum() + 1);
			else
				//установим значение, вычислив максимальное количество пассажирских поездов из номера пути пред. поезда
				Ptrain->at(it1).setRWnum(Ptrain->at(it1-1).getRWnum() - PtrainRW + 1);
		}
	}

	if (j > 1) {
		//определение номера пути  по времени для пассажирских поездов
		it1 = PtrainRW + 1;
		//расставляем для первых трех поездов номера платформ в порядке возразстания, 
		//чтобы основываясь на этом дальше работать с другими поездами
		for (; it1 != PtrainRW + EtrainRW; it1++)
			Etrain->at(it1).setRWnum(it1);
		for (; it1 <= i; it1++) {
			if (Etrain->at(it1).getRWnum() + 1 <= EtrainRW + PtrainRW)
				//установим значение, прибавив к номеру пути пред. поезда единицу
				Etrain->at(it1).setRWnum(Etrain->at(it1).getRWnum() + 1);
			else
				//установим значение, вычислив максимальное количество пассажирских поездов из номера пути пред. поезда
				Etrain->at(it1).setRWnum(Etrain->at(it1).getRWnum() - EtrainRW);
		}
	}

	if (k > 1) {
		//определение номера пути  по времени для грузовых поездов
		it1 = PtrainRW + EtrainRW + 1;
		//расставляем для первых трех поездов номера платформ в порядке возразстания, 
		//чтобы основываясь на этом дальше работать с другими поездами
		for (; it1 != FtrainRW + EtrainRW + PtrainRW; it1++)
			Ftrain->at(it1).setRWnum(it1);
		for (; it1 <= i; it1++) {
			if (Ftrain->at(it1).getRWnum() + 1 <= FtrainRW + EtrainRW + PtrainRW)
				//установим значение, прибавив к номеру пути пред. поезда единицу
				Ftrain->at(it1).setRWnum(Ftrain->at(it1).getRWnum() + 1);
			else
				//установим значение, вычислив максимальное количество пассажирских поездов из номера пути пред. поезда
				Ftrain->at(it1).setRWnum(Ftrain->at(it1).getRWnum() - FtrainRW);
		}
	}
}

void RailwayStation::sort_vectors()
{

	Psort();
	Esort();
	Fsort();

}

void RailwayStation::Psort()
{
	//comparator(*Ptrain->at(j - 1).departTime, *Ptrain->at(j).arrivalTime)
	//Pswap(Ptrain->at(j), Ptrain->at(j+1));
	size_t n = Ptrain->size();
	if (n != 0) {
		size_t i, j;
		bool swapped;
		for (i = 0; i < n - 1; i++)
		{
			swapped = false;
			for (j = 0; j < n - i - 1; j++)
			{
				if (comparator(*Ptrain->at(j).departTime, *Ptrain->at(j + 1).arrivalTime))
				{
					Pswap(Ptrain->at(j), Ptrain->at(j + 1));
					swapped = true;
				}
			}
			if (swapped == false)
				break;
		}
	}

}

void RailwayStation::Esort()
{
	size_t n = Etrain->size();
	if (n != 0) {
		size_t i, j;
		bool swapped;
		for (i = 0; i < n - 1; i++)
		{
			swapped = false;
			for (j = 0; j < n - i - 1; j++)
			{
				if (comparator(*Etrain->at(j).departTime, *Etrain->at(j + 1).arrivalTime))
				{
					Eswap(Etrain->at(j), Etrain->at(j + 1));
					swapped = true;
				}
			}
			if (swapped == false)
				break;
		}
	}
}

void RailwayStation::Fsort()
{
	size_t n = Ftrain->size();
	if (n != 0) {
		size_t i, j;
		bool swapped;
		for (i = 0; i < n - 1; i++)
		{
			swapped = false;
			for (j = 0; j < n - i - 1; j++)
			{
				if (comparator(*Ftrain->at(j).departTime, *Ftrain->at(j + 1).arrivalTime))
				{
					Fswap(Ftrain->at(j), Ftrain->at(j + 1));
					swapped = true;
				}
			}
			if (swapped == false)
				break;
		}
	}
}

void RailwayStation::Pswap(PassengerTrain& p1, PassengerTrain& p2)
{

	PassengerTrain temp;

	temp = p1;
	p1 = p2;
	p2 = temp;


}

void RailwayStation::Eswap(ElectricTrain& e1, ElectricTrain& e2)
{

	ElectricTrain temp;

	temp = e1;
	e1 = e2;
	e2 = temp;


}

void RailwayStation::Fswap(FrieghtTrain& f1, FrieghtTrain& f2)
{

	FrieghtTrain temp;

	temp = f1;
	f1 = f2;
	f2 = temp;


}

bool RailwayStation::comparator(Time t1, Time t2)
{
	return t1 > t2;
}

std::istream& operator>>(std::istream& in, RailwayStation& station)
{
	
	int temp;
	in >> temp;

	if (temp == 1) {

		PassengerTrain train;
		in >> train;
		station.Ptrain->push_back(train);

	} 
	else if (temp == 2) {
	
		ElectricTrain train;
		in >> train;
		station.Etrain->push_back(train);

	}
	else {

		FrieghtTrain train;
		in >> train;
		station.Ftrain->push_back(train);

	}

	return in;

}

std::ostream& operator<<(std::ostream& out, const RailwayStation& station)
{
	int pn, en, fn;
	pn = station.Ptrain->size();
	en = station.Etrain->size();
	fn = station.Ftrain->size();

	if (pn > 0) {
		out << "Пассажирские поезда:" << endl;
		for (int i = 0; i < pn; i++)
			out << station.Ptrain->at(i);
	}

	if (en > 0) {
		out << "Поезда быстрого следования:" << endl;
		for (int i = 0; i < en; i++)
			out << station.Etrain->at(i);
	}

	if (fn > 0) {
		out << "Грузовые поезда:" << endl;
		for (int i = 0; i < fn; i++)
			out << station.Ftrain->at(i);
	}

	return out;
}
