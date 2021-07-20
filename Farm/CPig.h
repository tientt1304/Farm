#pragma once
#include "CAnimal.h"
class CPig : public CAnimal
{
public:
	CPig();
	~CPig();
	void tiengKeu();
	int tinhTuoiDoi();
	void choAn(float);
	void diChuyen(CCoor);
	//void addDisplay(Window);
};

