#include <iostream>
#include<tuple>

using namespace std;

int main() {
    int n, numero, n_pergunta, pergunta;
    cin >> n;
    int numeros[n];

    for(int i = 0; i < n; i++) {
        cin >> numero;
        numeros[i] = numero;
    }

    cin >> n_pergunta;
    int perguntas[n_pergunta];

    for(int i = 0; i < n_pergunta; i++) {
        cin >> pergunta;
        perguntas[i] = pergunta;
    }

}
