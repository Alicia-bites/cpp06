#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate()
{
	srand(time(NULL));
	switch (rand() % 3)
	{
		case 0 : return new A;
		case 1 : return new B;
		case 2 : return new C;
		default : 
			std::cout << "Error, returning NULL" << std::endl;
			return NULL;
	}
}

bool	isA(Base *p)
{
	A* my_a = dynamic_cast<A*>(p);
	if (my_a != NULL)
		return 1;
	return 0;
}

bool	isA(Base &p)
{
	try
	{
		A my_a = dynamic_cast<A&>(p);
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
		return 0;
	}
	return 1;
}

bool	isB(Base *p)
{
	B* my_b = dynamic_cast<B*>(p);
	if (my_b != NULL)
		return 1;
	return 0;
}

bool	isB(Base &p)
{
	try
	{
		B my_b = dynamic_cast<B&>(p);
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
		return 0;
	}
	return 1;
}

bool	isC(Base *p)
{
	C* my_c = dynamic_cast<C*>(p);
	if (my_c != NULL)
		return 1;
	return 0;
}

bool	isC(Base &p)
{
	try
	{
		C my_c = dynamic_cast<C&>(p);
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
		return 0;
	}
	return 1;
}


void	identify(Base *p)
{
	if (isA(p))
		std::cout << DODGERBLUE2 << "The real type of the object pointed by p is : "
			<< "A" << RESET << std::endl;
	else if (isB(p))
		std::cout << DODGERBLUE2 << "The real type of the object pointed by p is : "
			<< "B" << RESET << std::endl;
	else if (isC(p))
		std::cout << DODGERBLUE2 << "The real type of the object pointed by p is : "
			<< "C" << RESET << std::endl;
	else
		std::cerr << RED1 << "No type found" << RESET << std::endl;

}

void	identify(Base &p)
{
	if (isA(p))
		std::cout << GREEN3 << "The real type of the object pointed by p is : "
			<< "A" << RESET << std::endl;
	else if (isB(p))
		std::cout << GREEN3 << "The real type of the object pointed by p is : "
			<< "B" << RESET << std::endl;
	else if (isC(p))
		std::cout << GREEN3 << "The real type of the object pointed by p is : "
			<< "C" << RESET << std::endl;
	else
		std::cerr << RED1 << "No type found" << RESET << std::endl;

}

int	main()
{
	Base	*p;

	std::cout << "Function identify(Base *p) will print type in "
		<< DODGERBLUE2
		<< "BLUE" 
		<< RESET
		<< ", and identify(Base &p) will print result in"
		<< GREEN3
		<< " GREEN"
		<< RESET
		<< std::endl << std::endl;
	p = generate();
	// calling identify(Base *p)
	identify(p);
	// calling identify(Base &p)
	identify(*p);
}