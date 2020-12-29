#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Coloana 
{private:
	string nume;
public:
	Coloana()
	{
		nume = " - ";
	}
	Coloana(string n)
	{
		this->nume = n;
	}
	Coloana(const Coloana& c)
	{
		this->nume = c.nume;
	}
	Coloana& operator=(const Coloana& c)
	{
		this->nume = c.nume;
		return *this;
	}
	~Coloana(){}
	string GetNume() const { return nume; }
	void SetNume(string n) { this->nume = n; }
	friend ostream& operator<<(ostream&, Coloana);
	friend istream& operator>>(istream&,Coloana&);
};


class Coloana_int : public Coloana
{
private:int s=0;
	   int* v = nullptr;
public:
	Coloana_int()
	{
		s = 0;
		v = nullptr;
	}
	Coloana_int(string n, int s, int* v) :Coloana(n)
	{
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
	friend ostream& operator<<(ostream&, Coloana_int);
	friend istream& operator>>(istream&, Coloana_int&);
};


class Coloana_float : public Coloana
{
private:int s=0;
	   float* v = nullptr;
public:
	Coloana_float()
	{
		s = 0;
		v = nullptr;
	}
	Coloana_float(string n, int s, float* v) :Coloana(n)
	{
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
	friend ostream& operator<<(ostream&, Coloana_float);
	friend istream& operator>>(istream&, Coloana_float&);
};

class Coloana_string : public Coloana
{
private: int s=0;
	   vector<string> v;
public:
	Coloana_string(){}
	Coloana_string(string nume,int s, vector<string> v):Coloana(nume)
	{
		
		if(v.empty()==false&& s>0)
		{
			this->s = s;
			v.resize(s);
			for (int i = 0; i < s; i++)
			{
				this->v[i] = v[i];
			}
		}

	}
	~Coloana_string(){}
	Coloana_string(const Coloana_string& c) :Coloana(c)
	{
		if (c.v.empty()==false && c.s != 0)
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

	void setVector(vector<string> x, int s)
	{
		if (v.empty()==false && s != 0)
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
		if (v.empty()==false)
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
public:
	Tabel(){}
	Tabel(string nume,int si, vector<Coloana_int>vi, int  sf, vector<Coloana_float> vf,int ss, vector<Coloana_string> vs)
	{
		this->nume = nume;
		this->si = si;
		this->sf = sf;
		this->ss = ss;
		this->vi = vi;
		this->vf = vf;
		this->vs = vs;
	}
	~Tabel(){}
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
	friend void Identificare_comanda(string command, vector<Tabel>& DB);
};


ostream& operator<<(ostream& out, Coloana c)
{
	cout << "Nume Coloana: ";
	out << c.nume << endl;
	return out;
}
istream& operator>>(istream& in, Coloana& c)
{
	cout << "Nume Coloana: ";
	in >> ws;
	getline(in, c.nume);
	return in;
}

ostream& operator<<(ostream& out, Coloana_int c)
{
	out << (Coloana)c << endl;
	out << "Nr. Inregistrari: "<< c.s << endl;
	out << "Inregistrari: "<<endl;
	if (c.v != nullptr)
	{
		for (int i = 0; i < c.s; i++)
		{
			out <<"	     "<< c.v[i]<<"   " << endl;
		}
	}
	else out << "N/A"<<"   ";
	return out;
}
istream& operator>>(istream& in, Coloana_int& c)
{
	in >> (Coloana&)c;
	cout << "Nr. Inregistrari: ";
	in >> c.s;
	if (c.v != nullptr)
	{
		delete[] c.v;
	}
	if (c.s > 0)
	{
		c.v = new int[c.s];
		for (int i = 0; i < c.s; i++)
		{
			cout << "Inregistrarea [" << i << "]:";
			in >> c.v[i];
		}
	}
	else
	{
		c.s = 0;
		c.v = nullptr;
	}
	return in;
}

ostream& operator<<(ostream& out, Coloana_float c)
{
	out << (Coloana)c << endl;
	out << "Nr. Inregistrari: " << c.s << endl;
	out << "Inregistrari: " << endl;
	if (c.v != nullptr)
	{
		for (int i = 0; i < c.s; i++)
		{
			out << "	     " << c.v[i] << "   " << endl;
		}
	}
	else out << "N/A"<<"   ";
	return out;
}
istream& operator>>(istream& in, Coloana_float& c)
{
	in >> (Coloana&)c;
	cout << "Nr. Inregistrari: ";
	in >> c.s;
	if (c.v != nullptr)
	{
		delete[] c.v;
	}
	if (c.s > 0)
	{
		c.v = new float[c.s];
		for (int i = 0; i < c.s; i++)
		{
			cout << "Inregistrarea [" << i << "]:";
			in >> c.v[i];
		}
	}
	else
	{
		c.s = 0;
		c.v = nullptr;
	}
	return in;
}
ostream& operator<<(ostream& out, Coloana_string c)
{
	out << (Coloana)c << endl;
	out << "Nr. Inregistrari: " << c.s << endl;
	out << "Inregistrari: " << endl;
	if (c.v.empty() == false)
	{
		for (int i = 0; i < c.s; i++)
		{
			out << "	     " << c.v[i] << "   " << endl;
		}
	}
	else out << "N/A"<<"  ";
	return out;
}
istream& operator>>(istream& in, Coloana_string& c)
{
	in >> (Coloana&)c;
	cout << "Nr. Inregistrari: ";
	in >> c.s;
	
	if (c.v.empty()==false)
	{
		c.v.clear();
	}
	if (c.s > 0)
	{
		c.v.resize(c.s);
		for (int i = 0; i < c.s; i++)
		{
			cout << "Inregistrarea [" << i << "]:";
			in >> c.v[i];
		}
	}
	else
	{
		c.s = 0;
		c.v.clear();
	}
	return in;
}

ostream& operator<<(ostream& out, Tabel c)
{
	cout << "Nume Tabel: ";
	out << c.nume << endl;
	
	if (c.vi.empty() == false)
	{
		for (int i = 0; i < c.si; i++)
		{
			out << "	     " << c.vi[i] << "   " ;
			
		}
	}
	else out << "N/A";

	if (c.vf.empty() == false)
	{
		for (int i = 0; i < c.sf; i++)
		{
			out << "	     " << c.vf[i] << "   ";

		}
	}
	else out << "N/A";
	if (c.vs.empty() == false)
	{
		for (int i = 0; i < c.ss; i++)
		{
			out << "	     " << c.vs[i] << "   ";

		}
	}
	else out << "N/A";
	cout << endl;
	
	return out;
}
istream& operator>>(istream& in, Tabel& c)
{
	cout << "Nume Tabel: ";
	in >> ws;
	getline(in, c.nume);
	cout << "Nr. Col. Tip int: ";
	in >> c.si;
	if (c.vi.empty() == false)
	{
		c.vi.clear();
	}
	if (c.si > 0)
	{
		c.vi.resize(c.si);
		for (int i = 0; i < c.si; i++)
		{
			cout << "Inregistrarea [" << i << "]:";
			in >> c.vi[i];
		}
	}
	else
	{
		c.si = 0;
		c.vi.clear();
	}
	cout << "Nr. Col. Tip Float: ";
	in >> c.sf;
	if (c.vf.empty() == false)
	{
		c.vf.clear();
	}
	if (c.sf > 0)
	{
		c.vf.resize(c.sf);
		for (int i = 0; i < c.sf; i++)
		{
			cout << "Inregistrarea [" << i << "]:";
			in >> c.vf[i];
		}
	}
	else
	{
		c.sf = 0;
		c.vf.clear();
	}
	cout << "Nr. Col. Tip String: ";
	in>> c.ss;
	if (c.vs.empty() == false)
	{
		c.vs.clear();
	}
	if (c.ss > 0)
	{
		c.vs.resize(c.ss);
		for (int i = 0; i < c.ss; i++)
		{
			cout << "Inregistrarea [" << i << "]:";
			in >> c.vs[i];
		}
	}
	else
	{
		c.ss = 0;
		c.vs.clear();
	}
	return in;
}





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

		
		string nume="";
		int si = 0;
		int sf = 0;
		int ss=0;
		vector<Coloana_int> vi;
		vector<Coloana_float>vf;
		vector<Coloana_string>vs;
		
		command.erase(0, 13);

		for (int i = 0; i < command.length(); i++)
		{
			if (command[i] == '(')
			{
				nume=(command.substr(0, i - 1));
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
				vector<string>a = { "" };
				a.resize(alfa.dimensiune);
				for (int i = 0; i < alfa.dimensiune; i++)
					a[i] = alfa.bazastring;

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
	command.erase(0,12);
	}
	if (command.substr(0, 12) == "DELETE FROM ")
	{
		string numetabel = "";
		string numecoloana = "";
		string coloanadesters = "";
		command.erase(0, 12);
		for (int i = 0; i < command.length(); i++)
		{
			if (command[i] == ' ')
			{
				numetabel = (command.substr(0, i - 1));
				command.erase(0, i - 1);
				i = command.length() + 1;
			}
		}
		command.erase(0, 1);
		if (command.substr(0, 6) == "WHERE ")
			command.erase(0, 6);
		for (int i = 0; i < command.length(); i++)
		{
			if (command[i] == ' ')
			{
				numecoloana = (command.substr(0, i - 1));
				command.erase(0, i - 1);
				i = command.length() + 1;
			}
		}
		command.erase(0, 3); for (int i = 0; i < command.length(); i++)
		{
			if (command[i] == ' ')
			{
				coloanadesters = (command.substr(0, i - 1));
				command.erase(0, i - 1);
				i = command.length() + 1;
			}
		}
		for (int i = 0; i < DB.size(); i++)
		{
			if (DB[i].GetNume() == numetabel)
			{
				for (vector <Coloana_int>::iterator it=DB[i].vi.begin();it!=DB[i].vi.end();++it)
					if (it->GetNume() == numecoloana)
					{
						DB[i].vi.erase(it);
					}
				for (vector <Coloana_float>::iterator it = DB[i].vf.begin(); it != DB[i].vf.end(); ++it)
					if (it->GetNume() == numecoloana)
					{
						DB[i].vf.erase(it);
					}
				for (vector <Coloana_string>::iterator it = DB[i].vs.begin(); it != DB[i].vs.end(); ++it)
					if (it->GetNume() == numecoloana)
					{
						DB[i].vs.erase(it);
					}
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
	
	
};

	
	
	
	
			
			
			
	
