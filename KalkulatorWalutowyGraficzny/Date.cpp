#include "Date.h"

Date::Date(){};
	void Date::setSystemData(){
		SYSTEMTIME st;
		GetLocalTime(&st);

		godzina = st.wHour;
		minuta = st.wMinute;
		sekunda = st.wSecond;
		milisekunda = st.wMilliseconds;
		dzien = st.wDay;
		miesiac = st.wMonth;
		rok = st.wYear;
		dzienTygodnia = st.wDayOfWeek;
	}

	int Date::getDzien(){ return dzien; }
	int Date::getMiesiac(){ return miesiac; }
	int Date::getRok(){ return rok; }
	int Date::getDzienTyogdnia(){ return dzienTygodnia; }
	int Date::getMilisekunda(){ return milisekunda; }
	int Date::getSekunda(){ return sekunda; }
	int Date::getMinuta(){ return minuta; }
	int Date::getGodzina(){ return godzina; }

	string Date::changeType(int zmienna){
		ostringstream ss;
		ss << zmienna;
		string str = ss.str();
		return str;
	}

	string Date::getDate(){
		string data, day, month, year;

		if (dzien < 10)
			day = "0" + changeType(dzien);
		else
			day = changeType(dzien);
		if (miesiac < 10)
			month = "0" + changeType(miesiac);
		else
			month = changeType(miesiac);

		year = changeType(rok);
		year = year.substr(2, 2);

		data = year + month + day;
		return data;
	}

	void Date::setNextDay(){
		if (dzien == 31 && miesiac == 12){
			rok++;
		}

		if (miesiac == 1 || miesiac == 3 || miesiac == 5 || miesiac == 7 || miesiac == 8 || miesiac == 10 || miesiac == 12){
			if (dzien == 31){
				dzien = 1;
				miesiac++;
			}
			else{
				dzien++;
			}
		}

		if (miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11){
			if (dzien == 30){
				dzien = 1;
				miesiac++;
			}
			else{
				dzien++;
			}
		}

		if (isRokPrzestepny(rok)){
			if (miesiac == 2 && dzien != 29){
				dzien++;
			}
			else if (miesiac == 2 && dzien == 29)
			{
				dzien = 1;
				miesiac++;
			}
		}
		else{
			if (miesiac == 2){
				if (dzien == 28){
					dzien = 1;
					miesiac++;
				}
				else{
					dzien++;
				}
			}
		}

	}

	void Date::setPreviousDay(){
		if (dzien == 1 && miesiac == 1){
			rok--;
		}

		if (miesiac == 1 || miesiac == 5 || miesiac == 7 || miesiac == 8 || miesiac == 10 || miesiac == 12){
			if (dzien == 1){
				dzien = 30;
				miesiac--;
			}
			else{
				dzien--;
			}
		}

		if (miesiac == 4 || miesiac == 2 || miesiac == 6 || miesiac == 9 || miesiac == 11){
			if (dzien == 1){
				dzien = 31;
				miesiac--;
			}
			else{
				dzien--;
			}
		}

		if (isRokPrzestepny(rok)){
			if (miesiac == 3 && dzien != 1){
				dzien--;
			}
			else if (miesiac == 3 && dzien == 1)
			{
				dzien = 29;
				miesiac--;
			}
		}
		else{
			if (miesiac == 3){
				if (dzien == 1){
					dzien = 28;
					miesiac--;
				}
				else{
					dzien--;
				}
			}
		}

	}

	bool Date::isRokPrzestepny(int rok){
		if (rok % 100 == 0 && rok % 400 == 0)
			return true;
		else
			return false;
	}

	void Date::changeFormat(string wybranaData){
		rok = atoi(wybranaData.substr(0, 4).c_str());
		miesiac = atoi(wybranaData.substr(5, 2).c_str());
		dzien = atoi(wybranaData.substr(8, 2).c_str());
	}
	Date::~Date(){};
