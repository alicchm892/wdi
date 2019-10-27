#include <iostream>
using namespace std;

int szukaj(int l, int r, int szukana, int tab[]) // wyszukiwanie binarne (iteracyjnie)
{
	int sr;
	while (l <= r)
	{
		sr = (r + l) / 2; // indeks elementu srodkowego przeszukiwanej tablicy

		if (szukana == tab[sr])
			return sr;

		if (szukana < tab[sr])
		{
			r = sr - 1;
		}
		else 
			l = sr + 1;
	}
	return -1; //jesli szukanego elementu nie ma w tablicy to zwroc -1
}


int szukaj_r(int l, int r, int szukana, int tab[]) // wyszukiwanie binarne (rekurencyjnie)
{
	if (l > r) // jesli szukanej liczby nie ma w tablicy to zakoncz i zwroc -1
		return -1;

	int sr = (r + l) / 2;

	if (szukana == tab[sr])
		return sr;

	if (szukana < tab[sr])
		szukaj_r(l, sr - 1, szukana, tab); //przeszukuje lewa strone tablicy
	else
		szukaj_r(sr + 1, r, szukana, tab); //przeszukuje prawa strone tablicy
}


int main()
{
	int const n = 7; // n - liczba elementów tablicy
	int tab[n]; // tab - tablica o liczbie elementów n

	for (int i = 0; i < n; i++) //uzupelnienie tablicy posortowanymi liczbami
	{
		tab[i] = i+1;
	}

	for (int i = 0; i < n; i++) //wypisanie tablicy
	{
		cout << tab[i] << " ";
	}
	cout << endl;

	int szukana;
	cout << "podaj szukana liczbe: ";
	cin >> szukana;

	//do rozwiazania iteracyjnego
	int nr_indeksu;
	nr_indeksu = szukaj(0,n-1,szukana,tab);

	if (nr_indeksu == -1)
		cout << "nie ma takiej liczby w tablicy" << endl;
	else
		cout << "nr indeksu szukanej liczby: " << nr_indeksu << endl;

	//do rozwiazania rekurencyjnego
	int nr_indeksu_r;
	nr_indeksu_r = szukaj_r(0, n - 1, szukana, tab);

	if (nr_indeksu_r == -1)
		cout << "nie ma takiej liczby w tablicy" << endl;
	else
		cout << "nr indeksu szukanej liczby: " << nr_indeksu_r << endl;


	system("pause");
	return 0;
}

//http://cpp.sh/
//http://www.algorytm.edu.pl/algorytmy-maturalne/wyszukiwanie-binarne.html
