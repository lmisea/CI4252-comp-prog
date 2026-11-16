
#include <iostream>
#include <vector>
#include <complex>

using namespace std;

/*
 * CI4252 - Programación Competitiva
 * Tarea 5 - POLYMUL (SPOJ)
 *
 * Multiplication de polinomios usando FFT.
 *
 * Complejidad:
 * Tiempo: O(n log n)
 * Memoria auxiliar: O(n)
 */

using cd = complex<double>;
const double PI = acos(-1.0);

void fft(vector<cd>& a, bool inversa) {
    int n = a.size();
    if (n == 1) return;

    // Dividir entre indices pares e impares.
    vector<cd> pares(n / 2);
    vector<cd> impares(n / 2);

    for (int i = 0; i < n / 2; i++) {
        pares[i] = a[2 * i];
        impares[i] = a[2 * i + 1];
    }

    // Resolver recursivamente ambas mitades.
    fft(pares, inversa);
    fft(impares, inversa);

    // Calcular la raíz de la unidad.
    double angulo = 2.0 * PI / n;
    if (inversa) angulo = -angulo;

    cd wn(cos(angulo), sin(angulo));
    cd w(1, 0);

    // Combinar las mitades usando mariposas.
    for (int i = 0; i < n / 2; i++) {
        cd t = w * impares[i];

        a[i] = pares[i] + t;
        a[i + n / 2] = pares[i] - t;

        w *= wn;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // El producto tiene grado 2*n.
        int necesarios = 2 * n + 1;
        // Menor potencia de 2 suficiente.
        int tam = 1;

        while (tam < necesarios) tam *= 2;

        vector<cd> A(tam);
        vector<cd> B(tam);

        // Leer desde mayor a menor grado.
        // Guardar internamente de menor a mayor.
        for (int i = n; i >= 0; i--) {
            long long valor;
            cin >> valor;
            A[i] = cd(valor, 0);
        }

        for (int i = n; i >= 0; i--) {
            long long valor;
            cin >> valor;
            B[i] = cd(valor, 0);
        }

        // Transformar ambos polinomios.
        fft(A, false);
        fft(B, false);

        // Multiplicar posición por posición.
        for (int i = 0; i < tam; i++) {
            A[i] *= B[i];
        }

        // Recuperar los coeficientes.
        fft(A, true);

        // Imprimir desde el mayor grado hasta el menor.
        for (int i = 2 * n; i >= 0; i--) {
            if (i < 2 * n) cout << ' ';

            long long coeficiente =
                llround(A[i].real() / tam);
            cout << coeficiente;
        }
        cout << '\n';
    }
    return 0;
}
