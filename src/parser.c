#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 32
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 27
#define ALIAS_COUNT 0
#define TOKEN_COUNT 13
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_fn = 1,
  sym_identifier = 2,
  anon_sym_LPAREN = 3,
  anon_sym_RPAREN = 4,
  anon_sym_COMMA = 5,
  anon_sym_LBRACE = 6,
  anon_sym_RBRACE = 7,
  anon_sym_EQ = 8,
  sym_number = 9,
  anon_sym_DQUOTE = 10,
  aux_sym_string_token1 = 11,
  aux_sym_string_token2 = 12,
  sym_source_file = 13,
  sym__definition = 14,
  sym_parameter_list = 15,
  sym_parameters = 16,
  sym_block = 17,
  sym__statement = 18,
  sym_expression = 19,
  sym_assignment = 20,
  sym_literal = 21,
  sym_string = 22,
  aux_sym_source_file_repeat1 = 23,
  aux_sym_parameters_repeat1 = 24,
  aux_sym_block_repeat1 = 25,
  aux_sym_string_repeat1 = 26,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_fn] = "fn",
  [sym_identifier] = "identifier",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COMMA] = ",",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_EQ] = "=",
  [sym_number] = "number",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token1] = "string_token1",
  [aux_sym_string_token2] = "string_token2",
  [sym_source_file] = "source_file",
  [sym__definition] = "_definition",
  [sym_parameter_list] = "parameter_list",
  [sym_parameters] = "parameters",
  [sym_block] = "block",
  [sym__statement] = "_statement",
  [sym_expression] = "expression",
  [sym_assignment] = "assignment",
  [sym_literal] = "literal",
  [sym_string] = "string",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_parameters_repeat1] = "parameters_repeat1",
  [aux_sym_block_repeat1] = "block_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_fn] = anon_sym_fn,
  [sym_identifier] = sym_identifier,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_number] = sym_number,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [aux_sym_string_token2] = aux_sym_string_token2,
  [sym_source_file] = sym_source_file,
  [sym__definition] = sym__definition,
  [sym_parameter_list] = sym_parameter_list,
  [sym_parameters] = sym_parameters,
  [sym_block] = sym_block,
  [sym__statement] = sym__statement,
  [sym_expression] = sym_expression,
  [sym_assignment] = sym_assignment,
  [sym_literal] = sym_literal,
  [sym_string] = sym_string,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_parameters_repeat1] = aux_sym_parameters_repeat1,
  [aux_sym_block_repeat1] = aux_sym_block_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_fn] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__definition] = {
    .visible = false,
    .named = true,
  },
  [sym_parameter_list] = {
    .visible = true,
    .named = true,
  },
  [sym_parameters] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment] = {
    .visible = true,
    .named = true,
  },
  [sym_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameters_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(5);
      if (lookahead == '"') ADVANCE(15);
      if (lookahead == '(') ADVANCE(8);
      if (lookahead == ')') ADVANCE(9);
      if (lookahead == ',') ADVANCE(10);
      if (lookahead == '=') ADVANCE(13);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead == 'f') ADVANCE(3);
      if (lookahead == '{') ADVANCE(11);
      if (lookahead == '}') ADVANCE(12);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(15);
      if (lookahead == '=') ADVANCE(13);
      if (lookahead == '}') ADVANCE(12);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(7);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(15);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(17);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 3:
      if (lookahead == 'n') ADVANCE(6);
      END_STATE();
    case 4:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(18);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(7);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym_string_token1);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(16);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(aux_sym_string_token2);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 2},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 1},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_fn] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [aux_sym_string_token2] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(30),
    [sym__definition] = STATE(16),
    [aux_sym_source_file_repeat1] = STATE(16),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_fn] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(9), 1,
      anon_sym_RBRACE,
    ACTIONS(11), 1,
      sym_number,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    STATE(8), 1,
      sym_string,
    STATE(14), 1,
      sym_literal,
    STATE(4), 4,
      sym__statement,
      sym_expression,
      sym_assignment,
      aux_sym_block_repeat1,
  [25] = 7,
    ACTIONS(15), 1,
      sym_identifier,
    ACTIONS(18), 1,
      anon_sym_RBRACE,
    ACTIONS(20), 1,
      sym_number,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    STATE(8), 1,
      sym_string,
    STATE(14), 1,
      sym_literal,
    STATE(3), 4,
      sym__statement,
      sym_expression,
      sym_assignment,
      aux_sym_block_repeat1,
  [50] = 7,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(11), 1,
      sym_number,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(26), 1,
      anon_sym_RBRACE,
    STATE(8), 1,
      sym_string,
    STATE(14), 1,
      sym_literal,
    STATE(3), 4,
      sym__statement,
      sym_expression,
      sym_assignment,
      aux_sym_block_repeat1,
  [75] = 6,
    ACTIONS(11), 1,
      sym_number,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(28), 1,
      sym_identifier,
    STATE(8), 1,
      sym_string,
    STATE(12), 1,
      sym_expression,
    STATE(14), 1,
      sym_literal,
  [94] = 2,
    ACTIONS(32), 1,
      anon_sym_EQ,
    ACTIONS(30), 4,
      sym_identifier,
      anon_sym_RBRACE,
      sym_number,
      anon_sym_DQUOTE,
  [104] = 1,
    ACTIONS(34), 4,
      sym_identifier,
      anon_sym_RBRACE,
      sym_number,
      anon_sym_DQUOTE,
  [111] = 1,
    ACTIONS(36), 4,
      sym_identifier,
      anon_sym_RBRACE,
      sym_number,
      anon_sym_DQUOTE,
  [118] = 4,
    ACTIONS(38), 1,
      anon_sym_DQUOTE,
    ACTIONS(40), 1,
      aux_sym_string_token1,
    ACTIONS(43), 1,
      aux_sym_string_token2,
    STATE(9), 1,
      aux_sym_string_repeat1,
  [131] = 1,
    ACTIONS(46), 4,
      sym_identifier,
      anon_sym_RBRACE,
      sym_number,
      anon_sym_DQUOTE,
  [138] = 4,
    ACTIONS(48), 1,
      anon_sym_DQUOTE,
    ACTIONS(50), 1,
      aux_sym_string_token1,
    ACTIONS(52), 1,
      aux_sym_string_token2,
    STATE(13), 1,
      aux_sym_string_repeat1,
  [151] = 1,
    ACTIONS(54), 4,
      sym_identifier,
      anon_sym_RBRACE,
      sym_number,
      anon_sym_DQUOTE,
  [158] = 4,
    ACTIONS(56), 1,
      anon_sym_DQUOTE,
    ACTIONS(58), 1,
      aux_sym_string_token1,
    ACTIONS(60), 1,
      aux_sym_string_token2,
    STATE(9), 1,
      aux_sym_string_repeat1,
  [171] = 1,
    ACTIONS(30), 4,
      sym_identifier,
      anon_sym_RBRACE,
      sym_number,
      anon_sym_DQUOTE,
  [178] = 3,
    ACTIONS(62), 1,
      ts_builtin_sym_end,
    ACTIONS(64), 1,
      anon_sym_fn,
    STATE(15), 2,
      sym__definition,
      aux_sym_source_file_repeat1,
  [189] = 3,
    ACTIONS(5), 1,
      anon_sym_fn,
    ACTIONS(67), 1,
      ts_builtin_sym_end,
    STATE(15), 2,
      sym__definition,
      aux_sym_source_file_repeat1,
  [200] = 3,
    ACTIONS(69), 1,
      anon_sym_RPAREN,
    ACTIONS(71), 1,
      anon_sym_COMMA,
    STATE(18), 1,
      aux_sym_parameters_repeat1,
  [210] = 3,
    ACTIONS(73), 1,
      anon_sym_RPAREN,
    ACTIONS(75), 1,
      anon_sym_COMMA,
    STATE(18), 1,
      aux_sym_parameters_repeat1,
  [220] = 3,
    ACTIONS(71), 1,
      anon_sym_COMMA,
    ACTIONS(78), 1,
      anon_sym_RPAREN,
    STATE(17), 1,
      aux_sym_parameters_repeat1,
  [230] = 1,
    ACTIONS(80), 2,
      ts_builtin_sym_end,
      anon_sym_fn,
  [235] = 2,
    ACTIONS(82), 1,
      sym_identifier,
    STATE(27), 1,
      sym_parameters,
  [242] = 1,
    ACTIONS(73), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [247] = 2,
    ACTIONS(84), 1,
      anon_sym_LBRACE,
    STATE(26), 1,
      sym_block,
  [254] = 2,
    ACTIONS(86), 1,
      anon_sym_LPAREN,
    STATE(23), 1,
      sym_parameter_list,
  [261] = 1,
    ACTIONS(88), 2,
      ts_builtin_sym_end,
      anon_sym_fn,
  [266] = 1,
    ACTIONS(90), 2,
      ts_builtin_sym_end,
      anon_sym_fn,
  [271] = 1,
    ACTIONS(92), 1,
      anon_sym_RPAREN,
  [275] = 1,
    ACTIONS(94), 1,
      sym_identifier,
  [279] = 1,
    ACTIONS(96), 1,
      anon_sym_LBRACE,
  [283] = 1,
    ACTIONS(98), 1,
      ts_builtin_sym_end,
  [287] = 1,
    ACTIONS(100), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 25,
  [SMALL_STATE(4)] = 50,
  [SMALL_STATE(5)] = 75,
  [SMALL_STATE(6)] = 94,
  [SMALL_STATE(7)] = 104,
  [SMALL_STATE(8)] = 111,
  [SMALL_STATE(9)] = 118,
  [SMALL_STATE(10)] = 131,
  [SMALL_STATE(11)] = 138,
  [SMALL_STATE(12)] = 151,
  [SMALL_STATE(13)] = 158,
  [SMALL_STATE(14)] = 171,
  [SMALL_STATE(15)] = 178,
  [SMALL_STATE(16)] = 189,
  [SMALL_STATE(17)] = 200,
  [SMALL_STATE(18)] = 210,
  [SMALL_STATE(19)] = 220,
  [SMALL_STATE(20)] = 230,
  [SMALL_STATE(21)] = 235,
  [SMALL_STATE(22)] = 242,
  [SMALL_STATE(23)] = 247,
  [SMALL_STATE(24)] = 254,
  [SMALL_STATE(25)] = 261,
  [SMALL_STATE(26)] = 266,
  [SMALL_STATE(27)] = 271,
  [SMALL_STATE(28)] = 275,
  [SMALL_STATE(29)] = 279,
  [SMALL_STATE(30)] = 283,
  [SMALL_STATE(31)] = 287,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(6),
  [18] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(8),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(11),
  [26] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [28] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1),
  [38] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(9),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(9),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [48] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [52] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment, 3),
  [56] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(28),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 2),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2), SHIFT_REPEAT(31),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 1),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__definition, 4),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 3),
  [98] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_rebel(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
