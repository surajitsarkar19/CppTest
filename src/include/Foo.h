#ifndef FOO_H
#define FOO_H

#include <iostream>

using namespace std;

class Foo
{
    public:
        Foo(int foo);
        virtual ~Foo();
        int GetFoo();
        void SetFoo(int val);
        virtual void DisplayMessage(string str);

    protected:

    private:
     int m_foo;
};

#endif // FOO_H
