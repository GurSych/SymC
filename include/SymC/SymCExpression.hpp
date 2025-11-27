#pragma once

#include "SymC/SymCNode.hpp"

#include <string>

namespace gtd {

    class SymCExpr;

    template<typename T>
    T* get_SymC_ptr(const SymCExpr&);

}

class gtd::SymCExpr {
template<typename T>
friend T* gtd::get_SymC_ptr(const gtd::SymCExpr&);
public:
    SymCExpr();
    SymCExpr(const SymCExpr&);
    SymCExpr(SymCExpr&&);
    SymCExpr(gtd::SymCNodePtr);
    SymCExpr(int64_t);
    gtd::SymCNodeType nodeType() {
        return _node->nodeType();
    }
    gtd::SymCType type() {
        return _node->type();
    }
    SymCExpr& operator=(const SymCExpr&);
    SymCExpr& operator=(SymCExpr&&);
    gtd::SymCExpr copy() const;
    bool operator==(const gtd::SymCExpr&) const;
    gtd::SymCExpr operator+(const gtd::SymCExpr&);
    std::string to_string() const;
protected:
    gtd::SymCNodePtr _node{};
};

namespace gtd {

    template<typename T>
    T* get_SymC_ptr(const gtd::SymCExpr& expr) {
        return gtd::get_SymC_ptr<T>(expr._node);
    }

}