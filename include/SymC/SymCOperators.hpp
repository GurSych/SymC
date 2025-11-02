#pragma once

#include "SymC/SymCNode.hpp"
#include "SymC/SymCExpression.hpp"

#include <string>

namespace gtd {

    class SymCOperator;

    class SymCPlus;

}

class gtd::SymCOperator: public gtd::SymCNode {
public:
    gtd::SymCNodeType nodeType() override {
        return gtd::SymCOperatorNode;
    }
    SymCOperator(gtd::SymCExpr,gtd::SymCExpr);
protected:
    gtd::SymCExpr _left;
    gtd::SymCExpr _right;
};

class gtd::SymCPlus: public gtd::SymCOperator {
public:
    gtd::SymCType type() override {
        return gtd::SymCPlusType;
    }
    using gtd::SymCOperator::SymCOperator;
    bool operator==(std::unique_ptr<gtd::SymCNode>& expr) const override {
        if(expr->type() != gtd::SymCPlusType) return false;
        return (_left == gtd::get_SymC_ptr<gtd::SymCPlus>(expr)->_left) && (_right == gtd::get_SymC_ptr<gtd::SymCPlus>(expr)->_right);
    }
    gtd::SymCNodePtr copy() const override {
        return std::make_unique<gtd::SymCPlus>(_left.copy(),_right.copy());
    }
    std::string to_string() const override {
        return '(' + _left.to_string() + '+' + _right.to_string() + ')';
    }
};