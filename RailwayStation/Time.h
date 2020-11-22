#pragma once
#include <iostream>

struct Node {

	int* hour;
	int* min;

	Node();//Стандартный конструктор
	Node(int&, int&);//Конструктор с параметрами
	Node(const Node&);//Конструктор копирования
	~Node();//Деструктор

};

class Time {

private:

	Node* _time;

public:

	Time();//Стандартный конструктор
	Time(int&, int&);//Конструктор с параметрами
	Time(const Time&);//Конструктор копирования
	~Time();//Деструктор

	Time& operator=(const Time& tmp);

	//----------------------------------------------------
	//в будущем просто оставить можно один из операторов
	bool operator<(const Time& tmp);

	bool operator>(const Time& tmp);

	bool operator==(const Time& tmp);
	//----------------------------------------------------

	friend std::istream& operator>>(std::istream& in, Time& time);

	friend std::ostream& operator<<(std::ostream& out, const Time& tmp);

};
