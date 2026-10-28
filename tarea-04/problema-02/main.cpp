#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Autor: Luis Isea | Carnet: 19-10175
 * Problema: PRIME1 - Prime Generator (SPOJ)
 * Enlace: https://www.spoj.com/problems/PRIME1/
 * Método: Criba de Eratóstenes segmentada
 *
 * Idea:
 * Primero generamos los primos pequeños hasta la raíz cuadrada
 * del mayor número permitido (10^9). Para cada caso, creamos
 * un vector que representa solo el intervalo [m, n].
 *
 * Para cada primo p, marcamos sus múltiplos dentro del intervalo.
 * Empezamos en max(p*p, ceil(m/p)*p): antes de p*p, los
 * múltiplos compuestos ya tienen un factor primo menor.
 * Finalmente imprimimos las posiciones que no fueron descartadas.
 *
 * Por qué funciona:
 * Todo número compuesto tiene al menos un factor primo menor
 * o igual que su raíz cuadrada. Así, todos los compuestos del
 * intervalo se marcan y ninguno de los primos se descarta.
 *
 * Complejidad:
 * Preprocesamiento: O(L log log L), L = 31623.
 * Por intervalo: O(pi(L) + (n-m+1) log log n) aproximadamente.
 * Memoria: O(L + (n-m+1)).
 */

const int LIMITE = 31623;

vector<int> generarPrimos() {
    vector<bool> esPrimo(LIMITE + 1, true);
    esPrimo[0] = esPrimo[1] = false;

    for (int p = 2; p * p <= LIMITE; ++p) {
        if (!esPrimo[p]) {
            continue;
        }
        for (int j = p * p; j <= LIMITE; j += p) {
            esPrimo[j] = false;
        }
    }

    vector<int> primos;
    for (int p = 2; p <= LIMITE; ++p) {
        if (esPrimo[p]) {
            primos.push_back(p);
        }
    }
    return primos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<int> primos = generarPrimos();

    int t;
    cin >> t;

    for (int caso = 0; caso < t; ++caso) {
        int m, n;
        cin >> m >> n;

        // El índice i representa el número m + i.
        vector<bool> esPrimo(n - m + 1, true);

        if (m == 1) {
            esPrimo[0] = false;
        }

        for (int p : primos) {
            if (1LL * p * p > n) {
                break;
            }

            // Primer múltiplo de p en [m, n], pero no anterior a p*p.
            long long cociente = m / p;
            if (m % p != 0) {
                ++cociente;
            }
            long long inicio = max(1LL * p * p, cociente * p);

            for (long long j = inicio; j <= n; j += p) {
                esPrimo[j - m] = false;
            }
        }

        // Línea en blanco entre casos, no antes del primero.
        if (caso > 0) {
            cout << '\n';
        }

        for (int i = m; i <= n; ++i) {
            if (esPrimo[i - m]) {
                cout << i << '\n';
            }
        }
    }

    return 0;
}
