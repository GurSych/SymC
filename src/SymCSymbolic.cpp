#include "SymC/SymCSymbolic.hpp"

gtd::Symbol::Symbol(char symbol) : _symbol{symbol} { }

gtd::SymCExpr gtd::getSymbol(char symbol) {
    return gtd::SymCExpr{std::make_unique<gtd::Symbol>(symbol)};
}