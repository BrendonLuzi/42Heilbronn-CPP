#ifndef CPP_SERIALIZER_HPP
#define CPP_SERIALIZER_HPP

#include <stdint.h>
#include <string>

typedef struct s_data
{
	std::string		something;
} t_data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& copy);
	~Serializer();

	Serializer& operator=(const Serializer& copy);
public:

	static uintptr_t	serialize(t_data* ptr);
	static t_data*		deserialize(uintptr_t raw);
};


#endif
