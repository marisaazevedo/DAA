#include <iostream>
#define M_PI 3.1415926535897

using namespace std;
double resolucao (double qx, double qy, double ql, double cx, double cy, double cr) {
        // qx  ----------->  x esquerda do quadrado
        // qy  ----------->  y inferior do quadrado
    double qx2 = qx + ql; // x direito do quadrado
	double qy2 = qy + ql; // y superior do quadrado
    double cx1 = cx - cr; // posicao à esquerda do circulo
	double cy1 = cy - cr; // posicao inferior do circulo
    double cx2 = cx + cr; // posicao à direita do circulo
	double cy2 = cy + cr; // posicao superior
    double intersecao = 0;

    if(cx1 >= qx && cx2 <= qx2 && cy1 >= qy && cy2 <= qy2) {
        return M_PI * cr * cr;
    } // circulo dentro do quadrado

    else if((qx - cx) * (qx - cx) + (qy - cy) * (qy - cy) <= cr * cr && (qx - cx) * (qx - cx) + (qy2 - cy) * (qy2 - cy) <= cr * cr && (qx2 - cx) * (qx2 - cx) + (qy - cy) * (qy - cy) <= cr * cr && (qx2 - cx) * (qx2 - cx) + (qy2 - cy) * (qy2 - cy) <= cr * cr) {
        return ql * ql;
    } // quadrado dentro do circulo

    else if(cx2 <= qx || cx1 >= qx2 || cy2 <= qy || cy1 >= qy2) {
        return 0;
    } // uma figura está garantidamente fora da outra



    else if(ql >= 0.001) {
        ql /= 2;
        intersecao += resolucao(qx,  qy,  ql, cx, cy, cr);
		intersecao += resolucao(qx2, qy,  ql, cx, cy, cr);
		intersecao += resolucao(qx,  qy2, ql, cx, cy, cr);
		intersecao += resolucao(qx2, qy2, ql, cx, cy, cr);

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
