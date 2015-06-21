
#ifndef AOBJECT_CLASS
# define AOBJECT_CLASS

#include "ASpace.class.hpp"

class		AObject : public ASpace {

	public:
		AObject( void );
		AObject( AObject const &src );
		~AObject( void );

		AObject &		operator=( AObject const &rhs );

		int			getDam( void ) const;
		std::string	getType( void ) const;

	protected:
		int				_dam;
		std::string		_type;
};

#endif
