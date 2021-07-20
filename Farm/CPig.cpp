#include "CPig.h"
CPig::CPig() {
	time_t age;
	LOAI = 3;
	setAge(time(&age));
	setWeight(2);
	setTuoiDoi(tinhTuoiDoi());
	setDoNo(100);
	coor.set();
	time(&birth);
	settimeAppear();
}
CPig::~CPig() {

}
void CPig::tiengKeu() {
	if (dono <= 50 && dono > 10)
		cout << "Con heo " << id << ": Ut ut ut.." << endl;
}
int CPig::tinhTuoiDoi() {
	tuoidoi = rand() % (10 - 5 + 1) + 5;
	return tuoidoi;
}
void CPig::choAn(float lgthucan) {
	time_t now;
	long count = time(&now) - timeAppear;
	int n = count / 8;
	dono = dono - n * 7;
	timeAppear = time(&now);
	tinhTuoi();
	checkChet();
	if (dono == 100) {
		weight = weight + rand() % (2 - 1 + 1) + 1;
		return;
	}
	else {
		dono = dono + lgthucan * 30;
		if (dono >= 100) {
			dono = 100;
			weight = weight + rand() % (2 - 1 + 1) + 1;
		}
		return;
	}
}

void CPig::diChuyen(CCoor c)
{
	CAnimal::timePig();
	double kc;
	kc = coor.khoangcach(c);
	dono = dono - kc * 7 / 10;
	coor.set(c);
}

//void CPig::addDisplay(Window window)
//{
//	Texture tCow;
//	tCow.loadFromFile("image/pig.png");
//	Sprite s(tCow);
//	while (window.isOpen()) {
//		window.display();
//	}
//}
