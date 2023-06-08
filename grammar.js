module.exports = grammar({
  name: "rebel",

  rules: {
    // TODO: add the actual grammar rules
    source_file: ($) => repeat($.module),

    // _definition: ($) => seq("fn", $.identifier, $.parameter_list, $.block),
    //
    // identifier: ($) => /[a-zA-Z_][a-zA-Z0-9_]*/,
    //
    // parameter_list: ($) => seq("(", $.parameters, ")"),
    //
    // parameters: ($) => seq($.identifier, repeat(seq(",", $.identifier))),
    //
    // expression: ($) => choice($.identifier, $.literal),
    //
    // assignment: ($) => seq($.identifier, "=", $.expression),
    //
    // literal: ($) => choice($.number, $.string),
    //

    string: ($) => seq('"', repeat(choice(/[^"\\]/, /\\./)), '"'),

    module: ($) => seq($.item),

    item: ($) => choice($.function, $.struct),

    function: ($) => seq("fn", $.identifier, $.parameter_list, $.block),

    parameter_list: ($) => seq("(", repeat($.parameter), ")"),

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
        $.ref_alloc,
        $.block
      ),

    function_call: ($) => seq($.identifier, repeat($.expression)),

    unary_op: ($) => seq($.un_op, $.expression),

    binary_op: ($) => seq($.expression, $.bin_op, $.expression),

    typecast: ($) => seq($.expression, "as", $.type_expr),

    statement: ($) => choice($.expression, $.return, $.let, $.assignment),

    block: ($) => seq("{", repeat($.statement), "}"),

    type_expr: ($) =>
      choice($.identifier, $.primitive_type, $.raw_ptr, $.ref, $.uninit),

    field_access: ($) => seq($.expression, ".", $.identifier),

    paren_expr: ($) => seq("(", $.expression, ")"),

    struct_literal: ($) => seq($.identifier, $.fields),

    ref_alloc: ($) => seq("&", $.expression),

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

    raw_ptr: ($) => seq("*", $.type_expr),

    ref: ($) => seq("&", $.type_expr),

    uninit: ($) => seq("uninit", $.type_expr),
  },
});
