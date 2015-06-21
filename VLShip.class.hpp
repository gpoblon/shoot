
#ifndef VLSHIP_CLASS
# define VLSHIP_CLASS

#include "AShip.class.hpp"

class	VL : public AShip {
	
	public:
		VL( void );
		VL( int x, int y );
		VL( VL const &src );
		~VL( void );

		VL &	operator=( VL const &rhs );
};


#endif
