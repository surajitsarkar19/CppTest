#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct absValue
{
	float operator()(float f) {
		return f > 0 ? f : -f;
	}
};

template<typename T>
class Print {
public:
	void operator()(T& elem) const {
		cout << elem << " ";
	}
};

void functorExample()
{
    float f = -123.45;
	absValue aObj;
	float abs_f = aObj(f);
	cout << "f = " << f << " abs_f = " << abs_f << endl;

	vector<int> vect;
	for (int i=1; i<10; ++i) {
		vect.push_back(i);
	}

	Print<int> print_it;
	for_each (vect.begin(), vect.end(), print_it);
        cout << endl;
}
