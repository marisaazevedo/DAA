#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

int generation(string matricula) {
    int cases =  10 * 10 * 10 * 10 * 23 * 23;

	if (isalpha(matricula[0])) {
		if (isalpha(matricula[7])) return cases * 3; // Geração 4
		else return 0; // Geração 1
	}
	else {
		if (isalpha(matricula[7])) return cases * 1; // Geração 2
		else return cases * 2 ; // Geração 3
	}
}

int solve(string matricula) {
	int base = 1;
	int difference = generation(matricula);

	for (int i = 7; i >= 0; i--) {
		if (isdigit(matricula[i])) {
			difference += (matricula[i] - '0') * base ;
			base *= 10;
		}
	}
	for (int i = 7; i >= 0; i--) {
		if (isalpha(matricula[i])) {
			int value = matricula[i] - 'A';
			if (matricula[i] > 'K') value--;
			if (matricula[i] > 'W') value--;
			if (matricula[i] > 'Y') value--;
			difference += value * base;
			base *= 23;
		}
	}
	return difference;
}

int main() {
    int T;
    string matricula_1, matricula_2;
    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> matricula_1 >> matricula_2;
        cout << abs(solve(matricula_2) - solve(matricula_1)) << endl;
    }
}
