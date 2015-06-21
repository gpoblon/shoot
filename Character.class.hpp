
#ifndef CHARACTER_CLASS
# define CHARACTER_CLASS

#include <iostream>
#include "AShip.class.hpp"

class		Character : public AShip {

	public:
		Character( void );
		Character( Character const &src );
		~Character( void );

		Character &		operator=( Character const &rhs );
		std::string		getIt(void);
		int				getScore(void) const;
		void			setScore(int nb);

	protected:
		int		_score;
};


#endif
