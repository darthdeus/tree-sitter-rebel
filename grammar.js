module.exports = grammar({
  name: "rebel",

  rules: {
    // TODO: add the actual grammar rules
    source_file: ($) => repeat($._definition),

    _definition: ($) => seq("fn", $.identifier, $.parameter_list, $.block),

    identifier: ($) => /[a-zA-Z_][a-zA-Z0-9_]*/,

    parameter_list: ($) => seq("(", $.parameters, ")"),

    parameters: ($) => seq($.identifier, repeat(seq(",", $.identifier))),

    block: ($) => seq("{", repeat($._statement), "}"),

    _statement: ($) => choice($.expression, $.assignment),

    expression: ($) => choice($.identifier, $.literal),

    assignment: ($) => seq($.identifier, "=", $.expression),

    literal: ($) => choice($.number, $.string),

    number: ($) => /\d+/,

    string: ($) => seq('"', repeat(choice(/[^"\\]/, /\\./)), '"'),
  },
});
