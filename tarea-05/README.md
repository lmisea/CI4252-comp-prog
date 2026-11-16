# Tarea 5 — Multiplicación de polinomios con FFT

**Problema:** [POLYMUL — Polynomial Multiplication (SPOJ)](https://www.spoj.com/problems/POLYMUL/)

**Estado:** ✅ Accepted en SPOJ. **15/15 pruebas locales correctas** (0 fallidas).

**Envío:** `36088012` · **Fecha:** 16 de noviembre de 2026 · **Tiempo:** 0.25 s · **Memoria:** 3.3 MB · **Lenguaje del envío:** C++14 (implementación compatible con C++17).

## Enunciado resumido

Se reciben `T` casos de prueba. Para cada caso se proporciona el grado `n` de dos polinomios y sus `n+1` coeficientes, **ordenados de mayor a menor grado**. Debemos imprimir los `2n+1` coeficientes del polinomio producto, también de mayor a menor grado.

Restricciones principales: `T <= 10`, `n <= 10000`, coeficientes de hasta `1000`, tiempo límite de `1 s`. La tarea pide usar **FFT**. Los coeficientes del producto pueden superar el rango de `int`, por lo que conviene trabajar con `long long` para el resultado.

## Archivos

```text
tarea-05/
├── README.md
└── problema-01/
    ├── main.cpp          # Solución FFT recursiva
    └── tests/
        ├── 01.in
        ├── 01.out
        └── ... hasta 15.in / 15.out
```

## Compilación y pruebas

Ejecutar desde la raíz del repositorio con el Makefile principal:

```bash
make build P=tarea-05/problema-01
make test  P=tarea-05/problema-01
make run  P=tarea-05/problema-01
```

## Solución implementada

Se utiliza una **FFT recursiva** para transformar los arreglos de coeficientes y calcular la convolución mediante multiplicación punto a punto:

1. Leer los coeficientes de mayor a menor grado y almacenarlos internamente de menor a mayor.
2. Calcular `2*n + 1`, la cantidad de coeficientes del producto, y ampliar ambos arreglos con ceros hasta la siguiente potencia de dos.
3. Aplicar la FFT directa, dividiendo recursivamente los coeficientes de índices pares e impares y combinando ambas mitades con raíces de la unidad (mariposas).
4. Multiplicar los valores transformados posición por posición.
5. Aplicar la FFT inversa, dividir cada resultado entre el tamaño de la transformada y redondear la parte real al entero más cercano con `llround`.
6. Imprimir los coeficientes desde el grado `2*n` hasta el término independiente.

**Complejidad:** `O(n log n)` en tiempo y `O(n)` en memoria auxiliar, donde `n` es el grado de los polinomios de entrada. Se utilizan `complex<double>` para la transformada y `long long` para los coeficientes enteros finales.

## Casos de prueba

| Archivo            | Qué comprueba                                       |
| ------------------ | --------------------------------------------------- |
| `01.in` / `01.out` | Ejemplo oficial: dos casos de grado 2               |
| `02.in` / `02.out` | Grado 1: multiplicaciones pequeñas                  |
| `03.in` / `03.out` | Grado 2: términos nulos y distintos patrones        |
| `04.in` / `04.out` | Grado 3: polinomios dispersos, identidad y cero     |
| `05.in` / `05.out` | Grado 4: coeficientes al límite y acumulación       |
| `06.in` / `06.out` | Varios casos de grado 5 a 10 con números pequeños   |
| `07.in` / `07.out` | Grado 15: alternancias y ceros                      |
| `08.in` / `08.out` | Grado 31 y 32: tamaños alrededor de potencia de dos |
| `09.in` / `09.out` | Grado 63 y 64: bordes de potencia de dos            |
| `10.in` / `10.out` | Grado 127 y 128: coeficientes densos                |
| `11.in` / `11.out` | Grado 255: polinomios uniformes                     |
| `12.in` / `12.out` | Grado 512: polinomios aleatorios                    |
| `13.in` / `13.out` | Grado 1024: entradas con muchos ceros               |
| `14.in` / `14.out` | Grado 4096: prueba de rendimiento                   |
| `15.in` / `15.out` | Grado máximo 10000: prueba de rendimiento y límites |

El caso `01` contiene exactamente los ejemplos oficiales. Se incluyen pruebas grandes de grado `4096` y `10000` para comprobar rendimiento, además de patrones con coeficientes cero, densos y uniformes.

Las salidas esperadas se generaron automáticamente mediante convolución y se verificaron con cálculos enteros independientes en posiciones seleccionadas.

**Resultado local:** `15 correctos, 0 fallidos`, ejecutando `make build P=tarea-05/problema-01 && make test P=tarea-05/problema-01` en GNU C++17 con `-O2 -Wall -Wextra -Wpedantic`.

**Resultado en el juez:** `Accepted` en SPOJ, envío **36088012** del **16/11/2026**, con tiempo **0.25 s** y memoria **3.3 MB** (lenguaje reportado por SPOJ: **CPP14**).

## Puntos clave de la solución

- Por qué la multiplicación directa necesita aproximadamente `O(n²)` operaciones.
- Qué representa cada coeficiente del producto.
- Qué aporta la FFT y por qué reduce el costo a aproximadamente `O(n log n)`.
- Cómo se elige el tamaño de trabajo y cómo se recuperan coeficientes enteros al final.

**Entrega:** subir la solución a GitHub y entregar únicamente la URL del repositorio, según la instrucción de la tarea.
