#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>


using namespace std;

class Date{
private:
	int godzina, minuta, sekunda, milisekunda, dzienTygodnia;
	int dzien, miesiac, rok;

public:
	Date();
	void setSystemData();

	int getDzien();
	int getMiesiac();
	int getRok();
	int getDzienTyogdnia();
	int getMilisekunda();
	int getSekunda();
	int getMinuta();
	int getGodzina();

	string changeType(int zmienna);
	string getDate();
	void setNextDay();
	void setPreviousDay();
	void changeFormat(string data);
	bool isRokPrzestepny(int rok);

	~Date();
};