#include "SubExpr.h"
#include "IntExpr.h"
#include "AddExpr.h"
#include "Expr.cpp"
#include <iostream>
#include <string>
using namespace std;

typedef  Expr* ExprPtr;
class  SubExpr : public Expr
{
    ExprPtr  left, right;

public:
    SubExpr(ExprPtr l, ExprPtr r) : left(l), right(r) {}
    ~SubExpr() { delete left; delete right; }

    int  eval() { return  left->eval() - right->eval(); }
    void  print()
    {
        cout << "(";
        left->print();
        cout << " - ";
        right->print();
        cout << ")";
    }
};