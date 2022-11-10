#include "Scalar.hpp"

// default constructor
Scalar::Scalar()
: input_("none")
{}

// Param1 constructor
Scalar::Scalar(std::string& string)
: input_(string)
{

}

// copy constructor
Scalar::Scalar(Scalar const& ori)
: input_(ori.input_)
{}

// destructor
Scalar::~Scalar()
{}

// OPERATOR OVERLOADS ----------------------------------------------

Scalar&		Scalar::operator=(Scalar const& rhs)
{
	if (this != &rhs)
		input_ = rhs.input_;
	return *this;
}

std::ostream& operator<<(std::ostream& o, Scalar const& rhs)
{
	o << "Input is : "
		<< rhs.getInput();
	return o;
}

// MEMBER FUNCTIONS ----------------------------------------------

bool	Scalar::isNumber(std::string const& string)
{
	for (size_t i = 0; i < string.length(); i++)
		if (std::isdigit(string.at(i)) == 0)
			return false;
	return true;
}

// -- GETTERS ---------------------------------------------------

std::string	Scalar::getInput() const
{
	return input_;
}
