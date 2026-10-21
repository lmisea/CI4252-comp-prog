# Tarea 3 — ANARC09A: Seinfeld

**Luis Isea — 19-10175**
**Juez:** [SPOJ ANARC09A](https://www.spoj.com/problems/ANARC09A/)
**Lenguaje:** C++17

## Enfoques requeridos

| Archivo         | Estrategia                      | Estado      | Envío                                                    |
| --------------- | ------------------------------- | ----------- | -------------------------------------------------------- |
| `greedy.cpp`    | Greedy, balance de llaves       | ✅ Accepted  | [36031451](https://www.spoj.com/status/ANARC09A,lmisea/) |
| `bottom_up.cpp` | Programación dinámica Bottom-Up | ✅ Accepted  | [36031515](https://www.spoj.com/status/ANARC09A,lmisea/) |
| `top_down.cpp`  | Programación dinámica Top-Down  | ⏳ Pendiente | —                                                        |

**Progreso: 2 de 3 enfoques aceptados.**

- **Greedy:** 3/3 archivos de prueba locales correctos. Envío `36031451` aceptado en SPOJ.
- **Bottom-Up:** envío `36031515` aceptado en SPOJ (0.31 s, 19 MB, según la captura del resultado).
- **Top-Down:** pendiente de implementar y comprobar.

Cada código debe explicar su idea, por qué funciona y su complejidad.

## Estructura

Los tres archivos `.cpp`, el `Makefile` y este `README.md` están directamente en `tarea-03/`; los casos compartidos están en `tarea-03/tests/`.

## Comandos

Desde la raíz del repositorio:

```bash
make -C tarea-03 all
make -C tarea-03 test-bottom_up
make -C tarea-03 test-top_down
make -C tarea-03 test-greedy
make -C tarea-03 test
make -C tarea-03 clean
```

Para ejecutar un caso concreto:

```bash
make -C tarea-03 all
./tarea-03/build/bottom_up < tarea-03/tests/01.in
```

Los casos de prueba usan pares `tests/XX.in` y `tests/XX.out`. Cada `.in` puede contener varias cadenas terminadas en una línea con guiones; la salida numera los casos desde 1.

**Entrega:** cuando los tres enfoques estén finalizados, empaquetar los archivos `.cpp` en el ZIP solicitado por el profesor.
