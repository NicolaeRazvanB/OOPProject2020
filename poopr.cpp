#include <iostream>
#include<vector>
#include<string>
#include "DBCommand.h"
#include "DBTables.h"
#include <fstream>
using namespace std;
int main()
{
	
	char argv[100] = "ComenziFlux2.txt ComenziFlux1.txt" ;
	char* numeFisier, * urmFisier;
	 char separator[] = " ";
	 vector<Tabel> DB;
	 string cmd;
	 Command command;

	numeFisier = strtok_s(argv,separator,&urmFisier);
	while (numeFisier!=nullptr)
	{
		ifstream in(numeFisier);
		
		while(getline(in, cmd))
		{
			
				cout << endl<<"Execut comanda " << cmd << endl;
				command.setCommand(cmd);
				command.Identificare_comanda(DB);
				in >> ws;
				
			
		} 
		in.close();
		numeFisier = strtok_s(nullptr,separator,&urmFisier);
	}
	/*fstream fisier("DATE.bin", ios::binary | ios::in);
	fisier.seekg(-4, ios::end);
	int element = 0;
	fisier.read((char*)&element, sizeof(int));
	cout << endl << "element = " << element;
	fisier.close();*/








}

