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
{}

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
	rhs.printChar(o);
	rhs.printInt(o);
	rhs.printFloat(o);
	rhs.printDouble(o);
	return o;
}

// MEMBER FUNCTIONS ----------------------------------------------

bool	Scalar::isNumber() const
{
	size_t i = 0;
	if (input_.compare("+") == 0 || input_.compare("-") == 0)
		return false;
	if (input_.at(0) == '+' || input_.at(0) == '-')
		i = 1;
	while (i < input_.length())
		if (std::isdigit(input_.at(i++)) == 0)
				return false;
	return true;
}

bool	Scalar::isChar() const
{
	if (isNumber() == 0)
		return true;
	return false;
}

bool	Scalar::isInt() const
{
	if (isNumber())
		return true;
	return false;
}

bool	Scalar::isDouble() const
{
	if (input_.compare("nan") == 0 || input_.compare("+inf") == 0
		|| input_.compare("-inf") == 0)
		return true;
	for(size_t i = 0; i < input_.length(); i++)
		if (input_.at(i) == '.' && input_.at(i + 1) != '\0')
			return true ;
	return false;
}

bool Scalar::isFloat() const
{
	if (input_.compare("nanf") == 0 || input_.compare("+inff") == 0
		|| input_.compare("-inff") == 0)
		return true;
	for(size_t i = 0; i < input_.length(); i++)
		if (input_.at(i) == '.' && input_.at(input_.length() - 1) == 'f')
			return true ;
	return false;
}

int	Scalar::giveType() const
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

void	Scalar::fromChar()
{
	char_ = input_[0];
	if (input_.length() > 1)
		std::cout << DARKSEAGREEN8
			<< "Keeping only first symbol..." << RESET << std::endl;
	int_ = static_cast<int>(char_);
	char_ = static_cast<char>(char_);
	float_ = static_cast<float>(char_);
	double_ = static_cast<double>(char_);
}

void	Scalar::fromInt()
{
	// std::istringstream(input_) >> int_;
	double_ = std::strtod(input_.c_str(), NULL); // I put the int in a double in case it's < -2147483648 or > 214748367
	int_ = static_cast<int>(double_);
	char_ = static_cast<char>(double_);
	float_ = static_cast<float>(double_);
	double_ = static_cast<double>(double_);
}

void	Scalar::fromFloat()
{
	// std::istringstream(input_) >> float_;
	float_ = std::strtod(input_.c_str(), NULL);
	int_ = static_cast<int>(float_);
	char_ = static_cast<char>(float_);
	float_ = static_cast<float>(float_);
	double_ = static_cast<double>(float_);
}

void	Scalar::fromDouble()
{
	// std::istringstream(input_) >> double_;
	double_ = std::strtod(input_.c_str(), NULL);
	int_ = static_cast<int>(double_);
	char_ = static_cast<char>(double_);
	float_ = static_cast<float>(double_);
	double_ = static_cast<double>(double_);
}

void	Scalar::convert()
{
	displayInputType();
	if (giveType() == CHAR)
		fromChar();
	else if (giveType() == INT)
		fromInt();
	else if (giveType() == FLOAT)
		fromFloat();
	else if (giveType() == DOUBLE)
		fromDouble();
	else
		std::cerr << "No type found." << std::endl;
}

std::ostream&	Scalar::printChar(std::ostream& o) const
{
	if (input_.compare("nan") == 0 || input_.compare("nanf") == 0)
		std::cout << "char : impossible" << std::endl;
	else if (int_ < 0 || int_ > 255)
		std::cout << "char : overflow" << std::endl;
	else if (int_ < 32 || int_ > 126)
		std::cout << "char : Non displayable" << std::endl;
	else
		o << "char : " << char_ << std::endl;
	return o;
}

std::ostream&	Scalar::printInt(std::ostream& o) const
{
	if (input_.compare("nan") == 0 || input_.compare("nanf") == 0)
		std::cout << "int : impossible" << std::endl;
	else if (double_ < INT_MIN || double_ > INT_MAX)
		std::cout << "int : overflow" << std::endl;
	else
		o << "int : " << int_ << std::endl;
	return o;
}

bool	Scalar::dotZero() const
{
	int i = input_.length() - 1;
	if (giveType() == FLOAT)
		i--;
	if (input_.at(i) == '0'
		&& input_.at(i - 1) == '.')
			return true;
	return false;
}

std::ostream&	Scalar::printFloat(std::ostream& o) const
{
	if ((giveType() != DOUBLE && giveType() != FLOAT) || dotZero())
		o << "float : " << float_ << ".0f" << std::endl;
	else
		o << "float : " << float_ << "f" << std::endl;
	return o;
}

std::ostream&	Scalar::printDouble(std::ostream& o) const
{
	if ((giveType() != DOUBLE && giveType() != FLOAT) || dotZero())
		o << "double : " << double_ << ".0" << std::endl;
	else
		o << "double : " << double_ << std::endl;
	return o;
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
