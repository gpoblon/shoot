
#include "ASpace.class.hpp"

ASpace::ASpace( void ) {
	this->_posX = 0;
	this->_posY = 0;
	this->_display = 0;
}

ASpace::ASpace( ASpace const &src ) {
	*this = src;
}

ASpace::~ASpace( void ) {
}

ASpace &				ASpace::operator=( ASpace const &rhs ) {
	this->_posX = rhs.getPosX();
	this->_posY = rhs.getPosY();
	this->_display = rhs.getDisplay();
	return *this;
}

std::ostream &			operator<<( std::ostream &o, ASpace const &rhs ){
	o << rhs.getDisplay();
	return o;
}

void			ASpace::movePosX( int i ) {
	if (i == 'l')
		this->_posX -= 1;
	else if (i == 'r')
		this->_posX += 1;
}

int				ASpace::getPosX( void ) const {
	return this->_posX;
}

int				ASpace::getPosY( void ) const {
	return this->_posY;
}

char			ASpace::getDisplay( void ) const {
	return this->_display;
}

