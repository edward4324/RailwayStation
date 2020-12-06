#include "Train.h"

Train::Train()
{

    depart = new string;
    arrival = new string;

    arrivalTime = new Time;
    departTime = new Time;

    num = new int;
    railwayNum = new int;

}

Train::Train(const Train& train)
{

    depart = train.depart;
    arrival = train.arrival;

    arrivalTime = train.arrivalTime;
    departTime = train.departTime;
    num = train.num;
    railwayNum = train.railwayNum;

}

Train::~Train()
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

}
