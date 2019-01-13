#include <iostream>
#include <string>

using namespace std;

template <class T>
inline T square(T x)
{
   T result;
   result = x * x;
   return result;
};

// template specialization for std::string
template <>
string square<string>(string ss)
{
   return (ss+ss);
};

void templateSpecialization()
{
    cout<<"square(4) :"<<square(4)<<endl;
    string str = "Bla";
    cout<<"square('Bla') :"<<square(str)<<endl;
}
