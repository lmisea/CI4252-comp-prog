# Tarea 3 — ANARC09A: Seinfeld

**Luis Isea — 19-10175**
**Problema:** [SPOJ ANARC09A — Seinfeld](https://www.spoj.com/problems/ANARC09A/)
**Lenguaje de desarrollo:** C++17

## Enfoques requeridos

| Enfoque      | Archivo         | Estado     | Envío SPOJ                                               |
| ------------ | --------------- | ---------- | -------------------------------------------------------- |
| Greedy       | `greedy.cpp`    | ✅ Accepted | [36031451](https://www.spoj.com/status/ANARC09A,lmisea/) |
| DP Bottom-Up | `bottom_up.cpp` | ✅ Accepted | [36031515](https://www.spoj.com/status/ANARC09A,lmisea/) |
| DP Top-Down  | `top_down.cpp`  | ✅ Accepted | [36031567](https://www.spoj.com/status/ANARC09A,lmisea/) |

**Progreso: 3 de 3 enfoques aceptados (100 %).**

## Estrategias y complejidades

- **Greedy:** recorre la cadena manteniendo un balance de llaves abiertas; corrige los cierres que dejarían un balance negativo y, al terminar, las aperturas restantes. Tiempo `O(n)` y memoria auxiliar `O(1)`.
- **DP Bottom-Up:** construye iterativamente los costos mínimos por posición y balance válido. Tiempo `O(n²)` y memoria `O(n²)`.
- **DP Top-Down:** calcula los mismos tipos de estados mediante recursión y memoización. Tiempo `O(n²)` y memoria `O(n²)`.

Los tres programas resuelven el mismo problema y comparten los casos de prueba.

## Estructura

```text
tarea-03/
├── README.md
├── Makefile
├── greedy.cpp
├── bottom_up.cpp
├── top_down.cpp
└── tests/
    ├── 01.in
    ├── 01.out
    ├── 02.in
    ├── 02.out
    ├── 03.in
    └── 03.out
```

## Compilar y probar

Desde la raíz del repositorio:

```bash
make -C tarea-03 all
make -C tarea-03 test-greedy
make -C tarea-03 test-bottom_up
make -C tarea-03 test-top_down
make -C tarea-03 test
make -C tarea-03 clean
```

Para ejecutar un caso manualmente:

```bash
make -C tarea-03 all
./tarea-03/build/top_down < tarea-03/tests/01.in
```

Los pares `tests/XX.in` y `tests/XX.out` permiten comparar las salidas esperadas. Cada archivo de entrada puede contener varios casos; una línea que empieza por `-` marca el final de la entrada, y la numeración de casos comienza en 1.

## Entrega

Los tres enfoques están aceptados en SPOJ. La entrega se empaqueta en un ZIP con los tres archivos `.cpp`, este README, el Makefile y la carpeta `tests/`.
