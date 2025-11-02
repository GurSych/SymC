#pragma once

#include "SymC/SymCNode.hpp"
#include "SymC/SymCExpression.hpp"

#include <string>

namespace gtd {

    class SymCSymbolic;

    class Symbol;

    gtd::SymCExpr getSymbol(char);

}

class gtd::SymCSymbolic: public gtd::SymCNode {
public:
    gtd::SymCNodeType nodeType() override {
        return SymCSymbolicNode;
    }
    std::string to_string() const override {
        return std::string{"#SYMBOLIC#"};
    }
};

class gtd::Symbol: public gtd::SymCSymbolic {
public:
    gtd::SymCType type() override {
        return gtd::SymCSymbolType;
    }
    Symbol(char);
    bool operator==(const gtd::SymCNodePtr& expr) const override {
        if(expr->type() != gtd::SymCSymbolType) return false;
        return _symbol == gtd::get_SymC_ptr<gtd::Symbol>(expr)->_symbol;
    }
    SymCNodePtr copy() const override {
        return std::make_unique<gtd::Symbol>(_symbol);
    }
    std::string to_string() const override {
        return std::string{_symbol};
    }
protected:
    char _symbol;
};