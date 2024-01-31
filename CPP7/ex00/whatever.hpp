#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename Type>
void swap(Type &a, Type &b) {
	Type tmp = a;
	a = b;
	b = tmp;
}

template <typename Type>
Type min(Type &a, Type &b) {
	if (a < b)
		return (a);
	return (b);
}

template <typename Type>
const Type min(const Type &a, const Type &b) {
	if (a < b)
		return (a);
	return (b);
}

template <typename Type>
Type max(Type &a, Type &b) {
	if (a > b)
		return (a);
	return (b);
}

template <typename Type>
const Type max(const Type &a, const Type &b) {
	if (a > b)
		return (a);
	return (b);
}

#endif