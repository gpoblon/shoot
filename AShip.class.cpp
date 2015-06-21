
#include "AShip.class.hpp"
#include "AObject.class.hpp"

AShip::AShip( void ) {
	this->_cHp = 0;
	this->_mHp = 0;
	this->_dam = 0;
	this->_type = "";
}

AShip::AShip( AShip const &src ) {
	*this = src;
}

AShip::~AShip( void ) {
}

AShip &		AShip::operator=( AShip const &rhs ) {
	this->_posX = rhs.getPosX();
	this->_posY = rhs.getPosY();
	this->_display = rhs.getDisplay();
	this->_cHp = rhs.getCHP();
	this->_mHp = rhs.getMHP();
	this->_dam = rhs.getDam();
	this->_type = rhs.getType();
	return *this;
}

void		AShip::move( int moveX, int moveY ) {
	if (moveX != 0)
		this->_posX += moveX;
	if (moveY != 0)
		this->_posY += moveY;
}

AObject *		AShip::attack( void ) {	
	AObject		*tir = new Tir(this->_posX + 1, this->_posY, this->_dam);
	return tir;
}

void		AShip::takeDam( int dam ) {
	this->_dam -= dam;
	if (this->_dam <= 0)
		delete this;
}

int			AShip::getCHP( void ) const {
	return this->_cHp;
}

int			AShip::getMHP( void ) const {
	return this->_mHp;
}

int			AShip::getDam( void ) const {
	return this->_dam;
}

std::string	AShip::getType( void ) const {
	return this->_type;
}

