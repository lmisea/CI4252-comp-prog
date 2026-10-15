# CI4252 — Programación Competitiva

**Luis Isea — 19-10175**
Universidad Simón Bolívar · Soluciones y prácticas en **C++17**.

Repositorio para organizar los ejercicios de la electiva, documentar las estrategias utilizadas y probar cada solución antes de enviarla a Codeforces.

## Tareas

| Tarea                         | Estado                        | Problemas                                                                                                                                                                                                                   |
| ----------------------------- | ----------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [Tarea 2](tarea-02/README.md) | ✅ 4/4 aceptados en Codeforces | [1230B](https://codeforces.com/contest/1230/problem/B) · [985C](https://codeforces.com/contest/985/problem/C) · [492C](https://codeforces.com/contest/492/problem/C) · [101A](https://codeforces.com/contest/101/problem/A) |

## Estructura del repositorio

```text
CI4252-comp-prog/
├── Makefile
├── README.md
├── plantillas/
│   └── main.cpp
└── tarea-02/
    ├── README.md
    ├── problema-01/
    │   ├── main.cpp
    │   └── tests/
    │       ├── 01.in
    │       ├── 01.out
    │       └── ...
    ├── problema-02/
    ├── problema-03/
    └── problema-04/
```

En general, cada `tarea-XX/problema-XX/` contiene la solución en `main.cpp` y los casos de prueba en `tests/`. Los pares `01.in`/`01.out`, `02.in`/`02.out`, etc. representan entradas y salidas esperadas. `plantillas/main.cpp` sirve para iniciar nuevos ejercicios y `build/` guarda ejecutables temporales (no se sube a Git).

## Requisitos en CachyOS (basado en Arch Linux)

```bash
sudo pacman -S --needed gcc make git unzip
```

## Compilar y probar

Ejecutar desde la raíz del repositorio, cambiando `P` por la ruta del problema:

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

`make test` compara la salida de cada caso con su archivo `.out` correspondiente. Los espacios y saltos de línea pueden influir en la comparación. Algunos problemas admiten varias salidas válidas; en esos casos, una comparación textual exacta no sustituye al veredicto del juez.

Cada solución incluye comentarios sobre la idea, su justificación y su complejidad.
