#include "bilet.h"
#include<iostream>
#include<string>
using namespace std;

int Bilet::nr_bilete_emise = 0;

Bilet::Bilet() :nr_maxim_bilete(0)
{
	id = 0;
	nume_persoana = "";
	tip_bilet = "";
	pret = 0;
	nr_bilete = 0;
}
Bilet::Bilet(int id, string nume_persoana, string tip_bilet, float pret, int nr_bilete) :nr_maxim_bilete(nr_maxim_bilete)
{
	this->id = id;
	this->nume_persoana = nume_persoana;
	this->tip_bilet = tip_bilet;
	this->pret = pret;
	this->nr_bilete = nr_bilete;

}

int Bilet::getId()
{
	return id;
}
string Bilet::getNumePersoana()
{
	return nume_persoana;
}
string Bilet::getTipBilet()
{
	return tip_bilet;
}
int Bilet::getPret()
{
	return pret;
}
int Bilet::getNrBilete()
{
	return nr_bilete;
}
void Bilet::setId(int id)
{
	if (id > 0)
		this->id = id;
}
void Bilet::setNumePersoana(string nume_persoana)
{
	if (nume_persoana != "")
		this->nume_persoana = nume_persoana;
}
void Bilet::setTipBilet(string tip_bilet)
{
	if (tip_bilet != "")
		this->tip_bilet = tip_bilet;
}
void Bilet::setPret(float pret)
{
	if (pret != 0)
		this->pret = pret;
}
void Bilet::setNrBilete(int nr_bilete)
{
	if ((nr_bilete != 0) && (nr_bilete < nr_maxim_bilete))
		this->nr_bilete = nr_bilete;
}

static void EmitereBilete(int x)
{
	Bilet::nr_bilete_emise = Bilet::nr_bilete_emise + x;
}
Bilet Bilet::operator--(int i)
{
	Bilet copie = *this;
	pret--;
	return copie;
}
Bilet Bilet::operator-(float mai_ieftin)
{
	this->pret = this->pret - mai_ieftin;
	return *this;
}
int Bilet::afla_valoarea_de_plata(float pret, int nr_bilete)
{
	pret = pret * nr_bilete;
	return pret;
}

Bilet Bilet::Discount(int procent)
{
	if (procent > 0)
		if (procent < 100)
			this->pret = this->pret - this->pret * (procent / 100.0f);
	return *this;

}

Bilet::Bilet(Bilet& bilete) :nr_maxim_bilete(bilete.nr_maxim_bilete)
{
	this->id = bilete.id;
	this->nume_persoana = bilete.nume_persoana;
	this->tip_bilet = bilete.tip_bilet;
	this->pret = bilete.pret;
	this->nr_bilete = bilete.nr_bilete;

}

Bilet& Bilet::operator=(const Bilet& biletNou)
{
	this->id = biletNou.id;
	this->nume_persoana = biletNou.nume_persoana;
	this->tip_bilet = biletNou.tip_bilet;
	this->pret = biletNou.pret;
	this->nr_bilete = biletNou.nr_bilete;

	return *this;
}
istream& operator>>(istream& in, Bilet& b)
{
	//cout << "Introduceti numarul maxim de bilete la acest eveniment:";
	//in >> b.nr_maxim_bilete;

	cout << "Introduceti id bilet: ";
	in >> b.id;

	cout << "Introduceti numele participantului: ";
	in.get();
	getline(in, b.nume_persoana);

	cout << "Introduceti tipul biletului: ";
	in >> b.tip_bilet;

	cout << "Introduceti pretul biletului: ";
	in >> b.pret;

	cout << "Introduceti numarul de bilete: ";
	in >> b.nr_bilete;

	return in;

}

ostream& operator<<(ostream& out, Bilet b)
{
	cout << "Id bilet este:";
	out << b.id << endl;

	cout << "Numele participantului este:";
	out << b.nume_persoana << endl;

	cout << "Tipul biletului este: ";
	out << b.tip_bilet << endl;

	cout << "Pretul biletului este:";
	out << b.pret << endl;

	cout << "Numarul de bilete este: ";
	out << b.nr_bilete << endl;


	return out;
}