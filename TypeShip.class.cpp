
#include "TypeShip.class.hpp"

VL::VL( void ) {
}

VL::VL( int x, int y ) : _posX(x), _posY(y) {
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

VL &		VL::operator=( VL const *rhs ) {
	this->_posX = rhs.getPosX();
	this->_posY = rhs.getPosY();
	this->_display = rhs.getDisplay();
	this->_cHp = rhs.getCHP();
	this->_mHp = rhs.getMHP();
	this->_dam = rhs.getDam();
	this->_type = rhs.getType();
	return *this;
}


VB::VB( void ) {
}

VB::VB( int x, int y ) : _posX(x), _posY(y) {
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

VB &		VB::operator=( VV const *rhs ) {
	this->_posX = rhs.getPosX();
	this->_posY = rhs.getPosY();
	this->_display = rhs.getDisplay();
	this->_cHp = rhs.getCHP();
	this->_mHp = rhs.getMHP();
	this->_dam = rhs.getDam();
	this->_type = rhs.getType();
	return *this;
}

