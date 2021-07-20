#include "Farm.h"
void Farm::NhapDanhSach() {
	CAnimal* dv;
	int chon;
	do {
		system("cls");
		cout << "========Them con vat=======" << endl;
		cout << "|| [1]. Con bo \t\t ||" << endl <<"|| \t\t\t ||"<< endl;
		cout << "|| [2]. Con cuu \t ||" << endl << "|| \t\t\t ||" << endl;
		cout << "|| [3]. Con heo \t ||" << endl << "|| \t\t\t ||" << endl;
		cout << "|| [4]. Con ga \t\t ||" << endl << "|| \t\t\t ||" << endl;
		cout << "|| [0].Thoat \t\t ||" << endl;
		cout << "===========================" << endl;
		cin >> chon;
		if (chon < 0 || chon > 5)
			cout << "Nhap lai!" << endl;
		switch (chon)
		{
		case 1:
			dv = new CCow();
			((CCow*)dv)->input();
			Animal.push_back(dv);
			break;
		case 2:
			dv = new CSheep();
			((CSheep*)dv)->input();
			Animal.push_back(dv);
			break;
		case 3:
			dv = new CPig();
			((CPig*)dv)->input();
			Animal.push_back(dv);
			break;
		case 4:
			dv = new CChicken();
			((CChicken*)dv)->input();
			Animal.push_back(dv);
			break;
		case 0:
			break;
		}
	} while (chon != 0);
}

void Farm::AddAnimal()
{
	cout << "Chon con vat muon them vao trang trai" << endl << endl;
	NhapDanhSach();
}

void Farm::PrintListAnimal()
{
	int iCow, iSheep, iPig, iChicken;
	iCow = iSheep = iPig = iChicken = 0;
	for (int i = 0; i < Animal.size(); i++) {
		switch (Animal[i]->LOAI)
		{
		case 1:
			if (Animal[i]->stillAlive == 1)
				iCow = iCow + 1;
			break;
		case 2:
			if (Animal[i]->stillAlive == 1)
				iSheep = iSheep + 1;
			break;
		case 3:
			if (Animal[i]->stillAlive == 1)
				iPig = iPig + 1;
			break;
		case 4:
			if (Animal[i]->stillAlive == 1)
				iChicken = iChicken + 1;
			break;
		default:
			break;
		}
	}
	cout << "==================== Alice's Farm =================" << endl;
	cout << "||Trang trai hien co: \t\t\t\t ||" << endl;
	cout << "||" << iCow << " con bo, " << iSheep << " con cuu, " << iPig << " con heo, " << iChicken << " con ga.\t ||" << endl<<"||\t\t\t\t\t\t ||" << endl;
	cout << "||Danh sach cac con vat hien co trong trang trai:||" << endl;
	for (int i = 0; i < Animal.size(); i++) {
		cout << "||";
		Animal[i]->printInfo();
		cout << "\t\t\t\t\t ||" << endl;
	}
	cout << "===================================================" << endl << endl;
}

void Farm::PrintInfoAnimal()
{
	int iCow, iSheep, iPig, iChicken;
	iCow = iSheep = iPig = iChicken = 0;
	for (int i = 0; i < Animal.size(); i++) {
		switch (Animal[i]->LOAI)
		{
		case 1:
			if (Animal[i]->stillAlive == 1)
				iCow = iCow + 1;
			break;
		case 2:
			if (Animal[i]->stillAlive == 1)
				iSheep = iSheep + 1;
			break;
		case 3:
			if (Animal[i]->stillAlive == 1)
				iPig = iPig + 1;
			break;
		case 4:
			if (Animal[i]->stillAlive == 1)
				iChicken = iChicken + 1;
			break;
		default:
			break;
		}
	}
	cout << "Trang trai hien co: " << endl;
	cout << iCow << " con bo, " << iSheep << " con cuu, " << iPig << " con heo, " << iChicken << " con ga." << endl << endl;
	cout << "Thong tin cac con vat hien co trong trang trai:" << endl << endl;
	for (int i = 0; i < Animal.size(); i++) {
		Animal[i]->printAll();
		cout << endl << "===============================" << endl << endl;
	}
}

void Farm::FeedAll()
{
	float thucan;
	cout << "Nhap luong thuc an (kg) moi con vat duoc cho: ";
	cin >> thucan;
	for (int i = 0; i < Animal.size(); i++) {
		Animal[i]->choAn(thucan);
	}
	cout << "Cho an thanh cong!" << endl << endl;
	cout << "Thong tin nong trai sau khi cho an" << endl;
	for (int i = 0; i < Animal.size(); i++) {
		Animal[i]->printAll();
		cout << endl << "===============================" << endl << endl;
	}
}

void Farm::FeedOne()
{
	string id;
	float thucan;
	cout << "Cac con vat hien co trong chuong: " << endl;
	for (int i = 0; i < Animal.size(); i++) {
		Animal[i]->printInfo();
		cout << endl;
	}
	cout << "Nhap ID con vat muon cho an:";
	cin.ignore();
	getline(cin, id);
	cout << "Nhap luong thuc an (kg) moi con vat duoc cho: ";
	cin >> thucan;
	for (int i = 0; i < Animal.size(); i++) {
		if (id == Animal[i]->getID()) {
			Animal[i]->choAn(thucan);
			cout << "Cho an thanh cong!" << endl << endl;
			cout << "Thong tin con vat sau khi cho an" << endl;
			Animal[i]->printAll();
		}
	}
}

void Farm::Move()
{
	string id;
	CCoor c;
	cout << "Cac con vat hien co trong chuong: " << endl;
	for (int i = 0; i < Animal.size(); i++) {
		Animal[i]->printInfo();
		cout << endl;
	}
	cout << "Nhap ID con vat muon di chuyen:";
	cin.ignore();
	getline(cin, id);
	for (int i = 0; i < Animal.size(); i++) {
		if (id == Animal[i]->getID()) {
			cout << "Vi tri ban dau cua con vat: ";
			(Animal[i]->getCoor()).print();
			cout << "Nhap vi tri muon den:";
			c.input();
			Animal[i]->diChuyen(c);
			Animal[i]->setCoor(c);
			cout << "Di chuyen thanh cong!" << endl << endl;
			cout << "Thong tin sau di chuyen: " << endl;
			Animal[i]->printAll();
		}
	}
}
