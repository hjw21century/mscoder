// cl.exe /W4 /nologo /EHsc /MTd
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename S> void print(const S& s) {
	for (const auto& p : s) {
		cout << "(" << p << ") ";
	}
	cout << endl;
}

// Test std::find()
template <class InputIterator, class T>
void find_print_result(InputIterator first, InputIterator last, const T& value) {

	// call <algorithm> std::find()
	auto p = find(first, last, value);

	cout << "value " << value;
	if (p == last) {
		cout << " not found." << endl;
	}
	else {
		cout << " found." << endl;
	}
}

// Test std::find_if()
template <class InputIterator, class Predicate>
void find_if_print_result(InputIterator first, InputIterator last,
	Predicate Pred, const string& Str) {

	// call <algorithm> std::find_if()
	auto p = find_if(first, last, Pred);

	if (p == last) {
		cout << Str << " not found." << endl;
	}
	else {
		cout << "first " << Str << " found: " << *p << endl;
	}
}

// Function to use as the UnaryPredicate argument to find_if() in this example
bool is_odd_int(int i) {
	return ((i % 2) != 0);
}

int main()
{
	// Test using a plain old array.
	const int x[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	const double y[] = { 1.1, 2.2, 3.1, 4.2, 5.5, 6.4, 7.3, 8.1, 9.1, 10.2 };
	cout << "array x[] contents: ";
	print(x);
	// Using non-member std::begin()/std::end() to get input iterators for the plain old array.
	cout << "Test std::find() with array..." << endl;
	find_print_result(begin(x), end(x), 10);
	find_print_result(begin(x), end(x), 42);
	cout << "Test std::find_if() with array..." << endl;

	find_print_result(begin(y), end(y), 6.4);
	find_print_result(begin(y), end(y), 6.3);

	find_if_print_result(begin(x), end(x), is_odd_int, "odd integer"); // function name
	find_if_print_result(begin(x), end(x), // lambda
		[](int i) { return ((i % 2) == 0); }, "even integer");

	// Test using a vector.
	vector<int> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back((i + 1) * 10);
	}
	cout << endl << "vector v contents: ";
	print(v);
	cout << "Test std::find() with vector..." << endl;
	find_print_result(v.begin(), v.end(), 20);
	find_print_result(v.begin(), v.end(), 12);
	cout << "Test std::find_if() with vector..." << endl;
	find_if_print_result(v.begin(), v.end(), is_odd_int, "odd integer");
	find_if_print_result(v.begin(), v.end(), // lambda
		[](int i) { return ((i % 2) == 0); }, "even integer");
}