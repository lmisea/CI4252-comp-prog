# CI4252 — Programación competitiva

**Luis Isea — 19-10175**
Soluciones y prácticas en C++17.

## Estructura
- `tarea-XX/problema-XX/main.cpp`: solución de cada ejercicio.
- `tarea-XX/problema-XX/entrada.txt`: caso local de prueba.
- `tarea-XX/problema-XX/esperado.txt`: salida correcta local.
- `plantillas/main.cpp`: archivo inicial para futuros ejercicios.
- `build/`: ejecutables temporales.

## Requisitos (CachyOS)
```sh
sudo pacman -S --needed gcc make git unzip
```

## Comandos desde la raíz
```sh
make build P=tarea-02/problema-01
make run P=tarea-02/problema-01
make test P=tarea-02/problema-01
make clean
```

`make run` lee de la terminal. Si prefieres probar con un archivo:
```sh
./build/tarea-02_problema-01 < tarea-02/problema-01/entrada.txt
```

`make test` compara exactamente la salida del programa con `esperado.txt` usando `diff`. Para usarlo, rellena ambos archivos primero. Espacios o saltos de línea adicionales pueden causar diferencias.


La plantilla no contiene soluciones de los ejercicios, es solo un punto de partida para empezar a programar más rápido.
