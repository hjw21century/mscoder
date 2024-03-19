// Compile using cl.exe /EHsc
// common_type sample
#include <iostream>
#include <type_traits>

struct Base {};
struct Derived : Base {};

int main()
{
	typedef std::common_type<unsigned char, short, int>::type NumericType;
	typedef std::common_type<float, double>::type FloatType;
	typedef std::common_type<const int, volatile int>::type ModifiedIntType;
	typedef std::common_type<Base, Derived>::type ClassType;

	std::cout << std::boolalpha;
	std::cout << "Test for typedefs of common_type int" << std::endl;
	std::cout << "NumericType: " << std::is_same<int, NumericType>::value << std::endl;
	std::cout << "FloatType: " << std::is_same<int, FloatType>::value << std::endl;
	std::cout << "ModifiedIntType: " << std::is_same<int, ModifiedIntType>::value << std::endl;
	std::cout << "ClassType: " << std::is_same<int, ClassType>::value << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Test for typedefs of common_type double" << std::endl;
	std::cout << "NumericType: " << std::is_same<double, NumericType>::value << std::endl;
	std::cout << "FloatType: " << std::is_same<double, FloatType>::value << std::endl;
	std::cout << "ModifiedIntType: " << std::is_same<double, ModifiedIntType>::value << std::endl;
	std::cout << "ClassType: " << std::is_same<double, ClassType>::value << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Test for typedefs of common_type Base" << std::endl;
	std::cout << "NumericType: " << std::is_same<Base, NumericType>::value << std::endl;
	std::cout << "FloatType: " << std::is_same<Base, FloatType>::value << std::endl;
	std::cout << "ModifiedIntType: " << std::is_same<Base, ModifiedIntType>::value << std::endl;
	std::cout << "ClassType: " << std::is_same<Base, ClassType>::value << std::endl;

	return 0;
}