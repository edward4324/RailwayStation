#pragma once
#include <iostream>

struct Node {

	int* hour;
	int* min;

	Node();//����������� �����������
	Node(int&, int&);//����������� � �����������
	Node(const Node&);//����������� �����������
	~Node();//����������

};

class Time {

private:

	Node* _time;

public:

	Time();//����������� �����������
	Time(int&, int&);//����������� � �����������
	Time(const Time&);//����������� �����������
	~Time();//����������

	Time& operator=(const Time& tmp);

	//----------------------------------------------------
	//� ������� ������ �������� ����� ���� �� ����������
	bool operator<(const Time& tmp);

	bool operator>(const Time& tmp);

	bool operator==(const Time& tmp);
	//----------------------------------------------------

	friend std::istream& operator>>(std::istream& in, Time& time);

	friend std::ostream& operator<<(std::ostream& out, const Time& tmp);

};
