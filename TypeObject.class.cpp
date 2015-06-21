
#include "TypeObject.class.hpp"

Block::Block( void ) {
}

Block::Block( int x, int y ) {
	this->_posX = x;
	this->_posY = y;
	this->_dam = 1000;
	this->_type = "block";
	this->_display = '|';
}

Block::Block( Block const &src ) {
	*this = src;
}

Block::~Block( void ) {
}

Block &			Block::operator=( Block const &rhs ) {
	this->_dam = rhs.getDam();
	this->_type = rhs.getType();
	this->_display = rhs.getDisplay();
	this->_posX = rhs.getPosX();
	this->_posY = rhs.getPosY();
	return *this;
}


Tir::Tir( void ) {
}

Tir::Tir( int x, int y, int dam) {
	this->_posX = x;
	this->_posY = y;
	this->_dam = dam;
	this->_type = "block";
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
