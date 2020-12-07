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

std::ostream& operator<<(std::ostream& out, const FrieghtTrain& Ftrain)
{

    out << "����� ��������� �� ���� �����: " << *Ftrain.railwayNum << endl;
    out << "����� �������� ������: " << *Ftrain.arrivalTime << endl;
    out << "����� ������� ������: " << *Ftrain.departTime << endl;
    out << "����� ������� �� ��������: " << endl;
    out << *Ftrain.arrival << " - " << *Ftrain.depart << endl;
    out << "����� ���������: " << *Ftrain.cargo << endl;
    out << "��� ������� ������: " << *Ftrain.typeOfWagon << endl;
    out << "���������������� ������: " << *Ftrain.liftingCapacity << endl;

    return out;
}

FrieghtTrain::FrieghtTrain()
{

    depart = new string;
    arrival = new string;
    cargo = new string;
    typeOfWagon = new string;

    arrivalTime = new Time;
    departTime = new Time;

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

    delete railwayNum;

    delete liftingCapacity;

}

bool FrieghtTrain::operator>(const FrieghtTrain& train)
{
    return
        train.arrivalTime > arrivalTime;
}
