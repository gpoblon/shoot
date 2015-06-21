
#include <sstream>
#include "Character.class.hpp"

Character::Character( void ) {
	this->_posX = 10;
	this->_posY = 15;
	this->_display = '@';
	this->_cHp = 100;
	this->_mHp = 100;
	this->_dam = 40;
	this->_type = "Joueur";
	this->_score = 0;
}

Character::Character( Character const &src ) {
	*this = src;
}

Character::~Character( void ) {
}


Character &			Character::operator=( Character const &rhs ) {
	this->_posX = rhs.getPosX();
	this->_posY = rhs.getPosY();
	this->_display = rhs.getDisplay();
	this->_cHp = rhs.getCHP();
	this->_mHp = rhs.getMHP();
	this->_dam = rhs.getDam();
	this->_type = rhs.getType();
	this->_type = rhs.getScore();
	return *this;
}

int		Character::getScore(void) const
{
	return _score;
}

void	Character::setScore(int nb)
{
	_score += nb;
}

std::string	Character::getIt(void)
{
	std::string str = std::to_string(this->getScore());
	return str;
}
