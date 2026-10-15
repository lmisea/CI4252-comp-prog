#include <iostream>
#include <string>
using namespace std;

/*
 * Autor: Luis Isea | Carnet: 19-10175
 * Problema: 1230B - Ania and Minimizing
 * Enlace: https://codeforces.com/contest/1230/problem/B
 *
 * Idea:
 * Recorremos el numero de izquierda a derecha con un indice i y
 * mientras nos queden cambios disponibles (k > 0):
 *   - Si i == 0 (primer digito):
 *       * Si n == 1, podemos poner un '0' (el unico digito puede ser 0).
 *       * Si n > 1, no podemos poner '0' porque quedaria con ceros a la
 *         izquierda. Entonces intentamos bajar a '1' si no lo es ya.
 *   - Si i > 0 (cualquier otro digito):
 *       * Siempre podemos intentar poner '0' si el digito actual no es '0'.
 * Si logramos cambiar el digito, gastamos 1 cambio (k--).
 * Si k llega a 0, terminamos.
 *
 * Por que funciona y por que es optima:
 * - Al recorrer de izquierda a derecha, priorizamos los digitos mas
 *   significativos. Reducir un digito mas a la izquierda siempre hace
 *   que el numero sea menor que reducir cualquier digito a la derecha.
 * - La unica restriccion es no crear ceros a la izquierda. Para el
 *   primer digito (i == 0) respetamos esa restriccion. Para los demas
 *   no hay problema porque ya hay un digito no cero a la izquierda.
 * - Esta estrategia greedy es optima porque en cada paso tomamos la
 *   mejor decision local (reducir al maximo posible) y como los cambios
 *   son limitados, agotarlos en los digitos mas significativos garantiza
 *   el menor valor posible.
 *
 * Complejidad:
 * Tiempo: O(n) | Memoria: O(1) (ademas de la cadena de entrada)
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    for (int i = 0; i < n && k > 0; ++i) {
        if (i == 0) {
            // Primer digito: no podemos poner '0' si n > 1.
            if (n == 1) {
                if (s[i] != '0') {
                    s[i] = '0';
                    --k;
                }
            } else {
                if (s[i] != '1') {
                    s[i] = '1';
                    --k;
                }
            }
        } else {
            // Cualquier otro digito: intentamos poner '0'.
            if (s[i] != '0') {
                s[i] = '0';
                --k;
            }
        }
    }

    cout << s << '\n';
    return 0;
}
