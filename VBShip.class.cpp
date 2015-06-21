
#include "VBShip.class.hpp"

VB::VB( void ) {
}

VB::VB( int x, int y ) {
	this->_posX = x;
	this->_posY = y;
	this->_cHp = 50;
	this->_mHp = 50;
	this->_dam = 20;
	this->_type = "VB-0";
	this->_display = '&';
}

VB::VB( VB const &src ) {
	*this = src;
}

VB::~VB( void ) {
}

VB &		VB::operator=( VB const &rhs ) {
	this->_posX = rhs.getPosX();
	this->_posY = rhs.getPosY();
	this->_display = rhs.getDisplay();
	this->_cHp = rhs.getCHP();
	this->_mHp = rhs.getMHP();
	this->_dam = rhs.getDam();
	this->_type = rhs.getType();
	return *this;
}

