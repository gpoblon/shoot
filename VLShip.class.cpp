
#include "VLShip.class.hpp"

VL::VL( void ) {
}

VL::VL( int x, int y ) {
	this->_posX = x;
	this->_posY = y;
	this->_cHp = 30;
	this->_mHp = 30;
	this->_dam = 15;
	this->_type = "VL-0";
	this->_display = '&';
}

VL::VL( VL const &src ) {
	*this = src;
}

VL::~VL( void ) {
}

VL &		VL::operator=( VL const &rhs ) {
	this->_posX = rhs.getPosX();
	this->_posY = rhs.getPosY();
	this->_display = rhs.getDisplay();
	this->_cHp = rhs.getCHP();
	this->_mHp = rhs.getMHP();
	this->_dam = rhs.getDam();
	this->_type = rhs.getType();
	return *this;
}


