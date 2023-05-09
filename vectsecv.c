#include <stdio.h>

#define MAXX 100
//Definim numarul maxim de pasi pe care ii putem face pana la gasirea perioadei.

void select_sort_d(int length, int v[10])
{
	int i, j;

	for (i = 0 ; i < length - 1 ; ++i) {
		for (j = i + 1 ; j < length ; ++j) {
			if (v[i] < v[j]) {
				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
}

//Functie de sortare a unui vector prin selectie

int sort_desc(int x)
{
	int v[10], cnt = 0;

	while (x) {
		v[cnt] = x % 10;
		cnt++;
		x /= 10;
	}

//Salvam cifrele numarului intr-un vector.

	select_sort_d(cnt, v);
//Sortam vectorul.

	for (int i = 0; i < cnt; ++i)
		x = x * 10 + v[i];
//Refacem numarul.

	return x;
}

//Functie prin care se ordoneaza descrescator cifrele unui numar

int mirror(int x)
{
	int o = 0;

	while (x) {
		o = o * 10 + x % 10;
		x /= 10;
	}

	return o;
}

/*Functie prin care se face oglinditul unui numar
Daca numarul este de forma a0, oglinditul sau este a.
Daca numarul este de forma ab0, oglinditul sau este ba.
Analog pentru numere cu mai multe cifre.*/

int main(void)
{
	int N, p = 1, step = 1, v[MAXX];
/*N - numarul dat
p - variabila de adevar
step - pasul curent
v -vectorul in care salvam secventa de diferente*/

	scanf("%d", &N);
//Citim numarul dat.

	v[0] = sort_desc(N) - mirror(sort_desc(N));

	while (p) {
		v[step] = sort_desc(v[step - 1]) - mirror(sort_desc(v[step - 1]));

		for (int k = 0; k < step; ++k) {
			if (v[k] == v[step]) {
				printf("%d\n", k);
				for (int j = k; j < step; ++j)
					printf("%d ", v[j]);
				printf("\n");
				p = 0;
			}
		}
		++step;
	}
//Algoritmul este descris in README.

	return 0;
}
