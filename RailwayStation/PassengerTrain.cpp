#include "PassengerTrain.h"

std::istream& operator>>(std::istream& in, PassengerTrain& Ptrain)
{
    in >> *(Ptrain.depart);
    in >> *(Ptrain.arrival);
    in >> *(Ptrain.arrivalTime);
    in >> *(Ptrain.departTime);

    in >> *(Ptrain.passengerNum);
    in >> *(Ptrain.coupe);
    in >> *(Ptrain.restourant);
    in >> *(Ptrain.carriagesForAnimals);
     
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

    depart = new string(*train.depart);
    arrival = new string(*train.arrival);

    arrivalTime = new Time(*train.arrivalTime);
    departTime = new Time(*train.departTime);
    railwayNum = new int(*train.railwayNum);

    passengerNum = new int(*train.passengerNum);

    coupe = new bool(*train.coupe);
    restourant = new bool(*train.restourant);
    carriagesForAnimals = new bool(*train.carriagesForAnimals);

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

PassengerTrain& PassengerTrain::operator=(const PassengerTrain& obj)
{

    *depart = *obj.depart;
    *arrival = *obj.arrival;

    *arrivalTime = *obj.arrivalTime;
    *departTime = *obj.departTime;

    *railwayNum = *obj.railwayNum;
    *passengerNum = *obj.passengerNum;

    *coupe = *obj.coupe;
    *restourant = *obj.restourant;
    *carriagesForAnimals = *obj.carriagesForAnimals;

    return *this;
}
