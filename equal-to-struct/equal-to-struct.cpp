// functional_equal_to.cpp
// compile with: /EHsc
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	vector <double> v1, v2, v3(6);
	vector <double>::iterator Iter1, Iter2, Iter3;

	int i;
	for (i = 0; i <= 5; i += 2)
	{
		v1.push_back(2.0 *i);
		v1.push_back(2.0 * i + 1.0);
	}

	int j;
	for (j = 0; j <= 5; j += 2)
	{
		v2.push_back(-2.0 * j);
		v2.push_back(2.0 * j + 1.0);
	}

	cout << "The vector v1 = ( ";
	for (Iter1 = v1.begin(); Iter1 != v1.end(); Iter1++)
		cout << *Iter1 << " ";
	cout << ")" << endl;

	cout << "The vector v2 = ( ";
	for (Iter2 = v2.begin(); Iter2 != v2.end(); Iter2++)
		cout << *Iter2 << " ";
	cout << ")" << endl;

	// Testing for the element-wise equality between v1 & v2
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(),
		equal_to<double>());

	cout << "The result of the element-wise equal_to comparison\n"
		<< "between v1 & v2 is: ( ";
	for (Iter3 = v3.begin(); Iter3 != v3.end(); Iter3++)
		cout << *Iter3 << " ";
	cout << ")" << endl;
}