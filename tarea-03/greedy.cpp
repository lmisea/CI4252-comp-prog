#include <iostream>
#include <string>
using namespace std;

/*
 * Autor: Luis Isea | Carnet: 19-10175
 * Problema: ANARC09A - Seinfeld
 * Enlace: https://www.spoj.com/problems/ANARC09A/
 *
 * Idea:
 * Recorremos la cadena llevando un balance de las llaves abiertas
 * que aun no se han cerrado.
 *
 * Si encontramos '{', aumentamos el balance.
 * Si encontramos '}', disminuimos el balance.
 *
 * Cuando el balance se vuelve negativo, significa que encontramos
 * una llave de cierre sin una apertura correspondiente.
 * Cambiamos esa llave a '{', contamos una operación y
 * dejamos el balance en 1.
 *
 * Al terminar, si quedan llaves abiertas sin cerrar,
 * necesitamos cambiar la mitad de ellas a llaves de cierre.
 *
 * Por que funciona:
 * Una cadena balanceada nunca puede tener un prefijo con
 * mas cierres que aperturas. Por eso corregimos inmediatamente
 * los balances negativos.
 *
 * Cada cambio de una apertura a un cierre reduce el balance
 * en 2. Por lo tanto, al terminar necesitamos balance / 2
 * operaciones adicionales.
 *
 * Complejidad:
 * Tiempo: O(n)
 * Memoria auxiliar: O(1)
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int caso = 1;

    while (cin >> s && s[0] != '-') {
        int balance = 0;
        int operaciones = 0;

        for (char c : s) {
            if (c == '{') {
                balance++;
            } else {
                balance--;

                if (balance < 0) {
                    operaciones++;
                    balance = 1;
                }
            }
        }

        operaciones += balance / 2;

        cout << caso << ". " << operaciones << '\n';
        caso++;
    }

    return 0;
}
