#include "MultExpr.h"
#include "Expr.cpp"
#include <iostream>
#include <string>
using namespace std;

typedef  Expr* ExprPtr;
class  MultExpr : public Expr
{
    ExprPtr  left, right;

public:
    MultExpr(ExprPtr l, ExprPtr r) : left(l), right(r) {}
    ~MultExpr() { delete left; delete right; }

    int  eval() { return  left->eval() * right->eval(); }
    void  print()
    {
        cout << "(";
        left->print();
        cout << " * ";
        right->print();
        cout << ")";
    }
};