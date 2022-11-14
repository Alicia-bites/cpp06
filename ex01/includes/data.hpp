# pragma once

#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdint.h>
#include "colors.hpp"

typedef struct	s_data
{
	int			x;
	int			y;
	char		c;
	bool		b;
	std::string	s;
}	Data;

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);