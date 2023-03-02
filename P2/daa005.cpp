#include <iostream>

using namespace std;

int main() {
    int N, energy, F, initial, final, sum = 0;
    cin >> N;
    int lista [N];
    for(int i = 0; i < N; i++) {
        cin >> energy;
        sum += energy;
        lista[i] = sum;
    }

    cin >> F;
    for(int i = 0; i < F; i++) {
        cin >> initial >> final;
        if(initial > 1) {
            cout << lista[final - 1] - lista[initial - 2] << endl;
        }
        else {
            cout << lista[final - 1] << endl;
        }
    }
}
