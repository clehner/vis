#ifndef VIS_H
#define VIS_H

#include "ui.h"
#include "editor.h"

typedef Editor Vis;

Vis *vis_new(Ui*);
#define vis_free editor_free

void vis_run(Vis*, int argc, char *argv[]);
void vis_die(Vis*, const char *msg, ...);

enum VisMode {
	VIS_MODE_BASIC,
	VIS_MODE_MOVE,
	VIS_MODE_OPERATOR,
	VIS_MODE_OPERATOR_OPTION,
	VIS_MODE_NORMAL,
	VIS_MODE_TEXTOBJ,
	VIS_MODE_VISUAL,
	VIS_MODE_VISUAL_LINE,
	VIS_MODE_READLINE,
	VIS_MODE_PROMPT,
	VIS_MODE_INSERT,
	VIS_MODE_REPLACE,
	VIS_MODE_LAST,
};

void vis_mode_switch(Vis*, enum VisMode);

enum VisOperator {
	OP_DELETE,
	OP_CHANGE,
	OP_YANK,
	OP_PUT,
	OP_SHIFT_RIGHT,
	OP_SHIFT_LEFT,
	OP_CASE_CHANGE,
	OP_JOIN,
	OP_REPEAT_INSERT,
	OP_REPEAT_REPLACE,
	OP_CURSOR,
};

void vis_operator(Vis*, enum VisOperator);

enum VisMotion {
	MOVE_LINE_DOWN,
	MOVE_LINE_UP,
	MOVE_SCREEN_LINE_UP,
	MOVE_SCREEN_LINE_DOWN,
	MOVE_SCREEN_LINE_BEGIN,
	MOVE_SCREEN_LINE_MIDDLE,
	MOVE_SCREEN_LINE_END,
	MOVE_LINE_PREV,
	MOVE_LINE_BEGIN,
	MOVE_LINE_START,
	MOVE_LINE_FINISH,
	MOVE_LINE_LASTCHAR,
	MOVE_LINE_END,
	MOVE_LINE_NEXT,
	MOVE_LINE,
	MOVE_COLUMN,
	MOVE_CHAR_PREV,
	MOVE_CHAR_NEXT,
	MOVE_LINE_CHAR_PREV,
	MOVE_LINE_CHAR_NEXT,
	MOVE_WORD_START_NEXT,
	MOVE_WORD_END_PREV,
	MOVE_WORD_END_NEXT,
	MOVE_WORD_START_PREV,
	MOVE_LONGWORD_START_PREV,
	MOVE_LONGWORD_START_NEXT,
	MOVE_LONGWORD_END_PREV,
	MOVE_LONGWORD_END_NEXT,
	MOVE_SENTENCE_PREV,
	MOVE_SENTENCE_NEXT,
	MOVE_PARAGRAPH_PREV,
	MOVE_PARAGRAPH_NEXT,
	MOVE_FUNCTION_START_PREV,
	MOVE_FUNCTION_START_NEXT,
	MOVE_FUNCTION_END_PREV,
	MOVE_FUNCTION_END_NEXT,
	MOVE_BRACKET_MATCH,
	MOVE_LEFT_TO,
	MOVE_RIGHT_TO,
	MOVE_LEFT_TILL,
	MOVE_RIGHT_TILL,
	MOVE_FILE_BEGIN,
	MOVE_FILE_END,
	MOVE_MARK,
	MOVE_MARK_LINE,
	MOVE_SEARCH_WORD_FORWARD,
	MOVE_SEARCH_WORD_BACKWARD,
	MOVE_SEARCH_FORWARD,
	MOVE_SEARCH_BACKWARD,
	MOVE_WINDOW_LINE_TOP,
	MOVE_WINDOW_LINE_MIDDLE,
	MOVE_WINDOW_LINE_BOTTOM,
	/* pseudo motions: keep them at the end to save space in array definition */
	MOVE_TOTILL_REPEAT,
	MOVE_TOTILL_REVERSE,
};

void vis_motion(Vis*, enum VisMotion, ...);

enum VisTextObject {
	TEXT_OBJ_INNER_WORD,
	TEXT_OBJ_OUTER_WORD,
	TEXT_OBJ_INNER_LONGWORD,
	TEXT_OBJ_OUTER_LONGWORD,
	TEXT_OBJ_SENTENCE,
	TEXT_OBJ_PARAGRAPH,
	TEXT_OBJ_OUTER_SQUARE_BRACKET,
	TEXT_OBJ_INNER_SQUARE_BRACKET,
	TEXT_OBJ_OUTER_CURLY_BRACKET,
	TEXT_OBJ_INNER_CURLY_BRACKET,
	TEXT_OBJ_OUTER_ANGLE_BRACKET,
	TEXT_OBJ_INNER_ANGLE_BRACKET,
	TEXT_OBJ_OUTER_PARANTHESE,
	TEXT_OBJ_INNER_PARANTHESE,
	TEXT_OBJ_OUTER_QUOTE,
	TEXT_OBJ_INNER_QUOTE,
	TEXT_OBJ_OUTER_SINGLE_QUOTE,
	TEXT_OBJ_INNER_SINGLE_QUOTE,
	TEXT_OBJ_OUTER_BACKTICK,
	TEXT_OBJ_INNER_BACKTICK,
	TEXT_OBJ_OUTER_ENTIRE,
	TEXT_OBJ_INNER_ENTIRE,
	TEXT_OBJ_OUTER_FUNCTION,
	TEXT_OBJ_INNER_FUNCTION,
	TEXT_OBJ_OUTER_LINE,
	TEXT_OBJ_INNER_LINE,
};

void vis_textobject(Vis*, enum VisTextObject);

bool vis_cmd(Vis*, const char *cmdline);

const char *vis_keys(Vis*, const char *input);

bool vis_signal_handler(Vis*, int signum, const siginfo_t *siginfo,
	const void *context);

#endif