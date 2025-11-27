#include <iostream>
#include <ios>

#include "SymC/SymC.hpp"

int main() {
	gtd::SymCExpr x = gtd::getSymbol('x');
	gtd::SymCExpr y = x + 3;
	std::cout << "y = " << y << std::endl;
	gtd::SymCExpr z = y;
	std::cout << "z = " << z << std::endl;
	std::cout << "z + 4 = " << z + 4 << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << std::boolalpha << "z == y: " << (z == y) << std::endl;
	z = z + z;
	std::cout << "z = " << z << std::endl;
	std::cout << std::boolalpha << "z == y: " << (z == y) << std::endl;
	return 0;
}