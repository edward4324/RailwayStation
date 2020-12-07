#include "FrieghtTrain.h"


std::istream& operator>>(std::istream& in, FrieghtTrain& Ftrain)
{

    in >> *(Ftrain.depart);
    in >> *(Ftrain.arrival);
    in >> *(Ftrain.arrivalTime);
    in >> *(Ftrain.departTime);

    in >> *(Ftrain.liftingCapacity);
    in >> *(Ftrain.cargo);
    in >> *(Ftrain.typeOfWagon);

    return in;
}

FrieghtTrain::FrieghtTrain()
{

    depart = new string;
    arrival = new string;
    cargo = new string;
    typeOfWagon = new string;

    arrivalTime = new Time;
    departTime = new Time;

    num = new int;
    railwayNum = new int;

    liftingCapacity = new double;  

}

FrieghtTrain::FrieghtTrain(const FrieghtTrain& train)
{

    depart = train.depart;
    arrival = train.arrival;
    cargo = train.cargo;
    typeOfWagon = train.typeOfWagon;

    arrivalTime = train.arrivalTime;
    departTime = train.departTime;

    num = train.num;
    railwayNum = train.railwayNum;

    liftingCapacity = train.liftingCapacity;

}

FrieghtTrain::~FrieghtTrain()
{

    delete depart;
    delete arrival;
    delete cargo;
    delete typeOfWagon;

    delete arrivalTime;
    delete departTime;

    delete num;
    delete railwayNum;

    delete liftingCapacity;

}

bool FrieghtTrain::operator>(const FrieghtTrain& train)
{
    return
        train.arrivalTime > arrivalTime;
}
