#include "Scalar.hpp"

// default constructor
Scalar::Scalar()
: input_("none")
, int_(0)
, char_(0)
, float_(0)
, double_(0)
{}

// Param1 constructor
Scalar::Scalar(std::string& string)
: input_(string)
, int_(0)
, char_(0)
, float_(0)
, double_(0)
{

}

// copy constructor
Scalar::Scalar(Scalar const& ori)
: input_(ori.input_)
, int_(0)
, char_(0)
, float_(0)
, double_(0)
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

bool	Scalar::isNumber()
{
	for (size_t i = 0; i < input_.length(); i++)
		if (std::isdigit(input_.at(i)) == 0)
			return false;
	return true;
}

bool	Scalar::isChar()
{
	if (isNumber() == 0)
		return true;
	return false;
}

bool	Scalar::isInt()
{
	if (isNumber())
		return true;
	return false;
}

bool	Scalar::isDouble()
{
	for(size_t i = 0; i < input_.length(); i++)
		if (input_.at(i) == '.' && input_.at(i + 1) != '\0')
			return true ;
	return false;
}

bool Scalar::isFloat()
{
	for(size_t i = 0; i < input_.length(); i++)
		if (input_.at(i) == '.' && input_.at(input_.length() - 1) == 'f')
			return true ;
	return false;
}

int	Scalar::giveType()
{
	if (isFloat())
		return (FLOAT);
	else if (isDouble())
		return (DOUBLE);
	else if (isInt())
		return (INT);
	else if (isChar())
		return (CHAR);
	return (UNKNOWN);
}

void	Scalar::displayInputType()
{
	if (isFloat())
		std::cout << "Input type is " << CYAN1 << "float" << RESET << std::endl;
	else if (isDouble())
		std::cout << "Input type is " << CORNFLOWERBLUE << "double" << RESET << std::endl;
	else if (isInt())
		std::cout << "Input type is " << DARKSLATEGRAY1 << "int" << RESET << std::endl;
	else if (isChar())
		std::cout << "Input type is " << DODGERBLUE2 << "char" << RESET << std::endl;
	else
		std::cout << "Input type not found." << std::endl;
}

void	Scalar::fromInt()
{
	static_cast<double>(input_);
	static_cast<char>(input_);
	static_cast<float>(input_);
}

void	Scalar::fromChar()
{
	static_cast<double>(input_);
	static_cast<int>(input_);
	static_cast<float>(input_);
}


void	Scalar::fromFloat()
{
	static_cast<double>(input_);
	static_cast<char>(input_);
	static_cast<int>(input_);
}

void	Scalar::fromInt()
{
	static_cast<double>(input_);
	static_cast<char>(input_);
	static_cast<float>(input_);
}

void	Scalar::convert()
{
	if (giveType() == INT)
		static_cast<int>();
	
}

// -- GETTERS ---------------------------------------------------

std::string	Scalar::getInput() const
{
	return input_;
}

int	Scalar::getInt() const
{
	return int_;
}

char	Scalar::getChar() const
{
	return char_;
}

float	Scalar::getFloat() const
{
	return float_;
}

double	Scalar::getDouble() const
{
	return double_;
}
