
#include "TirObject.class.hpp"

Tir::Tir( void ) {
}

Tir::Tir( int x, int y, int dam) {
	this->_posX = x;
	this->_posY = y;
	this->_dam = dam;
	this->_type = "tir";
	this->_display = '-';
}

Tir::Tir( Tir const &src ) {
	*this = src;
}

Tir::~Tir( void ) {
}

Tir &			Tir::operator=( Tir const &rhs ) {
	this->_dam = rhs.getDam();
	this->_type = rhs.getType();
	this->_display = rhs.getDisplay();
	this->_posX = rhs.getPosX();
	this->_posY = rhs.getPosY();
	return *this;
}


