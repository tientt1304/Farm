#include "CSheep.h"
CSheep::CSheep() {
	time_t age;
	LOAI = 2;
	setAge(time(&age));
	setWeight(3);
	setTuoiDoi(tinhTuoiDoi());
	setDoNo(100);
	coor.set();
	time(&birth);
	settimeAppear();
}
CSheep::~CSheep() {

}
void CSheep::tiengKeu() {
	if (dono <= 50 && dono > 10)
		cout << "Con cuu " << id << ": Beeee Beeee.." << endl << endl;
}
int CSheep::tinhTuoiDoi() {
	tuoidoi = rand() % (15 - 12 + 1) + 12;
	return tuoidoi;
}
void CSheep::choAn(float lgthucan) {
	time_t now;
	long count = time(&now) - timeAppear;
	int n = count / 8;
	dono = dono - n * 6;
	timeAppear = time(&now);
	tinhTuoi();
	checkChet();
	if (dono == 100) {
		weight = weight + rand() % (2 - 1 + 1) + 1;
		return;
	}	
	else {
		dono = dono + lgthucan * 20;
		if (dono >= 100) {
			dono = 100;
			weight = weight + rand() % (2 - 1 + 1) + 1;
		}
		return;
	}
}

void CSheep::diChuyen(CCoor c)
{
	CAnimal::timeSheep();
	double kc;
	kc = coor.khoangcach(c);
	dono = dono - kc * 6 / 10;
	coor.set(c);
}

//void CSheep::addDisplay(Window window)
//{
//	Texture tCow;
//	tCow.loadFromFile("image/sheep.png");
//	Sprite s(tCow);
//	while (window.isOpen()) {
//		window.display();
//	}
//}
