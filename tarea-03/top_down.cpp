#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Autor: Luis Isea | Carnet: 19-10175
 * Problema: ANARC09A - Seinfeld
 * Enlace: https://www.spoj.com/problems/ANARC09A/
 * Método: Programación Dinámica Top-Down
 *
 * Idea:
 * Utilizamos una función recursiva resolver(i, balance)
 * que calcula el mínimo numero de cambios necesarios
 * desde la posición i hasta terminar la cadena.
 *
 * Para cada carácter probamos dos posibilidades:
 * 1. Colocarlo como '{', aumentando el balance.
 * 2. Colocarlo como '}', disminuyendo el balance,
 *    siempre que haya alguna llave abierta.
 *
 * Si modificamos el carácter original, sumamos 1.
 * Guardamos los resultados en una tabla de memoización
 * para no resolver varias veces el mismo estado.
 *
 * Por que funciona:
 * Una cadena balanceada nunca tiene mas cierres que
 * aperturas en ninguno de sus prefijos y debe terminar
 * con balance cero.
 *
 * La recursion considera todas las opciones validas
 * y elige la de menor costo. Como las decisiones futuras
 * solo dependen de la posición y el balance actual,
 * podemos reutilizar los resultados memoizados.
 *
 * Complejidad:
 * Tiempo: O(n^2)
 * Memoria: O(n^2), incluyendo la tabla de memoización.
 */

const int INF = 1000000000;

string s;
int n;
vector<vector<int>> dp;

int resolver(int i, int balance) {
    // Caso base: llegamos al final de la cadena.
    if (i == n) {
        return balance == 0 ? 0 : INF;
    }

    // Si ya calculamos este estado, reutilizamos su valor.
    if (dp[i][balance] != -1) {
        return dp[i][balance];
    }

    // Opción 1: colocar '{'.
    int costo_abrir = (s[i] == '{') ? 0 : 1;
    int abrir = costo_abrir + resolver(i + 1, balance + 1);

    // Opción 2: colocar '}'.
    int cerrar = INF;

    if (balance > 0) {
        int costo_cerrar = (s[i] == '}') ? 0 : 1;
        cerrar = costo_cerrar + resolver(i + 1, balance - 1);
    }

    // Guardamos el mínimo de ambas posibilidades.
    dp[i][balance] = min(abrir, cerrar);
    return dp[i][balance];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int caso = 1;

    while (cin >> s && s[0] != '-') {
        n = s.size();

        // Reiniciar la memoización para cada caso.
        dp.assign(n + 1, vector<int>(n + 1, -1));

        int operaciones = resolver(0, 0);

        cout << caso << ". " << operaciones << '\n';
        ++caso;
    }

    return 0;
}
