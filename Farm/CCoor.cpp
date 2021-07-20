#include "CCoor.h"

CCoor::CCoor()
{
	x = 0;
	y = 0;
}

CCoor::CCoor(int xx, int yy)
{
	x = xx;
	y = yy;
}

CCoor::CCoor(const CCoor& c)
{
	x = c.x;
	y = c.y;
}

CCoor::~CCoor()
{
}

void CCoor::set()
{
	x = rand() % (100 - 1 + 1) + 1;
	y = rand() % (100 - 1 + 1) + 1;
}

void CCoor::set(CCoor)
{
}

void CCoor::setx(int xx)
{
	x = xx;
}

void CCoor::sety(int yy)
{
	y = yy;
}

int CCoor::getx()
{
	return x;
}

int CCoor::gety()
{
	return y;
}

void CCoor::input()
{
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << endl;
}

void CCoor::print()
{
	cout << "(" << x << ";" << y << ")" << endl;
}

double CCoor::khoangcach(CCoor c)
{
	return (double)sqrt(pow(x - c.x, 2) + pow(y - c.y, 2));
}
