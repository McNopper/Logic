# A many-valued and temporal logic

This implementation uses a [many-valued](https://en.wikipedia.org/wiki/Many-valued_logic) and a [temporal](https://en.wikipedia.org/wiki/Temporal_logic) logic and is inspired by the following thought experiment:

## Thought experiment
Before a [coin flipping](https://en.wikipedia.org/wiki/Coin_flipping), the truth value if e.g. the heads up is unknown. If the coin is flipped and kept covered, the truth value stays unknown. It only becomes true or false, if the coin is uncovered. However, if the coin is flipped again, this previous flipped truth value stays unknown.  
It seems, that the truth value unknown - a superposition - is the same in the future, the present and the past.

This thought experiment is inspired by [Wigner's friend](https://en.wikipedia.org/wiki/Wigner%27s_friend) and [Schrödinger's cat](https://en.wikipedia.org/wiki/Schr%C3%B6dinger%27s_cat).

## Implementation

The `TruthValue` can be `FALSE`, `UNKNOWN` and `TRUE`. The `TruthVariable` class contains the implementation of the basic boolean operations, where the given `TruthValue` is associated with a given `timePoint`. The `Logic.cpp` contains test functions and the main entry point.

### How to build?

The implementation is a C/C++ cross-platform application and requires C++17. Following STL libraries are used for convenience:

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
