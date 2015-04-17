#include "Currency.h"


	Currency::Currency(){}

	Currency::Currency(string nazwa){
		nazwaWaluty = nazwa;
	}

	void Currency::setNazwa(string nazwa){
		nazwaWaluty = nazwa;
	}

	void Currency::setCenaSprzedazy(){
		cenaSprzedazy = (getKursSredni()* 0.7);
	}

	void Currency::setCenaKupna(){
		cenaKupna = (getKursSredni() * 1.2);
	}

	void Currency::setKursSredni(float kurs){
		kursSredni = kurs;
	}
	void Currency::setIlosc(float ile){
		ilosc = ile;
	}

	string Currency::getNazwa(){ return nazwaWaluty; }

	float Currency::getCenaSprzedazy(){ return cenaSprzedazy; }

	float Currency::getCenaKupna(){ return cenaKupna; }

	float Currency::getKursSredni(){ return kursSredni; }

	float Currency::getIlosc(){ return ilosc; }

	void Currency::setCeny(){
		setCenaSprzedazy();
		setCenaKupna();
	}

	float Currency::przeliczKurs(Currency * waluta2){
		float currency1 = getCenaSprzedazy() *getIlosc();
		float currency2 = currency1 / waluta2->getCenaKupna();
		return currency2;
	}

	Currency::~Currency(){};
