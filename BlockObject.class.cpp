
#include "BlockObject.class.hpp"

Block::Block( void ) {
}

Block::Block( int x, int y ) {
	this->_posX = x;
	this->_posY = y;
	this->_dam = 1000;
	this->_type = "block";
	int rd = rand() % 2;
	if (rd == 1)
		this->_display = '/';
	else
		this->_display = '\\';
//	this->_display = '|';
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

