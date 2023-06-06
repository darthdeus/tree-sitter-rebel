.PHONY: generate test

default: test

generate:
	arch -arm64 tree-sitter generate

test: generate
	arch -arm64 tree-sitter parse examples/simple.rbl
