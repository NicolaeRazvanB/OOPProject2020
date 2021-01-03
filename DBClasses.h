#pragma once
#include <iostream>
#include<vector>
#include<string>
using namespace std;
class Coloana
{
private:
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
	~Coloana() {}
	string GetNume() const { return nume; }
	void SetNume(string n) { this->nume = n; }
	friend ostream& operator<<(ostream&, Coloana);
	friend istream& operator>>(istream&, Coloana&);
};


class Coloana_int : public Coloana
{
private:int s = 0;
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
		int  size = this->getVectorSize()+1;
		int* copie = new int[size];
		for (int i = 0; i < size-1; i++)
		{
			copie[i] = this->v[i];

		}
		copie[size-1] = x;
	
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
private:int s = 0;
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
		{int  size = this->getVectorSize() - 1;
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
		setVector(copie, size); }
	
	}

	
	friend ostream& operator<<(ostream&, Coloana_float);
	friend istream& operator>>(istream&, Coloana_float&);
};

class Coloana_string : public Coloana
{
private: int s = 0;
	   vector<string> v;
public:
	Coloana_string() {}
	Coloana_string(string nume, int s, vector<string> v) :Coloana(nume)
	{

		if (v.empty() == false && s > 0)
		{
			this->s = s;
		
			this->v = v;
		}

	}
	~Coloana_string() {}
	Coloana_string(const Coloana_string& c) :Coloana(c)
	{
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
public:
	Tabel() {}
	Tabel(string nume, int si, vector<Coloana_int>vi, int  sf, vector<Coloana_float> vf, int ss, vector<Coloana_string> vs)
	{
		this->nume = nume;
		this->si = si;
		this->sf = sf;
		this->ss = ss;
		this->vi = vi;
		this->vf = vf;
		this->vs = vs;
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
	out << "Nr. Inregistrari: " << c.s << endl;
	out << "Inregistrari: " << endl;
	if (c.v != nullptr)
	{
		for (int i = 0; i < c.s; i++)
		{
			out << "	     " << c.v[i] << "   " << endl;
		}
	}
	else out << "N/A" << "   " << endl;;
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
	else out << "N/A" << "   "<<endl;
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
	else out << "N/A" << "  "<<endl;
	return out;
}
istream& operator>>(istream& in, Coloana_string& c)
{
	in >> (Coloana&)c;
	cout << "Nr. Inregistrari: ";
	in >> c.s;

	if (c.v.empty() == false)
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
			out << "	     " << c.vi[i] << "   ";

		}
	}
	else out << "N/A"<<endl;

	if (c.vf.empty() == false)
	{
		for (int i = 0; i < c.sf; i++)
		{
			out << "	     " << c.vf[i] << "   ";

		}
	}
	else out << "N/A"<<endl;
	if (c.vs.empty() == false)
	{
		for (int i = 0; i < c.ss; i++)
		{
			out << "	     " << c.vs[i] << "   ";

		}
	}
	else out << "N/A"<<endl;
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
	in >> c.ss;
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

