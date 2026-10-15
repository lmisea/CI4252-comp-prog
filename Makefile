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
	@set -eu; \
	found=0; passed=0; failed=0; \
	for input in "$(P)"/tests/*.in; do \
	  [ -f "$$input" ] || continue; \
	  found=1; \
	  expected="$${input%.in}.out"; \
	  name=$$(basename "$${input%.in}"); \
	  if [ ! -f "$$expected" ]; then \
	    echo "FALTA salida esperada: $$expected"; failed=$$((failed+1)); continue; \
	  fi; \
	  actual="build/$$(printf '%s' '$(P)' | tr '/' '_')_$${name}.actual"; \
	  if "$(OUT)" < "$$input" > "$$actual" && diff -u "$$expected" "$$actual"; then \
	    echo "OK: $$name"; passed=$$((passed+1)); \
	  else \
	    echo "ERROR: $$name"; failed=$$((failed+1)); \
	  fi; \
	done; \
	if [ "$$found" -eq 0 ]; then echo "No hay archivos .in en $(P)/tests/"; exit 1; fi; \
	echo "Resultado: $$passed correctos, $$failed fallidos"; \
	[ "$$failed" -eq 0 ]

clean:
	rm -rf build

help:
	@echo 'make build P=tarea-02/problema-01'
	@echo 'make run P=tarea-02/problema-01'
	@echo 'make test P=tarea-02/problema-01  (todos los tests/*.in y *.out)'
	@echo 'make clean'
