
#ifndef ASTEROIDE_CLASS
# define ASTEROIDE_CLASS

# include "AObject.class.hpp"

class	Asteroide : public AObject {

	public:
		Asteroide( void );
		Asteroide( int x, int y );
		Asteroide( Asteroide const &src );
		~Asteroide( void );

		Asteroide &		operator=( Asteroide const &rhs );
};

#endif
