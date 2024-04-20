#include <iostream>
#include <vector>
using namespace std;


template <int stopien>
class Polynomial
{
public:

	Polynomial(vector <double> wsp):m_wspolczynniki(wsp){}
	~Polynomial(){}

	double calculate(double x);

	template<int stopien2>
	Polynomial<max(stopien, stopien2)> operator+(const Polynomial<stopien2>& other) const;
	template<int stopien2>
	Polynomial<max(stopien, stopien2)> operator-(const Polynomial<stopien2>& other) const;
	Polynomial<stopien> operator*(double stala) const;

	vector <double> m_wspolczynniki;
private:
	

};

template<int stopien>
template<int stopien2>
inline Polynomial<max(stopien, stopien2)> Polynomial<stopien>::operator+(const Polynomial<stopien2>& other) const
{
	int ws1 = m_wspolczynniki.size();
	int ws2 = other.m_wspolczynniki.size();
	int ws3 = abs(ws1 - ws2);
	int st = max(ws1, ws2);
	vector <double> wsp_wynik(st);

	int i1 = 0;
	int i2 = 0;
	int i = 0;
	if (ws1 > ws2)
	{
		while (ws3 > 0)
		{
			wsp_wynik[i] = m_wspolczynniki[i];
			i++;
			ws3--;
		}
		i1 = i;
	}
	else if (ws2 > ws1)
	{
		while (ws3 > 0)
		{
			wsp_wynik[i] = other.m_wspolczynniki[i];
			i++;
			ws3--;
		}
		i2 = i;
	}
	ws3 = max(ws2, ws1);
	while (i < ws3)
	{
		wsp_wynik[i] = m_wspolczynniki[i1] + other.m_wspolczynniki[i2];
		i++;
		i1++;
		i2++;
	}
	return Polynomial<max(stopien, stopien2)>(wsp_wynik);
}

template<int stopien>
template<int stopien2>
inline Polynomial<max(stopien,stopien2)> Polynomial<stopien>::operator-(const Polynomial<stopien2>& other) const
{
	int ws1 = m_wspolczynniki.size();
	int ws2 = other.m_wspolczynniki.size();
	int ws3 = abs(ws1 - ws2);
	int st = max(ws1,ws2);
	vector <double> wsp_wynik(st);

	int i1 = 0;
	int i2 = 0;
	int i = 0;
	if (ws1 > ws2)
	{
		while (ws3>0)
		{
			wsp_wynik[i] = m_wspolczynniki[i];
			i++;
			ws3--;
		}
		i1 = i;
	}
	else if (ws2 > ws1)
	{
		while (ws3>0)
		{
			wsp_wynik[i] = other.m_wspolczynniki[i];
			i++;
			ws3--;
		}
		i2 = i;
	}
	ws3 = max(ws2, ws1);
	while(i<ws3)
	{
		wsp_wynik[i] = m_wspolczynniki[i1] - other.m_wspolczynniki[i2];
		i++;
		i1++;
		i2++;
	}
	return Polynomial<max(stopien, stopien2)>(wsp_wynik);
}

template<int stopien>
Polynomial<stopien> Polynomial<stopien>::operator*(double stala) const
{
	vector<double> wsp_wynikowe(m_wspolczynniki);
	for (int i = 0; i < stopien + 1; i++)
	{
		wsp_wynikowe[i] *= stala;
	}
	return Polynomial<stopien>(wsp_wynikowe);
}


template<int stopien>
double Polynomial<stopien>::calculate(double x)
{
	double wynik = 0;
	int pot = stopien;
	for (int i = 0; i < stopien + 1; i++)
	{
		wynik += pow(x, pot) * m_wspolczynniki[i];
		pot--;
	}

	return wynik;
}

