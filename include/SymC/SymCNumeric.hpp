#pragma once

#include "SymC/SymCNode.hpp"

#include <cstdint>
#include <string>

namespace gtd {

    class SymCNumeric;

    class SymCInt;

}

class gtd::SymCNumeric: public gtd::SymCNode {
public:
    gtd::SymCNodeType nodeType() override {
        return gtd::SymCNumericNode;
    }
    std::string to_string() const override {
        return std::string{"#NUMERIC#"};
    }
};

class gtd::SymCInt: public gtd::SymCNumeric {
public:
    gtd::SymCType type() override {
        return gtd::SymCIntType;
    }
    SymCInt(int64_t);
    bool operator==(const gtd::SymCNodePtr& expr) const override {
        if(expr->type() != gtd::SymCIntType) return false;
        return _value == gtd::get_SymC_ptr<gtd::SymCInt>(expr)->_value;
    }
    gtd::SymCNodePtr copy() const override {
        return std::make_unique<gtd::SymCInt>(_value);
    }
    std::string to_string() const override {
        return std::to_string(_value);
    }
protected:
    int64_t _value;
};