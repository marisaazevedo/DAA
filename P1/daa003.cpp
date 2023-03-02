#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int diferenca_matriculas(string m1, string m2) {
    int diferenca = 0;
    if(geracao(m1) == geracao(m2)) {

    }
    return diferenca;
}

int geracao(matricula) {
    if(isalpha(matricula[0]) && isalpha(matricula[1]) && isdigit(matricula[3]) && isdigit(matricula[4]) && isdigit(matricula[6]) && isdigit(matricula[7])) {
        return 1;
    }
    else if(isdigit(matricula[0]) && isdigit(matricula[1]) && isdigit(matricula[3]) && isdigit(matricula[4]) && isalpha(matricula[6]) && isalpha(matricula[7])) {
        return 2;
    }
    else if(isdigit(matricula[0]) && isdigit(matricula[1]) && isalpha(matricula[3]) && isalpha(matricula[4]) && isdigit(matricula[6]) && isdigit(matricula[7])) {
        return 3;
    }
    else {
        return 4;
    }
}

int main() {
    int T;
    string matricula_1, matricula_2;
    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> matricula_1 >> matricula_2;
        cout << diferenca_matriculas(matricula_1, matricula_2) << endl;
    }
}
