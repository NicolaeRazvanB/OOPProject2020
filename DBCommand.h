#pragma once
#include <iostream>
#include <fstream>
#include<vector>
#include<string>
#include "DBTables.h"
#include <algorithm>
using namespace std;
class Command
{
private:
	string commandText;

public:
	void setCommand(string s)
	{
		commandText = s;
	}
	void IdentificareDisplayTable(vector<Tabel>& DB, int &nrDisplay)
	{
		string command = commandText;
		char * aux;
		int k = 0;
		for (int i = 0; i < DB.size(); i++)
			if (command.substr(14, command.length()) == DB[i].GetNume())
			{
				cout << DB[i];
				nrDisplay++;
				ofstream out("DisplayFile_" + to_string(nrDisplay)+".txt");
				out << DB[i];
				out.close();
				k = 1;

			}
		if (k == 0) cout << "Nu exista tabele cu acest nume" << endl;
	}
	void IdentificareDropTable(vector<Tabel>& DB)
	{
		string command = commandText;
		string numeTabelEliminat;
		string numeFisier;
		numeTabelEliminat = command.substr(11, command.length());
		for (int i = 0; i < DB.size(); i++)
			if (numeTabelEliminat == DB[i].GetNume())
			{
				DB.erase(DB.begin() + i);
				cout << "Tabelul " << numeTabelEliminat << " a fost sters cu succes." << endl;
				numeFisier = numeTabelEliminat + ".cfg";
				remove(numeFisier.c_str());
				numeFisier = numeTabelEliminat + ".dat";
				remove(numeFisier.c_str());
				return;
			}
		cout << "Nu exista tabele cu acest nume" << endl;
	}
	void IdentificareCreateTable(vector<Tabel>& DB)
	{
		string command = commandText;
		struct col
		{
			string name;
			int dimensiune;
			int bazaint;
			float bazafloat;
			string bazastring;
			string tip;
		};
		col alfa;
		alfa.name = "";
		alfa.dimensiune = 0;
		alfa.bazaint = 0;
		alfa.bazafloat = 0;
		alfa.tip = "";
		alfa.bazastring = "";


		string nume = "";
		int si = 0;
		int sf = 0;
		int ss = 0;
		vector<Coloana_int> vi;
		vector<Coloana_float>vf;
		vector<Coloana_string>vs;
		vector<string> vsAux;
		vector<pair<string, int>> ordineColoane;
		pair<string, int> valOrdineColoane;

		command.erase(0, 13);

		for (int i = 0; i < command.length(); i++)
		{
			if (command[i] == '(')
			{
				nume = (command.substr(0, i - 1));
				command.erase(0, i - 1);
				i = command.length() + 1;
			}
		}

		command.erase(0, 2);
		for (int i = 0; i < DB.size(); i++)
			if (DB[i].GetNume() == nume)
			{
				cout << "Tabela exista deja - nu se poate face create!" << endl;
				return;
			}

		while (command.empty() == false)
		{
			for (int i = 0; i < command.length(); i++)
			{
				if (command[i] == ',')
				{
					command.erase(0, 1);
					alfa.name = (command.substr(0, i - 1));
					command.erase(0, i + 1);
					i = command.length() + 1;
				}
			}

			for (int i = 0; i < command.length(); i++)
			{
				if (command[i] == ',')
				{
					if (command.substr(0, i) == "int")

					{
						alfa.tip = (command.substr(0, i));
						command.erase(0, i + 2);
						i = command.length() + 1;
					}
					else if (command.substr(0, i) == "float")

					{
						alfa.tip = (command.substr(0, i));
						command.erase(0, i + 2);
						i = command.length() + 1;
					}
					else if (command.substr(0, i) == "string")

					{
						alfa.tip = (command.substr(0, i));
						command.erase(0, i + 2);
						i = command.length() + 1;
					}

				}
			}

			for (int i = 0; i < command.length(); i++)
			{
				if (command[i] == ',')
				{
					if (alfa.tip == "int")
					{
						alfa.dimensiune = stoi(command.substr(0, i));
						command.erase(0, i + 2);
						i = command.length() + 1;
					}
					else if (alfa.tip == "float")
					{
						alfa.dimensiune = stoi(command.substr(0, i));
						command.erase(0, i + 2);
						i = command.length() + 1;
					}
					else
						if (alfa.tip == "string")
						{
							alfa.dimensiune = stoi(command.substr(0, i));
							command.erase(0, i + 2);
							i = command.length() + 1;
						}
				}
			}

			for (int i = 0; i < command.length(); i++)
			{

				if (command[i] == ')')
				{
					if (alfa.tip == "int")
						alfa.bazaint = stoi(command.substr(0, i));
					else
						if (alfa.tip == "float")
							alfa.bazafloat = stof(command.substr(0, i));
						else
							if (alfa.tip == "string")
								alfa.bazastring = command.substr(0, i);
					command.erase(0, i);
					if (command[1] == ')')
						command.clear();
					else
						command.erase(0, 3);
					i = command.length() + 1;
				}
			}

			if (alfa.tip == "int")
			{
				si++;
				Coloana_int CI(alfa.name, alfa.dimensiune, alfa.bazaint, 0,nullptr);
				vi.push_back(CI);
				valOrdineColoane.first = "int";
				valOrdineColoane.second = si-1;
				ordineColoane.push_back(valOrdineColoane);

			}
			if (alfa.tip == "float")
			{
				sf++;
				Coloana_float CF(alfa.name, alfa.dimensiune, alfa.bazafloat, 0, nullptr);
				vf.push_back(CF);
				valOrdineColoane.first = "float";
				valOrdineColoane.second = sf-1;
				ordineColoane.push_back(valOrdineColoane);

			}

			if (alfa.tip == "string")
			{
				ss++;
				Coloana_string CS(alfa.name, alfa.dimensiune, alfa.bazastring, 0, vsAux);
				vs.push_back(CS);
				valOrdineColoane.first = "string";
				valOrdineColoane.second = ss-1;
				ordineColoane.push_back(valOrdineColoane);
			}

			alfa.name = "";
			alfa.tip = "";
			alfa.dimensiune = 0;
			alfa.bazaint = 0;
			alfa.bazafloat = 0;
			alfa.bazastring = "";
		}
		Tabel temp(nume, si, vi, sf, vf, ss, vs, ordineColoane);
		DB.push_back(temp);
		ofstream out(nume + ".cfg");
		out << commandText.substr(13, commandText.length() - 13);
		out.close();
		ofstream dout(nume + ".dat");
		dout.close();
	}
	void IdentificareInsertInto(vector<Tabel>& DB)
	{
		string command = commandText;
		string numetabel = "";
		string linie;
		int indice = -1;
		command.erase(0, 12);
		for (int i = 0; i < command.length(); i++)
		{
			if (command[i] == ' ')
			{
				numetabel = (command.substr(0, i));
				command.erase(0, i);
				i = command.length() + 1;
			}
		}
		for (int i = 0; i < DB.size(); i++)
			if (DB[i].GetNume() == numetabel)
				indice = i;
		if (indice == -1)
			cout << "Tabela nu exista - nu se poate face insert!" << endl;

		command.erase(0, 8);
		linie = command;
		string element = "";
		int nrElemCrt = -1;

		string p_tip;
		int p_pozitie;
		
		while (command.empty() == false)
		{
			for (int i = 0; i < command.length(); i++)
			{
				if (command[i] == ',' || command[i] == ')')
				{
					element = (command.substr(0, i));
					nrElemCrt++;
					command.erase(0, i);
					i = command.length() + 1;
				}
			}
			if (command[0] == ',')
				command.erase(0, 2);
			else
				command.erase(0, 1);

			p_tip = DB[indice].ordineColoane[nrElemCrt].first;
			int p_pozitie = DB[indice].ordineColoane[nrElemCrt].second;

			if (p_tip == "int")
			{
				DB[indice].vi[p_pozitie].AddElement(stoi(element));
			}

			if (p_tip == "float")
			{
				DB[indice].vf[p_pozitie].AddElement(stof(element));
			}
			if (p_tip == "string")
			{
				DB[indice].vs[p_pozitie].AddElement(element);
			}
		}
		ofstream out(numetabel + ".dat", ios::app);
		out << linie;
		out.close();
	
	}
	void IdentificareUpdate(vector<Tabel>& DB)
	{
		string command = commandText;
		command.erase(0, 7);
		string numetabel = "";
		string coloanaupdate = "";
		string valoaremodif = "";


		for (int i = 0; i < command.length(); i++)
		{
			if (command[i] == ' ')
			{
				numetabel = (command.substr(0, i));
				command.erase(0, i);
				i = command.length() + 1;
			}
		}
		command.erase(0, 5);
		for (int i = 0; i < command.length(); i++)
		{
			if (command[i] == ' ')
			{
				coloanaupdate = (command.substr(0, i));
				command.erase(0, i);
				i = command.length() + 1;
			}
		}
		command.erase(0, 3);

		for (int i = 0; i < command.length(); i++)
		{
			if (command[i] == ' ')
			{
				valoaremodif = (command.substr(0, i));
				command.erase(0, i);
				i = command.length() + 1;
			}
		}

		string coloanaconditie = "";

		int indicetabel = -1;
		int indicecolconditie = -1;
		string tipcoloanaconditie = "";
		string valoareconditie = "";

		vector<int> pozitii;
		
		if (command.empty() == false)
		{
			command.erase(0, 7);
			for (int i = 0; i < command.length(); i++)
			{
				if (command[i] == ' ')
				{
					coloanaconditie = command.substr(0, i);
					command.erase(0, i);
					i = command.length() + 1;
				}
			}
			command.erase(0, 3);
			valoareconditie = command;
		}

		for (int i = 0; i < DB.size(); i++)
			if (DB[i].GetNume() == numetabel)
				indicetabel = i;
		if (indicetabel == -1)
		{
			cout << "Tabela nu exista-nu se poate face select all" << endl;
			return;
		}

		if (coloanaconditie != "")
		{
			indicecolconditie = -2;
			for (int i = 0; i < DB[indicetabel].vi.size(); i++)
			{
				if (DB[indicetabel].vi[i].GetNume() == coloanaconditie)
				{
					tipcoloanaconditie = "int";
					indicecolconditie = i;
				}
			}
			for (int i = 0; i < DB[indicetabel].vf.size(); i++)
			{
				if (DB[indicetabel].vf[i].GetNume() == coloanaconditie)
				{
					tipcoloanaconditie = "float";
					indicecolconditie = i;
				}
			}
			for (int i = 0; i < DB[indicetabel].vs.size(); i++)
			{
				if (DB[indicetabel].vs[i].GetNume() == coloanaconditie)
				{
					tipcoloanaconditie = "string";
					indicecolconditie = i;
				}
			}
			if (indicecolconditie == -2)
			{
				cout << "Coloana pe baza careia se face filtrare nu exista-nu se poate face update" << endl;
				return;
			}
		}
		if (tipcoloanaconditie == "int")
		{
			int* y = DB[indicetabel].vi[indicecolconditie].getVector();
			for (int i = 0; i < DB[indicetabel].vi[indicecolconditie].getVectorSize(); i++)
				if (y[i] == stoi(valoareconditie))
					pozitii.push_back(i);
		}
		if (tipcoloanaconditie == "float")
		{
			float* y = DB[indicetabel].vf[indicecolconditie].getVector();
			for (int i = 0; i < DB[indicetabel].vf[indicecolconditie].getVectorSize(); i++)
				if (y[i] == stof(valoareconditie))
					pozitii.push_back(i);
		}
		if (tipcoloanaconditie == "string")
		{
			vector<string> y = DB[indicetabel].vs[indicecolconditie].getVector();
			for (int i = 0; i < DB[indicetabel].vs[indicecolconditie].getVectorSize(); i++)
				if (y[i] == valoareconditie)
					pozitii.push_back(i);
		}
		if (tipcoloanaconditie == "")
		{
			int nrInregistrari = 0;
			if (DB[indicetabel].getSI() > 0)
				nrInregistrari = max(nrInregistrari, DB[indicetabel].vi[0].getVectorSize());

			if (DB[indicetabel].getSF() > 0)
				nrInregistrari = max(nrInregistrari, DB[indicetabel].vf[0].getVectorSize());

			if (DB[indicetabel].getSS() > 0)
				nrInregistrari = max(nrInregistrari, DB[indicetabel].vs[0].getVectorSize());

			for (int i = 0; i < nrInregistrari; i++)
				pozitii.push_back(i);
		}

	
		//update

	
		int okcolcrt = 0;
		int indicecolUpdate = -1;
		string tipcolUpdate = "";
		for (int i = 0; i < DB[indicetabel].vi.size(); i++)
		{
			if (DB[indicetabel].vi[i].GetNume() == coloanaupdate)
			{
				indicecolUpdate = i;
				tipcolUpdate = "int";
				okcolcrt = 1;
			}
		}
		for (int i = 0; i < DB[indicetabel].vf.size(); i++)
		{
			if (DB[indicetabel].vf[i].GetNume() == coloanaupdate)
			{
				indicecolUpdate = i;
				tipcolUpdate = "float";
				okcolcrt = 1;
			}
		}
		for (int i = 0; i < DB[indicetabel].vs.size(); i++)
		{
			if (DB[indicetabel].vs[i].GetNume() == coloanaupdate)
			{
				indicecolUpdate = i;
				tipcolUpdate = "string";
				okcolcrt = 1;				
			}
		}
		if (okcolcrt == 0)
		{
			cout << "Coloana care se doreste modificata nu exista -nu se poate face update" << endl;
			return;
		}


		if (tipcolUpdate == "int")
		{
			int* x = DB[indicetabel].vi[indicecolUpdate].getVector();
			for (int ipoz = 0; ipoz < pozitii.size(); ipoz++)
			{
				for (int i = 0; i < DB[indicetabel].vi[indicecolUpdate].getVectorSize(); i++)
				{
					if (i == pozitii[ipoz])
						x[i] = stoi(valoaremodif);
				}
			}
			DB[indicetabel].vi[indicecolUpdate].setVector(x, DB[indicetabel].vi[indicecolUpdate].getVectorSize());
		}
		if (tipcolUpdate == "float")
		{
			float* x = DB[indicetabel].vf[indicecolUpdate].getVector();
			for (int ipoz = 0; ipoz < pozitii.size(); ipoz++)
			{
				for (int i = 0; i < DB[indicetabel].vf[indicecolUpdate].getVectorSize(); i++)
				{
					if (i == pozitii[ipoz])
						x[i] = stof(valoaremodif);
				}
			}
			DB[indicetabel].vf[indicecolUpdate].setVector(x, DB[indicetabel].vf[indicecolUpdate].getVectorSize());
		}
		if (tipcolUpdate == "string")
		{
			vector <string> x = DB[indicetabel].vs[indicecolUpdate].getVector();
			for (int ipoz = 0; ipoz < pozitii.size(); ipoz++)
			{
				for (int i = 0; i < DB[indicetabel].vs[indicecolUpdate].getVectorSize(); i++)
				{
					if (i == pozitii[ipoz])
						x[i] = valoaremodif;
				}
			}
			DB[indicetabel].vs[indicecolUpdate].setVector(x, DB[indicetabel].vs[indicecolUpdate].getVectorSize());
			DB[indicetabel].IncarcaDate();
		}

	}

	void IdentificareSelectAllFrom(vector<Tabel>& DB, int &nrSelect)
	{
		string command = commandText;
		string numetabel = "";
		string coloanaconditie = "";

		int indicetabel = -1;
		int indicecolconditie = -1;
		string tipcoloanaconditie = "";
		string valoareconditie = "";

		vector<int> pozitii;

		command.erase(0, 16);
		for (int i = 0; i <= command.length(); i++)
		{
			if (command[i] == ' ' || i==command.length())
			{
				numetabel = command.substr(0, i);
				command.erase(0, i);
				i = command.length() + 1;
			}
		}
		if(command.empty()==false)
		{
			command.erase(0, 7);
			for (int i = 0; i < command.length(); i++)
			{
				if (command[i] == ' ')
				{
					coloanaconditie = command.substr(0, i);
					command.erase(0, i);
					i = command.length() + 1;
				}
			}
			command.erase(0, 3);
			valoareconditie = command;
		}

		for (int i = 0; i < DB.size(); i++)
			if (DB[i].GetNume() == numetabel)
				indicetabel = i;
		if (indicetabel == -1)
		{
			cout << "Tabela nu exista-nu se poate face select all" << endl;
			return;
		}

		if (coloanaconditie != "")
		{
			indicecolconditie = -2;
			for (int i = 0; i < DB[indicetabel].vi.size(); i++)
			{
				if (DB[indicetabel].vi[i].GetNume() == coloanaconditie)
				{
					tipcoloanaconditie = "int";
					indicecolconditie = i;
				}
			}
			for (int i = 0; i < DB[indicetabel].vf.size(); i++)
			{
				if (DB[indicetabel].vf[i].GetNume() == coloanaconditie)
				{
					tipcoloanaconditie = "float";
					indicecolconditie = i;
				}
			}
			for (int i = 0; i < DB[indicetabel].vs.size(); i++)
			{
				if (DB[indicetabel].vs[i].GetNume() == coloanaconditie)
				{
					tipcoloanaconditie = "string";
					indicecolconditie = i;
				}
			}
			if (indicecolconditie == -2)
			{
				cout << "Coloana pe baza careia se face filtrare nu exista-nu se poate face select all" << endl;
				return;
			}
		}
		if (tipcoloanaconditie == "int")
		{
			int* y = DB[indicetabel].vi[indicecolconditie].getVector();
			for (int i = 0; i < DB[indicetabel].vi[indicecolconditie].getVectorSize(); i++)
			{
				if (y[i] == stoi(valoareconditie))
					pozitii.push_back(i);
			}
		}
		if (tipcoloanaconditie == "float")
		{
			float* y = DB[indicetabel].vf[indicecolconditie].getVector();
			for (int i = 0; i < DB[indicetabel].vf[indicecolconditie].getVectorSize(); i++)
				if (y[i] == stof(valoareconditie))
					pozitii.push_back(i);
		}
		if (tipcoloanaconditie == "string")
		{
			vector<string> y = DB[indicetabel].vs[indicecolconditie].getVector();
			for (int i = 0; i < DB[indicetabel].vs[indicecolconditie].getVectorSize(); i++)
				if (y[i] == valoareconditie)
					pozitii.push_back(i);
		}
		if (tipcoloanaconditie=="")
		{
			int nrInregistrari = 0;
			if(DB[indicetabel].getSI()>0)
				nrInregistrari= max(nrInregistrari,DB[indicetabel].vi[0].getVectorSize());

			if (DB[indicetabel].getSF() > 0)
				nrInregistrari = max(nrInregistrari, DB[indicetabel].vf[0].getVectorSize());

			if (DB[indicetabel].getSS() > 0)
				nrInregistrari = max(nrInregistrari, DB[indicetabel].vs[0].getVectorSize());

			for (int i = 0; i < nrInregistrari; i++)
					pozitii.push_back(i);
		}
		

		//cap de tabel
		nrSelect++;
		ofstream out("SelectFile_" + to_string(nrSelect)+".txt");

		cout << numetabel << endl;
		out << numetabel << endl;
		for (int i = 0; i < DB[indicetabel].ordineColoane.size(); i++)
		{
			string p_tip = DB[indicetabel].ordineColoane[i].first;
			int p_pozitie = DB[indicetabel].ordineColoane[i].second;

			if (p_tip == "int")
			{
				cout << DB[indicetabel].vi[p_pozitie].GetNume() << " ";
			}

			if (p_tip == "float")
			{
				cout << DB[indicetabel].vf[p_pozitie].GetNume() << " ";
			}
			if (p_tip == "string")
			{
				cout << DB[indicetabel].vs[p_pozitie].GetNume() << " ";
			}
		}

		cout << endl;
		//datele
		for(int ipoz=0;ipoz<pozitii.size();ipoz++)
		{
			cout << "Inregistrarea [" << pozitii[ipoz] << "]: ";

			for (int i = 0; i < DB[indicetabel].ordineColoane.size(); i++)
			{
				string p_tip = DB[indicetabel].ordineColoane[i].first;
				int p_pozitie = DB[indicetabel].ordineColoane[i].second;

				if (p_tip == "int")
				{
					int* t = DB[indicetabel].vi[p_pozitie].getVector();
					cout << "[" << t[pozitii[ipoz]] << "] ";
				}

				if (p_tip == "float")
				{
					float* t = DB[indicetabel].vf[p_pozitie].getVector();
					cout << "[" << t[pozitii[ipoz]] << "] ";
				}
				if (p_tip == "string")
				{
					vector<string> t = DB[indicetabel].vs[p_pozitie].getVector();
					cout << "[" << t[pozitii[ipoz]] << "] ";
				}
			}
			cout << endl;
		}

	}
	void IdentificareSelect(vector<Tabel>& DB, int &nrSelect)
	{

		string command = commandText;
		command.erase(0, 7);
		command.erase(0, 1);
		vector<string> coloanedisplay;
		vector<pair<string, int>> ordineColoaneDiplay;
		pair<string, int> valOrdineColoaneDisplay;
		int count = 0;
		while (command[count] != ')')
			count++;
		string sectiune = command.substr(0, count + 1);
		sectiune[count] = ',';
		while (sectiune.empty() == false)
		{
			for (int i = 0; i < sectiune.length(); i++)
			{
				if (sectiune[i] == ',')
				{
					coloanedisplay.push_back(sectiune.substr(0, i));
					sectiune.erase(0, i + 2);
					i = sectiune.length() + 1;

				}

			}
		}

		string numetabel = "";
		string coloanaconditie = "";

		int indicetabel = -1;
		int indicecolconditie = -1;
		string tipcoloanaconditie = "";
		string valoareconditie = "";

		vector<int> pozitii;
		command.erase(0, count+1);
		command.erase(0, 6);
		for (int i = 0; i <= command.length(); i++)
		{
			if (command[i] == ' ' || i == command.length())
			{
				numetabel = command.substr(0, i);
				command.erase(0, i);
				i = command.length() + 1;
			}
		}
		if (command.empty() == false)
		{
			command.erase(0, 7);
			for (int i = 0; i < command.length(); i++)
			{
				if (command[i] == ' ')
				{
					coloanaconditie = command.substr(0, i);
					command.erase(0, i);
					i = command.length() + 1;
				}
			}
			command.erase(0, 3);
			valoareconditie = command;
		}

		for (int i = 0; i < DB.size(); i++)
			if (DB[i].GetNume() == numetabel)
				indicetabel = i;
		if (indicetabel == -1)
		{
			cout << "Tabela nu exista-nu se poate face select all" << endl;
			return;
		}

		if (coloanaconditie != "")
		{
			indicecolconditie = -2;
			for (int i = 0; i < DB[indicetabel].vi.size(); i++)
			{
				if (DB[indicetabel].vi[i].GetNume() == coloanaconditie)
				{
					tipcoloanaconditie = "int";
					indicecolconditie = i;
				}
			}
			for (int i = 0; i < DB[indicetabel].vf.size(); i++)
			{
				if (DB[indicetabel].vf[i].GetNume() == coloanaconditie)
				{
					tipcoloanaconditie = "float";
					indicecolconditie = i;
				}
			}
			for (int i = 0; i < DB[indicetabel].vs.size(); i++)
			{
				if (DB[indicetabel].vs[i].GetNume() == coloanaconditie)
				{
					tipcoloanaconditie = "string";
					indicecolconditie = i;
				}
			}
			if (indicecolconditie == -2)
			{
				cout << "Coloana pe baza careia se face filtrare nu exista-nu se poate face select all" << endl;
				return;
			}
		}
		if (tipcoloanaconditie == "int")
		{
			int* y = DB[indicetabel].vi[indicecolconditie].getVector();
			for (int i = 0; i < DB[indicetabel].vi[indicecolconditie].getVectorSize(); i++)
				if (y[i] == stoi(valoareconditie))
					pozitii.push_back(i);
		}
		if (tipcoloanaconditie == "float")
		{
			float* y = DB[indicetabel].vf[indicecolconditie].getVector();
			for (int i = 0; i < DB[indicetabel].vf[indicecolconditie].getVectorSize(); i++)
				if (y[i] == stof(valoareconditie))
					pozitii.push_back(i);
		}
		if (tipcoloanaconditie == "string")
		{
			vector<string> y = DB[indicetabel].vs[indicecolconditie].getVector();
			for (int i = 0; i < DB[indicetabel].vs[indicecolconditie].getVectorSize(); i++)
				if (y[i] == valoareconditie)
					pozitii.push_back(i);
		}
		if (tipcoloanaconditie == "")
		{
				int nrInregistrari = 0;
				if (DB[indicetabel].getSI() > 0)
					nrInregistrari = max(nrInregistrari, DB[indicetabel].vi[0].getVectorSize());

				if (DB[indicetabel].getSF() > 0)
					nrInregistrari = max(nrInregistrari, DB[indicetabel].vf[0].getVectorSize());

				if (DB[indicetabel].getSS() > 0)
					nrInregistrari = max(nrInregistrari, DB[indicetabel].vs[0].getVectorSize());

				for (int i = 0; i < nrInregistrari; i++)
					pozitii.push_back(i);
		}
	
		
		//cap de tabel
		nrSelect++;
		ofstream out("SelectFile_" + to_string(nrSelect)+".txt");

		cout << numetabel << endl;
		out << numetabel << endl;
		for (int i = 0; i < coloanedisplay.size(); i++)
		{
				cout << coloanedisplay[i] << " ";
				out << coloanedisplay[i] << " ";
		}

		cout << endl;
		out << endl;
		//datele

		for (int ic = 0; ic < coloanedisplay.size(); ic++)
		{

			int okcolcrt = 0;
			for (int i = 0; i < DB[indicetabel].vi.size(); i++)
			{
				if (DB[indicetabel].vi[i].GetNume() == coloanedisplay[ic])
				{
					valOrdineColoaneDisplay.first= "int";
					valOrdineColoaneDisplay.second = i;
					okcolcrt = 1;
				}
			}
			for (int i = 0; i < DB[indicetabel].vf.size(); i++)
			{
				if (DB[indicetabel].vf[i].GetNume() == coloanedisplay[ic])
				{
					valOrdineColoaneDisplay.first = "float";
					valOrdineColoaneDisplay.second = i;
					okcolcrt = 1;
				}
			}
			for (int i = 0; i < DB[indicetabel].vs.size(); i++)
			{
				if (DB[indicetabel].vs[i].GetNume() == coloanedisplay[ic])
				{
					valOrdineColoaneDisplay.first = "string";
					valOrdineColoaneDisplay.second = i;
					okcolcrt = 1;
				}
			}
			if (okcolcrt == 0)
			{
				cout << "Coloana care se doreste afisata nu exista -nu se poate face select" << endl;
				return;
			}
			ordineColoaneDiplay.push_back(valOrdineColoaneDisplay);
		}


		for (int ipoz = 0; ipoz < pozitii.size(); ipoz++)
		{
			cout << "Inregistrarea [" << pozitii[ipoz] << "]: ";
			out << "Inregistrarea [" << pozitii[ipoz] << "]: ";
			for (int i = 0; i < ordineColoaneDiplay.size(); i++)
			{
				string p_tip = ordineColoaneDiplay[i].first;
				int p_pozitie = ordineColoaneDiplay[i].second;

				if (p_tip == "int")
				{
					int* t = DB[indicetabel].vi[p_pozitie].getVector();
					cout << "[" << t[pozitii[ipoz]] << "] ";
					out << "[" << t[pozitii[ipoz]] << "] ";
				}

				if (p_tip == "float")
				{
					float* t = DB[indicetabel].vf[p_pozitie].getVector();
					cout << "[" << t[pozitii[ipoz]] << "] ";
					out << "[" << t[pozitii[ipoz]] << "] ";
				}
				if (p_tip == "string")
				{
					vector<string> t = DB[indicetabel].vs[p_pozitie].getVector();
					cout << "[" << t[pozitii[ipoz]] << "] ";
					out << "[" << t[pozitii[ipoz]] << "] ";
				}
			}
			cout << endl;
			out << endl;
		}
		out.close();	

	}
	void IdentificareDeleteFrom(vector<Tabel>& DB)
	{
		string command = commandText;
		string numetabel = "";
		command.erase(0, 12);
		for (int i = 0; i < command.length(); i++)
		{
			if (command[i] == ' ')
			{
				numetabel = (command.substr(0, i));
				command.erase(0, i);
				i = command.length() + 1;
			}
		}
		command.erase(0, 1);
		if (command.substr(0, 6) == "WHERE ")
			command.erase(0, 6);

		string coloanaconditie;
		int indicecolconditie;
		string tipcoloanaconditie;
		for (int i = 0; i < command.length(); i++)
		{
			if (command[i] == ' ')
			{
				coloanaconditie = (command.substr(0, i));
				command.erase(0, i);
				i = command.length() + 1;
			}
		}
		command.erase(0, 3);
		int indicetabel = 0;
		string valoareconditie = command;
		for (int i = 0; i < DB.size(); i++)
			if (DB[i].GetNume() == numetabel)
				indicetabel = i;
		for (int i = 0; i < DB[indicetabel].vi.size(); i++)
		{
			if (DB[indicetabel].vi[i].GetNume() == coloanaconditie)
			{
				tipcoloanaconditie = "int";
				indicecolconditie = i;
			}
		}
		for (int i = 0; i < DB[indicetabel].vf.size(); i++)
		{
			if (DB[indicetabel].vf[i].GetNume() == coloanaconditie)
			{
				tipcoloanaconditie = "float";
				indicecolconditie = i;
			}
		}
		for (int i = 0; i < DB[indicetabel].vs.size(); i++)
		{
			if (DB[indicetabel].vs[i].GetNume() == coloanaconditie)
			{
				tipcoloanaconditie = "string";
				indicecolconditie = i;
			}
		}
		vector<int> pozitii;
		if (tipcoloanaconditie == "int")
		{
			int* y = DB[indicetabel].vi[indicecolconditie].getVector();
			for (int i = 0; i < DB[indicetabel].vi[indicecolconditie].getVectorSize(); i++)
				if (y[i] == stoi(valoareconditie))
					pozitii.push_back(i);
		}
		if (tipcoloanaconditie == "float")
		{
			float* y = DB[indicetabel].vf[indicecolconditie].getVector();
			for (int i = 0; i < DB[indicetabel].vf[indicecolconditie].getVectorSize(); i++)
				if (y[i] == stof(valoareconditie))
					pozitii.push_back(i);
		}
		if (tipcoloanaconditie == "string")
		{
			vector<string> y = DB[indicetabel].vs[indicecolconditie].getVector();
			for (int i = 0; i < DB[indicetabel].vs[indicecolconditie].getVectorSize(); i++)
				if (y[i] == valoareconditie)
					pozitii.push_back(i);
		}



		for (int j = pozitii.size() - 1; j >= 0; j--)
		{
			for (int i = 0; i < DB[indicetabel].vi.size(); i++)
			{
				DB[indicetabel].vi[i].RemoveElementfromPosition(pozitii[j]);
			}
			for (int i = 0; i < DB[indicetabel].vf.size(); i++)
			{
				DB[indicetabel].vf[i].RemoveElementfromPosition(pozitii[j]);
			}


			for (int i = 0; i < DB[indicetabel].vs.size(); i++)
			{

				DB[indicetabel].vs[i].RemoveElementfromPosition(pozitii[j]);

			}
		}


	}
	void Identificare_comanda(vector<Tabel>& DB, int &nrDisplay, int &nrSelect)
	{


		string command = commandText;
		if (command.substr(0, 13) == "DISPLAY TABLE")
		{
			IdentificareDisplayTable(DB,nrDisplay);
		}

		if (command.substr(0, 10) == "DROP TABLE")
		{
			IdentificareDropTable(DB);
		}

		if (command.substr(0, 13) == "CREATE TABLE ")
		{

			IdentificareCreateTable(DB);


		}


		if (command.substr(0, 12) == "INSERT INTO ")
		{

			IdentificareInsertInto(DB);
		}

		if (command.substr(0, 7) == "UPDATE ")
		{
			IdentificareUpdate(DB);
		}
		if (command.substr(0, 16) == "SELECT ALL FROM ")
		{
			IdentificareSelectAllFrom(DB,nrSelect);
		}
		else
			if (command.substr(0, 7) == "SELECT ")
			{
				IdentificareSelect(DB,nrSelect);

			}

		if (command.substr(0, 12) == "DELETE FROM ")
		{
			IdentificareDeleteFrom(DB);

		}
	}
};

