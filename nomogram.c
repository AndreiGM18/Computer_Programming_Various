#include <stdio.h>

#define MAXX 100
//Definim numarul maxim de linii/coloane.

void read_matrix(int r,  int c, int v[MAXX][MAXX])
{
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			scanf("%d", &v[i][j]);
}

//Functie de citire a unei matrici

int sum_one_read(int n_steps)
{
	int x, S = 0;
	while (n_steps) {
		scanf("%d", &x);
		S += x;
		--n_steps;
	}
	return S;
}

//Functie prin care citim un numar n_steps de numere si calculam suma lor

void check_nono(int num)
{
	while (num) {
		int N, M, a[MAXX][MAXX] = {0};
		int n_groups, sum_r[MAXX] = {0}, sum_c[MAXX] = {0};
		int p = 1;
/*N - numarul de linii
M - numarul de coloane
a - grid-ul completat de Gigel
n_groups - numarul de grupuri colorate de pe o linie/coloana
sum_r - suma dimensiunile grupurilor colorate de pe o linie
sum_c - suma dimensiunile grupurilor colorate de pe o coloana
p - variabila de adevar*/

		scanf("%d %d", &N, &M);
//Citim numarul de linii si de coloane.

		for (int r = 0; r < N; ++r) {
			scanf("%d", &n_groups);
			sum_r[r] = sum_one_read(n_groups);
		}
//Calculam sumele dimensiunilor grupurilor colorate de pe fiecare linie.

		for (int c = 0; c < M; ++c) {
			scanf("%d", &n_groups);
			sum_c[c] = sum_one_read(n_groups);
		}
//Calculam sumele dimensiunilor grupurilor colorate de pe fiecare coloana.

		read_matrix(N, M, a);
//Citim grid-ul.

		int S_r, S_c, r = 0, c = 0;

		while ((p == 1) && (r < N || c < M)) {
			S_r = 0;

			for (int i = 0; i < M; ++i)
				S_r += a[r][i];

			if (S_r != sum_r[r])
				p = 0;

			++r;

			S_c = 0;

			for (int i = 0; i < N; ++i)
				S_c += a[i][c];

			if (S_c != sum_c[c])
				p = 0;

			++c;
			}
/*Calculam suma elementelor de pe o linie/coloana a grid-ului.
Verificam daca este egala cu suma liniei/coloanei respective calculata anterior.
Daca nu este sau daca depasim max(N, M) - 1, ne oprim.
Vectorii si matricea au fost initializate cu 0.
Astfel, daca depasim min(N, M) - 1, sumele "goale" ar fi 0.
S_r == sum_r[r]/S_c == sum_c[c] se respecta cand depasim min(N, M) - 1.*/

		p == 1 ? printf("Corect\n") : printf("Eroare\n");
//Afisam daca grid-ul este completat corect sau nu.

		--num;
	}
}

//Functie care verifica un numar num de puzzle-uri.

int main(void)
{
	int T;

	scanf("%d", &T);
//Citim numarul de puzzle-uri.

	check_nono(T);
//Verificam cele T puzzle-uri.

	return 0;
}
