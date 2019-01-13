#include "Foo.h"

Foo::Foo(int foo) : m_foo (foo)
{
    //ctor
}

Foo::~Foo()
{
    //dtor
}

int Foo::GetFoo () { return m_foo; }

void Foo::DisplayMessage(string str)
{
    cout<<"Message from Foo :"<<str<<endl;
}
void Foo::SetFoo(int val)
{
    m_foo = val;
}
