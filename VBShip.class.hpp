
#ifndef VBSHIP_CLASS
# define VBSHIP_CLASS

#include "AShip.class.hpp"

class	VB : public AShip {
	
	public:
		VB( void );
		VB( int x, int y );
		VB( VB const &src );
		~VB( void );

		VB &	operator=( VB const &rhs );
};


#endif
