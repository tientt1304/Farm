#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "CCoor.h"

using namespace std;

class CAnimal
{
protected:
	string id;
	int age;
	double weight;
	int tuoidoi;
	float dono;
	CCoor coor;
	time_t birth;//thoi gian sinh ra
	time_t timeAppear;//reset sau moi lan cho an/ di chuyen/xuat ds
	
public:
	int stillAlive;
	int LOAI;
	CAnimal();
	~CAnimal();

	void setID(string);
	void setAge(int);
	void setWeight(float);
	void setTuoiDoi(int);
	void setDoNo(float);
	void setBirth(time_t t);
	void setCoor(CCoor);
	void settimeAppear();

	string getID();
	int getAge();
	double getWeight();
	int getTuoiDoi();
	float getDoNo();
	int getBirth();
	CCoor getCoor();
	time_t gettimeAppear();

	virtual void tiengKeu() = 0;
	virtual int tinhTuoiDoi() = 0;
	virtual void choAn(float) = 0;
	virtual void checkChet();
	virtual void tinhTuoi();
	virtual void diChuyen(CCoor) = 0;

	void timeCow();
	void timeSheep();
	void timePig();
	void timeChicken();

	virtual void input();
	virtual void printAll();
	virtual void printInfo();
};

