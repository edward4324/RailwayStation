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

PassengerTrain::PassengerTrain()
{

    depart = new string;
    arrival = new string;

    arrivalTime = new Time;
    departTime = new Time;

    num = new int;
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
    num = train.num;
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
    delete num;
    delete railwayNum;
    delete passengerNum;
    //delete all bools
    delete coupe;
    delete restourant;
    delete carriagesForAnimals;

}
