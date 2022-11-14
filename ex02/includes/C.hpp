#pragma once

#include "Base.hpp"

class C : public Base
{
	private:
		
	public:
		C(void);
		C(C const& ori);
		~C(void);
		C &operator=(C const& rhs);
};

std::ostream&	operator<<(std::ostream& o, C const& rhs);