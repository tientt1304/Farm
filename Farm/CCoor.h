#pragma once
#include <iostream>
using namespace std;
class CCoor
{
private:
	int x;
	int y;
public:
	CCoor();
	CCoor(int, int);
	CCoor(const CCoor&);
	~CCoor();
	
	void set();//rand x,y
	void set(CCoor);
	void setx(int xx);
	void sety(int yy);

	int getx();
	int gety();

	void input();
	void print();
	double khoangcach(CCoor);
};

