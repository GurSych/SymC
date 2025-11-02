#include "SymC/SymCExpression.hpp"
#include "SymC/SymCNumeric.hpp"
#include "SymC/SymCOperators.hpp"

gtd::SymCExpr::SymCExpr() { }
gtd::SymCExpr::SymCExpr(gtd::SymCNodePtr node) : _node{std::move(node)} { }
gtd::SymCExpr::SymCExpr(int64_t value)         : _node{std::make_unique<gtd::SymCInt>(value)} { }
gtd::SymCExpr gtd::SymCExpr::copy() const {
    return gtd::SymCExpr{_node->copy()};
}
std::string gtd::SymCExpr::to_string() const {
    return _node->to_string();
}
bool gtd::SymCExpr::operator==(const gtd::SymCExpr& left_expr) const {
    return _node == left_expr._node;
}
gtd::SymCExpr gtd::SymCExpr::operator+(const gtd::SymCExpr& left_obj) {
    return gtd::SymCExpr{std::make_unique<gtd::SymCPlus>(std::move(_node),left_obj.copy())};
}