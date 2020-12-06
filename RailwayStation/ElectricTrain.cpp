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

ElectricTrain::ElectricTrain()
{

    depart = new string;
    arrival = new string;

    arrivalTime = new Time;
    departTime = new Time;

    num = new int;
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

    num = train.num;
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

   delete num;
   delete railwayNum;
   delete passengerNum;
   delete numOfStops;

   delete IsHigh_speed;

}
