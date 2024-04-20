#include <iostream>
#include "Polynomial.h"
using namespace std;

template <int stopien>
void printPolynomial(const Polynomial<stopien>& poly)
{
	int wsp = 0;
	for (int i = stopien; i > 0; i--)
	{
        if (poly.m_wspolczynniki[wsp] != 0)
        {
            if (poly.m_wspolczynniki[wsp] != 1) cout << poly.m_wspolczynniki[wsp];
            cout << "x^" << i << " + ";
        }
        wsp++;
	}
	cout << poly.m_wspolczynniki[wsp] << endl;
}

int main()
{
    Polynomial<3> poly1({ 1, 2, 3, 4 }); // x^3 + 2x^2 + 3x + 4
    Polynomial<2> poly2({ -1, 0, 1 }); // -x^2 + 1

    auto sum = poly1 + poly2;
    std::cout << "Suma wielomianow: ";
    printPolynomial(sum);
    auto diff = poly1 - poly2;
    cout << "Roznica wielomianow: ";
    printPolynomial(diff);
    double sc = 2;
    auto scaled = poly1 * sc; 
    cout << "Wielomian pomnozony przez 2: ";
    printPolynomial(scaled);
    double x = 2;
    cout << "Wartosc wielomianu dla x = " << x << ": " <<
        poly1.calculate(x) << std::endl;
    return 0;
}