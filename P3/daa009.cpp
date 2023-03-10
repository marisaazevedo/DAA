#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct {
    char letra;
    int freq;
} DNA;

struct compareDNA {
    bool operator()(const DNA & p1, const DNA & p2) {
        if (p1.freq < p2.freq) return true;
        if (p1.freq > p2.freq) return false;
        return 0;
    }
};

int main() {
    DNA lista[26];
    string dna;

    for(int i = 0 ; i < 26 ; i++) {
		lista[i].letra = 'A' + i ;
		lista[i].freq = 0;
	}

    cin >> dna;
    int size = dna.size();

    for(int i = 0; i < size; i++) {
        lista[dna[i] - 'A'].freq++;
    }

    sort(lista, lista + size, compareDNA());

    for(int i = 0; i < size; i++) {
        if(lista[i].freq != 0) {
            cout << lista[i].letra << " " << lista[i].freq << endl;
        }
    }
}
