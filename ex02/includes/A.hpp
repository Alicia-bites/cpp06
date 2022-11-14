#pragma once

#include "Base.hpp"

class A : public Base
{
	private:
		
	public:
		A(void);
		A(A const& ori);
		~A(void);
		A &operator=(A const& rhs);
};

std::ostream&	operator<<(std::ostream& o, A const& rhs);