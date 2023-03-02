#include <iostream>
#define M_PI 3.1416

using namespace std;

int area_quadrado(int lado) {
    return lado*lado;
}

int area_circulo(double raio) {
    return M_PI*raio*raio;
}

int main() {
    int N, qx, qy, ql, cx, cy;
    double cr;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> qx >> qy >> ql >> cx >> cy >> cr;
        if((qx < (cx - cr) && (qx + ql) > (cx + cr) && qy < (cy - cr) && (qy + ql) > (cy + cr))) {
            cout << area_circulo(cr) << endl;
        }
        else if((qx > (cx - cr) && (qx + ql) < (cx + cr) && qy > (cy - cr) && (qy + ql) < (cy + cr))) {
            cout << area_quadrado(ql) << endl;
        }
    }
}
