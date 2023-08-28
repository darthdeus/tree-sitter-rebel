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
    source_file: ($) => repeat($._item),

    _item: ($) =>
      choice(
        $.function,
        $.struct,
        $.enum,
        $.global,
        $.macro_def,
        $.macro_expr,
        $.impl_block,
      ),

    function: ($) =>
      seq(
        field("modifier", optional($.extern_modifier)),
        "fn",
        field("name", $.identifier),
        field("parameters", $._parameter_list),
        optional(seq("->", field("return_type", $._type_expr))),
        choice(";", $.block),
      ),

    struct: ($) =>
      seq("struct", field("name", $.identifier), field("fields", $.fields)),

    enum: ($) =>
      seq(
        "enum",
        field("name", $.identifier),
        field("variants", $.enum_variants),
      ),

    global: ($) =>
      seq(
        "global",
        field("name", $.identifier),
        ":",
        field("type", $._type_expr),
        "=",
        field("value", $._expression),
        ";",
      ),

    macro_def: ($) => seq("macro", field("name", $.identifier)),
    macro_expr: ($) =>
      seq("$", field("name", $.identifier), "(", $.identifier, ")"),

    impl_block: ($) => seq("impl", field("type", $._type_expr), $.block),

    enum_variants: ($) => repeat1(seq($.identifier, optional($._type_expr))),

    _expression: ($) =>
      choice(
        $.condition,
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
        $.array_literal,
        $.block,
      ),

    extern_modifier: ($) => seq("extern", field("call_conv", '"C"')),

    _parameter_list: ($) => seq("(", commaSep($.parameter), ")"),
    parameter: ($) => seq($.identifier, ":", $._type_expr),

    statement: ($) =>
      seq(
        choice(
          $._expression,
          $.return,
          $.let,
          $.assignment,
          $.for,
          $.macro_expr,
        ),
        ";",
      ),

    for: ($) =>
      seq(
        "for",
        field("ident", $.identifier),
        "in",
        field("from", $._expression),
        "..",
        field("to", $._expression),
        "{",
        field("body", $.block),
        "}",
      ),

    block: ($) =>
      seq(
        "{",
        field("statements", repeat($.statement)),
        field("return_expr", optional($._expression)),
        "}",
      ),

    condition: ($) =>
      seq(
        "if",
        field("condition", $._expression),
        $.block,
        optional(seq("else", field("else_branch", $.block))),
      ),

    function_call: ($) =>
      prec(1, seq($.identifier, "(", commaSep($._expression), ")")),

    struct_literal: ($) => prec(1, seq($.identifier, $.field_values)),

    array_literal: ($) => seq("[", repeat(seq($._expression)), "]"),

    field_values: ($) =>
      seq(
        "{",
        repeat(seq($.identifier, ":", $._expression, optional(","))),
        "}",
      ),

    fields: ($) => seq("{", repeat($.field), "}"),
    field: ($) =>
      seq(
        field("name", $.identifier),
        ":",
        field("type", $._type_expr),
        optional(","),
      ),

    bin_op: ($) => choice("+", "-", "*", "/"),
    un_op: ($) => choice("-", "*", "&"),

    unary_op: ($) => prec(2, seq($.un_op, $._expression)),
    binary_op: ($) => prec.left(1, seq($._expression, $.bin_op, $._expression)),
    typecast: ($) => seq($._expression, "as", $._type_expr),

    comment: ($) => token(seq("//", /.*/)),

    field_access: ($) => seq($._expression, ".", $.identifier),

    _type_expr: ($) => choice($.identifier, $.primitive_type, $.generic_type),

    generic_type: ($) =>
      seq(
        field("type", $.identifier),
        "<",
        field("type_args", sepBy1(",", $.identifier), optional(",")),
        ">",
      ),

    paren_expr: ($) => seq("(", $._expression, ")"),
    return: ($) => seq("return", $._expression),

    let: ($) =>
      seq(
        "let",
        $.identifier,
        optional(seq(":", $._type_expr)),
        "=",
        $._expression,
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
        "bool",
      ),

    string: ($) => seq('"', repeat(choice(/[^"\\]/, /\\./)), '"'),

    identifier: ($) => /[a-zA-Z_][a-zA-Z0-9_]*/,
    // identifier: ($) => /(?!\bif\b)[a-zA-Z_][a-zA-Z0-9_]*/,

    number: ($) => {
      const decimal_digits = /\d(_?\d)*/;
      const signed_operators = optional(/[-\+]/);
      const signed_integer = seq(signed_operators, decimal_digits);
      const decimal_integer_literal = seq(
        choice(
          "0",
          seq(
            optional("0"),
            /[1-9]/,
            optional(seq(optional("_"), decimal_digits)),
          ),
        ),
      );
      const hex_literal = seq(choice("0x", "0X"), /[\da-fA-F](_?[\da-fA-F])*/);

      const exponent_part = seq(choice("e", "E"), signed_integer);
      const binary_literal = seq(choice("0b", "0B"), /[0-1](_?[0-1])*/);
      const octal_literal = seq(choice("0o", "0O"), /[0-7](_?[0-7])*/);
      const bigint_literal = seq(
        choice(hex_literal, binary_literal, octal_literal, decimal_digits),
        "n",
      );

      const decimal_literal = choice(
        seq(
          signed_operators,
          decimal_integer_literal,
          ".",
          optional(decimal_digits),
          optional(exponent_part),
        ),
        seq(signed_operators, ".", decimal_digits, optional(exponent_part)),
        seq(signed_operators, decimal_integer_literal, exponent_part),
        seq(signed_operators, decimal_digits),
      );

      return token(
        choice(
          hex_literal,
          decimal_literal,
          binary_literal,
          octal_literal,
          bigint_literal,
        ),
      );
    },
  },
});
