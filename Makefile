.PHONY: generate test

OS := $(shell uname)
ifeq ($(OS),Darwin)
	CMD_PREFIX := arch -arm64
else
	CMD_PREFIX :=
endif

default: test

generate:
	$(CMD_PREFIX) tree-sitter generate

test: generate
	$(CMD_PREFIX) tree-sitter parse examples/simple.rbl
	# $(CMD_PREFIX) tree-sitter parse examples/a.rbl
