
#include <iostream>
/*

	Zasto su rulet gaja i vuk u cilindru u sretku
	- Jovan Polovina 2021
	Pise na spomen ploci palih limanskih junaka
	Slava slobodi i pravdi
	Svi za djapeta
	djape za sve

*/

using namespace std;


//gordic pimpmobile
#define MAX_PUTNIKA_U_YUGU 9
#define MAX_BRZINA_YUGO 6
#define CENA_YUGO 100000
#define GORIVO_YUGO 120
#define AIRBEGOVI_YUGO 0
#define YUGO_VRATA 2
#define YUGO_NAVIGACIJA false

#define PRODAVAC_MAX_VOZILA 12

enum nivoOpreme
{
	NIVO_0,
	NIVO_1,
	NIVO_2,
	NIVO_3,
	NIVO_4,
};

enum Oprema
{
	OPREMA_LICNA,
	OPREMA_ZAVOZILO,
};

enum nacinPlacanja
{
	NACIN_KES,
	NACIN_KREDIT,
	NACIN_LIZING,
};

enum TipMenjaca
{
	MENJAC_AUTOMATSKI,
	MENJAC_MANUALNI,
};

enum Pol
{
	POL_MUSKI,
	POL_ZENSKI,
};

class Menjac;
class Osoba;
class Vozilo;
class Cetvorotockas;
class Dvotockas;
class Automobil;
class Kombi;
class Tahograf;
class Kamion;
class Motor;
class Prodavac;
class Kupac;
class Reklamacija;
class dodatnaOprema;
class Yugo;

class Menjac
{
	public:
	Menjac();
	Menjac(Menjac& original);
	Menjac(int inputbrojbrzina, int inputbrzina, TipMenjaca inputtip, int inputminbrzina);
	~Menjac();
	int brzina;
	int brojbrzina; // broj jovana
	int minbrzina;
	bool operator == (Menjac& poredjenje)
	{
		if (poredjenje.brojbrzina != brojbrzina)
			return false;
		
		if (poredjenje.brzina != brzina)
			return false;

		if (poredjenje.minbrzina != minbrzina)
			return false;

		if (poredjenje.tip != tip)
			return false;

		return true;
	}

	friend ostream& operator << (ostream& output, Menjac& primerak)
	{
		output << "Brzina je " + primerak.brzina << ", broj brzina je " + primerak.brojbrzina <<
			", minimalna brzina je " + primerak.minbrzina;

		return output;
	}

	friend istream& operator >> (istream& input, Menjac& primerak)
	{
		input >> primerak.brzina >> primerak.brojbrzina >> primerak.minbrzina;
		return input;
	}

	TipMenjaca tip;

};

Menjac::Menjac()
{
	brzina = 0;
	brojbrzina = 6;
	minbrzina = 0;
	tip = MENJAC_MANUALNI;
}

Menjac::Menjac(Menjac& original)
{
	brzina = original.brzina;
	brojbrzina = original.brojbrzina;
	minbrzina = original.minbrzina;
	tip = original.tip;
}

Menjac::Menjac(int inputbrojbrzina, int inputbrzina, TipMenjaca inputtip, int inputminbrzina)
{
	brojbrzina = inputbrojbrzina;
	brzina = inputbrzina;
	tip = inputtip;
	minbrzina = inputminbrzina;
}

Menjac::~Menjac()
{
	brzina = 0;
	brojbrzina = 0;
	minbrzina = 0;
	tip = MENJAC_MANUALNI;
}

enum StanjeVozila
{
	UGASENO,
	POKVARENO,
	U_VOZNJI,
};

enum StanjeRacuna
{
	STANJE_NORMALNO,
	STANJE_ZAKLJUCANO,
	STANJE_ISCEKIVAJUCE,
};

typedef struct ListaPutnika
{
	struct ListaPutnika* head;
	struct ListaPutnika* next;
	Osoba* osoba;
} ListaPutnika;

typedef struct ListaKupaca
{
	struct ListaKupaca* head;
	struct ListaKupaca* next;
	Kupac* kupac;
} ListaKupaca;

class Osoba
{
public:
	Osoba();
	Osoba(string inputime, string inputprezime, Pol inputpol, int inputstarost, string inputbrojtelefona);
	Osoba(Osoba& original);
	~Osoba();
	string GetIme(void) { return ime; }
	string GetPrezime(void) { return prezime; }
	Pol GetPol(void) { return pol; }
	int GetStarost(void) { return starost; }
	string GetBrojTelefona(void) { return brojtelefona; }
	void SetIme(string novoIme) { ime = novoIme; }
	void SetPrezime(string novoPrezime) { ime = novoPrezime; }
	void SetPol(Pol noviPol) { pol = noviPol; }
	void SetStarost(int novaStarost) { starost = novaStarost; }
	void SetbrojTelefon(string noviBrojTelefon) { brojtelefona = noviBrojTelefon; }
	bool operator == (Osoba& poredjenje)
	{
		if (poredjenje.brojtelefona != brojtelefona)
			return false;

		if (poredjenje.ime != ime)
			return false;

		if (poredjenje.pol != pol)
			return false;

		if (poredjenje.prezime != prezime)
			return false;

		if (poredjenje.starost != starost)
			return false;

		return true;
	}

	friend ostream& operator << (ostream& output, Osoba& primerak)
	{
		output << "Broj telefona je " << primerak.brojtelefona << ", ime je " << primerak.ime << ", pol je " <<
			((primerak.pol == POL_MUSKI) ? "muski " : "zenski ") << ", prezime je " << primerak.prezime << ", starost je " << primerak.starost;

		return output;
	}

	friend istream& operator >> (istream& input, Osoba& primerak)
	{
		input >> primerak.brojtelefona >> primerak.ime;
		int polint;
		do
		{
			input >> polint;
		} while (polint != (int)POL_MUSKI && polint != (int)POL_ZENSKI);
		primerak.prezime = (Pol)polint;
		input >> primerak.prezime >> primerak.starost;
		return input;
	}

protected:
	string ime;
	string prezime;
	Pol pol;
	// nokia ringtone arabic
	string brojtelefona;
	int starost;
};

Osoba::Osoba()
{
	ime = "";
	prezime = "";
	pol = POL_MUSKI;
	brojtelefona = "";
	starost = 0;
}

Osoba::Osoba(string inputime, string inputprezime, Pol inputpol, int inputstarost, string inputbrojtelefona)
{
	ime = inputime;
	prezime = inputprezime;
	pol = inputpol;
	starost = inputstarost;
	brojtelefona = inputbrojtelefona;
}

Osoba::Osoba(Osoba& original)
{
	ime = original.ime;
	prezime = original.prezime;
	pol = original.pol;
	starost = original.starost;
	brojtelefona = original.brojtelefona;
}

Osoba::~Osoba()
{
	ime = "";
	prezime = "";
	pol = POL_MUSKI;
	starost = 0;
	brojtelefona = "";
}


class Vozilo
{
	public:
	float GetCena(void) { return cena; }
	float GetGorivo(void) { return gorivo; }
	float GetMaxGorivo(void) { return maxgorivo; }
	void SetCena(float novacena) { cena = novacena; }
	void SetGorivo(float novogorivo) { gorivo = novogorivo; }
	void SetMaxGorivo(float novogorivo) { maxgorivo = novogorivo; }
	virtual string GetProizvodjac(void) = 0;
	virtual float GetZapreminaPrtljaznika(void) = 0;
	virtual float GetKubikaza(void) = 0;
	TipMenjaca GetTipMenjaca(void) { return menjac.tip; }
	void SetTipMenjaca(TipMenjaca novtip) { menjac.tip = novtip; }
	void Ubrzaj(void);
	void Uspori(void);
	void Koci(void);
	void ZapocniMotor(void);
	Osoba *GetPutnik(Osoba* putnik);
	int GetBrojPutnika(void);
	void DodajPutnika(Osoba* putnik);
	void IzbaciPutnika(Osoba* putnik);
	virtual int GetMaxPutnika(void) = 0;
	int GetMaxBrzina(void) { return menjac.brojbrzina; }
	int GetMinBrzina(void) { return menjac.minbrzina; }
	int GetBrzina(void) { return menjac.brzina; }
	StanjeVozila GetStanje(void) { return stanje; }
	virtual void SetBrzina(int novabrzina) { menjac.brzina = novabrzina; }
	bool operator == (Vozilo& poredjenje)
	{
		if (!(poredjenje.menjac == menjac))
			return false;

		if (poredjenje.gorivo != gorivo)
			return false;

		if (poredjenje.cena != cena)
			return false;

		if (poredjenje.maxgorivo != maxgorivo)
			return false;

		if (poredjenje.listaputnika != listaputnika)
			return false;

		if (poredjenje.maxputnika != maxputnika)
			return false;

		if (poredjenje.stanje != stanje)
			return false;

		return true;
	}

	friend ostream& operator << (ostream& output, Vozilo& primerak)
	{

		output << "Menjac: " << primerak.menjac << ", gorivo je " << primerak.gorivo << ", cena je " << primerak.cena
			<< ", maksimalno gorivo je " << primerak.maxgorivo;
		ListaPutnika* temp = primerak.listaputnika;
		while (temp)
		{
			output << temp->osoba;
			temp = temp->next;
		}

		string stanjestring;

		output << ", maksimalan broj putnika je " << primerak.maxputnika << ", stanje vozila je: ";
		switch (primerak.stanje)
		{
		case U_VOZNJI:
			stanjestring = "u voznji";
			break;
		case UGASENO:
			stanjestring = "ugaseno";
			break;
		case POKVARENO:
			stanjestring = "pokvareno";
			break;
		default:
			stanjestring = "nepoznato (BG tablice)";
			break;
		}

		return output;
	}

	friend istream& operator >> (istream& input, Vozilo& primerak)
	{
		int inputstanje = 0;
		input >> primerak.menjac >> primerak.gorivo >> primerak.cena >> primerak.maxgorivo;
		do
		{
			input >> inputstanje;
		} while (inputstanje < 0 || inputstanje > 2);
		input >> primerak.maxputnika;

		return input;
	}

	protected:
	Menjac menjac;
	float gorivo;
	float cena; //jovancoin
	float maxgorivo;
	ListaPutnika *listaputnika;
	int maxputnika;
	StanjeVozila stanje;

};

void Vozilo::Ubrzaj(void)
{
	if (GetBrzina() == GetMaxBrzina())
		return;

	SetBrzina(GetBrzina() + 1);
}

void Vozilo::Uspori(void)
{
	if (GetBrzina() == GetMinBrzina())
		return;

	SetBrzina(GetBrzina() - 1);
}

void Vozilo::Koci(void)
{
	SetBrzina(GetMinBrzina());
}

Osoba *Vozilo::GetPutnik(Osoba* putnik)
{
	ListaPutnika *pLista = listaputnika->head;
	while (pLista)
	{
		if (pLista->osoba == putnik)
			return pLista->osoba;

		pLista = pLista->next;
	}

	return NULL;
}

int Vozilo::GetBrojPutnika(void)
{
	int counter = 0;
	ListaPutnika* pLista = listaputnika->head;
	while (pLista)
	{
		pLista = pLista->next;
		counter++;
	}

	return counter;
}

void Vozilo::DodajPutnika(Osoba* putnik)
{
	if (GetBrojPutnika() == GetMaxPutnika())
		return;

	ListaPutnika* pLista = listaputnika->head;
	while (pLista && pLista->osoba)
		pLista = pLista->next;

	pLista = new ListaPutnika;
	pLista->osoba = putnik;
}

void Vozilo::IzbaciPutnika(Osoba* putnik)
{
	ListaPutnika* pLista = listaputnika->head;
	while (pLista)
	{
		if (pLista->osoba == putnik)
		{
			ListaPutnika* pTemp = listaputnika->head;
			while (pTemp)
			{
				if (pTemp->next == pLista)
				{
					pTemp->next = pLista->next;
					delete pLista;
					pLista = NULL;
					break;
				}
			}
		}
	}
}

class Cetvorotockas : public Vozilo
{
	public:
	bool operator == (Cetvorotockas& poredjenje)
	{
		if (poredjenje.brojAirbegova != brojAirbegova)
			return false;

		if (poredjenje.boja != boja)
			return false;

		if (poredjenje.brojVrata != brojVrata)
			return false;

		if (poredjenje.Navigacija != Navigacija)
			return false;

		return true;
	}

	friend ostream& operator << (ostream& output, Cetvorotockas& primerak)
	{
		output << "Broj airbegova je " << primerak.brojAirbegova << ", boja je " << primerak.boja << ", broj vrata je " << primerak.brojVrata;
		output << ", " << primerak.Navigacija ? "ima navigaciju, " : "nema navigaciju, ";

		return output;
	}

	friend istream& operator >> (istream& input, Cetvorotockas& primerak)
	{
		input >> primerak.brojAirbegova >> primerak.boja >> primerak.brojVrata >>
			primerak.Navigacija;

		return input;
	}
	int brojAirbegova;
	string boja;
	int brojVrata;
	bool Navigacija;
	int GetbrojAirbegova(void) { return brojAirbegova; }
	string Getboja(void) { return boja; }
	int GetbrojVrata(void) { return brojVrata; }
	bool GetNavigacija(void) { return Navigacija; }
	void SetbrojAirbegova(int novibrojAibegova) { brojAirbegova = novibrojAibegova; }
	void Setboja(string novaboja) { boja = novaboja; }
	void setbrojVrata(int novibrojVrata) { brojVrata = novibrojVrata; }
	void setNavigacija(bool novaNavigacija) { Navigacija = novaNavigacija; }

	Cetvorotockas();
	Cetvorotockas(Cetvorotockas &original);
	Cetvorotockas(int nbrojAirbegova, string nboja, int nbrojVrata, bool nNavigacija, float ncena, float ngorivo, float nmaxgorivo);
	~Cetvorotockas();
};

Cetvorotockas::Cetvorotockas()
{
	cena = 100;
	gorivo = 100;
	maxgorivo = 100;
	brojAirbegova = 4;
	boja = "";
	brojVrata = 5;
	Navigacija = true;
}

Cetvorotockas::Cetvorotockas(int nbrojAirbegova, string nboja, int nbrojVrata, bool nNavigacija, float ncena, float ngorivo, float nmaxgorivo)
{
	cena = ncena;
	gorivo = ngorivo;
	maxgorivo = nmaxgorivo;
	brojAirbegova = nbrojAirbegova;
	boja = nboja;
	brojVrata = nbrojVrata;
	Navigacija = nNavigacija;
}

Cetvorotockas::Cetvorotockas(Cetvorotockas& original)
{
	cena = original.cena;
	gorivo = original.gorivo;
	maxgorivo = original.maxgorivo;
	brojAirbegova = original.brojAirbegova;
	boja = original.boja;
	brojVrata = original.brojVrata;
	Navigacija = original.Navigacija;
}

Cetvorotockas::~Cetvorotockas()
{
	cena = 0;
	gorivo = 0;
	maxgorivo = 0;
	brojAirbegova = 0;
	boja = "";
	brojVrata = 0;
	Navigacija = false;

}

class Dvotockas : public Vozilo
{
	public:
	string tip;
	bool operator == (Dvotockas& poredjenje)
	{
		if (poredjenje.tip != tip)
			return false;

		Vozilo *objekat1 = this;
		Vozilo* objekat2 = &poredjenje;
		return (objekat1 == objekat2);
	}

	friend ostream& operator << (ostream& output, Dvotockas& primerak)
	{
		output << "Tip je " << primerak.tip << ", ";
		Vozilo* objekat = (Vozilo*)&primerak;
		output << objekat;

		return output;
	}

	friend istream& operator >> (istream& input, Dvotockas& primerak)
	{
		input >> primerak.tip;
		Vozilo *objekat = &primerak;
		input >> *objekat;

		return input;
	}
	string Gettip(void) { return tip; }
	void Settip(string novitip) { tip = novitip; }
	Dvotockas();
	Dvotockas(Dvotockas& original);
	Dvotockas(float ncena, float ngorivo, float nmaxgorivo);
	~Dvotockas();
};

Dvotockas::Dvotockas()
{
	cena = 100;
	gorivo = 100;
	maxgorivo = 100;
}

Dvotockas::Dvotockas(float ncena, float ngorivo, float nmaxgorivo)
{
	cena = ncena;
	gorivo = ngorivo;
	maxgorivo = nmaxgorivo;
}

Dvotockas::Dvotockas(Dvotockas& original)
{
	cena = original.cena;
	gorivo = original.gorivo;
	maxgorivo = original.maxgorivo;
}

Dvotockas::~Dvotockas()
{
	cena = 0;
	gorivo = 0;
	maxgorivo = 0;

}

class Automobil : public Cetvorotockas
{
	public:
		Automobil();
		Automobil(Automobil& original);
		Automobil(float ncena, float ngorivo, float nmaxgorivo);
		~Automobil();
		bool operator == (Automobil& poredjenje)
		{
			if (poredjenje.tip != tip)
				return false;

			Cetvorotockas* objekat1 = this;
			Cetvorotockas* objekat2 = &poredjenje;
			return (objekat1 == objekat2);
		}

		friend ostream& operator << (ostream& output, Automobil& primerak)
		{
			output << "Tip je " << primerak.tip << ", ";
			Cetvorotockas* objekat = (Cetvorotockas*)&primerak;
			output << objekat;

			return output;
		}

		friend istream& operator >> (istream& input, Automobil& primerak)
		{
			input >> primerak.tip;
			Cetvorotockas* objekat = &primerak;
			input >> *objekat;

			return input;
		}
		string tip;
		string Gettip(void) { return tip; }
		void Settip(string noviTip) { tip = noviTip; } /*lttstore.com*/
		void povuciRucnu();
};

Automobil::Automobil()
{
	tip = "";
	cena = 100;
	maxgorivo = 100;
}

Automobil::Automobil(float ncena, float ngorivo, float nmaxgorivo)
{
	tip = "";
	cena = ncena;
	gorivo = ngorivo;
	maxgorivo = nmaxgorivo;
}

Automobil::Automobil(Automobil& original)
{
	tip = original.tip;
	cena = original.cena;
	gorivo = original.cena;
	maxgorivo = original.maxgorivo;
}

Automobil::~Automobil()
{
	tip = "";
	cena = 0;
	gorivo = 0;
	maxgorivo = 0;
}

void Automobil::povuciRucnu(void)
{
	if (GetBrzina() == GetMinBrzina())
		return;

	SetBrzina(0);
}

class Kombi : public Cetvorotockas
{
public:
	Kombi();
	Kombi(Kombi& original);
	Kombi(float ncena, float ngorivo, float nmaxgorivo);
	~Kombi();
	bool operator == (Kombi& poredjenje)
	{
		if (poredjenje.tip != tip)
			return false;

		if (poredjenje.brojMesta != brojMesta)
			return false;

		if (poredjenje.nosivost != nosivost)
			return false;

		Cetvorotockas* objekat1 = this;
		Cetvorotockas* objekat2 = &poredjenje;
		return (objekat1 == objekat2);
	}

	friend ostream& operator << (ostream& output, Kombi& primerak)
	{
		output << "Tip je " << primerak.tip << ", ";
		Cetvorotockas* objekat = (Cetvorotockas*)&primerak;
		output << objekat;

		return output;
	}

	friend istream& operator >> (istream& input, Kombi& primerak)
	{
		input >> primerak.tip;
		Cetvorotockas* objekat = &primerak;
		input >> *objekat;

		return input;
	}
	int brojMesta;
	string tip;
	float nosivost;
	int GetbrojMesta(void) { return brojMesta; }
	string Gettip(void) { return tip; }
	float Getnosivost(void) { return nosivost; }
	void SetbrojMesta(int novibrojMesta) { brojMesta = novibrojMesta; }
	void Settip(string novitip) { tip = novitip; }
	void SetNosivost(float novanosivost) { nosivost = novanosivost; }


};

Kombi::Kombi()
{
	brojMesta = 16;
	tip = "";
	nosivost = 100;
}

Kombi::Kombi(Kombi& original)
{
	brojMesta = original.brojMesta;
	tip = original.tip;
	nosivost = original.nosivost;
}

Kombi::Kombi(float ncena, float ngorivo, float nmaxgorivo)
{
	cena = ncena;
	gorivo = ngorivo;
	maxgorivo = nmaxgorivo;
}

Kombi::~Kombi()
{
	brojMesta = 0;
	tip = "";
	nosivost = 0;
}

class Tahograf
{
public:
	Tahograf();
	Tahograf(float nbrzina, float ndistanca);
	Tahograf(Tahograf& original);
	float GetBrzina(void) { return brzina; }
	float GetDistanca(void) { return distanca; }
	void SetBrzina(float nbrzina) { brzina = nbrzina; }
	void SetDistanca(float ndistanca) { distanca = ndistanca; }
	bool operator == (Tahograf& poredjenje)
	{
		if (poredjenje.brzina != brzina)
			return false;

		if (poredjenje.distanca != distanca)
			return false;

		return true;
	}

	friend ostream& operator << (ostream& output, Tahograf& primerak)
	{
		output << "Brzina je " << primerak.brzina << ", distanca je " << primerak.distanca;

		return output;
	}

	friend istream& operator >> (istream& input, Tahograf& primerak)
	{
		input >> primerak.brzina >> primerak.distanca;
		return input;
	}
private:
	float brzina;
	float distanca;
};

Tahograf::Tahograf()
{
	brzina = 0;
	distanca = 0;
}

Tahograf::Tahograf(float nbrzina, float ndistanca)
{
	brzina = nbrzina;
	distanca = ndistanca;
}

Tahograf::Tahograf(Tahograf& original)
{
	brzina = original.brzina;
	distanca = original.distanca;
}

class Kamion : public Cetvorotockas
{
	public:
		Kamion();
		Kamion(Kamion& original);
		Kamion(float ncena, float ngorivo, float nmaxgorivo);
		~Kamion();
		float velicinaPrikolice;
		Tahograf tahograf;
		virtual void SetBrzina(float novabrzina);
		bool operator == (Kamion& poredjenje)
		{
			if (velicinaPrikolice != poredjenje.velicinaPrikolice)
				return false;

			if (!(tahograf == poredjenje.tahograf))
				return false;

			Cetvorotockas* objekat1 = this;
			Cetvorotockas* objekat2 = &poredjenje;
			return (objekat1 == objekat2);
		}

		friend ostream& operator << (ostream& output, Kamion& primerak)
		{
			output << "Tahograf: " << primerak.tahograf << " velicina prikolice je " << primerak.velicinaPrikolice;
			Cetvorotockas* objekat = (Cetvorotockas*)&primerak;
			output << objekat;

			return output;
		}

		friend istream& operator >> (istream& input, Kamion& primerak)
		{
			input >> primerak.tahograf >> primerak.velicinaPrikolice;
			Cetvorotockas* objekat = (Cetvorotockas*)&primerak;
			input >> *objekat;

			return input;
		}
};

Kamion::Kamion()
{
	velicinaPrikolice = 100;
}

Kamion::Kamion(float ncena, float ngorivo, float nmaxgorivo)
{
	cena = ncena;
	gorivo = ngorivo;
	maxgorivo = nmaxgorivo;
}

Kamion::Kamion(Kamion& original)
{
	cena = original.cena;
	gorivo = original.gorivo;
	maxgorivo = original.maxgorivo;
	tahograf = original.tahograf;
}

Kamion::~Kamion()
{
	cena = 0;
	gorivo = 0;
	maxgorivo = 0;
}

void Kamion::SetBrzina(float novabrzina)
{
	tahograf.SetBrzina(novabrzina);
}

class Motor : public Dvotockas
{
	public:
		Motor();
		Motor(Motor& original);
		Motor(float ncena, float ngorivo, float nmaxgorivo, bool nkoferi);
		~Motor();
		bool operator == (Motor& poredjenje)
		{
			if (zakljucanvolan != poredjenje.zakljucanvolan)
				return false;

			if (koferi != poredjenje.koferi)
				return false;

			Dvotockas* objekat1 = this;
			Dvotockas* objekat2 = &poredjenje;
			return (objekat1 == objekat2);
		}

		friend ostream& operator << (ostream& output, Motor& primerak)
		{
			output << (primerak.koferi ? "Ima kofere " : "Nea kofere ") << (primerak.zakljucanvolan ? "volan je zakljucan" : "nije zakljucan volan");

			return output;
		}

		friend istream& operator >> (istream& input, Motor& primerak)
		{
			input >> primerak.koferi >> primerak.zakljucanvolan;

			return input;
		}
		void SetVolanZakljucan(bool zakljucano) { zakljucanvolan = zakljucano; }
		bool GetVolanZakljucan(void) { return zakljucanvolan; }
protected:
		bool koferi; 
		bool zakljucanvolan;
};

Motor::Motor()
{
	cena = 100;
	gorivo = 100;
	maxgorivo = 100;
	koferi = false;
}

Motor::Motor(Motor& original)
{
	cena = original.cena;
	gorivo = original.gorivo;
	maxgorivo = original.maxgorivo;
	koferi = original.koferi;
}

Motor::Motor(float ncena, float ngorivo, float nmaxgorivo, bool nkoferi)
{
	cena = ncena;
	gorivo = ngorivo;
	maxgorivo = nmaxgorivo;
	koferi = nkoferi;
}

Motor::~Motor()
{
	cena = 0;
	gorivo = 0;
	maxgorivo = 0;
	koferi = false;
}

class Bicikl : public Dvotockas
{
	public:
		Bicikl();
		Bicikl(Bicikl& original);
		Bicikl(float ncena, int nvelicinaRama, int nbrojBrzina, int ndimenzijaTocka, bool inputnapumpanegume, bool inputzategnutlanac);
		~Bicikl();
		int velicinaRama;
		int brojBrzina;
		int dimezijeTocka;
		bool napumpanegume;
		bool zategnutlanac;
		bool operator == (Bicikl& poredjenje)
		{

			Dvotockas* objekat1 = this;
			Dvotockas* objekat2 = &poredjenje;
			return (objekat1 == objekat2);
		}

		friend ostream& operator << (ostream& output, Bicikl& primerak)
		{
			output << "Velicina rama je " << primerak.velicinaRama << ", broj brzina je " <<
				primerak.brojBrzina << ", dimenzije tocka su " << primerak.dimezijeTocka;
			Dvotockas* objekat = (Dvotockas*)&primerak;
			output << objekat;

			return output;
		}

		friend istream& operator >> (istream& input, Bicikl& primerak)
		{
			input >> primerak.tip;
			Cetvorotockas* objekat = (Cetvorotockas*)&primerak;
			input >> *objekat;

			return input;
		}
		int GetvelicinaRama(void) { return velicinaRama; }
		int GetbrojBrzina(void) { return brojBrzina; }
		int GetdimezijeTocka(void) { return dimezijeTocka; }
		void SetvelicinaRama(int novaVelicinaRama) { velicinaRama = novaVelicinaRama; }
		void SetbrojBrzina(int novibrojBrzina) { brojBrzina = novibrojBrzina; }
		void SetdimenzijeTocka(int novedimezijeTocka) { dimezijeTocka = novedimezijeTocka; }
		bool NapumpaneGume(void) { return napumpanegume; }
		bool ZategnutLanac(void) { return zategnutlanac; }
		void napumpajGume();
		void zategniLanac();
};

Bicikl::Bicikl()
{
	cena = 100;
	velicinaRama = 0;
	brojBrzina = 0;
	dimezijeTocka = 0;
	napumpanegume = true;
	zategnutlanac = true;
}

Bicikl::Bicikl(float ncena, int nvelicinaRama, int nbrojBrzina, int ndimenzijaTocka, bool inputnapumpanegume, bool inputzategnutlanac)
{
	cena = ncena;
	velicinaRama = nvelicinaRama;
	brojBrzina = nbrojBrzina;
	dimezijeTocka = ndimenzijaTocka;
	napumpanegume = inputnapumpanegume;
	zategnutlanac = inputzategnutlanac;
}

Bicikl::Bicikl(Bicikl& original)
{
	cena = original.cena;
	velicinaRama = original.velicinaRama;
	brojBrzina = original.brojBrzina;
	dimezijeTocka = original.dimezijeTocka;
	napumpanegume = original.napumpanegume;
	zategnutlanac = original.zategnutlanac;
}

Bicikl::~Bicikl()
{
	cena = 0;
	velicinaRama = 0;
	brojBrzina = 0;
	dimezijeTocka = 0;
}

class Prodavac : public Osoba
{
public:
	Prodavac();
	Prodavac(int inputpozitivnarecepcija,
		int inputnegativnarecepcija);
	Prodavac(Prodavac& original);
	~Prodavac();
	int GetBrojKupaca(void);
	Kupac* GetKupac(Kupac* kupac);
	void DodajKupca(Kupac* kupac);
	void IzbaciKupca(Kupac* kupac);
	int GetBrojPonuda(void);
	bool DaLiJeDobarProdavac(void)
	{
		return (pozitivnarecepcija > negativnarecepcija);
	}
	Vozilo* GetPonuda(int ponuda) { return ponude[ponuda]; }
	void DodajPonudu(Vozilo *ponuda);
	void IzbaciPonudu(Vozilo *ponuda);
	void Prodaj(Kupac* kupac, Vozilo *ponuda);
	bool operator == (Prodavac& poredjenje)
	{
		if (poredjenje.pozitivnarecepcija != pozitivnarecepcija)
			return false;

		if (poredjenje.negativnarecepcija != negativnarecepcija)
			return false;

		if (listakupaca != poredjenje.listakupaca)
			return false;

		if (ponude != poredjenje.ponude)
			return false;

		Osoba* objekat1 = this;
		Osoba* objekat2 = &poredjenje;
		return (objekat1 == objekat2);
	}

	friend ostream& operator << (ostream& output, Prodavac& primerak)
	{
		ListaKupaca* temp = primerak.listakupaca;
		while (temp)
		{
			output << temp->kupac;
			temp = temp->next;
		}
		for (int i = 0; i < sizeof(primerak.ponude) / sizeof(primerak.ponude[0]); i++)
			output << primerak.ponude[i];
		Osoba* objekat = (Osoba*)&primerak;
		output << objekat;

		return output;
	}

	friend istream& operator >> (istream& input, Prodavac& primerak)
	{
		input >> primerak.pozitivnarecepcija >> primerak.negativnarecepcija;
		Osoba* objekat = (Osoba*)&primerak;
		input >> *objekat;

		return input;
	}
private:
	ListaKupaca* listakupaca;
	Vozilo *ponude[PRODAVAC_MAX_VOZILA];
	int pozitivnarecepcija;
	int negativnarecepcija;
};

Prodavac::Prodavac()
{
	listakupaca = new ListaKupaca;
	pozitivnarecepcija = 0;
	negativnarecepcija = 0;
}

Prodavac::Prodavac(int inputpozitivnarecepcija,
	int inputnegativnarecepcija)
{
	pozitivnarecepcija = inputpozitivnarecepcija;
	negativnarecepcija = inputnegativnarecepcija;
	listakupaca = new ListaKupaca;
}

Prodavac::Prodavac(Prodavac& original)
{
	listakupaca = original.listakupaca;
	pozitivnarecepcija = original.pozitivnarecepcija;
	negativnarecepcija = original.negativnarecepcija;
}

Prodavac::~Prodavac()
{
	delete listakupaca;
	listakupaca = NULL;
	pozitivnarecepcija = 0;
	negativnarecepcija = 0;
}

Kupac* Prodavac::GetKupac(Kupac* kupac)
{
	ListaKupaca* temp = listakupaca;
	while (temp)
	{
		if (temp->kupac == kupac)
			return kupac;

		temp = temp->next;
	}

	return NULL;
}

void Prodavac::DodajKupca(Kupac* kupac)
{
	ListaKupaca* temp = listakupaca;
	while (temp->kupac)
	{
		if (!temp->next)
			temp->next = new ListaKupaca;

		temp = temp->next;
	}
	temp->kupac = kupac;
}

void Prodavac::IzbaciKupca(Kupac* kupac)
{
	ListaKupaca* temp = listakupaca;
	while (temp)
	{
		if (temp->kupac == kupac)
		{
			ListaKupaca* temp2 = listakupaca;
			while (temp2)
			{
				if (temp2->next == temp)
				{
					temp2->next = temp->next;
					delete temp;
					temp = NULL;
					break;
				}
				temp2 = temp2->next;
			}
		}
		temp = temp->next;
	}
}

int Prodavac::GetBrojPonuda(void)
{
	return(sizeof(ponude) / sizeof(ponude[0]));
}

void Prodavac::Prodaj(Kupac* kupac, Vozilo *ponuda)
{
	IzbaciKupca(kupac);
	for (int i = 0; i < PRODAVAC_MAX_VOZILA; i++)
	{
		if (ponude[i] && ponude[i] == ponuda)
		{
			delete ponude[i];
			ponude[i] = NULL;
			break;
		}
	}
}

class Reklamacija
{
public:
	Reklamacija();
	Reklamacija(int nbrojProblema, string nproblem, string ndatumgarancije);
	Reklamacija(Reklamacija& original);
	~Reklamacija();
	int brojProblema;
	string problem;
	string datumgarancije;
	int GetbrojProblema(void) { return brojProblema; }
	string GetProblem(void) { return problem; }
	string Getdatumgarancije(void) { return datumgarancije; }
	void SetbrojProblema(int novibrojProblema) { brojProblema = novibrojProblema; }
	void SetProblem(string noviProblem) { problem = noviProblem; }
	void Setdatumgarancije(string novidatumgarancije) { datumgarancije = novidatumgarancije; }
	bool operator == (Reklamacija& poredjenje)
	{
		if (poredjenje.brojProblema != brojProblema)
			return false;

		if (poredjenje.problem != problem)
			return false;

		if (poredjenje.datumgarancije != datumgarancije)
			return false;

		return true;
	}

	friend ostream& operator << (ostream& output, Reklamacija& primerak)
	{
		output << "Broj problema je " << primerak.brojProblema << ", problem je " << primerak.problem <<
			", datum garancije je " << primerak.datumgarancije;

		return output;
	}

	friend istream& operator >> (istream& input, Reklamacija& primerak)
	{
		input >> primerak.brojProblema >> primerak.problem >> primerak.datumgarancije;

		return input;
	}


	void reklamirajVozilo()
	{
		brojProblema++;
	}
};

// al nije on uvek u pravu
class Kupac : public Osoba
{
public:
	Kupac();
	Kupac(Kupac& original);
	Kupac(string inputadresa, string inputemail);
	~Kupac();
	string GetEmail(void) { return email; }
	void SetEmail(string nemail) { email = nemail; }
	StanjeRacuna GetStanjeRacuna(void) { return stanjeracuna; }
	void SetStanjeRacuna(StanjeRacuna stanje) { stanjeracuna = stanje; }
	string GetAdresa(void) { return adresa; }
	void SetAdresa(string nadresa) { adresa = nadresa; }
	int GetPlatniRacun(void) { return platniracun; }
	void SetPlatniRacun(int nplatniracun) { platniracun = nplatniracun; }
	bool operator == (Kupac& poredjenje)
	{
		if (poredjenje.email != email)
			return false;

		if (poredjenje.stanjeracuna != stanjeracuna)
			return false;

		if (poredjenje.adresa != adresa)
			return false;

		if (poredjenje.platniracun != platniracun)
			return false;

		Osoba* objekat1 = this;
		Osoba* objekat2 = &poredjenje;
		return (objekat1 == objekat2);
	}

	friend ostream& operator << (ostream& output, Kupac& primerak)
	{
		output << "E-mail je " << primerak.email << ", stanje racuna: ";
		string stanjeracunastring;
		switch (primerak.stanjeracuna)
		{
		case STANJE_NORMALNO:
			stanjeracunastring = "normalno";
			break;
		case STANJE_ZAKLJUCANO:
			stanjeracunastring = "zakljucano";
			break;
		case STANJE_ISCEKIVAJUCE:
			stanjeracunastring = "iscekivanje";
			break;
		default:
			stanjeracunastring = "";
			break;
		}
		output << stanjeracunastring << ", adresa je" << primerak.adresa << ", platni racun je " << primerak.platniracun;
		Cetvorotockas* objekat = (Cetvorotockas*)&primerak;
		output << objekat;

		return output;
	}

	friend istream& operator >> (istream& input, Kupac& primerak)
	{
		input >> primerak.email >> primerak.adresa >> primerak.platniracun;
		int inputzaenum;
		do
		{
			input >> inputzaenum;
		} while (inputzaenum < 0 || inputzaenum > 2);
		primerak.stanjeracuna = (StanjeRacuna)inputzaenum;
		Cetvorotockas* objekat = (Cetvorotockas*)&primerak;
		input >> *objekat;

		return input;
	}
private:
	string email;	//molim vas ne gledajte moj
	StanjeRacuna stanjeracuna;
	string adresa;
	int platniracun;
protected:
	Reklamacija reklamacija;
};

Reklamacija::Reklamacija()
{
	brojProblema = 0;
	problem = "";
	datumgarancije = "";
}
Reklamacija::Reklamacija(int nbrojProblema, string nproblem, string ndatumgarancije)
{
	brojProblema = nbrojProblema;
	problem = nbrojProblema;
	datumgarancije = ndatumgarancije;
}

Reklamacija::Reklamacija(Reklamacija& original)
{
	brojProblema = original.brojProblema;
	problem = original.problem;
	datumgarancije = original.datumgarancije;
}
Reklamacija::~Reklamacija()
{
	brojProblema = 0;
	problem = "";
	datumgarancije = "";
}

Kupac::Kupac()
{
	email = "";
	stanjeracuna = STANJE_NORMALNO;
	adresa = "";
	platniracun = 0;
}

Kupac::Kupac(string inputadresa, string inputemail)
{
	adresa = inputadresa;
	email = inputemail;
	stanjeracuna = STANJE_NORMALNO;
	platniracun = 0;
}

Kupac::Kupac(Kupac& original)
{
	email = original.email;
	stanjeracuna = original.stanjeracuna;
	adresa = original.adresa;
	platniracun = original.platniracun;
}

Kupac::~Kupac()
{
	email = "";
	stanjeracuna = STANJE_ZAKLJUCANO;
	adresa = "";
	platniracun = 0;
}

class Racun
{
    public:
		virtual float GetIznos(void) = 0;
		virtual void SetIznos(float noviIznos) { iznos = noviIznos; }
		bool operator == (Racun& poredjenje)
		{
			if (iznos != poredjenje.iznos)
				return false;

			if (placanje != poredjenje.placanje)
				return false;

			return true;
		}

		friend ostream& operator << (ostream& output, Racun& primerak)
		{
			output << "Iznos je " << primerak.iznos << ", nacin placanja je ";
			string nacinstring;
			switch (primerak.placanje)
			{
			case NACIN_KES:
				nacinstring = "kes";
				break;
			case NACIN_KREDIT:
				nacinstring = "kredit";
				break;
			case NACIN_LIZING:
				nacinstring = "lizing";
				break;
			default:
				nacinstring = "";
				break;
			}

			return output;
		}

		friend istream& operator >> (istream& input, Racun& primerak)
		{
			int inputzaenum;
			do
			{
				input >> inputzaenum;

			} while (inputzaenum < 0 || inputzaenum > 2);
			primerak.placanje = (nacinPlacanja)inputzaenum;
			input >> primerak.iznos;

			return input;
		}
    protected:
	float iznos;
	nacinPlacanja placanje;
};

class dodatnaOprema
{
    public:
	dodatnaOprema();
	dodatnaOprema(dodatnaOprema& original);
	dodatnaOprema(float ncena, Oprema ntip, nivoOpreme nnivo);
	~dodatnaOprema();
	Oprema Gettip(void) { return tip; }
	nivoOpreme Getnivo(void) { return nivo; }
	float Getcena(void) { return cena; }
	void Settip(Oprema novitip) { tip = novitip; }
	void Setnivo(nivoOpreme noviNivo) { nivo = noviNivo; }
	void Setcena(float novaCena) { cena = novaCena; }
	bool operator == (dodatnaOprema& poredjenje)
	{
		if (tip != poredjenje.tip)
			return false;

		if (nivo != poredjenje.nivo)
			return false;

		if (cena != poredjenje.cena)
			return false;

		return true;
	}

	friend ostream& operator << (ostream& output, dodatnaOprema& primerak)
	{
		string tipstring;
		switch (primerak.tip)
		{
		case OPREMA_LICNA:
			tipstring = "licna";
			break;
		case OPREMA_ZAVOZILO:
			tipstring = "za vozilo";
			break;
		default:
			tipstring = "";
			break;
		}

		output << "Tip je " << tipstring << ", nivo je " << primerak.nivo << ", cena je " << primerak.cena;

		return output;
	}

	friend istream& operator >> (istream& input, dodatnaOprema& primerak)
	{
		int inputzaenum;
		do
		{
			input >> inputzaenum;
		} while (inputzaenum < 0 || inputzaenum > 2);
		primerak.tip = (Oprema)inputzaenum;
		do
		{
			input >> inputzaenum;
		} while (inputzaenum < 0 || inputzaenum > 4);
		primerak.nivo = (nivoOpreme)inputzaenum;
		input >> primerak.cena;

		return input;
	}
	Oprema tip;
	nivoOpreme nivo;
	float cena;

};
dodatnaOprema::dodatnaOprema()
{
	tip = OPREMA_LICNA;
	nivo = NIVO_1;
	cena = 100;
}

dodatnaOprema::dodatnaOprema(float ncena, Oprema ntip, nivoOpreme nnivo)
{
	cena = ncena;
	tip = ntip;
	nivo = nnivo;
}

dodatnaOprema::dodatnaOprema(dodatnaOprema& original)
{
	cena = original.cena;
	tip = original.tip;
	nivo = original.nivo;
}

dodatnaOprema::~dodatnaOprema()
{
	cena = 0;
	tip = OPREMA_LICNA;
	nivo = NIVO_0;
}

class Yugo : public Cetvorotockas
{
public:
	Yugo();
	Yugo(float ncena, float ngorivo, float nmaxgorivo, int nairbegovi, string nboja, int nbrojvrata, bool nnavigacija);
	Yugo(Yugo& original);
	~Yugo();
};

Yugo::Yugo()
{
	cena = CENA_YUGO;
	gorivo = 60;
	maxgorivo = GORIVO_YUGO;
	brojAirbegova = AIRBEGOVI_YUGO;
	boja = "bijela";
	brojVrata = YUGO_VRATA;
	Navigacija = YUGO_NAVIGACIJA;
}

Yugo::Yugo(float ncena, float ngorivo, float nmaxgorivo, int nairbegovi, string nboja, int nbrojvrata, bool nnavigacija)
{
	cena = ncena;
	gorivo = ngorivo;
	maxgorivo = nmaxgorivo;
	brojAirbegova = nairbegovi;
	boja = nboja;
	brojVrata = nbrojvrata;
	Navigacija = nnavigacija;
}

Yugo::Yugo(Yugo& original)
{
	cena = original.cena;
	gorivo = original.gorivo;
	maxgorivo = original.maxgorivo;;
	brojAirbegova = original.brojAirbegova;
	boja = original.boja;
	brojVrata = original.brojVrata;
	Navigacija = original.Navigacija;
}

Yugo::~Yugo()
{
	cena = 0;
	gorivo = 0;
	maxgorivo = 0;
	brojAirbegova = 0;
	boja = "";
	brojVrata = 0;
	Navigacija = false;
}


int main()
{
	//nea te
}
