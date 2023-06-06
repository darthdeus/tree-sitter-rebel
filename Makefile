.PHONY: generate test

default: test

generate:
	arch -arm64 tree-sitter generate

test:
	arch -arm64 tree-sitter parse examples/a.rbl
