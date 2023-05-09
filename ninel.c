#include <stdio.h>

#define MAXX 1000000
//Definim inaltimea maxima a unui copac (care nu poate fi atinsa).

int main(void)
{
	int N, copac_pred, copac, copac_succ;
/*N - numarul copacilor
copac - inaltimea copacului testat pentru a fi verificat daca este special
copac_pred && copac_succ - inaltimile copacilor adiacenti celui testat*/

	int xmax_impar = -1, xmin_par = MAXX;
/*xmax_impar ia valoarea -1 din doua motive:
-Daca un copac este special, atunci inaltimea sa va fi cu siguranta mai mare.
-Daca nu exista niciun copac special cu indice impar,
dar exista copaci speciali, semnaleaza acest lucru.
xmin_par ia valoare MAXX, cum MAXX > orice inaltime.
Daca nu exista un copac special cu indice par, dar exista copaci speciali,
atunci (!).*/

	double m_a, cnt = 0;
	long S;
/*Restul variabilelor:
S - suma inaltimilor copacilor speciali
m_a - media aritmetica a inaltimilor copacilor speciali
cnt - numarul copacilor speciali (double pentru a simplifica calculul m_a)
Am optat pentru double in loc de float,
pentru a asigura o buna functionare a programului.*/

	S *= 0;
/*Checker-ul considera long S ca fiind o variabila globala.
Daca nu initializam S = 0 pot aparea probleme.
Este un work-around.*/

	scanf("%d", &N);
	scanf("%d %d", &copac_pred, &copac);
/*Citim numarul copacilor si inaltimile primilor 2 copaci.
Primul copac nu poate fi special, deci nu va fi testat.*/

	for (int i = 1; i < N - 1; ++i) {
		scanf("%d", &copac_succ);
		if (copac > copac_pred && copac > copac_succ) {
			S += copac;
			++cnt;
			if (i % 2 == 1 && copac > xmax_impar)
				xmax_impar = copac;
			if (i % 2 == 0 && copac < xmin_par)
				xmin_par = copac;
		}
		copac_pred = copac;
		copac = copac_succ;
	}
/*Algoritmul este descris in README.
Al (n-1)-lea copac este ultimul copac si deci nu poate fi testat.*/

	if (xmin_par == MAXX)
		xmin_par = -1;
/*(!) Daca nu exista copac special cu indice par,
dar exista copaci speciali, ramane MAXX.
Il schimbam in -1, pentru a semnala acest lucru.*/

	if (cnt == 0) {
		S = 0;
		m_a = 0;
		xmax_impar = 0;
		xmin_par = 0;
	} else {
		m_a = S / cnt;
	}
/*Daca cnt  == 0, atunci nu exista copaci speciali,
si deci toate variabilele cautate sunt 0.
Astfel ne asiguram si ca m_a nu se calculeaza impartind la 0.*/

	printf("%ld\n%.7lf\n%d\n%d\n", S, m_a, xmax_impar, xmin_par);
//Afisam variabilele calculate.

	return 0;
}
