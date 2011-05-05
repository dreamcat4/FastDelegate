class SomeClass;

typedef void (SomeClass::*SomePtr)(void);

static SomePtr ptr;
static SomeClass *pClass;

void Invoker()
{
        (pClass->*ptr)();
}

class X
{
public:
          void   somefunc();
};

typedef void (X::*XPtr)(void);

X* pX;
XPtr Xptr;

void XInvoke()
{
        (pX->*Xptr)();
}

