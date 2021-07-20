#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include "CAnimal.h"
#include "CCow.h"
#include "CSheep.h"
#include "CPig.h"
#include "CChicken.h"

using namespace std;


class Farm
{
private:
	vector<CAnimal*> Animal;
public:
	void NhapDanhSach();
	void AddAnimal();
	void PrintListAnimal();
	void PrintInfoAnimal();
	void FeedAll();
	void FeedOne();
	void Move();
};