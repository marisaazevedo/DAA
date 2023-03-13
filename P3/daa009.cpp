#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct {
    char letra;
    int freq;
    int first_ind;
} DNA;

struct compareDNA {
    bool operator()(const DNA & p1, const DNA & p2) {
        if (p1.freq < p2.freq) return false;
        if (p1.freq > p2.freq) return true;
        if (p1.freq == p2.freq && p1.first_ind < p2.first_ind) return true;
        if (p1.freq == p2.freq && p1.first_ind > p2.first_ind) return false;
        return 0;
    }
};

int main() {
    DNA lista[26];
    string dna;

    for(int i = 0 ; i < 26 ; i++) {
		lista[i].letra = 'A' + i ;
		lista[i].freq = 0;
		lista[i].first_ind = -1;
	}

    cin >> dna;
    int size = dna.size();

    for(int i = 0; i < size; i++) {
        lista[dna[i] - 'A'].freq++;
    }

    for(int i = 0; i < size; i++) {
        if(lista[dna[i] - 'A'].first_ind == -1) {
            lista[dna[i] - 'A'].first_ind = i;
        }
    }

    sort(lista, lista + 26, compareDNA());

    for(int i = 0; i < 26; i++) {
        if(lista[i].freq != 0) {
            cout << lista[i].letra << " " << lista[i].freq << endl;
        }
    }
}
