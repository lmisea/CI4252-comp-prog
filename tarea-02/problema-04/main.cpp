#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Autor: Luis Isea | Carnet: 19-10175
 * Problema: 101A - Homework
 * Enlace: https://codeforces.com/contest/101/problem/A
 *
 * Idea:
 * Contamos cuantas veces aparece cada letra. Ordenamos las letras por
 * frecuencia de menor a mayor. Vamos eliminando las letras menos
 * frecuentes hasta que ya no podamos eliminar mas sin pasarnos de k.
 *
 * Por que funciona:
 * Al eliminar las letras menos frecuentes, reducimos el numero de
 * letras distintas gastando la menor cantidad de borrados posible.
 *
 * Complejidad:
 * Tiempo: O(n + 26 log 26) | Memoria: O(1)
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int k;
    cin >> s >> k;

    // Contar frecuencia de cada letra.
    vector<pair<int, char>> freq(26);
    for (int i = 0; i < 26; ++i) {
        freq[i] = {0, (char)('a' + i)};
    }
    for (char c : s) {
        freq[c - 'a'].first++;
    }

    // Ordenar por frecuencia ascendente.
    sort(freq.begin(), freq.end());

    // Marcar que letras eliminaremos por completo.
    vector<bool> eliminar(26, false);
    int eliminados = 0;
    int distintas = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq[i].first > 0) {
            distintas++;
        }
    }

    for (int i = 0; i < 26 && eliminados + freq[i].first <= k; ++i) {
        if (freq[i].first > 0) {
            eliminar[freq[i].second - 'a'] = true;
            eliminados += freq[i].first;
            distintas--;
        }
    }

    // Construir la subsecuencia.
    string resultado;
    for (char c : s) {
        if (!eliminar[c - 'a']) {
            resultado += c;
        }
    }

    cout << distintas << '\n';
    cout << resultado << '\n';

    return 0;
}
