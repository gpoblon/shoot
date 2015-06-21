#ifndef GAMEPLAY_HPP
# define GAMEPLAY_HPP

# include <iostream>
# include <curses.h>
# include <ncurses.h>
# include "retro.hpp"
# include "ASpace.class.hpp"
# include "Character.class.hpp"
# include "AShip.class.hpp"
# include "AObject.class.hpp"
# include "TirObject.class.hpp"
# include "BlockObject.class.hpp"
# include "AsteroideObject.class.hpp"
# include "VLShip.class.hpp"

class	Gameplay
{
	public :
		Gameplay(void);
		Gameplay(WINDOW *win, Character *player);
		Gameplay(Gameplay & copy);
		virtual ~Gameplay();
		Gameplay & operator=(Gameplay & copy);
		void readGet(int get);
		void menu(void);
		void quit(void);
		void play(void);
		void display(void);
		void collision(ASpace *obs);
		void gameOver(void);
		void moveAll(void);
	private :
	   	WINDOW *_win;
		Character *_player;
		ASpace	***_tab;
};

#endif
