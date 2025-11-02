#include "SymC/SymC.hpp"

std::ostream& operator<<(std::ostream& os, const gtd::SymCExpr& expr) {
    os << expr.to_string();
    return os;
}