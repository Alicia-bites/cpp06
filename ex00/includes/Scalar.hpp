#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include "limits.h"
#include "colors.hpp"

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
		
		int			int_;
		char		char_;
		float		float_;
		double		double_;
	public:
		Scalar(void);
		Scalar(std::string& input);
		Scalar(Scalar const& ori);
		~Scalar(void);
		Scalar &operator=(Scalar const& rhs);

		bool				isFloat() const;
		bool				isDouble() const;
		bool				isInt() const;
		bool				isChar() const;
		bool				isNumber() const;
		int					giveType() const;
		bool				dotZero() const;

		void				displayInputType();
		std::ostream&		printChar(std::ostream& o) const;
		std::ostream&		printInt(std::ostream& o) const;
		std::ostream&		printFloat(std::ostream& o) const;
		std::ostream&		printDouble(std::ostream& o) const;

		void				fromInt();
		void				fromChar();
		void				fromFloat();
		void				fromDouble();		

		void				convert();

		std::string			getInput() const;
		int					getInt() const;
		char				getChar() const;
		float				getFloat() const;
		double				getDouble() const;

};

std::ostream&	operator<<(std::ostream& o, Scalar const& rhs);