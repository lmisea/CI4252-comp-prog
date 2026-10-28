# CI4252 — Programación Competitiva

**Luis Isea — 19-10175**
Universidad Simón Bolívar · Soluciones y prácticas en **C++17**.

Repositorio para organizar los ejercicios de la electiva, documentar las estrategias utilizadas y probar cada solución antes de enviarla a los jueces en línea.

## Tareas

| Tarea                         | Estado                           | Problemas                                                                                                                                                                                                                   |
| ----------------------------- | -------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [Tarea 2](tarea-02/README.md) | ✅ 4/4 aceptados en Codeforces    | [1230B](https://codeforces.com/contest/1230/problem/B) · [985C](https://codeforces.com/contest/985/problem/C) · [492C](https://codeforces.com/contest/492/problem/C) · [101A](https://codeforces.com/contest/101/problem/A) |
| [Tarea 3](tarea-03/README.md) | ✅ 3/3 enfoques aceptados en SPOJ | [ANARC09A — Seinfeld](https://www.spoj.com/problems/ANARC09A/): Greedy, DP Bottom-Up y DP Top-Down                                                                                                                          |
| [Tarea 4](tarea-04/README.md) | ✅ 2/2 aceptados                  | [UVa 10104 — Euclid Problem](https://vjudge.net/problem/UVA-10104) (VJudge) · [PRIME1 — Prime Generator](https://www.spoj.com/problems/PRIME1/) (SPOJ)                                                                      |

## Estructura del repositorio

```text
CI4252-comp-prog/
├── Makefile
├── README.md
├── plantillas/
│   └── main.cpp
├── tarea-02/
│   ├── README.md
│   ├── problema-01/
│   │   ├── main.cpp
│   │   └── tests/ (01.in, 01.out, ...)
│   ├── problema-02/
│   ├── problema-03/
│   └── problema-04/
├── tarea-03/
│   ├── README.md
│   ├── Makefile
│   ├── bottom_up.cpp
│   ├── top_down.cpp
│   ├── greedy.cpp
│   └── tests/ (01.in, 01.out, ...)
└── tarea-04/
    ├── README.md
    ├── problema-01/
    │   ├── main.cpp
    │   └── tests/ (01.in, 01.out, ...)
    └── problema-02/
        ├── main.cpp
        └── tests/ (01.in, 01.out, ...)
```

En las **Tareas 2 y 4**, cada carpeta `problema-XX/` contiene su solución en `main.cpp` y casos de prueba en `tests/`. Los pares `01.in`/`01.out`, `02.in`/`02.out`, etc. representan entradas y salidas esperadas.

En la **Tarea 3**, el mismo problema se resuelve con tres enfoques independientes. Los programas comparten `tarea-03/tests/` y se compilan con un Makefile propio.

`plantillas/main.cpp` sirve para iniciar nuevos ejercicios. Las carpetas `build/` contienen ejecutables temporales y no se suben a Git.

## Requisitos en CachyOS (basado en Arch Linux)

```bash
sudo pacman -S --needed gcc make git unzip
```

## Compilar y probar — Tareas 2 y 4

Ejecutar desde la raíz del repositorio, cambiando `P` por la ruta del problema:

```bash
# Ejemplo: Tarea 2
make build P=tarea-02/problema-01
make test  P=tarea-02/problema-01
make run  P=tarea-02/problema-01

# Problema 1 de la Tarea 4 (UVa 10104)
make build P=tarea-04/problema-01
make test  P=tarea-04/problema-01

# Problema 2 de la Tarea 4 (SPOJ PRIME1)
make build P=tarea-04/problema-02
make test  P=tarea-04/problema-02

# Limpiar ejecutables del Makefile principal
make clean
```

Para ejecutar manualmente un caso concreto, después de compilar:

```bash
./build/tarea-04_problema-01 < tarea-04/problema-01/tests/01.in
./build/tarea-04_problema-02 < tarea-04/problema-02/tests/01.in
```

## Compilar y probar — Tarea 3

Desde la raíz del repositorio:

```bash
make -C tarea-03 all              # Compilar los tres enfoques
make -C tarea-03 test-bottom_up   # Probar DP Bottom-Up
make -C tarea-03 test-top_down    # Probar DP Top-Down
make -C tarea-03 test-greedy      # Probar Greedy
make -C tarea-03 test             # Probar los tres enfoques
make -C tarea-03 clean            # Eliminar ejecutables
```

Para ejecutar manualmente uno de los enfoques:

```bash
make -C tarea-03 all
./tarea-03/build/greedy < tarea-03/tests/01.in
```

También puedes sustituir `greedy` por `bottom_up` o `top_down`.

Las pruebas comparan las salidas con los archivos `.out` correspondientes. Los espacios y saltos de línea pueden influir en la comparación. Algunos problemas admiten varias salidas válidas; en esos casos, la comparación textual no sustituye al veredicto del juez.

Cada solución incluye comentarios sobre su idea, justificación y complejidad. Los detalles y enlaces de los envíos aceptados están en el README de cada tarea.
