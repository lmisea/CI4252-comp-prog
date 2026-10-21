# CI4252 — Programación Competitiva

**Luis Isea — 19-10175**
Universidad Simón Bolívar · Soluciones y prácticas en **C++17**.

Repositorio para organizar los ejercicios de la electiva, documentar las estrategias utilizadas y probar cada solución antes de enviarla a los jueces en línea.

## Tareas

| Tarea                         | Estado                           | Problemas                                                                                                                                                                                                                   |
| ----------------------------- | -------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [Tarea 2](tarea-02/README.md) | ✅ 4/4 aceptados en Codeforces    | [1230B](https://codeforces.com/contest/1230/problem/B) · [985C](https://codeforces.com/contest/985/problem/C) · [492C](https://codeforces.com/contest/492/problem/C) · [101A](https://codeforces.com/contest/101/problem/A) |
| [Tarea 3](tarea-03/README.md) | 🚧 2/3 enfoques aceptados en SPOJ | [ANARC09A — Seinfeld](https://www.spoj.com/problems/ANARC09A/) · ✅ Greedy · ✅ DP Bottom-Up · ⏳ DP Top-Down                                                                                                                  |

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
│   │   └── tests/
│   │       ├── 01.in
│   │       ├── 01.out
│   │       └── ...
│   ├── problema-02/
│   ├── problema-03/
│   └── problema-04/
└── tarea-03/
    ├── README.md
    ├── Makefile
    ├── bottom_up.cpp
    ├── top_down.cpp
    ├── greedy.cpp
    └── tests/
        ├── 01.in
        ├── 01.out
        ├── 02.in
        ├── 02.out
        └── ...
```

En la **Tarea 2**, cada carpeta `problema-XX/` contiene una solución en `main.cpp` y casos de prueba en `tests/`. Los pares `01.in`/`01.out`, `02.in`/`02.out`, etc. representan entradas y salidas esperadas.

En la **Tarea 3**, el mismo problema se resuelve de tres formas independientes (`bottom_up.cpp`, `top_down.cpp` y `greedy.cpp`). Todas comparten los casos de prueba de `tarea-03/tests/` y se gestionan mediante un Makefile propio, directamente en `tarea-03/`.

`plantillas/main.cpp` sirve para iniciar nuevos ejercicios. Las carpetas `build/` contienen ejecutables temporales y no deben subirse a Git.

## Requisitos en CachyOS (basado en Arch Linux)

```bash
sudo pacman -S --needed gcc make git unzip
```

## Compilar y probar — Tarea 2

Desde la raíz del repositorio, cambiando `P` por la ruta del problema:

```bash
make build P=tarea-02/problema-01  # Compilar con C++17
make test P=tarea-02/problema-01   # Ejecutar todos los pares de tests
make run P=tarea-02/problema-01    # Ejecutar con entrada interactiva
make clean                        # Eliminar ejecutables temporales
```

Para ejecutar manualmente un caso concreto:

```bash
./build/tarea-02_problema-01 < tarea-02/problema-01/tests/01.in
```

## Compilar y probar — Tarea 3

Desde la raíz del repositorio:

```bash
make -C tarea-03 all              # Compilar los tres enfoques
make -C tarea-03 test-bottom_up   # Probar DP Bottom-Up
make -C tarea-03 test-top_down    # Probar DP Top-Down
make -C tarea-03 test-greedy      # Probar Greedy
make -C tarea-03 test             # Probar los tres enfoques
make -C tarea-03 clean            # Eliminar sus ejecutables
```

Para ejecutar manualmente un enfoque con un archivo de entrada:

```bash
make -C tarea-03 all
./tarea-03/build/bottom_up < tarea-03/tests/01.in
```

Puedes sustituir `bottom_up` por `greedy` o `top_down`.

Las pruebas comparan la salida del programa con el archivo `.out` correspondiente. Los espacios y saltos de línea pueden influir en la comparación. Algunos problemas admiten varias salidas válidas; en esos casos, una comparación textual exacta no sustituye al veredicto del juez.

Cada solución incluye comentarios sobre su idea, justificación y complejidad. La Tarea 3 se entregará en un ZIP con los tres códigos cuando estén terminados y comprobados.
