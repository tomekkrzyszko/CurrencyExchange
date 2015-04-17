#include <iostream>
#include <string>

using namespace std;

class Currency{
private:
	string nazwaWaluty;
	float cenaSprzedazy;
	float cenaKupna;
	float kursSredni;
	float ilosc;
public:
	Currency();
	Currency(string nazwa);

	void setNazwa(string nazwa);
	void setCenaSprzedazy();
	void setCenaKupna();
	void setKursSredni(float kurs);
	void setIlosc(float ile);

	string getNazwa();
	float getCenaSprzedazy();
	float getCenaKupna();
	float getKursSredni();
	float getIlosc();
	void setCeny();

	float przeliczKurs(Currency * waluta2);

	~Currency();
};