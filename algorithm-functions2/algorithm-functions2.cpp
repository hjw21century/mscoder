// alg_copy_if.cpp
// compile with: /EHsc
#include <list>
#include <algorithm>
#include <iostream>

void listlist(std::list<int> l)
{
	std::cout << "( ";
	for (auto const& el : l)
		std::cout << el << " ";
	std::cout << ")" << std::endl;
}

int main()
{
	using namespace std;
	list<int> li{ 46, 59, 88, 72, 79, 71, 60, 5, 40, 84 };
	list<int> le(li.size()); // le = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	list<int> lo(li.size()); // lo = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	cout << "li = ";
	listlist(li);

	// is_even checks if the element is even.
	auto is_even = [](int const elem) { return !(elem % 2); };
	// use copy_if to select only even elements from li
	// and copy them to le, starting from le's begin position
	auto ec = copy_if(li.begin(), li.end(), le.begin(), is_even);
	le.resize(std::distance(le.begin(), ec));  // shrink le to new size

	cout << "Even numbers are le = ";
	listlist(le);

	// is_odd checks if the element is odd.
	auto is_odd = [](int const elem) { return (elem % 2); };
	// use copy_if to select only odd elements from li
	// and copy them to lo, starting from lo's begin position
	auto oc = copy_if(li.begin(), li.end(), lo.begin(), is_odd);
	lo.resize(std::distance(lo.begin(), oc));  // shrink lo to new size

	cout << "Odd numbers are lo = ";
	listlist(lo);
}