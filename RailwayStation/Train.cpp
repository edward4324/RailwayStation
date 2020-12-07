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

void Train::setRWnum(int rwnum)
{

   *railwayNum = rwnum;

}

int Train::getRWnum()
{
    if (railwayNum != nullptr)
        return *railwayNum;
    else
        return 0;

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
