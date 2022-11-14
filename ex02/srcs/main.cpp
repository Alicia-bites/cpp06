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
	B* my_b = dynamic_cast<B*>(p);
	if (my_b != NULL)
		std::cout << "The real type of the object pointed by p is : "
			<< "b" << std::endl;
	else
	    std::cerr << "Cet objet n'est pas de type B" << std::endl;
}

bool	isB(Base *p)
{
	B* my_b = dynamic_cast<B*>(p);
	if (my_b != NULL)
	{
		std::cout << "The real type of the object pointed by p is : "
			<< "b" << std::endl;
		return 1;
	}
	else
	    std::cerr << "Cet objet n'est pas de type B" << std::endl;
}

bool	isC(Base *p)
{
	B* my_b = dynamic_cast<B*>(p);
	if (my_b != NULL)
		std::cout << "The real type of the object pointed by p is : "
			<< "b" << std::endl;
	else
	    std::cerr << "Cet objet n'est pas de type B" << std::endl;
}


void	identify(Base *p)
{
	isB(p);
}

int	main()
{
	Base	*p;

	p = generate();
	(void)p;
	// identify(p);
}