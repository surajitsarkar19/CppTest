#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
#include <string>
#include <cstdlib>
using namespace std;

vector<std::string> split(const std::string& s, char delimiter)
{
   vector<std::string> tokenss;
   string token;
   istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    string mystr;
    int n,a,b,x;

    getline (cin,mystr);
    stringstream(mystr) >> n;
    assert(n>=1 && n<=500000);

    string str;
    getline (cin,mystr);
    str = mystr;

    vector<string> list = split(str, ' ');
    assert(list.size() == n);
    cin>>x;
    assert(x>=1 && x<=n);
    cin>>a>>b;
    assert(a>=1 && a<=n);
    assert(b>=1 && b<=n && b>a);

    list.erase(list.begin()+(x-1));

    list.erase(list.begin()+(a-1),list.begin()+(b-1));

    cout<<list.size()<<endl;
    for (auto it = list.begin() ; it != list.end(); ++it)
        cout << *it <<' ';


    return 0;
}