#include "Scalar.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage : ./convert <your string>" << std::endl;
		return 0;
	}
	std::string arg(argv[1]);
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	Scalar	scalar(arg);
	std::cout << scalar << std::endl;
	scalar.displayInputType();
	scalar.toInt();
	scalar.toChar();
	scalar.toFloat();
	scalar.toDouble();
	return 0;
}