#include <iostream>
#include <Windows.h>
#include "RStation.h"


using namespace std;

//������� �������������� ������������� �� �����, ������������� �� ��������, ������������ � ������ ������� �������
//�������� ����� ���������� ��� �������
//������� ���� ���������� ����� ����
//������� ��������� ����� ������������

int main() {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	RailwayStation station;

	station.getDataFromFile("DB.txt");

	cout << "����� ������ � �������:" << endl;
	cout << station;

	return 0;

}