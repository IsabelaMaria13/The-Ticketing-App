#include"eveniment.h"
#include<iostream>
#include<string>
using namespace std;

Eveniment::Eveniment()
{
	nume_eveniment = "";
	ora = "";
	data = "";
	nr_evenimente = 0;
}
Eveniment::Eveniment(string nume_eveniment, string ora, string data, int nr_evenimente)
{
	this->nume_eveniment = nume_eveniment;
	this->ora = ora;
	this->data = data;
	this->nr_evenimente = nr_evenimente;
}

string Eveniment::getNumeEveniment()
{
	return nume_eveniment;
}
string Eveniment::getOra()
{
	return ora;
}
string Eveniment::getData()
{
	return data;
}
int Eveniment::getNrEvenimente()
{
	return nr_evenimente;
}

void Eveniment::setNumeEveniment(string nume_eveniment)
{
	if (nume_eveniment != "")
		this->nume_eveniment = nume_eveniment;
}
void Eveniment::setOra(string ora)
{
	if (ora != "")
		this->ora = ora;
}
void Eveniment::setData(string data)
{
	if (data != "")
		this->data = data;
}
void Eveniment::setNrEvenimente(int nr_evenimente)
{
	if (nr_evenimente != 0)
		this->nr_evenimente = nr_evenimente;
}
bool Eveniment::operator!()
{
	return ora != "";
}
Eveniment Eveniment::operator++(int i)
{
	Eveniment copie = *this;
	nr_evenimente++;
	return copie;
}
void Eveniment::MultiplicaNrEvenimentelor(int nr_evenimente)
{
	this->nr_evenimente = this->nr_evenimente * nr_evenimente;

}
void Eveniment::SchimbaOraEvenimentului(string oraNoua)
{
	ora = oraNoua;
}

Eveniment::Eveniment(Eveniment& event)
{
	nume_eveniment = event.nume_eveniment;
	ora = event.ora;
	data = event.data;
	nr_evenimente = event.nr_evenimente;
}
istream& operator>>(istream& in, Eveniment& e)
{
	cout << "Introduceti numele evenimetului: ";
	in.get();
	getline(in, e.nume_eveniment);

	cout << "Introduceti numarul evenimentlor:";
	in >> e.nr_evenimente;

	cout << "Introduceti ora evenimentului: ";
	in >> e.ora;

	cout << "Introduceti data evenimentului: ";
	in >> e.data;



	return in;

}

ostream& operator<<(ostream& out, Eveniment e)
{
	cout << "Denumirea evenimentului este:";
	out << e.nume_eveniment << endl;

	cout << "Numarul de evenimente este:";
	out << e.nr_evenimente << endl;

	cout << "Ora evenimentului este: ";
	out << e.ora << endl;

	cout << "Data evenimentului este:";
	out << e.data << endl;

	return out;
}