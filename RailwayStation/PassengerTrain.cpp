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

std::ostream& operator<<(std::ostream& out, const PassengerTrain& Ptrain)
{

    out << "Поезд прибывает на путь номер: " << *Ptrain.railwayNum << endl;
    out << "Время прибытия поезда: " << *Ptrain.arrivalTime << endl;
    out << "Время отбытия поезда: " << *Ptrain.departTime << endl;
    out << "Поезд следует по маршруту: " << endl;
    out << *Ptrain.arrival << " - " << *Ptrain.depart << endl;
    out << "Количество пассажиров в поезде: " << *Ptrain.passengerNum << endl;
    out << "Перевозить в животных в вагонах поезда: " 
         << (*Ptrain.carriagesForAnimals? "разрешенно" : "запрещено") << endl;
    out << "Вагон - ресторан в поезде "
         << (*Ptrain.restourant? "есть" : "отсутствует") << endl;
    out << "В поезде купейные вагоны " 
         << (*Ptrain.coupe? "есть" : "отсутствуют") << endl;

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

    depart = train.depart;
    arrival = train.arrival;

    arrivalTime = train.arrivalTime;
    departTime = train.departTime;
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
