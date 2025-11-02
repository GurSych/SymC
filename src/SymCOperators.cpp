#include "SymC/SymCOperators.hpp"

gtd::SymCOperator::SymCOperator(gtd::SymCExpr left_expr, gtd::SymCExpr right_expr)
                    : _left{left_expr.copy()}, _right{right_expr.copy()} { }