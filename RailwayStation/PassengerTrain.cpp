#include "PassengerTrain.h"

std::istream& operator>>(std::istream& in, PassengerTrain& Ptrain)
{

    in >> *(Ptrain.passengerNum);
    in >> *(Ptrain.coupe);
    in >> *(Ptrain.restourant);
    in >> *(Ptrain.carriagesForAnimals);

    in >> *(Ptrain.depart);
    in >> *(Ptrain.arrival);
    in >> *(Ptrain.arrivalTime);
    in >> *(Ptrain.departTime);

    return in;
}

std::ostream& operator<<(std::ostream& out, const PassengerTrain& Ptrain)
{

    out << "����� ��������� �� ���� �����: " << *Ptrain.railwayNum << endl;
    out << "����� �������� ������: " << *Ptrain.arrivalTime << endl;
    out << "����� ������� ������: " << *Ptrain.departTime << endl;
    out << "����� ������� �� ��������: " << endl;
    out << *Ptrain.arrival << " - " << *Ptrain.depart << endl;
    out << "���������� ���������� � ������: " << *Ptrain.passengerNum << endl;
    out << "���������� � �������� � ������� ������: " 
         << (*Ptrain.carriagesForAnimals? "����������" : "���������") << endl;
    out << "����� - �������� � ������ "
         << (*Ptrain.restourant? "����" : "�����������") << endl;
    out << "� ������ �������� ������ " 
         << (*Ptrain.coupe? "����" : "�����������") << endl;

    return out;

}

PassengerTrain::PassengerTrain()
{

    depart = new string;
    arrival = new string;

    arrivalTime = new Time;
    departTime = new Time;

    railwayNum = new int;

    passengerNum = new int;
    coupe = new bool;
    restourant = new bool;
    carriagesForAnimals = new bool;

}

PassengerTrain::PassengerTrain(const PassengerTrain& train)
{

    depart = train.depart;
    arrival = train.arrival;

    arrivalTime = train.arrivalTime;
    departTime = train.departTime;
    railwayNum = train.railwayNum;

    passengerNum = train.passengerNum;

    coupe = train.coupe;
    restourant = train.restourant;
    carriagesForAnimals = train.carriagesForAnimals;

}

PassengerTrain::~PassengerTrain()
{

    //delete all strings
    delete depart;
    delete arrival;
    //delete all Time
    delete arrivalTime;
    delete departTime;
    //delete all ints
    delete railwayNum;
    delete passengerNum;
    //delete all bools
    delete coupe;
    delete restourant;
    delete carriagesForAnimals;

}

bool PassengerTrain::operator>(const PassengerTrain& train)
{
    return
        train.arrivalTime > arrivalTime;

}
