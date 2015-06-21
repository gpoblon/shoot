
#ifndef TYPESHIP_CLASS
# define TYPESHIP_CLASS

#include "AShip.class.hpp"

class	VL : public AShip {
	
	public:
		VL( void );
		VL( int x, int y );
		VL( VL const &src );
		~VL( void );

		VL &	operator=( VL const *rhs );
};

class	VB : public AShip {
	
	public:
		VB( void );
		VB( int x, int y );
		VB( VL const &src );
		~VB( void );

		VB &	operator=( VB const *rhs );
};


#endif
