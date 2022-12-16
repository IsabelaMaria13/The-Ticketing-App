#include"eveniment.h"
#include"locatii.h"
#include"bilet.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	//Creare obiecte
	Bilet ConcertRomexpo(1456, "Carstian Diana", "VIP", 100, 1);
	Eveniment Concert("Concert The Weekend", "22.00", "18.12.2022", 3);
	Locatii Romexpo((char*)"Bulevardul Marasti 65", "CategoriaA", 3, 104, 100);
	cout << ConcertRomexpo << endl << Concert << endl << Romexpo << endl;

	//Verificare operatori Eveniment
	bool OraValida = !Concert;
	cout << "Daca este =1 inseamna ca ora este valida:     ";
	cout << OraValida << endl;
	Concert++;
	cout << "Numarul de evenimente s-a modificat la: " << endl;
	cout << Concert << endl;

	//Verificare metode Eveniment
	Concert.MultiplicaNrEvenimentelor(10);
	cout << "S-a modificat numarul de evenimente. Biletul este acum:  " << endl;
	cout << Concert << endl;
	Concert.SchimbaOraEvenimentului("23.00");
	cout << "Atentie! S-a modificat ora evenimentului. Biletul este acum: " << endl;
	cout << Concert << endl;

	//Verificare operatori Locatii
	int x = Romexpo[2];
	cout << x << endl;
	int LocatieModificata;
	LocatieModificata = Romexpo(200);
	cout << "S-a modificat numarul de locuri. Noul loc este:  ";
	cout << LocatieModificata << endl;

	//Verificare metode Locatii
	Romexpo.SchimbaLocul(55);
	cout << Romexpo << endl;
	Romexpo.SchimbaNumeleAdresei((char*)"Bulevardul Marasesti 65-67");
	cout << Romexpo << endl;

	//Verificare operatori Bilete
	ConcertRomexpo--;
	cout << "A scazut pretul biletului cu 1. Noul bilet este:" << endl;
	cout << ConcertRomexpo << endl;
	ConcertRomexpo - 3;
	cout << "A scazut pretul biletului cu 3. Noul bilet este:" << endl;
	cout << ConcertRomexpo << endl;

	//Verificare metode Bilet
	cout << ConcertRomexpo.afla_valoarea_de_plata(100, 5) << endl;
	ConcertRomexpo.Discount(10);
	cout << ConcertRomexpo;

	//Verificare metoda statica Bilet
		//ConcertRomexpo.EmitereBilete(100);
}