#include "CCow.h"
CCow::CCow() {
	time_t age;
	LOAI = 1;
	setAge(time(&age));
	setWeight(30);
	setTuoiDoi(tinhTuoiDoi());
	setDoNo(100);
	coor.set();
	time(&birth);
	settimeAppear();
}
CCow::~CCow() {
	
}

void CCow::tiengKeu() {
	if (dono <= 50 && dono > 10)
		cout << "Con bo " << id << ": Um bo.o..o.." << endl << endl;
}
int CCow::tinhTuoiDoi() {
	tuoidoi = rand() % (20 - 18 + 1) + 18;
	return tuoidoi;
}
void CCow::choAn(float lgthucan) {
	time_t now;
	long count = time(&now) - timeAppear;
	int n = count / 8;
	dono = dono - n * 5;
	timeAppear = time(&now);
	tinhTuoi();
	checkChet();
	if (dono == 100) {
		weight = weight + rand() % (3 - 1 + 1) + 1;
		return;
	}	
	else {
		dono = dono + lgthucan * 20;
		if (dono >= 100) {
			dono = 100;
			weight = weight + rand() % (3 - 1 + 1) + 1;
		}	
		return;
	}
}

void CCow::diChuyen(CCoor c)
{
	CAnimal::timeCow();
	double kc;
	kc = coor.khoangcach(c);
	dono = dono - kc * 5 / 10;
	coor.set(c);
}



