#ifndef BOO_H
#define BOO_H

#include "Foo.h"

class Boo: public Foo
{
    public:
        Boo();
        virtual ~Boo();
        void DisplayMessage();
        void DisplayMessage(string str);

    protected:

    private:
};

#endif // BOO_H
