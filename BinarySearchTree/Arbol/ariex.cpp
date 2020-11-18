#include <iostream>
#include <string>
#include <vector>
using namespace std;
class   Expr
{
public:
    virtual  int   eval() = 0;
    virtual  void  print() = 0;
    virtual  ~Expr() {}
};

typedef  Expr* ExprPtr;

class  IntExpr : public Expr
{
    int  n;

public:
    IntExpr(int x) : n(x) {}
    ~IntExpr() { }

    int   eval() { return  n; }
    void  print() { cout << n; }
};


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

class  DivExpr : public Expr {

    ExprPtr  left, right;

public:
    DivExpr(ExprPtr l, ExprPtr r) : left(l), right(r) {}
    ~DivExpr() { delete left; delete right; }

    int  eval() { return  left->eval() / right->eval(); }
    void  print()
    {
        cout << "(";
        left->print();
        cout << " / ";
        right->print();
        cout << ")";
    }
};


class  NegateExpr : public Expr {

    ExprPtr  only;

public:
    NegateExpr(ExprPtr o) : only(o) {}
    ~NegateExpr() { delete only; }

    int  eval() { return  -only->eval(); }
    void  print()
    {
        cout << "-(";
        only->print();
        cout << ")";
    }
};



int main()
{
    IntExpr    i123(123);
    MultExpr   m(new IntExpr(5), new AddExpr(new IntExpr(2), new IntExpr(3)));
    NegateExpr    n(new  IntExpr(-1));
    DivExpr    d(new  IntExpr(3), new  NegateExpr(new  IntExpr(2)));


    i123.print();
    cout << endl;
    cout << i123.eval() << "\n" << endl;

    m.print();
    cout << endl;
    cout << m.eval() << "\n" << endl;

    n.print();
    cout << endl;
    cout << n.eval() << "\n" << endl;

    d.print();
    cout << endl;
    cout << d.eval() << "\n" << endl;

}

