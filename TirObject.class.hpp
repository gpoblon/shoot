
#ifndef TIROBJECT_CLASS
# define TIROBJECT_CLASS

# include "AObject.class.hpp"

class	Tir : public AObject {

	public:
		Tir( void );
		Tir( int x, int y, int dam );
		Tir( Tir const &src );
		~Tir( void );

		Tir &		operator=( Tir const &rhs );
};

#endif
