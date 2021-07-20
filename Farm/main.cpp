#include <Windows.h>
#include <sstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Farm.h"
#include "CCow.h"
#include "CSheep.h"
#include "CPig.h"
#include "CChicken.h"

using namespace std;
//using namespace sf;
// 5s trong game = 1h thuc te
// 1 don vi = 1/10 met
//RenderWindow window(VideoMode(1500, 870), "Alice's Farm");
//void playMusic(const std::string& filename) {
//	sf::Music music;
//	if (!music.openFromFile("resources/" + filename))
//		return;
//
//	// Display music informations
//	std::cout << filename << ":" << std::endl;
//	std::cout << " " << music.getDuration().asSeconds() << " seconds" << std::endl;
//	std::cout << " " << music.getSampleRate() << " samples / sec" << std::endl;
//	std::cout << " " << music.getChannelCount() << " channels" << std::endl;
//
//	// Play it
//	music.play();
//
//	// Loop while the music is playing
//	while (music.getStatus() == sf::Music::Playing)
//	{
//		// Leave some CPU time for other processes
//		sf::sleep(sf::milliseconds(100));
//
//		// Display the playing position
//		std::cout << "\rPlaying... " << music.getPlayingOffset().asSeconds() << " sec        ";
//		std::cout << std::flush;
//	}
//	std::cout << std::endl << std::endl;
//}
//
//void createMenu(Font font) {
//	Text title, option;
//	title.setFont(font);
//	title.setString("Menu");
//	title.setCharacterSize(30);
//	title.setFillColor(Color::Red);
//	title.setStyle(Text::Bold | Text::Underlined);
//	option.setPosition(0, 50);
//	option.setFont(font);
//	option.setString("[1]. Them mot con vat vao trang trai \n[2]. Danh sach cac con vat trong trang trai\n[3]. Thong tin cac con vat\n[4]. Cho tat ca cac con vat an\n[5]. Cho mot con an\n[6]. Di chuyen con vat\n[0]. Thoat");
//	option.setCharacterSize(24);
//	option.setFillColor(Color::Black);
//	window.draw(title);
//	window.draw(option);
//}
void SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Bottom = height;
	WindowSize.Right = width;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD NewSize;
	NewSize.X = width;
	NewSize.Y = height;

	SetConsoleScreenBufferSize(hStdout, NewSize);
}
int main() {
	SetWindowSize(50, 30);
	SetScreenBufferSize(50, 30);
	Farm farm;
	int chon;
	do {
		system("cls");
		cout << "======================  MENU  =====================" << endl;
		cout << "|| [1]. Them mot con vat vao trang trai \t ||" << endl << "||\t\t\t\t\t\t ||" << endl;
		cout << "|| [2]. Danh sach cac con vat trong trang trai \t ||" << endl << "||\t\t\t\t\t\t ||" << endl;
		cout << "|| [3]. Thong tin cac con vat \t\t\t ||" << endl << "||\t\t\t\t\t\t ||" << endl;
		cout << "|| [4]. Cho tat ca cac con vat an \t\t ||" << endl << "||\t\t\t\t\t\t ||" << endl;
		cout << "|| [5]. Cho mot con an \t\t\t\t ||" << endl << "||\t\t\t\t\t\t ||" << endl;
		cout << "|| [6]. Di chuyen con vat \t\t\t ||" << endl << "||\t\t\t\t\t\t ||" << endl;
		cout << "|| [0]. Thoat \t\t\t\t\t ||" << endl;
		cout << "===================================================" << endl << endl;
		cout << "Nhap gia tri: " << endl;
		cin >> chon;
		if (chon < 0 || chon > 6)
			cout << "Nhap lai..." << endl;
		switch (chon)
		{
		case 1:
			system("cls");
			farm.AddAnimal();
			break;
		case 2:
			system("cls");
			farm.PrintListAnimal();
			system("pause");
			break;
		case 3:
			system("cls");
			farm.PrintInfoAnimal();
			system("pause");
			break;
		case 4:
			system("cls");
			farm.FeedAll();
			system("pause");
			break;
		case 5:
			system("cls");
			farm.FeedOne();
			system("pause");
			break;
		case 6:
			system("cls");
			farm.Move();
			system("pause");
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (chon != 0);
	return 0;
}


