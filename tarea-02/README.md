# Tarea 2 — CI4252 Programación Competitiva

**Luis Isea — 19-10175**

| Carpeta       | Problema                    | Enlace                                        | Estado       |
| ------------- | --------------------------- | --------------------------------------------- | ------------ |
| `problema-01` | 1230B — Ania and Minimizing | https://codeforces.com/contest/1230/problem/B | Por resolver |
| `problema-02` | 985C — Liebig's Barrels     | https://codeforces.com/contest/985/problem/C  | Por resolver |
| `problema-03` | 492C — Vanya and Exams      | https://codeforces.com/contest/492/problem/C  | Por resolver |
| `problema-04` | 101A — Homework             | https://codeforces.com/contest/101/problem/A  | Por resolver |

Cada carpeta contiene `main.cpp` (plantilla vacía) y una carpeta `tests/` con los ejemplos oficiales numerados: `01.in`, `01.out`, etc.

Desde la raíz del repositorio:

```sh
make build P=tarea-02/problema-01
make test P=tarea-02/problema-01
make run P=tarea-02/problema-01
```

Para agregar otro caso, crea `tests/04.in` y `tests/04.out` con el mismo número (elige el siguiente número disponible). `make test` recorre **todos** los archivos `.in` y comprueba su salida esperada con `diff`. Las plantillas están vacías, por lo que los tests no pasarán hasta implementar las soluciones.

**Ojo con el problema 101A (Homework):** Codeforces permite distintas respuestas correctas. `make test` compara contra una respuesta de ejemplo específica, de modo que un `ERROR` puede ser un falso negativo si tu subsecuencia es diferente pero válida. En ese caso comprueba las condiciones del enunciado o el resultado enviado a Codeforces.

Los ejemplos no sustituyen las pruebas de casos límite ni el veredicto de Codeforces. La tarea pide resolver individualmente, con comentarios explicando idea, corrección y optimalidad.
