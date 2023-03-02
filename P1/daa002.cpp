#include <iostream>

using namespace std;

int main() {
    int t, n, k, soma, j;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        soma = 0;
        while(!(soma == k)) {
            soma = 0;
            n++;
            j = n;
            while(j > 0) {
                soma += j % 10;
                j /= 10;
            }
        }
        cout << n << endl;
    }
}
