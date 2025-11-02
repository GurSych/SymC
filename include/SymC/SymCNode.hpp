#pragma once

#include <memory>

namespace gtd {

    enum SymCNodeType {
        SymCNullNodeType,
        SymCSymbolicNode,
        SymCNumericNode,
        SymCOperatorNode
    };
    enum SymCType {
        SymCNull,
        SymCSymbolType,
        SymCIntType,
        SymCPlusType
    };

    class SymCNode;

    using SymCNodePtr = std::unique_ptr<SymCNode>;

    template<typename T>
    T* get_SymC_ptr(const gtd::SymCNodePtr& node) {
        return static_cast<T*>(node.get());
    }

}

class gtd::SymCNode {
public:
    virtual ~SymCNode() = default;
    virtual gtd::SymCNodeType nodeType() {
        return gtd::SymCNullNodeType;
    }
    virtual gtd::SymCType type() {
        return gtd::SymCNull;
    }
    virtual bool operator==(gtd::SymCNodePtr&) const = 0;
    virtual gtd::SymCNodePtr copy() const = 0;
    //virtual SymCNodePtr subs(SymCExpr,SymCExpr) const = 0;
    virtual std::string to_string() const = 0;
};