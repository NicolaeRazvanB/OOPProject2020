#pragma once
#include <iostream>
#include<vector>
#include<string>
using namespace std;
class Command;
class Coloana
{
private:
	string nume;
	int dimensiune;
	int pozitieInTabela;
public:
	Coloana()
	{
		nume = " - ";
		dimensiune = 0;
	}
	Coloana(string n, int dimensiune)
	{
		this->nume = n;
		this->dimensiune = dimensiune;
	}
	Coloana(const Coloana& c)
	{
		this->nume = c.nume;
		this->dimensiune = c.dimensiune;
	}
	Coloana& operator=(const Coloana& c)
	{
		this->nume = c.nume;
		this->dimensiune = c.dimensiune;
		return *this;
	}
	~Coloana() {}
	string GetNume() const { return nume; }
	int GetDimensiune() const { return dimensiune; }
	void SetNume(string n) { this->nume = n; }
	void setDimensiune(int dimensiune) { this->dimensiune = dimensiune; }
	friend ostream& operator<<(ostream&, Coloana);
	friend istream& operator>>(istream&, Coloana&);
};


class Coloana_int : public Coloana
{
private:
	   int valoareImplicita;
	   int s = 0;
	   int* v = nullptr;
public:
	Coloana_int()
	{
		s = 0;
		v = nullptr;
		valoareImplicita = 0;
	}
	Coloana_int(string n, int dimensiune, int valoareImpicita, int s, int* v) :Coloana(n,dimensiune)
	{
		this->valoareImplicita = valoareImpicita;
		if (v != nullptr && s > 0)
		{
			this->s = s;
			this->v = new int[s];
			for (int i = 0; i < s; i++)
			{
				this->v[i] = v[i];
			}
		}

	}
	Coloana_int(const Coloana_int& c) :Coloana(c)
	{
		this->valoareImplicita = c.valoareImplicita;
		if (c.v != nullptr && c.s != 0)
		{
			this->s = c.s;
			this->v = new int[c.s];
			for (int i = 0; i < c.s; i++)
			{
				this->v[i] = c.v[i];
			}
		}
		else
		{
			this->v = nullptr;
			this->s = 0;
		}
	}
	Coloana_int& operator=(const Coloana_int& c)
	{
		Coloana::operator=(c);
		this->valoareImplicita = c.valoareImplicita;
		if (c.v != nullptr && c.s != 0)
		{
			this->s = c.s;
			this->v = new int[c.s];
			for (int i = 0; i < c.s; i++)
			{
				this->v[i] = c.v[i];
			}
		}
		else
		{
			this->v = nullptr;
			this->s = 0;
		}
		return *this;
	}
	~Coloana_int()
	{
		if (v != nullptr)
		{
			delete[] v;
		}
	}
	void SetValoareImplicita(int valoareImplicita)
	{
		this->valoareImplicita = valoareImplicita;
	}
	int GetValoareImplicita()
	{
		return this->valoareImplicita;
	}
	void setVector(int* v, int s)
	{
		if (v != nullptr && s != 0)
		{
			this->s = s;
			if (this->v != nullptr)
			{
				delete[] this->v;

			}
			this->v = new int[s];
			for (int i = 0; i < s; i++)
			{
				this->v[i] = v[i];
			}
		}
		else
		{
			this->v = nullptr;
			this->s = 0;
		}
	}
	int* getVector()
	{
		if (v != nullptr)
		{
			int* copie = new int[s];
			for (int i = 0; i < s; i++)
			{
				copie[i] = v[i];

			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}
	int getVectorSize()
	{
		return s;
	}

	void AddElement(int x)
	{
		int  size = this->getVectorSize() + 1;
		int* copie = new int[size];
		for (int i = 0; i < size - 1; i++)
		{
			copie[i] = this->v[i];

		}
		copie[size - 1] = x;

		setVector(copie, size);
	}

	void RemoveElementfromPosition(int x)
	{
		if (this->getVectorSize() == 1 && x == 0)
		{
			int* copie = nullptr;
			setVector(copie, 0);
		}
		else
		{
			int  size = this->getVectorSize() - 1;
			int* copie = new int[size];
			for (int i = 0; i < x; i++)
				copie[i] = this->v[i];
			for (int i = x; i < size; i++)
				copie[i] = this->v[i + 1];
			if (size == 1 && x == 0)
			{
				copie = nullptr;
				size = 0;
			}
			setVector(copie, size);
		}
	}
	friend ostream& operator<<(ostream&, Coloana_int);
	friend istream& operator>>(istream&, Coloana_int&);
};


class Coloana_float : public Coloana
{
private:
	   float valoareImplicita;
	   int s = 0;
	   float* v = nullptr;
public:
	Coloana_float()
	{
		s = 0;
		v = nullptr;
		valoareImplicita = 0;
	}
	Coloana_float(string n, int dimensiune, float valoareImplicita, int s, float* v) :Coloana(n,dimensiune)
	{
		this->valoareImplicita = valoareImplicita;
		if (v != nullptr && s > 0)
		{
			this->s = s;
			this->v = new float[s];
			for (int i = 0; i < s; i++)
			{
				this->v[i] = v[i];
			}
		}

	}
	Coloana_float(const Coloana_float& c) :Coloana(c)
	{
		this->valoareImplicita = c.valoareImplicita;
		if (c.v != nullptr && c.s != 0)
		{
			this->s = c.s;
			this->v = new float[c.s];
			for (int i = 0; i < c.s; i++)
			{
				this->v[i] = c.v[i];
			}
		}
		else
		{
			this->v = nullptr;
			this->s = 0;
		}
	}
	Coloana_float& operator=(const Coloana_float& c)
	{
		Coloana::operator=(c);
		this->valoareImplicita = c.valoareImplicita;
		if (c.v != nullptr && c.s != 0)
		{
			this->s = c.s;
			this->v = new float[c.s];
			for (int i = 0; i < c.s; i++)
			{
				this->v[i] = c.v[i];
			}
		}
		else
		{
			this->v = nullptr;
			this->s = 0;
		}
		return *this;
	}
	~Coloana_float()
	{
		if (v != nullptr)
		{
			delete[] v;
		}
	}
	void SetValoareImplicita(float valoareImplicita)
	{
		this->valoareImplicita = valoareImplicita;
	}
	float GetValoareImplicita()
	{
		return this->valoareImplicita;
	}
	void setVector(float* v, int s)
	{
		if (v != nullptr && s != 0)
		{
			this->s = s;
			if (this->v != nullptr)
			{
				delete[] this->v;

			}
			this->v = new float[s];
			for (int i = 0; i < s; i++)
			{
				this->v[i] = v[i];
			}
		}
		else
		{
			this->v = nullptr;
			this->s = 0;
		}
	}
	float* getVector()
	{
		if (v != nullptr)
		{
			float* copie = new float[s];
			for (int i = 0; i < s; i++)
			{
				copie[i] = v[i];

			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}
	int getVectorSize()
	{
		return s;
	}
	void AddElement(float x)
	{
		int  size = this->getVectorSize() + 1;
		float* copie = new float[size];
		for (int i = 0; i < size - 1; i++)
		{
			copie[i] = this->v[i];

		}
		copie[size - 1] = x;

		setVector(copie, size);
	}
	void RemoveElementfromPosition(int x)
	{
		if (this->getVectorSize() == 1 && x == 0)
		{
			float* copie = nullptr;
			setVector(copie, 0);
		}
		else
		{
			int  size = this->getVectorSize() - 1;
			float* copie = new float[size];
			for (int i = 0; i < x; i++)
				copie[i] = this->v[i];
			for (int i = x; i < size; i++)
				copie[i] = this->v[i + 1];
			if (size == 1 && x == 0)
			{
				copie = nullptr;
				size = 0;
			}
			setVector(copie, size);
		}

	}


	friend ostream& operator<<(ostream&, Coloana_float);
	friend istream& operator>>(istream&, Coloana_float&);
};

class Coloana_string : public Coloana
{
private: 
	   string valoareImplicita="-";
	   int s = 0;
	   vector<string> v;
public:
	Coloana_string() {}
	Coloana_string(string nume, int dimensiune, string valoareImplicita, int s, vector<string> v) :Coloana(nume,dimensiune)
	{
		this->valoareImplicita = valoareImplicita;
		if (v.empty() == false && s > 0)
		{
			this->s = s;

			this->v = v;
		}

	}
	~Coloana_string() {}
	Coloana_string(const Coloana_string& c) :Coloana(c)
	{
		this->valoareImplicita = c.valoareImplicita;
		if (c.v.empty() == false && c.s != 0)
		{
			this->s = c.s;
			v.resize(c.s);
			for (int i = 0; i < c.s; i++)
			{
				this->v[i] = c.v[i];
			}
		}
		else
		{
			v.clear();
			this->s = 0;
		}
	}
	Coloana_string& operator=(const Coloana_string& c)
	{
		Coloana::operator=(c);
		this->valoareImplicita = c.valoareImplicita;
		if (c.v.empty() == false && c.s != 0)
		{
			this->s = c.s;
			v.resize(c.s);
			for (int i = 0; i < c.s; i++)
			{
				this->v[i] = c.v[i];
			}
		}
		else
		{
			v.clear();
			this->s = 0;
		}
		return *this;
	}
	void SetValoareImplicita(string valoareImplicita)
	{
		this->valoareImplicita = valoareImplicita;
	}
	string GetValoareImplicita()
	{
		return this->valoareImplicita;
	}

	void setVector(vector<string> x, int s)
	{
		if (v.empty() == false && s != 0)
		{
			this->s = s;
			if (v.empty() == false)
			{
				v.clear();

			}
			v.resize(s);
			for (int i = 0; i < s; i++)
			{
				this->v[i] = v[i];
			}
		}
	}

	vector<string> getVector()
	{
		if (v.empty() == false)
		{
			vector<string> copie;
			copie.resize(s);
			for (int i = 0; i < s; i++)
			{
				copie[i] = v[i];

			}
			return copie;
		}
		else
		{
			vector<string> empty;
			return empty;
		}
	}

	int getVectorSize()
	{
		return s;
	}

	void AddElement(string x)
	{
		this->s = this->s + 1;
		this->v.push_back(x);
	}
	void RemoveElementfromPosition(int x)
	{
		this->v.erase(v.begin() + x);
		this->s = this->s - 1;
	}

	friend ostream& operator<<(ostream&, Coloana_string);
	friend istream& operator>>(istream&, Coloana_string&);
};

class Tabel
{
private:string nume = "";
	   int si = 0;
	   int sf = 0;
	   int ss = 0;
	   vector<Coloana_int> vi;
	   vector<Coloana_float> vf;
	   vector<Coloana_string> vs;
	   vector<pair<string,int>> ordineColoane;
public:
	Tabel() {}
	Tabel(string nume, int si, vector<Coloana_int>vi, int  sf, vector<Coloana_float> vf, int ss, vector<Coloana_string> vs, vector<pair<string,int>> ordineColoane)
	{
		this->nume = nume;
		this->si = si;
		this->sf = sf;
		this->ss = ss;
		this->vi = vi;
		this->vf = vf;
		this->vs = vs;
		if (ordineColoane.empty() == false && si + sf + ss != 0)
		{
			this->ordineColoane.resize(si + sf + ss);
			for (int i = 0; i < si + sf + ss; i++)
			{
				this->ordineColoane[i] = ordineColoane[i];
			}
		}
		else
		{
			ordineColoane.clear();
		}
	}
	~Tabel() {}
	Tabel(const Tabel& t)
	{
		this->nume = t.nume;
		this->si = t.si;
		this->sf = t.sf;
		this->ss = t.ss;
		if (t.vi.empty() == false && t.si != 0)
		{
			this->si = t.si;
			vi.resize(t.si);
			for (int i = 0; i < t.si; i++)
			{
				this->vi[i] = t.vi[i];
			}
		}
		else
		{
			vi.clear();
			this->si = 0;
		}
		if (t.vf.empty() == false && t.sf != 0)
		{
			this->sf = t.sf;
			vf.resize(t.sf);
			for (int i = 0; i < t.sf; i++)
			{
				this->vf[i] = t.vf[i];
			}
		}
		else
		{
			vf.clear();
			this->sf = 0;
		}
		if (t.vs.empty() == false && t.ss != 0)
		{
			this->ss = t.ss;
			vs.resize(t.ss);
			for (int i = 0; i < t.ss; i++)
			{
				this->vs[i] = t.vs[i];
			}
		}
		else
		{
			vs.clear();
			this->ss = 0;
		}
		if (t.ordineColoane.empty() == false && t.si + t.sf+t.ss != 0)
		{
			ordineColoane.resize(t.si+t.sf+t.ss);
			for (int i = 0; i < t.si+t.sf+t.ss; i++)
			{
				this->ordineColoane[i] = t.ordineColoane[i];
			}
		}
		else
		{
			ordineColoane.clear();
		}
	}
	Tabel& operator=(const Tabel& t)
	{
		this->nume = t.nume;
		this->si = t.si;
		this->sf = t.sf;
		this->ss = t.ss;
		if (t.vi.empty() == false && t.si != 0)
		{
			this->si = t.si;
			vi.resize(t.si);
			for (int i = 0; i < t.si; i++)
			{
				this->vi[i] = t.vi[i];
			}
		}
		else
		{
			vi.clear();
			this->si = 0;
		}
		if (t.vf.empty() == false && t.sf != 0)
		{
			this->sf = t.sf;
			vf.resize(t.sf);
			for (int i = 0; i < t.sf; i++)
			{
				this->vf[i] = t.vf[i];
			}
		}
		else
		{
			vf.clear();
			this->sf = 0;
		}
		if (t.vs.empty() == false && t.ss != 0)
		{
			this->ss = t.ss;
			vs.resize(t.ss);
			for (int i = 0; i < t.ss; i++)
			{
				this->vs[i] = t.vs[i];
			}
		}
		else
		{
			vs.clear();
			this->ss = 0;
		}
		if (t.ordineColoane.empty() == false && t.si + t.sf + t.ss != 0)
		{
			ordineColoane.resize(t.si + t.sf + t.ss);
			for (int i = 0; i < t.si + t.sf + t.ss; i++)
			{
				this->ordineColoane[i] = t.ordineColoane[i];
			}
		}
		else
		{
			ordineColoane.clear();
		}
		return *this;
	}
	string GetNume() const { return nume; }
	void SetNume(string n) { this->nume = n; }
	void setVI(vector<Coloana_int> vi, int si)
	{
		if (vi.empty() == false && si != 0)
		{
			this->si = si;
			if (vi.empty() == false)
			{
				vi.clear();

			}
			vi.resize(si);
			for (int i = 0; i < si; i++)
			{
				this->vi[i] = vi[i];
			}
		}
	}

	vector<Coloana_int> getVI()
	{
		if (vi.empty() == false)
		{
			vector<Coloana_int> copie;
			copie.resize(si);
			for (int i = 0; i < si; i++)
			{
				copie[i] = vi[i];

			}
			return copie;
		}
		else
		{
			vector<Coloana_int> empty;
			return empty;
		}
	}

	void setVF(vector<Coloana_float> vf, int sf)
	{
		if (vf.empty() == false && sf != 0)
		{
			this->sf = sf;
			if (vf.empty() == false)
			{
				vf.clear();

			}
			vf.resize(sf);
			for (int i = 0; i < sf; i++)
			{
				this->vf[i] = vf[i];
			}
		}
	}

	vector<Coloana_float> getVF()
	{
		if (vf.empty() == false)
		{
			vector<Coloana_float> copie;
			copie.resize(sf);
			for (int i = 0; i < sf; i++)
			{
				copie[i] = vf[i];

			}
			return copie;
		}
		else
		{
			vector<Coloana_float> empty;
			return empty;
		}
	}

	void setVS(vector<Coloana_string> vs, int ss)
	{
		if (vs.empty() == false && ss != 0)
		{
			this->ss = ss;
			if (vs.empty() == false)
			{
				vs.clear();

			}
			vs.resize(ss);
			for (int i = 0; i < ss; i++)
			{
				this->vs[i] = vs[i];
			}
		}
	}

	vector<Coloana_string> getVS()
	{
		if (vs.empty() == false)
		{
			vector<Coloana_string> copie;
			copie.resize(ss);
			for (int i = 0; i < ss; i++)
			{
				copie[i] = vs[i];

			}
			return copie;
		}
		else
		{
			vector<Coloana_string> empty;
			return empty;
		}
	}

	void IncarcaStructura(string numeFisier)
	{
		string linie;
		ifstream in(numeFisier);
		in >> *this;
		in.close();
		ofstream out(GetNume() + ".dat");
		out.close();
	}

	void IncarcaDate()
	{
		string linie;
		ifstream in(GetNume()+".dat");
		in >> ws;
		while (getline(in, linie))
		{
			AddLinie(linie);
			in >> ws;
		}
		in.close();
	}

	void AddLinie(string command)
	{
		int indice = -1;
		string element = "";
		int nrElemCrt = -1;

		string p_tip;
		int p_pozitie;
		command.erase(0,1);

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

			p_tip = this->ordineColoane[nrElemCrt].first;
			int p_pozitie = this->ordineColoane[nrElemCrt].second;

			if (p_tip == "int")
			{
				this->vi[p_pozitie].AddElement(stoi(element));
			}

			if (p_tip == "float")
			{
				this->vf[p_pozitie].AddElement(stof(element));
			}
			if (p_tip == "string")
			{
				this->vs[p_pozitie].AddElement(element);
			}
		}
	}

	
	int getSI()
	{
		return si;
	}
	int getSF()
	{
		return sf;
	}
	int getSS()
	{
		return ss;
	}

	friend ostream& operator<<(ostream&, Tabel);
	friend istream& operator>>(istream&, Tabel&);
	friend class Command;
};


ostream& operator<<(ostream& out, Coloana c)
{
	out << "coloana "<<c.nume << " " << c.dimensiune;
	return out;
}
istream& operator>>(istream& in, Coloana& c)
{
	string tip;
	in >> c.nume >>tip>>c.dimensiune;
	if (tip != "int" && tip != "float" && tip != "string")
		cout << "Tipul citit este necorespunzator!";
	return in;
}

ostream& operator<<(ostream& out, Coloana_int c)
{
	out << (Coloana)c << " "<<c.valoareImplicita<<" int";
	return out;
}
istream& operator>>(istream& in, Coloana_int& c)
{
	in >> (Coloana&)c;
	in >> c.valoareImplicita;
	return in;
}

ostream& operator<<(ostream& out, Coloana_float c)
{
	out << (Coloana)c << " "<<c.valoareImplicita<<" float";
	return out;
}
istream& operator>>(istream& in, Coloana_float& c)
{
	in >> (Coloana&)c;
	in >> c.valoareImplicita;
	return in;
}
ostream& operator<<(ostream& out, Coloana_string c)
{
	out << (Coloana)c << " "<<c.valoareImplicita<<" string";
	return out;
}
istream& operator>>(istream& in, Coloana_string& c)
{
	in >> (Coloana&)c;
	in >> c.valoareImplicita;
	return in;
}

ostream& operator<<(ostream& out, Tabel c)
{
	out << "Nume Tabel: ";
	out << c.nume << endl;
	for (int i=0;i<c.ordineColoane.size();i++)
	{
		string p_tip = c.ordineColoane[i].first;
		int p_pozitie = c.ordineColoane[i].second;

		if(p_tip=="int")
		{
			out << c.vi[p_pozitie] << endl;
		}

		if (p_tip == "float")
		{
			out << c.vf[p_pozitie] << endl;
		}
		if (p_tip == "string")
		{
			out << c.vs[p_pozitie] << endl;
		}
	}
	out << endl;
	

	return out;
}
istream& operator>>(istream& in, Tabel& c)
{
	string command;

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

	getline(in, command);
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
			Coloana_int CI(alfa.name, alfa.dimensiune, alfa.bazaint, 0, nullptr);
			vi.push_back(CI);
			valOrdineColoane.first = "int";
			valOrdineColoane.second = si - 1;
			ordineColoane.push_back(valOrdineColoane);

		}
		if (alfa.tip == "float")
		{
			sf++;
			Coloana_float CF(alfa.name, alfa.dimensiune, alfa.bazafloat, 0, nullptr);
			vf.push_back(CF);
			valOrdineColoane.first = "float";
			valOrdineColoane.second = sf - 1;
			ordineColoane.push_back(valOrdineColoane);

		}

		if (alfa.tip == "string")
		{
			ss++;
			Coloana_string CS(alfa.name, alfa.dimensiune, alfa.bazastring, 0, vsAux);
			vs.push_back(CS);
			valOrdineColoane.first = "string";
			valOrdineColoane.second = ss - 1;
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
	c = temp;
	return in;
}

