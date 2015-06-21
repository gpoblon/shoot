
#ifndef BLOCKOBJECT_CLASS
# define BLOCKOBJECT_CLASS

#include "AObject.class.hpp"

class	Block : public AObject {

	public:
		Block( void );
		Block( int x, int y );
		Block( Block const &src );
		~Block( void );

		Block &		operator=( Block const &rhs );
};

#endif
