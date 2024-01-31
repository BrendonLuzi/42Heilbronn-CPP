#include "Array.hpp"
#include <iostream>

int main()
{
	Array<std::string> array(3);

	array[0] = "Miao";
	array[1] = "Mao";
	array[2] = "Mau";

	std::cout << "Array:" << std::endl;
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << " " << array[i] << std::endl;

	const Array<std::string> another(array);
	array[0] = "Bau";
	std::cout << "Another array:" << std::endl;
	for (unsigned int i = 0; i < another.size(); i++)
		std::cout << " " << another[i] << std::endl;

	Array<int> intArray(3);
	intArray[0] = 1;
	intArray[1] = 2;
	intArray[2] = 3;

	std::cout << "Int array:" << std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << " " << intArray[i] << std::endl;

	try
	{
		std::cout << "Trying to access an element out of bounds:" << std::endl;
		(void)intArray[3];
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "Trying to access an element of an empty array:" << std::endl;
		Array<int> emptyArray;
		(void)emptyArray[0];
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
