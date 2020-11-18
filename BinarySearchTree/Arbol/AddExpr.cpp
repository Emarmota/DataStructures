#include "AddExpr.h"
#include "Expr.cpp"
#include <iostream>
#include <string>
using namespace std;

typedef  Expr* ExprPtr;
class  AddExpr : public Expr
{
    ExprPtr  left, right;

public:
    AddExpr(ExprPtr l, ExprPtr r) : left(l), right(r) {}
    ~AddExpr() { delete left; delete right; }

    int  eval() { return  left->eval() + right->eval(); }
    void  print()
    {
        cout << "(";
        left->print();
        cout << " + ";
        right->print();
        cout << ")";
    }
};
