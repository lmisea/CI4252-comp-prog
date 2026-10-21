#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Autor: Luis Isea | Carnet: 19-10175
 * Problema: ANARC09A - Seinfeld
 * Enlace: https://www.spoj.com/problems/ANARC09A/
 * Método: Programación Dinámica Bottom-Up
 *
 * Idea:
 * Usamos dp[i][b] para guardar el mínimo numero de cambios
 * necesarios después de procesar i caracteres y terminar
 * con un balance b de llaves abiertas.
 *
 * Para cada carácter consideramos dos opciones:
 * 1. Colocar '{', aumentando el balance en 1.
 * 2. Colocar '}', disminuyendo el balance en 1,
 *    siempre que el balance anterior sea positivo.
 *
 * Si cambiamos el carácter original, sumamos una operación.
 * Al finalizar, la respuesta sera dp[n][0].
 *
 * Por que funciona:
 * Consideramos todas las opciones validas para cada posición
 * y guardamos solamente el menor costo de cada estado.
 * Como el costo futuro depende de la posición y del balance,
 * no necesitamos recordar exactamente los cambios anteriores.
 *
 * Complejidad:
 * Tiempo: O(n^2)
 * Memoria: O(n^2)
 */

int resolver(const string& s) {
    int n = s.size();
    const int INF = 1000000000;

    vector<vector<int>> dp(
        n + 1, vector<int>(n + 1, INF)
    );

    // Caso base: cadena vacía, balance cero y cero cambios.
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int b = 0; b <= i; ++b) {
            if (dp[i][b] == INF) {
                continue;
            }

            // Opción 1: colocar una llave de apertura.
            int costo_abrir = (s[i] == '{') ? 0 : 1;

            dp[i + 1][b + 1] = min(
                dp[i + 1][b + 1],
                dp[i][b] + costo_abrir
            );

            // Opción 2: colocar una llave de cierre.
            // Solo se permite si hay una apertura pendiente.
            if (b > 0) {
                int costo_cerrar = (s[i] == '}') ? 0 : 1;

                dp[i + 1][b - 1] = min(
                    dp[i + 1][b - 1],
                    dp[i][b] + costo_cerrar
                );
            }
        }
    }

    return dp[n][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int caso = 1;

    while (cin >> s && s[0] != '-') {
        cout << caso << ". " << resolver(s) << '\n';
        ++caso;
    }

    return 0;
}
