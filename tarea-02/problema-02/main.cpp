#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Autor: Luis Isea | Carnet: 19-10175
 * Problema: 985C - Liebig's Barrels
 * Enlace: https://codeforces.com/contest/985/problem/C
 *
 * Idea:
 * Ordenamos los n*k tablones. El menor tablon a[0] tiene que ser el
 * mínimo de algún barril; por tanto, todos los mínimos deben estar
 * entre a[0] y a[0]+l. Contamos cuantos tablones cumplen esto.
 * Si hay menos de n, no es posible formar los n barriles.
 *
 * Si es posible, elegimos los mínimos de izquierda a derecha.
 * Para cada barril, usamos como relleno tantos tablones validos como
 * podamos (hasta k-1), siempre reservando al menos un mínimo valido
 * para cada barril pendiente. Los demás tablones, mas grandes, pueden
 * completar los barriles sin disminuir ninguno de sus mínimos.
 *
 * Por que funciona y por que es optima:
 * El tablon mas pequeño debe aparecer en algún barril como mínimo.
 * Es mejor consumir tablones validos adicionales en los primeros
 * barriles cuando hacerlo no impide construir los restantes: asi
 * los mínimos de los barriles siguientes quedan lo mas grandes
 * posible. Los tablones de fuera del rango valido solo pueden servir
 * de relleno. Esta elección greedy maximiza la suma de mínimos.
 *
 * Complejidad: O(n*k*log(n*k)) tiempo por ordenar,
 * O(n*k) memoria por almacenar el arreglo.
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    long long l;
    cin >> n >> k >> l;

    int m = n * k;
    vector<long long> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    int validos = upper_bound(a.begin(), a.end(), a[0] + l) - a.begin();
    if (validos < n) {
        cout << 0 << '\n';
        return 0;
    }

    long long respuesta = 0;
    int pos = 0;
    for (int barril = 0; barril < n; ++barril) {
        respuesta += a[pos];
        int pendientes = n - barril - 1;
        int disponibles = validos - pos;
        pos += min(k, disponibles - pendientes);
    }

    cout << respuesta << '\n';
    return 0;
}
