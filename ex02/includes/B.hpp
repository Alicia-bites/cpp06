#pragma once

#include "Base.hpp"

class B : public Base
{
	private:
		
	public:
		B(void);
		B(B const& ori);
		~B(void);
		B &operator=(B const& rhs);
};

std::ostream&	operator<<(std::ostream& o, B const& rhs);