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

    depart = new string(*train.depart);
    arrival = new string(*train.arrival);
    cargo = new string(*train.cargo);
    typeOfWagon = new string(*train.typeOfWagon);

    arrivalTime = new Time(*train.arrivalTime);
    departTime = new Time(*train.departTime);

    railwayNum = new int(*train.railwayNum);

    liftingCapacity = new double(*train.liftingCapacity);

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

FrieghtTrain& FrieghtTrain::operator=(const FrieghtTrain& obj)
{
    *depart = *obj.depart;
    *arrival = *obj.arrival;

    *arrivalTime = *obj.arrivalTime;
    *departTime = *obj.departTime;

    *railwayNum = *obj.railwayNum;

    *cargo = *obj.cargo;
    *typeOfWagon = *obj.typeOfWagon;
    *liftingCapacity = *obj.liftingCapacity;

    return *this;

}
