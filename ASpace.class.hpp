
#ifndef ASPACE_CLASS
# define ASPACE_CLASS

#include <iostream>
#include <cwchar>

class		ASpace {
	
	public:
		ASpace( void );	
		ASpace( ASpace const &src );
		~ASpace( void );	

		ASpace &		operator=( ASpace const &rhs );
		int				getPosX( void ) const;
		int				getPosY( void ) const;
		char			getDisplay( void ) const;
		void			movePosX( int i );

	protected:
		int			_posX;
		int			_posY;
		char		_display;

};

std::ostream &			operator<<( std::ostream &o, ASpace const &rhs );

#endif
