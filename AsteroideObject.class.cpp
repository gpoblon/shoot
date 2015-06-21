
#include "AsteroideObject.class.hpp"


Asteroide::Asteroide( void ) {
}

Asteroide::Asteroide( int x, int y) {
	this->_posX = x;
	this->_posY = y;
	this->_dam = 5;
	this->_type = "asteroide";
	this->_display = '#';
}

Asteroide::Asteroide( Asteroide const &src ) {
	*this = src;
}

Asteroide::~Asteroide( void ) {
}

Asteroide &			Asteroide::operator=( Asteroide const &rhs ) {
	this->_dam = rhs.getDam();
	this->_type = rhs.getType();
	this->_display = rhs.getDisplay();
	this->_posX = rhs.getPosX();
	this->_posY = rhs.getPosY();
	return *this;
}
