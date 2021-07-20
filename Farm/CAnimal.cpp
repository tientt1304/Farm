#include "CAnimal.h"
CAnimal::CAnimal() {
	LOAI = 0;
	stillAlive = 1;
}
CAnimal::~CAnimal() {
	
}

void CAnimal::setID(string id) {
	this->id = id;
}
void CAnimal::setAge(int age){
	if (age >= 0 && age <= tuoidoi)
		this->age = age;
}
void CAnimal::setWeight(float w) {
	if (w > 0)
		this->weight = w;
}
void CAnimal::setTuoiDoi(int tuoidoi) {
	if (tuoidoi > 0)
		this->tuoidoi = tuoidoi;
}
void CAnimal::setDoNo(float dono) {
	if(dono>=0 && dono<=100)
		this->dono = dono;
}
void CAnimal::setBirth(time_t t) {
	this->birth = time(&t);
}

void CAnimal::setCoor(CCoor c)
{
	coor.setx(c.getx());
	coor.sety(c.gety());
}

string CAnimal::getID() {
	return id;
}
int CAnimal::getAge() {
	return age;
}
double CAnimal::getWeight() {
	return weight;
}
void CAnimal::settimeAppear()
{
	time(&timeAppear);
}

int CAnimal::getTuoiDoi() {
	return tuoidoi;
}
float CAnimal::getDoNo() {
	return dono;
}
int CAnimal::getBirth() {
	return birth;
}

CCoor CAnimal::getCoor()
{
	return coor;
}

void CAnimal::checkChet() {
	if (dono <= 10) {
		cout << "Con vat co id " << id << " da chet doi" << endl;
		stillAlive = 0;
	}
	if (age == tuoidoi) {
		cout << "Con vat co id " << id << " da gia qua ma chet" << endl;
		stillAlive = 0;
	}
}

void CAnimal::tinhTuoi() {
	time_t now;
	age = time(&now) - this->birth;
	age = (int)age / 8760;
}
time_t CAnimal::gettimeAppear()
{
	return timeAppear;
}
void CAnimal::input() {
	ostringstream x;
	int i;
	cout << "Nhap ID: ";
	cin >> i;
	
	switch (this->LOAI)
	{
	case 1:
		x << "C" << i;
		id = x.str();
		break;
	case 2:
		x << "S" << i;
		id = x.str();
		break;
	case 3:
		x << "P" << i;
		id = x.str();
		break;
	case 4:
		x << "CH" << i;
		id = x.str();
		break;
	default:
		break;
	}
}

void CAnimal::printInfo()
{
	if (stillAlive == 1)
		cout << "ID: " << id;
}

void CAnimal::timeCow()
{
	time_t now;
	long count = time(&now) - timeAppear;
	int n = count / 8;
	dono = dono - n * 5;
	timeAppear = time(&now);
	tinhTuoi();
	checkChet();
	tiengKeu();
}

void CAnimal::timeSheep()
{
	time_t now;
	long count = time(&now) - timeAppear;
	int n = count / 8;
	dono = dono - n * 6;
	timeAppear = time(&now);
	tinhTuoi();
	checkChet();
	tiengKeu();
}

void CAnimal::timePig()
{
	time_t now;
	long count = time(&now) - timeAppear;
	int n = count / 8;
	dono = dono - n * 7;
	timeAppear = time(&now);
	tinhTuoi();
	checkChet();
	tiengKeu();
}

void CAnimal::timeChicken()
{
	time_t now;
	long count = time(&now) - timeAppear;
	int n = count / 12;
	dono = dono - n * 10;
	timeAppear = time(&now);
	tinhTuoi();
	checkChet();
	tiengKeu();
}

void CAnimal::printAll() {
	if (stillAlive == 1) {
		switch (this->LOAI)
		{
		case 1:
			this->timeCow();
			break;
		case 2:
			this->timeSheep();
			break;
		case 3:
			this->timePig();
			break;
		case 4:
			this->timeChicken();
			break;
		default:
			break;
		}
	}
	if (stillAlive == 1) {
		switch (this->LOAI)
		{
		case 1:
			cout << "Con bo: " << endl;
			break;
		case 2:
			cout << "Con cuu: " << endl;
			break;
		case 3:
			cout << "Con heo: " << endl;
			break;
		case 4:
			cout << "Con ga: " << endl;
			break;
		default:
			break;
		}
		cout << "ID: " << id << endl;
		cout << "Tuoi: " << (int)age << endl;
		cout << "Can nang: " << weight << "kg" << endl;
		cout << "Do no: " << dono << "%" << endl;
		cout << "Tuoi doi: " << (int)tuoidoi << " nam" << endl;
		cout << "Vi tri: ";
		this->coor.print();
	}
}