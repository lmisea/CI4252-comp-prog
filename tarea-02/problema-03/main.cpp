#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Autor: Luis Isea | Carnet: 19-10175
 * Problema: 492C - Vanya and Exams
 * Enlace: https://codeforces.com/contest/492/problem/C
 *
 * Idea:
 * 1. Calculamos la suma total de notas actuales (sum).
 * 2. Calculamos la suma total de notas necesaria para alcanzar el promedio:
 *    total_needed = n * avg.
 *    Si sum >= total_needed, no necesitamos escribir ensayos (devolvemos 0).
 * 3. Ordenamos los exámenes de menor a mayor según el costo b_i (ensayos
 *    necesarios para subir 1 punto).
 * 4. Recorremos los exámenes en ese orden. Para cada examen:
 *    - Calculamos cuantos puntos podemos subirle sin pasarnos de r:
 *      max_subir = r - a_i.
 *    - Calculamos cuantos puntos nos faltan para alcanzar total_needed:
 *      faltan = total_needed - sum.
 *    - Tomamos el mínimo entre max_subir y faltan: subir = min(max_subir, faltan).
 *    - Sumamos a la respuesta los ensayos necesarios: ans += subir * b_i.
 *    - Actualizamos sum += subir.
 *    - Si sum >= total_needed, terminamos.
 * 5. Devolvemos ans.
 *
 * Por que funciona y por que es optima:
 * - Para minimizar el numero de ensayos, debemos gastar los ensayos en los
 *   exámenes que nos den mas "puntos por ensayo", es decir, los que tengan
 *   menor b_i. Ordenar por b_i y subir primero los mas baratos es la
 *   estrategia greedy optima.
 * - La restricción de que la nota no puede exceder r se maneja tomando el
 *   mínimo entre lo que podemos subir y lo que nos falta. Esto asegura que
 *   no desperdiciamos ensayos en puntos que no podemos obtener.
 * - Como cada examen se procesa a lo sumo una vez, y solo subimos la nota
 *   hasta el máximo necesario, no hay forma de obtener una solución con
 *   menos ensayos: cualquier otra combinación implicaría usar un examen
 *   con b_i mayor antes que uno con b_i menor, lo que aumentaría el total
 *   de ensayos.
 *
 * Complejidad:
 * Tiempo: O(n log n) por el ordenamiento. El recorrido posterior es O(n).
 * Memoria: O(n) para almacenar los exámenes.
 */

struct Examen {
    long long a; // nota actual
    long long b; // ensayos por punto
};

bool compararPorCosto(const Examen& x, const Examen& y) {
    return x.b < y.b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, r, avg;
    cin >> n >> r >> avg;

    vector<Examen> examenes(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> examenes[i].a >> examenes[i].b;
        sum += examenes[i].a;
    }

    long long total_necesario = n * avg;
    if (sum >= total_necesario) {
        cout << 0 << '\n';
        return 0;
    }

    // Ordenamos por costo (b) ascendente.
    sort(examenes.begin(), examenes.end(), compararPorCosto);

    long long ans = 0;
    for (int i = 0; i < n && sum < total_necesario; ++i) {
        long long max_subir = r - examenes[i].a;
        long long faltan = total_necesario - sum;
        long long subir = min(max_subir, faltan);

        ans += subir * examenes[i].b;
        sum += subir;
    }

    cout << ans << '\n';
    return 0;
}
