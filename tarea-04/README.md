# Tarea 4 — CI4252 Programación Competitiva

**Estudiante:** Luis Isea · **Carnet:** 19-10175
**Universidad:** Simón Bolívar · **Lenguaje de desarrollo:** C++17

## Problemas

| Carpeta        | Problema                                                               | Estado               |
| -------------- | ---------------------------------------------------------------------- | -------------------- |
| `problema-01/` | [UVa 10104 — Euclid Problem](https://vjudge.net/problem/UVA-10104)     | ✅ Accepted en VJudge |
| `problema-02/` | [SPOJ PRIME1 — Prime Generator](https://www.spoj.com/problems/PRIME1/) | ✅ Accepted en SPOJ   |

**Progreso: 2 de 2 problemas aceptados (100 %).**

### Envíos y pruebas

- **UVa 10104:** enviado mediante [VJudge](https://vjudge.net/problem/UVA-10104) ante dificultades para iniciar sesión en UVa Online Judge. **Envío #73799674 — Accepted (50 ms)**, 28 de octubre de 2026. Pruebas locales: **3/3** correctas.
- **SPOJ PRIME1:** [Prime Generator](https://www.spoj.com/problems/PRIME1/). **Envío #36048257 — Accepted (0.02 s, 5.2 MB)**, 28 de octubre de 2026. Incluye cinco pares de archivos de prueba locales.

> **Nota sobre la consigna:** el profesor indicó que la Tarea 4 debía resolverse sin utilizar IA y que las soluciones debían poder explicarse y justificarse.

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

Los archivos `.in` contienen las entradas de prueba y los `.out` sus salidas esperadas. `make test` compara la salida textual mediante `diff`.

## Estrategias y particularidades

### UVa 10104 — Euclid Problem

- Leer pares `A B` hasta el final del archivo (EOF).
- Obtener `X Y D`, cumpliendo `A*X + B*Y = D` con `D = mcd(A,B)`.
- Minimizar `|X| + |Y|` y respetar el criterio de desempate del enunciado.
- **Estrategia:** algoritmo extendido de Euclides y selección de los coeficientes de Bézout adecuados.

### SPOJ PRIME1 — Prime Generator

- Leer `t` intervalos inclusivos `[m, n]` con `1 <= m <= n <= 10^9` y `n - m <= 100000`.
- Imprimir un primo por línea y una línea vacía entre casos de prueba.
- Recordar que `1` no es primo y que algunos intervalos no contienen números primos.
- **Estrategia:** criba de Eratóstenes para primos pequeños y criba segmentada para descartar compuestos dentro del intervalo sin reservar memoria hasta `n`.
