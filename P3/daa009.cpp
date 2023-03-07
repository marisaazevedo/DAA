#include <iostream>
#include <string>
#include<set>

using namespace std;

int contagem(string dna, int n) {
    set<char> visitados;

    for(int i = 0; i < n; i++) {
        if(visitados.find(dna[i])) {
            continue;
        }
        visitados.insert(dna[i]);
        int contador = 0;
        for(int j = i + 1; j < n; j++) {
            if (dna[i] == dna[i]) {
                contador++;
            }
        }
        cout << dna[i], contador << endl;
    }
    return 0;
}

using namespace std;

int main() {
    string dna;
    cin >> dna;
    contagem(dna, sizeof(dna));
}
