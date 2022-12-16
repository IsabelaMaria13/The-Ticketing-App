#pragma once
#include<iostream>
#include<string>
using namespace std;

class Locatii
{
private:
	char* adresa; //vector de caractere alocat dinamic
	string sector;
	int rand;
	int loc;
	int* locOcupat; //vector de numere alocat dinamic
	int nr_locuri;

public:
	//constructori
	Locatii();
	Locatii(char*, string, int, int, int);
	//getteri  
	char* getAdresa();
	string getSector();
	int getRand();
	int getLoc();
	int getNrLocuri();
	int* getLocOcupat();
	//setteri
	void setAdresa(char*);
	void setSector(string);
	void setRand(int);
	void setLoc(int);
	void setLocOcupat(int*, int);
	//metode generice
	int SchimbaLocul(int);
	void SchimbaNumeleAdresei(char*);
	//int Verifica_disponibilitatea_locurilor(int*);
//operatori
	int operator[](int);
	int operator()(int);
	//regula celor 3
	Locatii(Locatii& locatie);
	Locatii& operator=(const Locatii& locatieNoua);
	~Locatii();
	//afisare si citire
	friend ostream& operator<<(ostream& out, Locatii l);
	friend istream& operator>>(istream& in, Locatii& l);

};