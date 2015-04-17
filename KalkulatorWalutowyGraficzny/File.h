#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <urlmon.h> 
#include <windows.h>
#include <shellapi.h>
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "urlmon.lib")

using namespace std;


double wartoscKursu(string nazwaWaluty, int tryb);
void otwarciePliku(string nazwa);
void otwarciePliku2(string nazwa);
void otwarciePliku3(string nazwa);

void pobierzKurs(string adres);
string pobierzKonkretnyPlik(string haslo);
void zamienPrzecinekNaKropke();
void closeFiles();
string getKodyWalut();
string getWaluty();
void setPointerInFile();
void closeFile1();
int getIloscWalut();
void openPDF();
string ToStdString(System::String^ source);
System::String^ ToSysString(string source);