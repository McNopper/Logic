# A many-valued and temporal logic

This implementation uses a [many-valued](https://en.wikipedia.org/wiki/Many-valued_logic) and [temporal](https://en.wikipedia.org/wiki/Temporal_logic) logic to solve the following problem:

## Problem
Before a [coin flipping](https://en.wikipedia.org/wiki/Coin_flipping) experiment by a person and an observer, the truth value is to both unknown, if e.g. the head side is on top or not. After the coin is flipped by this person and catches it with one hand and covers it with the other hand, the head side is either on top or not. For the person and the observer, the truth value remains unknown even though the head is either on top or not. If the person uncovers the coin for the observer, the truth value becomes for the observer either true or false. The observer already knows the truth value. However, for the person who flipped the coin the truth value remains unknown. After the person uncovers the coin, the truth value also becomes either true or false.  
  
From my point of view, this problem is a similar problem to [Schrödinger's cat](https://en.wikipedia.org/wiki/Schr%C3%B6dinger%27s_cat), as I think the coin is also in a [paradox](https://en.wikipedia.org/wiki/Paradox) state after the flipping and before the uncovering.

## Implementation

The `TruthValue` class is implemented in a generic way, which implements a combination of a many-valued and temporal logic. The `Logic.cpp` file utilizes this class as an experiment on the given problem.

### How to build?

The implementation is a C/C++ cross-platform application and requires C++17 because it is set in the project file. Following STL libraries are used co convenience:

- `<algorithm>`
- `<cstdint>`
- `<cstdio>`
- `<map>`
- `<string>`

For building, the [GNU Compiler Collection](https://gcc.gnu.org/) is used.

### Required tools
- [Eclipse C/C++ Development Tooling](https://projects.eclipse.org/projects/tools.cdt)
- [MSYS2](https://www.msys2.org/) on Windows  
  Execute `pacman -S mingw-w64-x86_64-gcc` to install MinGW64
