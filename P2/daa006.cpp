#include <iostream>
#define M_PI 3.1415926535897

using namespace std;

double resolucao (double qx1, double qy1, double ql, double cx, double cy, double cr) {
        // qx1  ----------->  x esquerda do quadrado
        // qy2  ----------->  y inferior do quadrado
    double qx2 = qx1 + ql; // x direito do quadrado
	double qy2 = qy1 + ql; // y superior do quadrado
    double cx1 = cx - cr;  // posicao à esquerda do circulo
	double cy1 = cy - cr;  // posicao inferior do circulo
    double cx2 = cx + cr;  // posicao à direita do circulo
	double cy2 = cy + cr;  // posicao superior
    double intersecao = 0;

    if(((qx1 - cx) * (qx1 - cx) + (qy1 - cy) * (qy1 - cy) > cr * cr) && ((qx1 - cx) * (qx1 - cx) + (qy2 - cy) * (qy2 - cy) > cr * cr) && ((qx2 - cx) * (qx2 - cx) + (qy1 - cy) * (qy1 - cy) > cr * cr) && ((qx2 - cx) * (qx2 - cx) + (qy2 - cy) * (qy2 - cy) > cr * cr) && (!(cx > qx1 && cx < qx2)) && (!(cy > qy1 && cy < qy2))) {
        // uma figura está garantidamente fora da outra
        return 0;
    }

    else if((cx1 > qx1) && (cx2 < qx2) && (cy1 > qy1) && (cy2 < qy2)) {
        // circulo dentro do quadrado
        return M_PI * cr * cr;
    }

    else if((((qx1 - cx) * (qx1 - cx) + (qy1 - cy) * (qy1 - cy)) < (cr * cr)) && (((qx1 - cx) * (qx1 - cx) + (qy2 - cy) * (qy2 - cy)) < (cr * cr)) && (((qx2 - cx) * (qx2 - cx) + (qy1 - cy) * (qy1 - cy)) < (cr * cr)) && (((qx2 - cx) * (qx2 - cx) + (qy2 - cy) * (qy2 - cy)) < (cr * cr))) {
        // quadrado dentro do circulo
        return ql * ql;
    }

    else if(ql >= 0.001) {
        ql /= 2;
        intersecao += resolucao(qx1,      qy1 + ql, ql, cx, cy, cr);
		intersecao += resolucao(qx1 + ql, qy1 + ql, ql, cx, cy, cr);
		intersecao += resolucao(qx1,      qy1,      ql, cx, cy, cr);
		intersecao += resolucao(qx1 + ql, qy1,      ql, cx, cy, cr);

    }
    return intersecao;
}

int main() {
    int N;
    double qx, qy, ql, cx, cy, cr;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> qx >> qy >> ql >> cx >> cy >> cr;
        cout << resolucao(qx, qy, ql, cx, cy, cr) << endl;
    }
    return 0;
}
