#ifndef ITER_HPP
# define ITER_HPP

template <typename Type>
void iter(Type *array, int length, void (*func)(Type &))
{
	if (!func || !array)
		return ;
	for (int i = 0; i < length; i++)
		func(array[i]);
}

template <typename Type>
void iter(const Type *array, int length, void (*func)(const Type &))
{
	if (!func || !array)
		return ;
	for (int i = 0; i < length; i++)
		func(array[i]);
}

#endif