#include <iostream>
#include<vector>
#include<string>
#include<DBClasses.h>
using namespace std;

void Identificare_comanda(string command, vector<Tabel>& DB)
{



	if (command.substr(0, 13) == "DISPLAY TABLE")
	{
		int k = 0;
		for (int i = 0; i < DB.size(); i++)
			if (command.substr(14, command.length()) == DB[i].GetNume())
			{
				cout << DB[i];
				k = 1;
			}
		if (k == 0) cout << "Nu exista tabele cu acest nume";
	}

	if (command.substr(0, 10) == "DROP TABLE")
	{
		int l = 0;
		for (int i = 0; i < DB.size(); i++)
			if (command.substr(11, command.length()) == DB[i].GetNume())
			{
				DB.erase(DB.begin() + i);
				l = 1;
				cout << "Tabelul " << DB[i].GetNume() << " a fost sters cu succes.";
			}
		if (l == 0) cout << "Nu exista tabele cu acest nume";
	}

	if (command.substr(0, 13) == "CREATE TABLE ")
	{

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
				int* a = new int[alfa.dimensiune];
				for (int i = 0; i < alfa.dimensiune; i++)
					a[i] = alfa.bazaint;
				Coloana_int CI(alfa.name, alfa.dimensiune, a);
				vi.push_back(CI);

			}
			if (alfa.tip == "float")
			{
				sf++;
				float* a = new float[alfa.dimensiune];
				for (int i = 0; i < alfa.dimensiune; i++)
					a[i] = alfa.bazafloat;
				Coloana_float CF(alfa.name, alfa.dimensiune, a);
				vf.push_back(CF);


			}

			if (alfa.tip == "string")
			{
				ss++;
				vector<string>a;
				a.resize(alfa.dimensiune, alfa.bazastring);
				Coloana_string CS(alfa.name, alfa.dimensiune, a);
				vs.push_back(CS);

			}

			alfa.name = "";
			alfa.tip = "";
			alfa.dimensiune = 0;
			alfa.bazaint = 0;
			alfa.bazafloat = 0;
			alfa.bazastring = "";
		}
		Tabel temp(nume, si, vi, sf, vf, ss, vs);
		DB.push_back(temp);


	}




	if (command.substr(0, 12) == "INSERT INTO ")
	{

		string numetabel = "";
		int indice = 0;
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
		command.erase(0, 8);

		int imax = DB[indice].vi.size();
		int fmax = DB[indice].vf.size();
		int smax = DB[indice].vs.size();
		string element = "";


		while (command.empty() == false)
		{
			int sw1 = 0; int sw2 = 0; int sw3 = 0;

			for (int i = 0; i < command.length(); i++)
			{
				if (command[i] == ',' || command[i] == ')')
				{
					element = (command.substr(0, i));
					command.erase(0, i);
					i = command.length() + 1;
				}
			}
			if (command[0] == ',')
				command.erase(0, 2);
			else
				command.erase(0, 1);

			if (imax > 0)
			{

				DB[indice].vi[DB[indice].vi.size() - imax].AddElement(stoi(element));
				sw1 = 1;

			}
			if (imax == 0 && fmax > 0)
			{

				DB[indice].vf[DB[indice].vf.size() - fmax].AddElement(stof(element));
				sw2 = 1;

			}
			if (fmax == 0 && smax > 0)
			{

				DB[indice].vs[DB[indice].vs.size() - smax].AddElement(element);
				sw3 = 1;

			}
			if (sw1 == 1) imax--;
			if (sw2 == 1) fmax--;
			if (sw3 == 1) smax--;

		}
	}

	if (command.substr(0, 7) == "UPDATE ")
	{
		command.erase(0, 7);
		string numetabel = "";
		string coloanaupdate = "";
		string valoaremodif = "";
		string coloanaconditie = "";

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
		command.erase(0, 7);

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
		string valconditie = command;

		string tip = "";
		int indicet = 0;
		int indicecu = 0;
		for (int i = 0; i < DB.size(); i++)
			if (DB[i].GetNume() == numetabel)
				indicet = i;

		for (int i = 0; i < DB[indicet].vi.size(); i++)
		{
			if (DB[indicet].vi[i].GetNume() == coloanaupdate)
				tip = "int";
			indicecu = i;
		}
		for (int i = 0; i < DB[indicet].vf.size(); i++)
		{
			if (DB[indicet].vf[i].GetNume() == coloanaupdate)
				tip = "float";
			indicecu = i;
		}
		for (int i = 0; i < DB[indicet].vs.size(); i++)
		{
			if (DB[indicet].vs[i].GetNume() == coloanaupdate)
				tip = "string";
			indicecu = i;
		}

		int indicecc = 0;
		string tip2 = "";
		for (int i = 0; i < DB[indicet].vi.size(); i++)
		{
			if (DB[indicet].vi[i].GetNume() == coloanaconditie)
				tip2 = "int";
			indicecc = i;
		}
		for (int i = 0; i < DB[indicet].vf.size(); i++)
		{
			if (DB[indicet].vf[i].GetNume() == coloanaconditie)
				tip2 = "float";
			indicecc = i;
		}
		for (int i = 0; i < DB[indicet].vs.size(); i++)
		{
			if (DB[indicet].vs[i].GetNume() == coloanaconditie)
				tip2 = "string";
			indicecc = i;
		}


		if (tip2 == "int")
		{
			vector<int> pozitii;
			int* y = DB[indicet].vi[indicecc].getVector();
			for (int i = 0; i < DB[indicet].vi[indicecc].getVectorSize(); i++)
				if (y[i] = stoi(valconditie))
					pozitii.push_back(i);
			if (tip == "int")
			{
				int* x = DB[indicet].vi[indicecu].getVector();
				while (pozitii.empty() == false)
				{
					for (int i = 0; i < DB[indicet].vi[indicecu].getVectorSize(); i++)
					{
						if (i == pozitii[0])
							x[i] = stoi(valoaremodif);
					}
					pozitii.erase(pozitii.begin());
				}
				DB[indicet].vi[indicecu].setVector(x, DB[indicet].vi[indicecu].getVectorSize());
			}
			if (tip == "float")
			{
				float* x = DB[indicet].vf[indicecu].getVector();
				while (pozitii.empty() == false)
				{
					for (int i = 0; i < DB[indicet].vf[indicecu].getVectorSize(); i++)
					{
						if (i == pozitii[0])
							x[i] = stof(valoaremodif);
					}
					pozitii.erase(pozitii.begin());
				}
				DB[indicet].vf[indicecu].setVector(x, DB[indicet].vf[indicecu].getVectorSize());
			}
			if (tip == "string")
			{
				vector<string> x = DB[indicet].vs[indicecu].getVector();
				while (pozitii.empty() == false)
				{
					for (int i = 0; i < DB[indicet].vs[indicecu].getVectorSize(); i++)
					{
						if (i == pozitii[0])
							x[i] = valoaremodif;
					}
					pozitii.erase(pozitii.begin());
				}
				DB[indicet].vs[indicecu].setVector(x, DB[indicet].vs[indicecu].getVectorSize());
			}


		}

		if (tip2 == "float")
		{
			vector<int> pozitii;
			float* y = DB[indicet].vf[indicecc].getVector();
			for (int i = 0; i < DB[indicet].vf[indicecc].getVectorSize(); i++)
				if (y[i] = stof(valconditie))
					pozitii.push_back(i);
			if (tip == "int")
			{
				int* x = DB[indicet].vi[indicecu].getVector();
				while (pozitii.empty() == false)
				{
					for (int i = 0; i < DB[indicet].vi[indicecu].getVectorSize(); i++)
					{
						if (i == pozitii[0])
							x[i] = stoi(valoaremodif);
					}
					pozitii.erase(pozitii.begin());
				}
				DB[indicet].vi[indicecu].setVector(x, DB[indicet].vi[indicecu].getVectorSize());
			}
			if (tip == "float")
			{
				float* x = DB[indicet].vf[indicecu].getVector();
				while (pozitii.empty() == false)
				{
					for (int i = 0; i < DB[indicet].vf[indicecu].getVectorSize(); i++)
					{
						if (i == pozitii[0])
							x[i] = stof(valoaremodif);
					}
					pozitii.erase(pozitii.begin());
				}
				DB[indicet].vf[indicecu].setVector(x, DB[indicet].vf[indicecu].getVectorSize());
			}
			if (tip == "string")
			{
				vector<string> x = DB[indicet].vs[indicecu].getVector();
				while (pozitii.empty() == false)
				{
					for (int i = 0; i < DB[indicet].vs[indicecu].getVectorSize(); i++)
					{
						if (i == pozitii[0])
							x[i] = valoaremodif;
					}
					pozitii.erase(pozitii.begin());
				}
				DB[indicet].vs[indicecu].setVector(x, DB[indicet].vs[indicecu].getVectorSize());
			}


		}

		if (tip2 == "string")
		{
			vector<int> pozitii;
			vector<string> y = DB[indicet].vs[indicecc].getVector();
			for (int i = 0; i < DB[indicet].vs[indicecc].getVectorSize(); i++)
				if (y[i] == valconditie)
					pozitii.push_back(i);
			if (tip == "int")
			{
				int* x = DB[indicet].vi[indicecu].getVector();
				while (pozitii.empty() == false)
				{
					for (int i = 0; i < DB[indicet].vi[indicecu].getVectorSize(); i++)
					{
						if (i == pozitii[0])
							x[i] = stoi(valoaremodif);
					}
					pozitii.erase(pozitii.begin());
				}
				DB[indicet].vi[indicecu].setVector(x, DB[indicet].vi[indicecu].getVectorSize());
			}
			if (tip == "float")
			{
				float* x = DB[indicet].vf[indicecu].getVector();
				while (pozitii.empty() == false)
				{
					for (int i = 0; i < DB[indicet].vf[indicecu].getVectorSize(); i++)
					{
						if (i == pozitii[0])
							x[i] = stof(valoaremodif);
					}
					pozitii.erase(pozitii.begin());
				}
				DB[indicet].vf[indicecu].setVector(x, DB[indicet].vf[indicecu].getVectorSize());
			}
			if (tip == "string")
			{
				vector<string> x = DB[indicet].vs[indicecu].getVector();
				while (pozitii.empty() == false)
				{
					for (int i = 0; i < DB[indicet].vs[indicecu].getVectorSize(); i++)
					{
						if (i == pozitii[0])
							x[i] = valoaremodif;
					}
					pozitii.erase(pozitii.begin());
				}
				DB[indicet].vs[indicecu].setVector(x, DB[indicet].vs[indicecu].getVectorSize());
			}


		}
	}
	if (command.substr(0, 16) == "SELECT ALL FROM ")
	{
		string numetabel = "";
		string coloanaconditie = "";
		command.erase(0, 16);
		for (int i = 0; i < command.length(); i++)
		{
			if (command[i] == ' ')
			{
				numetabel = command.substr(0, i);
				command.erase(0, i);
				i = command.length() + 1;
			}
		}
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
		string valoareconditie = command;
		int indicetabel = 0;
		int indicecolconditie = 0;
		string tipcoloanaconditie = "";

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
		vector<int> copie = pozitii;
		for (int i = 0; i < DB[indicetabel].vi.size(); i++)
		{
			pozitii = copie;
			int* t = DB[indicetabel].vi[i].getVector();
			cout << DB[indicetabel].vi[i].GetNume() << endl;
			while (pozitii.empty() == false)
			{
				for (int j = 0; j < DB[indicetabel].vi[i].getVectorSize(); j++)
					if (j == pozitii[0])
					{
						cout << "Inregistrarea [" << j << "]: " << t[j] << endl;
						pozitii.erase(pozitii.begin());
					}
			}

		}
		for (int i = 0; i < DB[indicetabel].vf.size(); i++)
		{
			pozitii = copie;
			float* t = DB[indicetabel].vf[i].getVector();
			cout << DB[indicetabel].vf[i].GetNume() << endl;
			while (pozitii.empty() == false)
			{
				for (int j = 0; j < DB[indicetabel].vf[i].getVectorSize(); j++)
					if (j == pozitii[0])
					{
						cout << "Inregistrarea [" << j << "]: " << t[j] << endl;
						pozitii.erase(pozitii.begin());
					}
			}

		}
		for (int i = 0; i < DB[indicetabel].vs.size(); i++)
		{
			pozitii = copie;
			vector<string> t = DB[indicetabel].vs[i].getVector();
			cout << DB[indicetabel].vs[i].GetNume() << endl;
			while (pozitii.empty() == false)
			{
				for (int j = 0; j < DB[indicetabel].vs[i].getVectorSize(); j++)
					if (j == pozitii[0])
					{
						cout << "Inregistrarea [" << j << "]: " << t[j] << endl;
						pozitii.erase(pozitii.begin());
					}
			}

		}


	}
	else
		if (command.substr(0, 7) == "SELECT ")
		{
			command.erase(0, 7);
			command.erase(0, 1);
			vector<string> coloanedisplay;
			vector<int> indicicoloanedisplay;
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
						sectiune.erase(0, i);
						i = sectiune.length() + 1;

					}
					if (sectiune[0] == ',')
						sectiune.erase(0, 2);
				}
			}
			command.erase(0, count + 7);
			string numetabel; int indicetabel;
			for (int i = 0; i < command.length(); i++)
			{
				if (command[i] == ' ')
				{
					numetabel = (command.substr(0, i));
					command.erase(0, i);
					i = command.length() + 1;
				}
			}
			command.erase(0, 7);
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
			vector<int> copie = pozitii;


			while (coloanedisplay.size() > 0)
			{

				for (int i = 0; i < DB[indicetabel].vi.size(); i++)
				{
					if (DB[indicetabel].vi[i].GetNume() == coloanedisplay[0])
					{
						int* t = DB[indicetabel].vi[i].getVector();
						cout << DB[indicetabel].vi[i].GetNume() << endl;
						while (pozitii.empty() == false)
						{
							for (int j = 0; j < DB[indicetabel].vi[i].getVectorSize(); j++)
								if (j == pozitii[0])
								{
									cout << "Inregistrarea [" << j << "]: " << t[j] << endl;
									pozitii.erase(pozitii.begin());
								}
						}

						i = DB[indicetabel].vi.size() + 1;
					}
				}



				for (int i = 0; i < DB[indicetabel].vf.size(); i++)
				{
					if (DB[indicetabel].vf[i].GetNume() == coloanedisplay[0])
					{
						float* t = DB[indicetabel].vf[i].getVector();
						cout << DB[indicetabel].vf[i].GetNume() << endl;
						while (pozitii.empty() == false)
						{
							for (int j = 0; j < DB[indicetabel].vf[i].getVectorSize(); j++)
								if (j == pozitii[0])
								{
									cout << "Inregistrarea [" << j << "]: " << t[j] << endl;
									pozitii.erase(pozitii.begin());
								}

						}


						i = DB[indicetabel].vf.size() + 1;
					}
				}



				for (int i = 0; i < DB[indicetabel].vs.size(); i++)
				{
					if (DB[indicetabel].vs[i].GetNume() == coloanedisplay[0])
					{
						vector<string> t = DB[indicetabel].vs[i].getVector();
						cout << DB[indicetabel].vs[i].GetNume() << endl;
						while (pozitii.empty() == false)
						{
							for (int j = 0; j < DB[indicetabel].vs[i].getVectorSize(); j++)
								if (j == pozitii[0])
								{
									cout << "Inregistrarea [" << j << "]: " << t[j] << endl;
									pozitii.erase(pozitii.begin());
								}
						}

						i = DB[indicetabel].vs.size() + 1;
					}
				}

				if (coloanedisplay.size() == 1)
					coloanedisplay.clear();
				else
				{
					coloanedisplay.erase(coloanedisplay.begin());
				}
				pozitii = copie;

			}

		}

	if (command.substr(0, 12) == "DELETE FROM ")
	{
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
		
		

		for (int j = pozitii.size()-1; j >= 0; j--)
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
}

			
		









int main()
{
	vector<Tabel> DB;
	string command;
	cout << "Introduceti Comanda:";
	cin >> ws;
	getline(cin,command);
	Identificare_comanda(command,DB );
	cout << "Introduceti Comanda:";
	getline(cin, command);
	Identificare_comanda(command, DB);
	cout << "Introduceti Comanda:";
	getline(cin, command);
	Identificare_comanda(command, DB);

	
	
	
}

	
	
	
	
			
			
			
	
