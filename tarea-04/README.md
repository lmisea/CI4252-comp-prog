# Tarea 4 — CI4252 Programación Competitiva

**Estudiante:** Luis Isea · **Carnet:** 19-10175
**Universidad:** Simón Bolívar · **Lenguaje de desarrollo:** C++17

## Problemas

| Carpeta        | Problema                                                                                                                       | Estado                                                       |
| -------------- | ------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------ |
| `problema-01/` | [UVa 10104 — Euclid Problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045) | ✅ Accepted en [VJudge](https://vjudge.net/problem/UVA-10104) |
| `problema-02/` | [SPOJ PRIME1 — Prime Generator](https://www.spoj.com/problems/PRIME1/)                                                         | ⏳ Pendiente                                                  |

**Progreso: 1 de 2 problemas aceptados (50 %).**

### Envíos y pruebas

- **UVa 10104:** enviado mediante VJudge porque se presentaron dificultades para iniciar sesión directamente en UVa Online Judge. **Envío #73799674 — Accepted (50 ms)**, el 28 de octubre de 2026. Pruebas locales: **3/3** correctas.
- **SPOJ PRIME1:** pendiente de implementación y envío.

> **Consigna del profesor:** resolver la tarea sin utilizar IA. Las soluciones deben incluir su razonamiento y poder explicarse.

## Estructura

```text
tarea-04/
├── README.md
├── problema-01/
│   ├── main.cpp
│   └── tests/
│       ├── 01.in / 01.out  (ejemplo oficial UVa)
│       ├── 02.in / 02.out  (casos adicionales)
│       └── 03.in / 03.out  (casos adicionales)
└── problema-02/
    ├── main.cpp
    └── tests/
        ├── 01.in / 01.out  (ejemplo oficial SPOJ)
        ├── 02.in / 02.out  (casos adicionales)
        ├── 03.in / 03.out  (casos límite)
        ├── 04.in / 04.out  (intervalo cerca de 10^9)
        └── 05.in / 05.out  (intervalo sin primos)
```

## Compilar y probar

Desde la **raíz del repositorio** `CI4252-comp-prog/`, utilizando el Makefile principal:

```bash
# UVa 10104
make build P=tarea-04/problema-01
make test  P=tarea-04/problema-01
make run  P=tarea-04/problema-01

# SPOJ PRIME1
make build P=tarea-04/problema-02
make test  P=tarea-04/problema-02
make run  P=tarea-04/problema-02

# Eliminar ejecutables temporales
make clean
```

Para ejecutar un caso manualmente después de compilar:

```bash
./build/tarea-04_problema-01 < tarea-04/problema-01/tests/01.in
./build/tarea-04_problema-02 < tarea-04/problema-02/tests/01.in
```

Los archivos `.in` contienen las entradas de prueba y los `.out` sus salidas esperadas. `make test` comprueba la coincidencia textual mediante `diff`.

## Particularidades de los problemas

**UVa 10104 — Euclid Problem**

- Leer pares de enteros `A B` hasta llegar al fin del archivo (EOF).
- Para cada par, imprimir `X Y D`, de modo que `A*X + B*Y = D` y `D = mcd(A,B)`.
- Minimizar `|X| + |Y|`; en caso de empate, aplicar el criterio del enunciado.
- La solución emplea el algoritmo extendido de Euclides para calcular los coeficientes de Bézout y seleccionar el par adecuado.

**SPOJ PRIME1 — Prime Generator**

- La primera línea indica la cantidad de casos `t` (`t <= 10`).
- Cada caso especifica un intervalo inclusivo `[m, n]`, con `1 <= m <= n <= 10^9` y `n - m <= 100000`.
- Imprimir un primo por línea, con una línea vacía **entre casos**.
- Tener en cuenta que `1` no es primo y que puede haber intervalos sin números primos.
