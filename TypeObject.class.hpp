
#ifndef TYPEOBJECT_CLASS
# define TYPEOBJECT_CLASS

# include "AObject.class.hpp"

class	Block : public AObject {

	public:
		Block( void );
		Block( int x, int y );
		Block( Block const &src );
		~Block( void );

		Block &		operator=( Block const &rhs );
};

class	Tir : public AObject {

	public:
		Tir( void );
		Tir( int x, int y, int dam );
		Tir( Tir const &src );
		~Tir( void );

		Tir &		operator=( Tir const &rhs );
};

class	Asteroide : public AObject {

	public:
		Asteroide( void );
		Asteroide( int x, int y );
		Asteroide( Asteroide const &src );
		~Asteroide( void );

		Asteroide &		operator=( Asteroide const &rhs );
};

#endif
