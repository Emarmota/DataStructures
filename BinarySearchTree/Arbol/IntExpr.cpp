#include "IntExpr.h"
#include "AddExpr.h"
#include "Expr.cpp"
#include <iostream>
#include <string>
using namespace std;
class  IntExpr : public Expr
{
    int  n;

public:
    IntExpr(int x) : n(x) {}
    ~IntExpr() { }

    int   eval() { return  n; }
    void  print() { cout << n; }
};
