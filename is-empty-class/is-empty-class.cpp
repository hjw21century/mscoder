// std__type_traits__is_empty.cpp
// compile with: /EHsc
#include <type_traits>
#include <iostream>

struct empty
{
};

struct trivial
{
	int val;
};

int main()
{
	std::cout << "is_empty<trivial> == " << std::boolalpha
		<< std::is_empty<trivial>::value << std::endl;
	std::cout << "is_empty<empty> == " << std::boolalpha
		<< std::is_empty<empty>::value << std::endl;
	std::cout << "is_empty<int> == " << std::boolalpha
		<< std::is_empty<int>::value << std::endl;

	return (0);
}