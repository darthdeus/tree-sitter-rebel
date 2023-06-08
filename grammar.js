function commaSep(rule) {
  return optional(seq(rule, repeat(seq(",", rule))));
}

module.exports = grammar({
  name: "rebel",

  rules: {
    source_file: ($) => repeat($.module),

    string: ($) => seq('"', repeat(choice(/[^"\\]/, /\\./)), '"'),

    module: ($) => seq($.item),

    item: ($) => choice($.function, $.struct),

    function: ($) => choice($.defined_function, $.extern_function),
    defined_function: ($) =>
      seq(
        "fn",
        $.identifier,
        $.parameter_list,
        optional(seq("->", $.type_expr)),
        $.block
      ),

    extern_function: ($) =>
      seq(
        "extern",
        '"C"',
        "fn",
        $.identifier,
        $.parameter_list,
        optional(seq("->", $.type_expr)),
        ";"
      ),

    extern: ($) => seq("extern", $.string),

    parameter_list: ($) => seq("(", commaSep($.parameter), ")"),

    parameter: ($) => seq($.identifier, ":", $.type_expr),

    struct: ($) => seq("struct", $.identifier, $.fields),

    fields: ($) => seq("{", repeat($.field), "}"),

    field: ($) => seq($.identifier, ":", $.type_expr),

    identifier: ($) => /[a-zA-Z_][a-zA-Z0-9_]*/,

    number: ($) => /\d+/,

    bin_op: ($) => choice("+", "-", "*", "/"),

    un_op: ($) => choice("-", "*"),

    expression: ($) =>
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

    function_call: ($) =>
      prec(1, seq($.identifier, "(", repeat($.expression), ")")),

    struct_literal: ($) => prec(1, seq($.identifier, $.fields)),

    unary_op: ($) => prec(2, seq($.un_op, $.expression)),

    binary_op: ($) => prec.left(1, seq($.expression, $.bin_op, $.expression)),

    typecast: ($) => seq($.expression, "as", $.type_expr),

    statement: ($) => choice($.expression, $.return, $.let, $.assignment),

    block: ($) => seq("{", repeat($.statement), "}"),

    type_expr: ($) =>
      choice($.identifier, $.primitive_type, $.raw_ptr, $.ref, $.uninit),

    field_access: ($) => seq($.expression, ".", $.identifier),

    paren_expr: ($) => seq("(", $.expression, ")"),

    // ref_alloc: ($) => seq("&", $.expression),

    return: ($) => seq("return", $.expression),

    let: ($) => seq("let", $.identifier, "=", $.expression),

    assignment: ($) => seq($.expression, "=", $.expression),

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

    raw_ptr: ($) => seq("RawPtr<", $.type_expr, ">"),

    ref: ($) => seq("Ref<", $.type_expr, ">"),

    uninit: ($) => seq("uninit", $.type_expr),
  },
});
