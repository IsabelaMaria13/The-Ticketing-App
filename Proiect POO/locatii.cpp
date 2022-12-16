#include "locatii.h"
#include<iostream>
#include<string>
using namespace std;

Locatii::Locatii()
{
	adresa = nullptr;
	sector = "";
	rand = 0;
	loc = 0;
	locOcupat = nullptr;
	nr_locuri = 0;

}

Locatii::Locatii(char* adresa, string sector, int rand, int loc, int nr_locuri)
{
	delete[] this->adresa;
	this->adresa = new char[strlen(adresa) + 1];
	strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
	this->sector = sector;
	this->rand = rand;
	this->loc = loc;
	this->nr_locuri = nr_locuri;
}

char* Locatii::getAdresa()
{
	return adresa;
}

void Locatii::setAdresa(char* adresa)
{
	if (adresa != nullptr)
	{
		delete[] this->adresa;
		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
	}

}
string Locatii::getSector()
{
	return sector;
}
void Locatii::setSector(string sector)
{
	if (sector != "")
		this->sector = sector;
}
int Locatii::getRand()
{
	return rand;
}

void Locatii::setRand(int rand)
{
	if (rand != 0)
		this->rand = rand;
}

int Locatii::getLoc()
{
	return loc;
}

void Locatii::setLoc(int loc)
{
	if (loc != 0)
		this->loc = loc;
}
int Locatii::getNrLocuri()
{
	return nr_locuri;
}
int* Locatii::getLocOcupat()
{
	return locOcupat;
}

void Locatii::setLocOcupat(int* locOcupat, int nr_locuri)
{
	if (nr_locuri > 0)
		this->nr_locuri = nr_locuri;

	if (locOcupat != nullptr)
		for (int i = 0; i < nr_locuri; i++)
			locOcupat[i] = 0;
}
int Locatii::SchimbaLocul(int locModificat)
{
	loc = locModificat;
	return loc;
}
//void Locatii::OcupaLoc(int loc, int nr_locuri)
//{
	//for (int i = 0;i < nr_locuri;i++)
		//if (i == loc)
			//locOcupat[i] = 0;
//}

int Locatii::operator[](int i)
{
	if (locOcupat != nullptr)
	{
		if ((i < 0) || (i > nr_locuri))
			return 0;
		else
			return locOcupat[i];
	}
}
void Locatii::SchimbaNumeleAdresei(char* adresaNoua)
{
	if (adresaNoua != nullptr)
	{
		if (adresa != nullptr)
			delete[] adresa;
		adresa = new char[strlen(adresaNoua) + 1];
		strcpy_s(adresa, strlen(adresaNoua) + 1, adresaNoua);
	}
}

int Locatii::operator()(int nr_locuri_noi)
{
	return nr_locuri + nr_locuri_noi;

	//se suplimenteaza sala cu scaune
}

Locatii::Locatii(Locatii& locatie)
{
	//if(adresa!=nullptr)
	//delete[] adresa;
	adresa = new char[strlen(locatie.adresa) + 1];
	strcpy_s(adresa, strlen(locatie.adresa) + 1, locatie.adresa);
	sector = locatie.sector;
	rand = locatie.rand;
	loc = locatie.loc;
	nr_locuri = locatie.nr_locuri;
	//for (int i = 0;i < locatie.nr_locuri;i++)
		//locOcupat[i] = locatie.locOcupat[i];
}
Locatii& Locatii:: operator=(const Locatii& locatieNoua)
{
	if (this != &locatieNoua)
	{
		if (this != nullptr)
		{
			delete[] adresa;
			delete[] locOcupat;
		}
		if (locatieNoua.adresa != nullptr)
		{
			adresa = new char[strlen(locatieNoua.adresa) + 1];
			strcpy_s(adresa, strlen(locatieNoua.adresa) + 1, locatieNoua.adresa);
		}
		sector = locatieNoua.sector;
		rand = locatieNoua.rand;
		loc = locatieNoua.loc;
		nr_locuri = locatieNoua.nr_locuri;
		if (locatieNoua.locOcupat != nullptr)
			for (int i = 0; i < locatieNoua.nr_locuri; i++)
				locOcupat[i] = locatieNoua.locOcupat[i];
	}
	return *this;
}


istream& operator>>(istream& in, Locatii& l)
{
	cout << "Introduceti adresa evenimentului: ";
	string buffer;
	in >> buffer;
	delete[] l.adresa;
	l.adresa = new char[buffer.length() + 1];
	strcpy_s(l.adresa, buffer.length() + 1, buffer.c_str());

	cout << "Introduceti sectorul biletului(fara spatii): ";
	//in.get();
	//getline(in, l.sector);
	in >> l.sector;

	cout << "Introduceti randul biletului: ";
	in >> l.rand;

	cout << "Introduceti locul biletului: ";
	in >> l.loc;

	cout << "Introduceti numarul de locuri disponibile: ";
	in >> l.nr_locuri;

	return in;

}
ostream& operator<<(ostream& out, Locatii l)
{
	cout << "Adresa evenimenului este:";
	if (l.adresa != nullptr)
		out << l.adresa << endl;
	else
		out << "Evenimentul nu exista" << endl;

	cout << "Sectorul biletului este: ";
	if (l.sector != "")
		out << l.sector << endl;
	else
		out << "Evenimentul nu exista" << endl;

	cout << "Randul biletului este:";
	if (l.rand != 0)
		out << l.rand << endl;
	else
		out << "Evenimentul nu exista" << endl;

	cout << "Locul biletului este:";
	if (l.loc != 0)
		out << l.loc << endl;
	else
		out << "Evenimentul nu exista" << endl;

	cout << "Numarul disponibil de locuri este: ";
	out << l.nr_locuri << endl;

	return out;
}

Locatii::~Locatii()
{
	if (adresa != nullptr)
		delete[] adresa;
	//adresa = nullptr;
}
