
#ifndef ASHIP_CLASS
# define ASHIP_CLASS

#include "ASpace.class.hpp"
#include "AObject.class.hpp"
#include "TirObject.class.hpp"

class		AShip : public ASpace {

	public:
		AShip( void );
		AShip( AShip const &src );
		~AShip( void );

		AShip &		operator=( AShip const &rhs );
		
		void		move( int moveX, int moveY );
		AObject		*attack( void );
		void		takeDam( int dam );
		
		int			getCHP( void ) const;
		int			getMHP( void ) const;
		int			getDam( void ) const;
		std::string	getType( void ) const;

	protected:
		int			_cHp;
		int			_mHp;
		int			_dam;
		std::string	_type;
};

#endif
