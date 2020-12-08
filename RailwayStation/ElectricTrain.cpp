#include "ElectricTrain.h"

std::istream& operator>>(std::istream& in, ElectricTrain& Etrain)
{
    
    in >> *(Etrain.depart);
    in >> *(Etrain.arrival);
    in >> *(Etrain.arrivalTime);
    in >> *(Etrain.departTime);

    in >> *(Etrain.passengerNum);
    in >> *(Etrain.numOfStops);
    in >> *(Etrain.IsHigh_speed);
    
    return in;
}

std::ostream& operator<<(std::ostream& out, const ElectricTrain& Etrain)
{

    out << "����� ��������� �� ���� �����: " << *Etrain.railwayNum << endl;
    out << "����� �������� ������: " << *Etrain.arrivalTime << endl;
    out << "����� ������� ������: " << *Etrain.departTime << endl;
    out << "����� ������� �� ��������: " << endl;
    out << *Etrain.arrival << " - " << *Etrain.depart << endl;
    out << "���������� ���������: " << *Etrain.numOfStops << endl;
    out << "���������� ���������� � ������: " << *Etrain.passengerNum << endl;
    out << "����� ����������������: "
        << (*Etrain.IsHigh_speed ? "��" : "���") << endl;
   

    return out;
}

ElectricTrain::ElectricTrain()
{

    depart = new string;
    arrival = new string;

    arrivalTime = new Time;
    departTime = new Time;

    railwayNum = new int;
    passengerNum = new int;
    numOfStops = new int;

    IsHigh_speed = new bool;

}

ElectricTrain::ElectricTrain(const ElectricTrain& train)
{

   depart = new string(*train.depart);
   arrival = new string(*train.arrival);

    arrivalTime = new Time(*train.arrivalTime);
    departTime = new Time(*train.departTime);

   railwayNum = new int(*train.railwayNum);
   passengerNum = new int(*train.passengerNum);
   numOfStops = new int(*train.numOfStops);

    IsHigh_speed = new bool(*train.IsHigh_speed);

}

ElectricTrain::~ElectricTrain()
{

   delete depart;
   delete arrival;

   delete arrivalTime;
   delete departTime;

   delete railwayNum;
   delete passengerNum;
   delete numOfStops;

   delete IsHigh_speed;

}

bool ElectricTrain::operator>(const ElectricTrain& train)
{
    return
        train.arrivalTime > arrivalTime;
}

ElectricTrain& ElectricTrain::operator=(const ElectricTrain& obj)
{

    *depart = *obj.depart;
    *arrival = *obj.arrival;

    *arrivalTime = *obj.arrivalTime;
    *departTime = *obj.departTime;

    *railwayNum = *obj.railwayNum;
    *passengerNum = *obj.passengerNum;

    *numOfStops = *obj.numOfStops;
    *IsHigh_speed = *obj.IsHigh_speed;

    return *this;

}
