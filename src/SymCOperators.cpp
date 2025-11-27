#include "SymC/SymCOperators.hpp"

gtd::SymCOperator::SymCOperator(gtd::SymCExpr left_expr, gtd::SymCExpr right_expr)
                    : _left{std::move(left_expr.copy())}, _right{std::move(right_expr.copy())} { }