#include "retro.hpp"

int		main(void)
{
	initscr();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	srand(time(NULL));
	WINDOW *genwin = newwin(50, 150, 0, 0);
	WINDOW *win = subwin(genwin, 30, 120, 0, 0);
	Character	*player = new Character();
	nodelay(genwin, TRUE);
	nodelay(win, TRUE);
	Gameplay	*game = new Gameplay(win, player);
	endwin();
	delete game;
	return 0;
}
