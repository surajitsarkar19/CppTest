#include "Boo.h"

Boo::Boo()
:Foo(0)
{
    //ctor
}

Boo::~Boo()
{
    //dtor
}

void Boo::DisplayMessage()
{

}

void Boo::DisplayMessage(string str)
{
    cout<<"Message from Boo :"<<str<<endl;
}
