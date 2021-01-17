#include <iostream>
#include<vector>
#include<string>
#include "DBCommand.h"
#include "DBTables.h"
#include <fstream>
using namespace std;



void Initializare(vector<Tabel>& DB, char *argv, int &nrDisplay, int &nrSelect)
{
	char* numeFisier, * urmFisier;
	char separator[] = " ";
	
	string cmd;
	Command command;
	cout << "Initializare pe baza comenzilor din fisierele "<<argv << endl;
	numeFisier = strtok_s(argv, separator, &urmFisier);
	while (numeFisier != nullptr)
	{
		ifstream in(numeFisier);

		while (getline(in, cmd))
		{

			cout << endl << "Execut comanda " << cmd << endl;
			command.setCommand(cmd);
			command.Identificare_comanda(DB,nrDisplay, nrSelect);
			in >> ws;
			cout << "-------------------------------------------------------------" << endl;

		}
		in.close();
		numeFisier = strtok_s(nullptr, separator, &urmFisier);
	}
	cout << "S-a incheiat initializarea pe baza comenzilor din fisiere" << endl;
	cout << "-------------------------------------------------------------" << endl;
}
void Meniu(vector<Tabel> &DB, int& nrDisplay, int& nrSelect)
{
	
	int optiune;
	do
	{
		cout << endl<<"-------------------------------------------------------------" << endl;
		cout << "MENIU"<<endl;
		cout << "1 - Incarcati structura unui tabel dintr-un fisier dat" << endl;
		cout << "2 - Introduceti comanda de la tastatura" << endl;
		cout << "0 - EXIT" << endl;

		cin >> optiune;

		cout << "-------------------------------------------------------------" << endl;
		switch (optiune)
		{
		case 1:
		{
			Tabel temp;
			temp.IncarcaStructura("tabelProiecte.cfg");
			temp.IncarcaDate();
			DB.push_back(temp);
			break;
		}

		case 2:
		{
			string cmd;
			Command command;

			cout << "Puteti introduce una dintre comenzile urmatoare:" << endl;
			cout << "CREATE TABLE numeTabel((numeColoana1, tipColoana1, dimensiuneColoana1, valInitiala), (numeColoana2...))" << endl;
			cout << "DROP TABLE numeTabel" << endl;
			cout << "DISPLAY TABLE numeTabel" << endl;
			cout << "INSERT INTO numeTabel VALUES(valColoana1, valColoana2....)" << endl;
			cout << "UPDATE numeTabel SET coloana = valoareNoua WHERE coloanaConditie = valoareConditie" << endl;
			cout << "DELETE FROM numeTabel WHERE coloana = valoare" << endl;
			cout << "SELECT ALL FROM numeTabel" << endl;
			cout << "SELECT ALL FROM numeTabel WHERE coloana = valoare" << endl;
			cout << "SELECT(coloanaAfis1, coloanaAfis2, ....) FROM numeTabel" << endl;
			cout << "SELECT(coloanaAfis1, coloanaAfis2, ....) FROM numeTabel WHERE coloana = valoare" << endl;
			cout << "-------------------------------------------------------------" << endl;
			cin >> ws;
			getline(cin, cmd);
			cout << endl << "Execut comanda " << cmd << endl;
			command.setCommand(cmd);
			command.Identificare_comanda(DB, nrDisplay, nrSelect);
		}
		}
	} while (optiune != 0);
}

int main(int argc, char *argv)
{
	
	vector<Tabel> DB;

	int nrSelect = 0;
	int nrDisplay = 0;
	
	Initializare(DB, argv, nrDisplay, nrSelect);
	Meniu(DB, nrDisplay, nrSelect);
}

