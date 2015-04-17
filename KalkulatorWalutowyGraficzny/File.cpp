#include "File.h"

ifstream plik;
fstream plik2,plik3;
double wartoscKursu(string nazwaWaluty, int tryb){
	
	int i = 0;
	if (tryb == 0){

		string wyraz;
		while (plik.good()){ //dopuki dane OK i nie jest EOF
			plik >> wyraz;

			if (i == 1){
				i = 0;
				plik.seekg(0, ios::beg);
				return atof(wyraz.c_str());
				
			}

			if (wyraz == nazwaWaluty)
				i = 1;
		}
		
	}
	else if (tryb == 1){
		string ello = "<kod_waluty>" + nazwaWaluty + "</kod_waluty>";
		string wyraz;
		while (plik2.good()){ //dopuki dane OK i nie jest EOF
			plik2 >> wyraz;

			if (i == 1){
				i = 0;
				string test = wyraz.substr(13, 6);
				plik2.seekg(0, ios::beg);
				return atof(test.c_str());

			}

			if (wyraz == ello)
				i = 1;

		}
	}
}

string getWaluty(){
	string ello = "<kod_waluty>";
	string ello2 = "<kurs_sredni>";
	string ello3 = "<nazwa_waluty>";
	string wyraz;

	while (plik2.good()){ //dopuki dane OK i nie jest EOF
		plik2 >> wyraz;
		if (wyraz.substr(0, 13) == ello2){
			string kod = wyraz.substr(13, 6);
			return kod;
		}
		if (wyraz.substr(0, 12) == ello){

			string kod = wyraz.substr(12, 3);
			return kod;
		}

	}
}

string getKodyWalut(){
	string ello = "<kod_waluty>";
	string wyraz;
	while (plik2.good()){ //dopuki dane OK i nie jest EOF
		plik2 >> wyraz;
		if (wyraz.substr(0, 12) == ello){
			string kod = wyraz.substr(12, 3);
			return kod;
		}
	}

}

int getIloscWalut(){
	string ello = "<pozycja>";
	string wyraz;
	int licznik = 0;
	while (plik2.good()){ //dopuki dane OK i nie jest EOF
		plik2 >> wyraz;
		if (wyraz.substr(0, 12) == ello){
			licznik++;
		}
	}
	plik2.seekg(0, ios::beg);
	return licznik;
}

void setPointerInFile(){
	plik2.seekg(0, ios::beg);
	plik.seekg(0, ios::beg);
}

void otwarciePliku(string nazwa){
	plik.open(nazwa);
	if (!plik.is_open()){
		cout << "Podany plik nie istnieje";
		exit(EXIT_FAILURE);
	}
}
void otwarciePliku2(string nazwa){
	plik2.open(nazwa);
	if (!plik2.is_open()){
		cout << "Podany plik nie istnieje";
		exit(EXIT_FAILURE);
	}
}

void otwarciePliku3(string nazwa){
	plik3.open(nazwa);
	if (!plik3.is_open()){
		cout << "Podany plik nie istnieje";
		exit(EXIT_FAILURE);
	}
}


void pobierzKurs(string adres){
	string save;
	string data = adres.substr(27, 12);
	if (plik.is_open())
		plik.close();
	
	if (adres == "http://www.nbp.pl/kursy/xml/LastA.xml")
		save = "C:\\Users\\Tomek\\C++\\KalkulatorWalutowyGraficzny\\kurs.txt";

	else
			save = "C:\\Users\\Tomek\\C++\\KalkulatorWalutowyGraficzny\\"+data+".txt";
	
	
	if (URLDownloadToFileA(NULL, adres.c_str(), save.c_str(), 0, NULL) == S_OK)
		cout << adres << " done. " << '\n';
		
	else
		cout << adres << " fail. " << '\n';
	otwarciePliku(save);
}

string pobierzKonkretnyPlik(string haslo){
	string wyraz, test;
		while (plik3.good()){ //dopuki dane OK i nie jest EOF
		plik3 >> wyraz;
		if (wyraz[0] == 'a'){
			test = wyraz.substr(5, 6);
			if (test == haslo){
				string adresURL = "http://www.nbp.pl/kursy/xml/"+wyraz+".xml";
				plik3.seekg(0, ios::beg);
				return adresURL;
				}
			}
		}
	plik3.seekg(0, ios::beg);
	return "error";
}

void openPDF(){
	ShellExecuteA(NULL, "open", "C:\\Users\\Tomek\\C++\\KalkulatorWalutowyGraficzny\\UserGuide.pdf", NULL, NULL, SW_SHOW);
}

void zamienPrzecinekNaKropke(){
	if (plik.good() && plik2.good())                       // sprawdzenie czy pliki otwarly sie prawidlowo
	{
		char c;                                             // definicja zmiennej c;

		while (plik.get(c))                                //get() wyjmuje ze strumienia 1 bajt i umieszcza go w zmiennej c, nastepnie dopoki nie wystapi
		{
			if (c == ',') c = '.';                          // koniec pliku bedzie nastepowala zamiana , na .

			plik2 << c;
		}
		
	}
	plik2.seekg(0, ios::beg);
}

void closeFiles(){
		plik3.close();
		plik2.close();
		plik.close();

}

void closeFile1(){
	plik.close();
}
string ToStdString(System::String^ source)
{
	string result;
	int len = source->Length;
	for (int i = 0; i<len; i++)
		result += (char)source[i];
	return result;
}

System::String^ ToSysString(string source)
{
	System::String^ result;
	int len = (int)source.length();
	for (int i = 0; i<len; i++)
		result += (wchar_t)source[i];
	return result;
}
