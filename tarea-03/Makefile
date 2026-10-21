CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -Wpedantic
METHODS := bottom_up top_down greedy
BUILD_DIR := build

.PHONY: all test clean
all: $(addprefix $(BUILD_DIR)/,$(METHODS))

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

test: $(addprefix test-,$(METHODS))

test-%: $(BUILD_DIR)/%
	@set -eu; count=0; for input in tests/*.in; do \
	  name=$${input%.in}; output=$${name}.out; actual=$$(mktemp); \
	  if ./$(BUILD_DIR)/$* < "$$input" > "$$actual" && diff -u "$$output" "$$actual"; then \
	    printf 'OK (%s): %s\n' '$*' "$$input"; \
	  else \
	    printf 'FALLO (%s): %s\n' '$*' "$$input"; rm -f "$$actual"; exit 1; \
	  fi; \
	  rm -f "$$actual"; count=$$((count+1)); \
	done; printf '%s: %s casos correctos\n' '$*' "$$count"

clean:
	rm -rf $(BUILD_DIR)
