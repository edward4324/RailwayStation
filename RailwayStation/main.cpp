#include <iostream>
#include <Windows.h>
#include "RStation.h"


using namespace std;

//сделать автоматическое распределение по пут€м, распределение по товарным, пассажирским и другим классам поездов
//добавить новую информацию дл€ поездов
//сделать ввод информации через файл
//сделать программу через наследование

int main() {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	RailwayStation station;

	station.getDataFromFile("DB.txt");

	cout << "¬ывод данных о поездах:" << endl;
	cout << station;

	return 0;

}