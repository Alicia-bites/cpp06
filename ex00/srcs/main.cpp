#include "Scalar.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage : ./convert <your string>" << std::endl;
		return 0;
	}
	std::string arg(argv[1]);
	Scalar	scalar(arg);
	scalar.convert();
	std::cout << scalar << std::endl;
	return 0;
}