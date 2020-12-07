#include "ElectricTrain.h"

std::istream& operator>>(std::istream& in, ElectricTrain& Etrain)
{

    in >> *(Etrain.passengerNum);
    in >> *(Etrain.numOfStops);
    in >> *(Etrain.IsHigh_speed);

    in >> *(Etrain.depart);
    in >> *(Etrain.arrival);
    in >> *(Etrain.arrivalTime);
    in >> *(Etrain.departTime);

    return in;
}

std::ostream& operator<<(std::ostream& out, const ElectricTrain& Etrain)
{

    out << "Поезд прибывает на путь номер: " << *Etrain.railwayNum << endl;
    out << "Время прибытия поезда: " << *Etrain.arrivalTime << endl;
    out << "Время отбытия поезда: " << *Etrain.departTime << endl;
    out << "Поезд следует по маршруту: " << endl;
    out << *Etrain.arrival << " - " << *Etrain.depart << endl;
    out << "Количество остановок: " << *Etrain.numOfStops << endl;
    out << "Количество пассажиров в поезде: " << *Etrain.passengerNum << endl;
    out << "Поезд высокоскоростной: "
        << (*Etrain.IsHigh_speed ? "да" : "нет") << endl;
   

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

    depart = train.depart;
    arrival = train.arrival;

    arrivalTime = train.arrivalTime;
    departTime = train.departTime;

    railwayNum = train.railwayNum;
    passengerNum = train.passengerNum;
    numOfStops = train.numOfStops;

    IsHigh_speed = train.IsHigh_speed;

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
