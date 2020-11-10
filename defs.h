/* See LICENSE file for copyright and license details. */
#ifndef DEFS_H
#define DEFS_H

#define MOVE_UP_NORM            'k'
#define MOVE_UP_VIM             'w'
#define MOVE_DOWN_NORM          's'
#define MOVE_DOWN_VIM           'j'
#define MOVE_LEFT_NORM          'a'
#define MOVE_LEFT_VIM           'h'
#define MOVE_RIGHT_NORM         'd'
#define MOVE_RIGHT_VIM          'l'
#define MOVE_ENTER              '\n'
#define MOVE_OPEN_CELL          'o'
#define MOVE_FLAG_CELL          'f'
#define MOVE_DEFUSE_CELL        'g'
#define MOVE_OPEN_MENU          'm'
#define MOVE_RESTART            'r'
#define MOVE_QUIT               'q'

#define MINE_DEFUSED            'd'
#define CELL_FLAGGED            'F'
#define CELL_BLANK              ' '
#define CELL_MINE               '*'
#define GRID_BOX                "[ ]"

#define OPT_CTRLS               "m Controls"
#define OPT_QUIT                "q         Quit"
#define OPT_RESTART             "r         Restart"
#define OPT_MOVE_UP             "w/k       Move up"
#define OPT_MOVE_DOWN           "s/j       Move down"
#define OPT_MOVE_LEFT           "a/h       Move left"
#define OPT_MOVE_RIGHT          "d/l       Move right"
#define OPT_FLAG_CELL           "f         Flag cell"
#define OPT_DEFUSE              "g         Defuse (if flagged only)"
#define OPT_OPEN_CELL           "[ENTER]/o Open cell"

#define MSG_COLS                "Columns (Min = %d, Max = %d): "
#define MSG_ROWS                "Rows (Min = %d, Max = %d): "
#define MSG_MINES               "Mines (Min = %d, Max = %d): "
#define MSG_QUIT_MENU           "Press any key to quit the menu"
#define MSG_CONT                "Press any key to continue"
#define MSG_CURPOS              "Current position: (%d, %d) "
#define MSG_NDEFUSED            "Defused mines: %d/%d"
#define MSG_WIN_1               "You defused all the mines!"
#define MSG_WIN_2               "You won :)"
#define MSG_LOSE_1              "You hit a mine! (or tried to defuse the wrong cell)"
#define MSG_LOSE_2              "Game over :("

#define GAME_LOST               0
#define GAME_WON                1

#define CURSES_INIT() do {      \
        initscr();              \
        noecho();               \
        cbreak();               \
} while (0)

#define MINEBOARD_INIT(m) do {  \
        minesplace(m);          \
        adjadd(m);              \
        spacesfill(m);          \
} while (0)

#define GAME_RESTART(m) do {    \
        boardsdealloc(m);       \
        gamereset(m);           \
} while (0)

#define YMAX(x)                 (getmaxy((x)))
#define XMAX(x)                 (getmaxx((x)))
#define YMID(x)                 (getmaxy((x)) / 2)
#define XMID(x)                 (getmaxx((x)) / 2)
#define GRIDSPACE_X(x)          ((x) * 3 + 2)
#define GRIDSPACE_Y(y)          ((y) + 2)
#define ARRSPACE_X(x)           (((x) - 2) / 3)
#define ARRSPACE_Y(y)           ((y) - 1)
#define CENTER(x, y)            ((x) / 2 - (y) / 2)
#define CURS_UPDATE(m, y, x)    (wmove((m)->gamewin, (y), (x)))
#define IS_MINE(m, r, c)        ((m)->mineboard[(r)][(c)] == CELL_MINE)
#define IS_FLAGGED(m, r, c)     ((m)->dispboard[(r)][(c)] == CELL_FLAGGED)
#define IS_BLANK(m, r, c)       ((m)->dispboard[(r)][(c)] == CELL_BLANK)
#define OUT_OF_BOUNDS(m, r, c)  ((r) < 0 || (r) > ((m)->rows - 1) || \
                                 (c) < 0 || (c) > ((m)->cols - 1))

#endif /* DEFS_H */
