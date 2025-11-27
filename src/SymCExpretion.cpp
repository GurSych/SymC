#include "SymC/SymCExpression.hpp"
#include "SymC/SymCNumeric.hpp"
#include "SymC/SymCOperators.hpp"

gtd::SymCExpr::SymCExpr() { }
gtd::SymCExpr::SymCExpr(const gtd::SymCExpr& expr) : _node{std::move(expr._node->copy())} {}
gtd::SymCExpr::SymCExpr(gtd::SymCExpr&& expr)      : _node{std::move(expr._node)} {}
gtd::SymCExpr::SymCExpr(gtd::SymCNodePtr node)     : _node{std::move(node)} { }
gtd::SymCExpr::SymCExpr(int64_t value)             : _node{std::make_unique<gtd::SymCInt>(value)} { }
gtd::SymCExpr& gtd::SymCExpr::operator=(const gtd::SymCExpr& expr) {
    if (this != &expr) _node = std::move(expr._node->copy());
    return *this;
}
gtd::SymCExpr& gtd::SymCExpr::operator=(gtd::SymCExpr&& expr) {
    if (this != &expr) _node = std::move(expr._node);
    return *this;
}
gtd::SymCExpr gtd::SymCExpr::copy() const {
    return gtd::SymCExpr{std::move(_node->copy())};
}
bool gtd::SymCExpr::operator==(const gtd::SymCExpr& left_expr) const {
    return _node->operator==(left_expr._node);
}
gtd::SymCExpr gtd::SymCExpr::operator+(const gtd::SymCExpr& left_obj) {
    return gtd::SymCExpr{std::make_unique<gtd::SymCPlus>(_node->copy(),left_obj.copy())};
}
std::string gtd::SymCExpr::to_string() const {
    return _node->to_string();
}