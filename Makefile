CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -Wpedantic
P ?= tarea-02/problema-01
SRC := $(P)/main.cpp
OUT := build/$(subst /,_,$(P))

.PHONY: all build run test clean help
all: build

build:
	@test -f "$(SRC)" || (echo "No existe $(SRC)"; exit 1)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) "$(SRC)" -o "$(OUT)"

run: build
	@"$(OUT)"

test: build
	@test -s "$(P)/entrada.txt" || (echo "Completa $(P)/entrada.txt primero"; exit 1)
	@test -s "$(P)/esperado.txt" || (echo "Completa $(P)/esperado.txt primero"; exit 1)
	@"$(OUT)" < "$(P)/entrada.txt" > "build/salida.txt"
	@diff -u "$(P)/esperado.txt" "build/salida.txt" && echo "Prueba OK"

clean:
	rm -rf build

help:
	@echo 'make build P=tarea-02/problema-01'
	@echo 'make run P=tarea-02/problema-01   (escribe datos por stdin)'
	@echo 'make test P=tarea-02/problema-01  (entrada.txt vs esperado.txt)'
	@echo 'make clean'
