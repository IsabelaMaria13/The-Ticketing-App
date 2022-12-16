#pragma once
#include<iostream>
#include<string>
using namespace std;

class Eveniment
{
private:
	string nume_eveniment;
	string ora;
	string data;
	int nr_evenimente;
public:
	//constructori
	Eveniment();
	Eveniment(string, string, string, int);
	//getteri
	string getNumeEveniment();
	string getOra();
	string getData();
	int getNrEvenimente();
	//setteri
	void setNumeEveniment(string);
	void setOra(string);
	void setData(string);
	void setNrEvenimente(int);
	//operatori
	bool operator!();
	Eveniment operator++(int);
	//metode generice
	void MultiplicaNrEvenimentelor(int);
	void SchimbaOraEvenimentului(string);
	//constructor de copiere
	Eveniment(Eveniment& event);
	//citire si afisare
	friend istream& operator>>(istream&, Eveniment&);
	friend ostream& operator<<(ostream&, Eveniment);

};