#include <stdio.h>

#define MAXX 100
//Numarul maxim de materii

void read_vect(int length, int v[MAXX])
{
	for (int i = 0; i < length; ++i)
		scanf("%d", &v[i]);
}

//Functie de citire a unui vector

void special_sort(int length, int v[MAXX], int w[MAXX])
{
	int i, j;

	for (i = 0 ; i < length; ++i) {
		for (j = i + 1 ; j < length; ++j) {
			if (((10 - v[i]) * w[i]) < ((10 - v[j]) * w[j])) {
				int aux;
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				aux = w[i];
				w[i] = w[j];
				w[j] = aux;
			}
		}
	}
}

//Algoritmul de sortare speciala descris in README.

int main(void)
{
	int N, nota[MAXX], credite[MAXX], P = 0, p_min, m = 0;
/*N - numarul de materii
nota - vector in care salvam notele
credite - vector in care salvam numarul de credite pentru fiecare materie
P - punctajul
p_min - punctajul minim*/

	scanf("%d", &N);
//Citim numarul de materii.

	read_vect(N, nota);
//Citim notele.

	read_vect(N, credite);
//Citim creditele asociate fiecarei materii.

	scanf("%d", &p_min);
//Citim p_min.

	for (int i = 0; i < N; ++i)
		P += nota[i] * credite[i];
//Calculam P.

	special_sort(N, nota, credite);
//Algoritmul de sortare speciala descris in README

	int stop = N - 1;

	while (nota[stop] == 10)
		--stop;
//Calculam indicele de la care in vectorul nota se gaseste doar 10.

	while (P < p_min && m <= stop) {
		P += credite[m] * (10 - nota[m]);
		m++;
	}
//Algoritmul este descris in README.

	P >= p_min ? printf("%d\n", m) : printf("-1\n");
//Afisam m sau -1 daca problema nu are solutie.

	return 0;
}
