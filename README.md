# SymC

SymC is my C++ library for symbolic computing

# Using Library

> The library is in development so this section is updated together with library itself

## Library connection

```cpp
#include "SymC/SymC.hpp"
```

> [!NOTE]
> All library classes are in `gtd` namespace.

## Personal compiling notes

These are my ways to comile test files with SymC using g++

```bash
g++ test.cpp -o test -I include $(find src -name "*.cpp")
```

and using clang++

```bash
clang++ test.cpp -o test -I include $(find src -name "*.cpp")
```