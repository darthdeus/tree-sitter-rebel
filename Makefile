.PHONY: generate test

default: test

generate:
	tree-sitter generate

test:
	tree-sitter parse examples/a.rbl
