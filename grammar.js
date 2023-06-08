function sepBy1(sep, rule) {
  return seq(rule, repeat(seq(sep, rule)));
}

function sepBy(sep, rule) {
  return optional(sepBy1(sep, rule));
}

function commaSep(rule) {
  return optional(seq(rule, repeat(seq(",", rule))));
}

function semicolonSep(rule) {
  return optional(seq(rule, repeat(seq(";", rule))));
}

module.exports = grammar({
  name: "rebel",

  rules: {
    source_file: ($) => repeat($._module),

    _module: ($) => seq(choice($.function, $.struct, $.comment)),

    function: ($) =>
      seq(
        field("modifier", optional($.extern_modifier)),
        "fn",
        field("name", $.identifier),
        field("parameters", $._parameter_list),
        optional(seq("->", field("return_type", $._type_expr))),
        choice(";", $.block)
      ),

    extern_modifier: ($) => seq("extern", field("call_conv", '"C"')),

    _parameter_list: ($) => seq("(", commaSep($.parameter), ")"),
    parameter: ($) => seq($.identifier, ":", $._type_expr),

    struct: ($) => seq("struct", $.identifier, $.fields),
    fields: ($) => seq("{", repeat($.field), "}"),
    field: ($) => seq($.identifier, ":", $._type_expr, optional(",")),

    string: ($) => seq('"', repeat(choice(/[^"\\]/, /\\./)), '"'),
    identifier: ($) => /[a-zA-Z_][a-zA-Z0-9_]*/,
    number: ($) => /\d+/,
    bin_op: ($) => choice("+", "-", "*", "/"),
    un_op: ($) => choice("-", "*", "&"),

    _expression: ($) =>
      choice(
        $.identifier,
        $.number,
        $.string,
        $.function_call,
        $.unary_op,
        $.binary_op,
        $.typecast,
        $.field_access,
        $.paren_expr,
        $.struct_literal,
        // $.ref_alloc,
        $.block
      ),

    block: ($) => seq("{", repeat($.statement), "}"),

    function_call: ($) =>
      prec(1, seq($.identifier, "(", commaSep($._expression), ")")),

    struct_literal: ($) => prec(1, seq($.identifier, $.field_values)),

    field_values: ($) =>
      seq(
        "{",
        repeat(seq($.identifier, ":", $._expression, optional(","))),
        "}"
      ),

    unary_op: ($) => prec(2, seq($.un_op, $._expression)),
    binary_op: ($) => prec.left(1, seq($._expression, $.bin_op, $._expression)),
    typecast: ($) => seq($._expression, "as", $._type_expr),

    statement: ($) =>
      seq(
        choice($.comment, $._expression, $.return, $.let, $.assignment),
        optional(";")
      ),

    comment: ($) => token(seq("//", /.*/)),

    field_access: ($) => seq($._expression, ".", $.identifier),

    _type_expr: ($) => choice($.identifier, $.primitive_type, $.generic_type),
    generic_type: ($) =>
      seq(
        field("type", $.identifier),
        "<",
        field("type_args", sepBy1(",", $.identifier), optional(",")),
        ">"
      ),

    paren_expr: ($) => seq("(", $._expression, ")"),

    return: ($) => seq("return", $._expression),

    let: ($) =>
      seq(
        "let",
        $.identifier,
        optional(seq(":", $._type_expr)),
        "=",
        $._expression
      ),

    assignment: ($) => seq($._expression, "=", $._expression),

    primitive_type: ($) =>
      choice(
        "i8",
        "i16",
        "i32",
        "i64",
        "u8",
        "u16",
        "u32",
        "u64",
        "f32",
        "f64",
        "bool"
      ),
  },
});
