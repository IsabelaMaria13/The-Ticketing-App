#pragma once
#include<iostream>
#include<string>
using namespace std;

class Bilet
{
private:
	const long nr_maxim_bilete; //constant
	int id;
	string nume_persoana;
	string tip_bilet;
	float pret;
	int nr_bilete;

public:
	static int nr_bilete_emise; //static
	//constructori:
	Bilet();
	Bilet(int, string, string, float, int);
	//getteri
	int getId();
	string getNumePersoana();
	string getTipBilet();
	int getPret();
	int getNrBilete();
	//setteri
	void setId(int);
	void setNumePersoana(string);
	void setTipBilet(string);
	void setPret(float);
	void setNrBilete(int);

	//operatori
	Bilet operator--(int);
	Bilet operator-(float);
	Bilet& operator=(const Bilet&);
	//metode generice
	int afla_valoarea_de_plata(float, int);
	Bilet Discount(int);
	//constructor de copiere
	Bilet(Bilet& bilete);
	//metoda statica
	static void EmitereBilete(int x);
	//citire si afisare
	friend ostream& operator<<(ostream&, Bilet);
	friend istream& operator>>(istream&, Bilet&);
};
