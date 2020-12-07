#include "RStation.h"
#include <fstream>

RailwayStation::RailwayStation()
{

	Ptrain = new vector<PassengerTrain>;
	Etrain = new vector<ElectricTrain>;
	Ftrain = new vector<FrieghtTrain>;
	
	for (int i = 0; i < 10; i++)
		checkRW[i] = 0;
}

RailwayStation::RailwayStation(const RailwayStation& station)
{

	*Ptrain = *station.Ptrain;
	*Etrain = *station.Etrain;
	*Ftrain = *station.Ftrain;

	for (int i = 0; i < 10; i++)
		checkRW[i] = 0;
}

RailwayStation::~RailwayStation()
{

	delete Ptrain;
	delete Etrain;
	delete Ftrain;

	for (int i = 0; i < 10; i++)
		checkRW[i] = 0;
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

	sort_vectors();

	//����������� ������ ����  �� ������� ��� ������������ �������
	size_t it1 = 1;
	//����������� ��� ������ ���� ������� ������ �������� � ������� ������������, 
	//����� ����������� �� ���� ������ �������� � ������� ��������
	for (; it1 != PtrainRW; it1++)
		Ptrain->at(it1).setRWnum(it1);
	for (; it1 <= i; it1++) {		
			if (Ptrain->at(it1).getRWnum() + 1 <= PtrainRW)
				//��������� ��������, �������� � ������ ���� ����. ������ �������
				Ptrain->at(it1).setRWnum(Ptrain->at(it1).getRWnum() + 1);
			else
				//��������� ��������, �������� ������������ ���������� ������������ ������� �� ������ ���� ����. ������
				Ptrain->at(it1).setRWnum(Ptrain->at(it1).getRWnum() - PtrainRW);
	}

	//����������� ������ ����  �� ������� ��� ������������ �������
	it1 = PtrainRW + 1;
	//����������� ��� ������ ���� ������� ������ �������� � ������� ������������, 
	//����� ����������� �� ���� ������ �������� � ������� ��������
	for (; it1 != PtrainRW + EtrainRW; it1++)
		Etrain->at(it1).setRWnum(it1);
	for (; it1 <= i; it1++){
			if (Etrain->at(it1).getRWnum() + 1 <= EtrainRW + PtrainRW)
				//��������� ��������, �������� � ������ ���� ����. ������ �������
				Etrain->at(it1).setRWnum(Etrain->at(it1).getRWnum() + 1);
			else
				//��������� ��������, �������� ������������ ���������� ������������ ������� �� ������ ���� ����. ������
				Etrain->at(it1).setRWnum(Etrain->at(it1).getRWnum() - EtrainRW);
	}

	//����������� ������ ����  �� ������� ��� �������� �������
	it1 = PtrainRW + EtrainRW + 1;
	//����������� ��� ������ ���� ������� ������ �������� � ������� ������������, 
	//����� ����������� �� ���� ������ �������� � ������� ��������
	for (; it1 != FtrainRW + EtrainRW + PtrainRW; it1++)
		Ftrain->at(it1).setRWnum(it1);
	for (; it1 <= i; it1++) {
		if (Ftrain->at(it1).getRWnum() + 1 <= FtrainRW + EtrainRW + PtrainRW)
				//��������� ��������, �������� � ������ ���� ����. ������ �������
				Ftrain->at(it1).setRWnum(Ftrain->at(it1).getRWnum() + 1);
			else
				//��������� ��������, �������� ������������ ���������� ������������ ������� �� ������ ���� ����. ������
				Ftrain->at(it1).setRWnum(Ftrain->at(it1).getRWnum() - FtrainRW);
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

	size_t n = Ptrain->size();

	for (size_t i = 0; i < n; i++) {

		for (size_t j = n - 1; j > i; j--) {

			if (comparator(*Ptrain->at(j - 1).departTime, *Ptrain->at(j).arrivalTime)) {

				swap(Ptrain->at(j - 1), Ptrain->at(j));

			}

		}

	}

}

void RailwayStation::Esort()
{
	size_t n = Etrain->size();

	for (size_t i = 0; i < n; i++) {

		for (size_t j = n - 1; j > i; j--) {

			if (comparator(*Etrain->at(j - 1).departTime, *Etrain->at(j).arrivalTime)) {

				swap(Etrain->at(j - 1), Etrain->at(j));

			}

		}

	}
}

void RailwayStation::Fsort()
{
	size_t n = Ftrain->size();

	for (size_t i = 0; i < n; i++) {

		for (size_t j = n - 1; j > i; j--) {

			if (comparator(*Ftrain->at(j - 1).departTime, *Ftrain->at(j).arrivalTime)) {

				swap(Ftrain->at(j - 1), Ftrain->at(j));

			}

		}

	}
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