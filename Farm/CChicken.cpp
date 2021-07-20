#include "CChicken.h"
CChicken::CChicken() {
	time_t age;
	LOAI = 4;
	setAge(time(&age));
	setWeight(0.05);
	setTuoiDoi(tinhTuoiDoi());
	setDoNo(100);
	coor.set();
	time(&birth);
	settimeAppear();
}
CChicken::~CChicken() {

}
void CChicken::tiengKeu() {
	if (dono <= 50 && dono > 10)
		cout << "Con ga " << id << ": Cuc tac cuc tac.." << endl << endl;
}
int CChicken::tinhTuoiDoi() {
	tuoidoi = rand() % (8 - 7 + 1) + 7; 
	return tuoidoi;
}
void CChicken::choAn(float lgthucan) {
	time_t now;
	long count = time(&now) - timeAppear;
	int n = count / 12;
	dono = dono - n * 10;
	timeAppear = time(&now);
	tinhTuoi();
	checkChet();
	if (dono == 100) {
		weight = weight + 0.01 + static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (0.2 - 0.01));
		return;
	}
	else {
		dono = dono + lgthucan * 500;
		if (dono >= 100) {
			dono = 100;
			weight = weight + 0.01 + static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (0.2 - 0.01));
		}
		return;
	}
}

void CChicken::diChuyen(CCoor c)
{
	CAnimal::timeChicken();
	double kc;
	kc = coor.khoangcach(c);
	dono = dono - kc * 10 / 10;
	coor.set(c);
}

//void CChicken::addDisplay(Window window)
//{
//	Texture tCow;
//	tCow.loadFromFile("image/hen.png");
//	Sprite s(tCow);
//	while (window.isOpen()) {
//		window.display();
//	}
//}
