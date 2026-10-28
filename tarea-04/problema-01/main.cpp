#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/*
 * Autor: Luis Isea | Carnet: 19-10175
 * Problema: 10104 - Euclid Problem (UVa)
 * Enlace: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045
 *
 * Idea:
 * 1. Aplicar Euclides extendido recursivamente para obtener X0, Y0 y D.
 * 2. Usar las soluciones X = X0 + (B/D)*t, Y = Y0 - (A/D)*t.
 * 3. Probar los enteros cercanos a los puntos donde X o Y se hacen cero,
 *    y escoger la menor suma |X| + |Y|. Si hay empate, preferir X <= Y.
 *
 * Corrección:
 * La recursión mantiene la identidad AX + BY = D.
 * La suma de valores absolutos es una función convexa de t;
 * sus cambios de pendiente ocurren cuando X o Y valen cero.
 * Por eso es suficiente comparar los enteros vecinos a esos puntos.
 *
 * Complejidad:
 * Tiempo: O(log(min(A, B))) para A, B positivos.
 * Memoria: O(log(min(A, B))) por la recursión.
 */

struct Resultado {
    long long x, y, d;
};

Resultado euclidesExtendido(long long a, long long b) {
    if (b == 0) {
        return {1, 0, a};
    }

    Resultado anterior = euclidesExtendido(b, a % b);
    long long x = anterior.y;
    long long y = anterior.x - (a / b) * anterior.y;
    return {x, y, anterior.d};
}

// División hacia menos infinito, también si el numerador es negativo.
long long divisionPiso(long long a, long long b) {
    long long q = a / b;
    if (a % b < 0) {
        --q;
    }
    return q;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) {
            cout << "0 0 0\n";
            continue;
        }

        Resultado inicial = euclidesExtendido(a, b);
        long long pasoX = b / inicial.d;
        long long pasoY = a / inicial.d;
        vector<long long> candidatos = {0};

        // Los mínimos posibles están cerca de donde X o Y valen cero.
        if (pasoX > 0) {
            long long t = divisionPiso(-inicial.x, pasoX);
            candidatos.push_back(t);
            candidatos.push_back(t + 1);
        }
        if (pasoY > 0) {
            long long t = divisionPiso(inicial.y, pasoY);
            candidatos.push_back(t);
            candidatos.push_back(t + 1);
        }

        long long mejorX = inicial.x;
        long long mejorY = inicial.y;

        for (long long t : candidatos) {
            long long x = inicial.x + pasoX * t;
            long long y = inicial.y - pasoY * t;
            long long costo = llabs(x) + llabs(y);
            long long mejorCosto = llabs(mejorX) + llabs(mejorY);

            if (costo < mejorCosto ||
                (costo == mejorCosto && x <= y && mejorX > mejorY) ||
                (costo == mejorCosto && (x <= y) == (mejorX <= mejorY) && x < mejorX)) {
                mejorX = x;
                mejorY = y;
            }
        }

        cout << mejorX << ' ' << mejorY << ' ' << inicial.d << '\n';
    }

    return 0;
}
