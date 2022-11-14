#include "data.hpp"

uintptr_t	serialize(Data *ptr)
{
	uintptr_t	output = reinterpret_cast<uintptr_t>(ptr);
	return output;
}

Data	*deserialize(uintptr_t raw)
{
	Data	*output = reinterpret_cast<Data *>(raw);
	return output;
}

int main()
{
	Data		*ptr = new Data;
	uintptr_t	raw;
	Data		*finalResult;

	ptr->x = 5;
    ptr->y = 10;
    ptr->c = 'a';
    ptr->b = true;
	ptr->s = "what's up";

	std::cout << "ptr->x  = " << ptr->x << std::endl;
	std::cout << "ptr->y = " << ptr->y << std::endl;
	std::cout << "ptr->c = " << ptr->c << std::endl;
	std::cout << "ptr->b = " << ptr->b << std::endl;
	std::cout << "ptr->s = " << ptr->s << std::endl;
	std::cout << std::endl;
	std::cout << CADETBLUE1
		<< "Taking ptr and converting it to uintptr..."
		<< RESET
		<< std::endl;
	raw = serialize(ptr);
	std::cout << "Raw = " << raw << std::endl;
	std::cout << std::endl;
	std::cout << DARKORANGE2
		<< "Taking raw and converting it back to a pointer on our Data struct..."
		<< RESET
		<< std::endl;
	finalResult = deserialize(raw);
	std::cout << "finalResult->x = " << finalResult->x << std::endl;
	std::cout << "finalResult->y = " << finalResult->y << std::endl;
	std::cout << "finalResult->c = " << finalResult->c << std::endl;
	std::cout << "finalResult->b = " << finalResult->b << std::endl;
	std::cout << "finalResult->s = " << finalResult->s << std::endl;

	return 0;
}