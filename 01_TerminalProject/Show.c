#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <locale.h>
#include <string.h>

#define DX 7
#define DY 3

#define ESC 27
#define SPACE 32

int main(int argc, char* argv[])
{
    char* file_name = argv[1];
    FILE* file = fopen(file_name, "r");
    char line[256];

    WINDOW *frame, *win;
    int c = 0;

    setlocale(LC_ALL, "");
    initscr();
    noecho();
    cbreak();

    frame = newwin(LINES - 2*DY, COLS - 2*DX, DY, DX);
    box(frame, 0, 0);
    mvwaddstr(frame, 0, (int)((COLS - 2*DX - 5) / 2), file_name);
    wrefresh(frame);

    int WIN_LINES = LINES - 2*DY - 2;
    int WIN_COLS = COLS - 2*DX-2;
    win = newwin(WIN_LINES, WIN_COLS, DY+1, DX+1);
    keypad(win, TRUE);
    scrollok(win, TRUE);

    for(int i = 0; i < WIN_LINES; ++i) {
        if (fgets(line, WIN_COLS, file) == NULL) {
            break;
        }
        line[strcspn(line, "\n")] = '\0';
        mvwprintw(win, i, 0, "%s", line);
    }
    while((c = wgetch(win)) != ESC) {
        if (c == SPACE) {
            if (fgets(line, WIN_COLS, file) != NULL) {
                line[strcspn(line, "\n")] = '\0';
                wscrl(win, 1);
                mvwprintw(win, WIN_LINES - 1, 0, "%s", line);
            }
        }
    }   

    delwin(win);
    delwin(frame);
    endwin();
    return 0;
}