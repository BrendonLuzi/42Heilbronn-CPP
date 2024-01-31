#include "Serializer.hpp"

#include <iostream>

int main(void)
{
	t_data	*data = new t_data;
	data->something = "Miao!";

	std::cout << "Data pointer:\t\t" << data << std::endl;
	std::cout << "Data content:\t\t" << data->something << std::endl;

	uintptr_t	serialized = Serializer::serialize(data);

	std::cout << "Serialized pointer:\t" << serialized << std::endl;

	t_data*		deserialized = Serializer::deserialize(serialized);

	std::cout << "Deserialized pointer:\t" << deserialized << std::endl;
	std::cout << "Deserialized content:\t" << deserialized->something << std::endl;

	delete data;

	return (0);
}
