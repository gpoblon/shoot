
#include "AObject.class.hpp"

AObject::AObject( void ) {
	this->_dam = 0;
	this->_type = "";
}

AObject::AObject( AObject const &src ) {
	*this = src;
}

AObject::~AObject( void ) {
}

AObject &			AObject::operator=( AObject const &rhs ) {
	this->_dam = rhs.getDam();
	this->_type = rhs.getType();
	return *this;
}

int					AObject::getDam( void ) const {
	return this->_dam;
}

std::string			AObject::getType( void ) const {
	return this->_type;
}

