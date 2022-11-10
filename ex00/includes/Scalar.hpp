#pragma once

#include <iostream>

typedef enum	e_type
{
	UNKNOWN,
	CHAR,
	INT, 
	FLOAT, 
	DOUBLE
} t_type;

class Scalar
{
	private:
		std::string	input_;
	public:
		Scalar(void);
		Scalar(std::string& input);
		Scalar(Scalar const& ori);
		~Scalar(void);
		Scalar &operator=(Scalar const& rhs);

		bool		isFloat(std::string const& string);
		bool		isDouble(std::string const& string);
		bool		isInt(std::string const& string);
		bool		isChar(std::string const& string);
		bool		isNumber(std::string const& string);
		int			convert(std::string);

		std::string	getInput() const;
};

std::ostream&	operator<<(std::ostream& o, Scalar const& rhs);