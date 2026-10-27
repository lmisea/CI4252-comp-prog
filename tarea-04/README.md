# Tarea 4 — CI4252 Programación Competitiva

**Estudiante:** Luis Isea · **Carnet:** 19-10175
**Universidad:** Simón Bolívar · **Lenguaje:** C++17

## Problemas

| Carpeta        | Problema                                                                                                                       | Estado    |
| -------------- | ------------------------------------------------------------------------------------------------------------------------------ | --------- |
| `problema-01/` | [UVa 10104 — Euclid Problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045) | Pendiente |
| `problema-02/` | [SPOJ PRIME1 — Prime Generator](https://www.spoj.com/problems/PRIME1/)                                                         | Pendiente |

**Nota del profesor:** esta tarea debe resolverse sin utilizar IA. Los `main.cpp` incluidos son solamente plantillas vacías; cada solución y su justificación deben desarrollarse individualmente.

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

Desde la **raíz del repositorio** `CI4252-comp-prog/`, usando el Makefile principal ya existente:

```bash
# UVa 10104
make build P=tarea-04/problema-01
make test  P=tarea-04/problema-01
make run  P=tarea-04/problema-01

# SPOJ PRIME1
make build P=tarea-04/problema-02
make test  P=tarea-04/problema-02
make run  P=tarea-04/problema-02

# Limpiar ejecutables temporales del Makefile principal
make clean
```

Probar un archivo manualmente después de compilar:

```bash
./build/tarea-04_problema-01 < tarea-04/problema-01/tests/01.in
./build/tarea-04_problema-02 < tarea-04/problema-02/tests/01.in
```


## Particularidades importantes de los enunciados

**UVa 10104:**
- Leer pares de enteros `A B` hasta el final del archivo (EOF).
- Para cada línea, imprimir `X Y D` cumpliendo `A*X + B*Y = D` con `D = mcd(A,B)`.
- La especificación pide minimizar `|X|+|Y|`; en caso de empate, elegir de acuerdo con la condición `X <= Y` del enunciado.
- Las pruebas locales usan `diff` (comparación exacta). Si tu respuesta difiere, revisa también si satisface todas las condiciones antes de concluir que el algoritmo está mal.

**SPOJ PRIME1:**
- La primera línea contiene `t`, la cantidad de casos (t <= 10).
- Cada caso define un intervalo inclusivo `[m,n]`, con `1 <= m <= n <= 10^9` y `n-m <= 100000`.
- Mostrar un primo por línea y **una línea vacía entre casos** (no antes del primer caso).
- Prestar atención a los intervalos sin primos y al valor `1`.
- La comparación local es textual: una línea extra al final puede diferir aunque el juez acepte la presentación.
