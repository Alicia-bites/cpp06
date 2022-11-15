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

bool	isB(Base *p)
{
	B* my_b = dynamic_cast<B*>(p);
	if (my_b != NULL)
		return 1;
	return 0;
}

bool	isC(Base *p)
{
	C* my_c = dynamic_cast<C*>(p);
	if (my_c != NULL)
		return 1;
	return 0;
}


void	identify(Base *p)
{
	if (isA(p))
		std::cout << "The real type of the object pointed by p is : "
			<< "A" << std::endl;
	else if (isB(p))
		std::cout << "The real type of the object pointed by p is : "
			<< "B" << std::endl;
	else if (isC(p))
		std::cout << "The real type of the object pointed by p is : "
			<< "C" << std::endl;
	else
		std::cerr << RED1 << "No type found" << RESET << std::endl;

}

int	main()
{
	Base	*p;

	p = generate();
	(void)p;
	identify(p);
}