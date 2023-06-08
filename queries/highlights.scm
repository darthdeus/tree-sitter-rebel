[
  (primitive_type)
  (identifier)
  "fn"
  "let"
  "return"
  "as"
  "extern"
  "struct"
  "uninit"
] @keyword

; Comments
(comment) @comment

; Function definitions and calls
(defined_function (identifier) @function)
(extern_function (identifier) @function.macro)
(function_call (identifier) @function)

; Variables
(parameter (identifier) @variable.parameter)
(field (identifier) @variable.field)
(let (identifier) @variable)

; Type Expressions
(primitive_type) @type
(type_expr (identifier) @type)

; Constants
(string) @string
(number) @number
(call_conv) @string

; Binary operations
(binary_op (bin_op) @operator)

; Unary operations
(unary_op (un_op) @operator)

; Keywords
"fn" @keyword.function
"let" @keyword.declaration
"return" @keyword.control
"as" @keyword.operator
"extern" @keyword.directive
"struct" @keyword.type
"uninit" @keyword.directive
