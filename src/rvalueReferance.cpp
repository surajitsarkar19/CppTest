#include <iostream>

using namespace std;

struct W
{
    int m_a,m_b;
   W(int& a, int& b)
   :m_a(a),m_b(b){}
};

template <class T, class A1, class A2>
T* factory(A1&& a1, A2&& a2) //using R-value referance
{
   return new T(a1, a2);
}

void rValueReferance()
{
    int a=5.8,b=6.7;
	W* w = factory<W>(a,b);
	//W* w = factory<W>(5,7); //without && it will give compile time error
	cout<<"rvalue :"<<w->m_a<<" "<<w->m_b<<endl;
}
