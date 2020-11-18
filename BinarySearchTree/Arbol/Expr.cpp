#include "Expr.h"
class   Expr
{
public:
    virtual  int   eval() = 0;
    virtual  void  print() = 0;
    virtual  ~Expr() {}
};