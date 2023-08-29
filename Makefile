.PHONY: generate test both test-parse simple

OS := $(shell uname)
ifeq ($(OS),Darwin)
	CMD_PREFIX := arch -arm64
else
	CMD_PREFIX :=
endif

# FILE=examples/a.rbl
# FILE=examples/loops.rbl
FILE=examples/methods.rbl
# FILE=examples/fn.rbl
# FILE=examples/big.rbl
# FILE=examples/err.rbl

# default: test
default: test-parse
# default: highlight
# default: both
# default: simple

both: test highlight

test: generate
	$(CMD_PREFIX) tree-sitter test

generate:
	$(CMD_PREFIX) tree-sitter generate

highlight:
	$(CMD_PREFIX) tree-sitter highlight $(FILE)

test-parse: generate
	$(CMD_PREFIX) tree-sitter parse $(FILE)
	# $(CMD_PREFIX) tree-sitter parse examples/big.rbl
	# $(CMD_PREFIX) tree-sitter parse examples/simple.rbl
	# $(CMD_PREFIX) tree-sitter parse examples/a.rbl

simple: generate
	$(CMD_PREFIX) tree-sitter parse examples/simple.rbl
