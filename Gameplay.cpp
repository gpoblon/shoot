#include "retro.hpp"

Gameplay::Gameplay(void)
{
}

Gameplay::Gameplay(WINDOW *win, Character *player) : _win(win), _player(player)
{
	_tab = new ASpace**[30];
	for (int i = 0; i < 30; i++)
	{
		_tab[i] = new ASpace*[120];
		for (int j = 0; j < 120; j++)
			_tab[i][j] = NULL;
	}
	_tab[_player->getPosY()][_player->getPosX()] = _player;
	this->menu();
}

Gameplay::Gameplay(Gameplay & copy)
{
	(*this) = copy;
}

Gameplay::~Gameplay()
{
}

Gameplay & Gameplay::operator=(Gameplay & copy)
{
	(void)copy;	
	return (*this);
}

void	Gameplay::collision(ASpace *obs)
{
	_tab[obs->getPosY()][obs->getPosX()] = NULL;
	_tab[obs->getPosY()][obs->getPosX() + 1] = NULL;
	this->gameOver();
}

void	Gameplay::readGet(int get)
{
	if (get == 259 || get == 258 || get == 261 || get == 260)
	{
		if (get == 259 && _player->getPosY() > 1)
		{
			_tab[_player->getPosY()][_player->getPosX()] = NULL;
			_player->move(0, -1);
			if (_tab[_player->getPosY()][_player->getPosX()] != NULL)
				this->collision(_tab[_player->getPosY()][_player->getPosX()]);
			_tab[_player->getPosY()][_player->getPosX()] = _player;
		}
		else if (get == 258 && _player->getPosY() < 28)
		{
			_tab[_player->getPosY()][_player->getPosX()] = NULL;
			_player->move(0, 1);
			if (_tab[_player->getPosY()][_player->getPosX()] != NULL)
				this->collision(_tab[_player->getPosY()][_player->getPosX()]);
			_tab[_player->getPosY()][_player->getPosX()] = _player;
		}
	}
	else if (get == 32)
	{
		_tab[_player->getPosY()][_player->getPosX() + 1] = _player->attack();
	}
	else
	{
		if (get == 27 || get == 113)
			this->quit();
	}
	wrefresh(_win);
}

void	Gameplay::menu(void)
{
	int		test = 0;
	int		get = 0;

	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	WINDOW *menu = subwin(_win, 30, 120, 0, 0);
	wattron(menu, COLOR_PAIR(1));
	mvwprintw(menu, 30 / 3, 120 / 2 - 2, "MENU");
	wattroff(menu, COLOR_PAIR(1));
	wattron(menu, COLOR_PAIR(2));
	wattroff(menu, COLOR_PAIR(2));
	mvwprintw(menu, 30 / 2, 120 / 2 - 6, "Wanna play ?");
	mvwprintw(menu, 30 / 2 + 2, 120 / 2 - 4, "Good bye");
	mvwprintw(menu, 30 / 2, 120 / 2 - 8, "*");
	wrefresh(menu);
	while (1)
	{
		get = getch();
		nodelay(menu, TRUE);
		if (get == 27)
			this->quit();
		if (get == 259)
		{
			mvwprintw(menu, 30 / 2 + 2, 120 / 2 - 8, " ");
			mvwprintw(menu, 30 / 2, 120 / 2 - 8, "*");
			test = 1;
		}
		if (get == 258)
		{
			mvwprintw(menu, 30 / 2, 120 / 2 - 8, " ");
			mvwprintw(menu, 30 / 2 + 2, 120 / 2 - 8, "*");
			test = 2;
		}
		if (get == 10)
			break ;
		wrefresh(menu);
	}
	if (test == 2)
		this->quit();
	else
		this->play();
}

void	Gameplay::play(void)
{
	timeout(10);
	while (1)
	{
		usleep(40000);
		wclear(_win);
		box(_win, '-', '|');
		int	get = getch();
		this->readGet(get);

		if (_tab[_player->getPosY()][_player->getPosX() + 1] != NULL && _tab[_player->getPosY()][_player->getPosX() + 1]->getDisplay() != '-')
			this->collision(_tab[_player->getPosY()][_player->getPosX() + 1]);
		this->moveAll();
		this->display();
		wrefresh(_win);
	}
}

void	Gameplay::moveAll(void)
{
	for (int i = 0; i < 30; ++i)
	{
		for (int j = 1; j < 120; ++j)
		{
			if (((_tab[i][j] && _tab[i][j]->getDisplay() != '@') || _tab[i][j] == NULL) && ((_tab[i][j - 1] && _tab[i][j - 1]->getDisplay() != '@') || _tab[i][j - 1] == NULL))
			{
				if (_tab[i][j] && _tab[i][j]->getDisplay() != '-')
				{
					if (_tab[i][j])
					{
						_tab[i][j]->movePosX('l');
						if (_tab[i][j]->getPosX() == 0)
							delete _tab[i][j];
					}
					_tab[i][j - 1] = _tab[i][j];
					_tab[i][j] = NULL;
				}
			}
		}
	}
	for (int i = 29; i >= 0; --i)
	{
		for (int j = 119; j >= 0; --j)
		{
			if (_tab[i][j] && _tab[i][j]->getDisplay() == '-' && j < 119)
			{
				if (j < 119 && _tab[i][j + 1] == NULL)
				{
					_tab[i][j]->movePosX('r');
					_tab[i][j + 1] = _tab[i][j];
					_tab[i][j] = NULL;
				}
				else if (j < 119)
				{
					if (_tab[i][j + 1] && _tab[i][j + 1]->getDisplay() == '&')
					{
						_tab[i][j + 1] = NULL;
						_player->setScore(1);
					}
					if (_tab[i][j + 1] && _tab[i][j + 1]->getDisplay() == '#')
					{
						_tab[i][j + 1] = NULL;
						_player->setScore(1);
					}
					_tab[i][j] = NULL;
				}
			}
		}
	}
	int rd;
	int rd2;
	if ((rd = rand() % 8) == 1)
		_tab[1][118] = new Block(118, 1);
	if ((rd = rand() % 12) == 1)
		_tab[2][118] = new Block(118, 2);
	if ((rd = rand() % 18) == 1)
		_tab[3][118] = new Block(118, 3);
	if ((rd = rand() % 25) == 1)
		_tab[4][118] = new Block(118, 4);
	if ((rd = rand() % 40) == 1)
		_tab[5][118] = new Block(118, 5);
	if ((rd = rand() % 8) == 1)
		_tab[28][118] = new Block(118, 28);
	if ((rd = rand() % 12) == 1)
		_tab[27][118] = new Block(118, 27);
	if ((rd = rand() % 18) == 1)
		_tab[26][118] = new Block(118, 26);
	if ((rd = rand() % 25) == 1)
		_tab[25][118] = new Block(118, 25);
	if ((rd = rand() % 40) == 1)
		_tab[24][118] = new Block(118, 24);
	rd2 = rand() % 10;
	rd = rand() % 20;
	if (rd2 == 2)
		_tab[rd + 5][118] = new Asteroide(118, rd + 5);	
	else if (rd2 == 8)
	{
		if ((rd2 = rand() % 5) > 0)
			_tab[rd + 5][118] = new VL(118, rd + 5);
		else
			_tab[rd + 5][118] = new VB(118, rd + 5);
	}
}

void	Gameplay::display(void)
{
	start_color();	
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	for (int i = 0; i < 30; ++i)
	{
		for (int j = 0; j < 120; ++j)
		{
			if (_tab[i][j] != NULL)
			{
				if (_tab[i][j]->getDisplay() == '-')
				{
					wattron(_win, COLOR_PAIR(1));
					mvwaddch(_win, _tab[i][j]->getPosY(), _tab[i][j]->getPosX(), _tab[i][j]->getDisplay());
					wattroff(_win, COLOR_PAIR(1));
				}
				else if (_tab[i][j]->getDisplay() == '&')
				{
					wattron(_win, COLOR_PAIR(2));
					mvwaddch(_win, _tab[i][j]->getPosY(), _tab[i][j]->getPosX(), _tab[i][j]->getDisplay());
					wattroff(_win, COLOR_PAIR(2));
				}
				else if (_tab[i][j]->getDisplay() == '\\' || _tab[i][j]->getDisplay() == '/')
				{
					wattron(_win, COLOR_PAIR(3));
					mvwaddch(_win, _tab[i][j]->getPosY(), _tab[i][j]->getPosX(), _tab[i][j]->getDisplay());
					wattroff(_win, COLOR_PAIR(3));
				}
				else if (_tab[i][j]->getDisplay() == '#')
				{
					wattron(_win, COLOR_PAIR(4));
					mvwaddch(_win, _tab[i][j]->getPosY(), _tab[i][j]->getPosX(), _tab[i][j]->getDisplay());
					wattroff(_win, COLOR_PAIR(4));
				}
				else if (_tab[i][j]->getDisplay() == '@')
				{
					wattron(_win, COLOR_PAIR(5));
					mvwaddch(_win, _tab[i][j]->getPosY(), _tab[i][j]->getPosX(), _tab[i][j]->getDisplay());
					wattroff(_win, COLOR_PAIR(5));
				}

			}
		}
	}
	wattron(_win, COLOR_PAIR(5));
	std::string score = _player->getIt();
	mvwprintw(_win, 0, 0, score.c_str());
	wattroff(_win, COLOR_PAIR(5));
	wrefresh(_win);
}

void	Gameplay::gameOver(void)
{
	int	get = 0;
	std::string score = _player->getIt();
	wclear(_win);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 10, 60 - 5, "GAME OVER");
	mvwprintw(_win, 15, 60 - 8, "Score :");
	mvwprintw(_win, 15, 60 + 2, score.c_str());
	mvwprintw(_win, 20, 60 - 10, "Press Enter to continue");
	wattroff(_win, COLOR_PAIR(1));
	wrefresh(_win);
	while (1)
	{
		get = getch();
		if (get == 10)
		{
			wclear(_win);
			Character *ret = new Character();
			for (int i = 0; i < 30; i++)
			{
				for (int j = 0; j < 120; j++)
					_tab[i][j] = NULL;
			}
			_player = ret;
			_tab[_player->getPosY()][_player->getPosX()] = _player;
			this->menu();
		}
		else if (get == 27)
			this->quit();
	}
}

void	Gameplay::quit(void)
{
	wclear(_win);
	mvwprintw(_win, 15, 60 - 4, "Good bye");
	wrefresh(_win);
	sleep(1);
	delete [] _tab;
	delete _player;
	exit (EXIT_SUCCESS);
}
