#pragma once

#include <cstdint>
#include <ctype.h>
#include <memory>
#include <string>

namespace gtd {

    enum SymCNodeType {
        SymCNullNodeType,
        SymCSymbolNode,
        SymCNumericNode,
        SymCOperatorNode
    };
    enum SymCType {
        SymCNull,
        SymCSymbolType,
        SymCIntType, SymCFloatType,
        SymCPlusType, SymCMinusType,
        SymCMulType, SymCDivideType
    };

    class SymCNode {
    public:
        virtual ~SymCNode() = default;
        virtual SymCNodeType nodeType() {
            return SymCNullNodeType;
        }
        virtual SymCType type() {
            return SymCNull;
        }
        virtual std::unique_ptr<SymCNode> copy();
    };
    using SymCNodePtr = std::unique_ptr<SymCNode>;

    class SymCExpr {
    public:
        SymCExpr();
        SymCExpr(SymCNodePtr);
        SymCExpr(int64_t);
        SymCExpr(float);
        SymCExpr(char);
    private:
        SymCNodePtr _node{};
    };

    class SymCSymbol: public SymCNode {
    public:
        SymCNodeType nodeType() override {
            return SymCSymbolNode;
        }
    };
    class Symbol: public SymCSymbol {
    public:
        SymCType type() override {
            return SymCSymbolType;
        }
    };

    class SymCNumeric: public SymCNode {
    public:
        SymCNodeType nodeType() override {
            return SymCNumericNode;
        }
    };
    class SymCInt: public SymCNumeric {
    public:
        SymCType type() override {
            return SymCIntType;
        }
    };
    class SymCFloat: public SymCNumeric {
    public:
        SymCType type() override {
            return SymCFloatType;
        }
    };

    class SymCOperator: public SymCNode {
    public:
        SymCNodeType nodeType() override {
            return SymCOperatorNode;
        }
    };
    
    class SymCPlus: public SymCOperator {
    public:
        SymCType type() override {
            return SymCPlusType;
        }
    };
    class SymCMinus: public SymCOperator {
    public:
        SymCType type() override {
            return SymCMinusType;
        }
    };
    class SymCMul: public SymCOperator {
    public:
        SymCType type() override {
            return SymCMulType;
        }
    };
    class SymCDivide: public SymCOperator {
    public:
        SymCType type() override {
            return SymCDivideType;
        }
    };

}