# A many-valued and temporal logic

This implementation uses a [many-valued](https://en.wikipedia.org/wiki/Many-valued_logic) and a [temporal](https://en.wikipedia.org/wiki/Temporal_logic) logic and is inspired by the following thought experiment:

## Thought experiment
After a [coin flipping](https://en.wikipedia.org/wiki/Coin_flipping) by one person and an observing person, the truth value - if e.g. the head of the coin is up - is for both unknown when the coin is kept covered. Even both persons know, that either the head of the coin is up or not, the coin is in a superposition for both of them. If the person uncovers the coin for the observer, the truth value becomes for the observer either true or false. However, for the person who flipped the coin, the truth value remains unknown until the coin is completely uncovered.  
It is interesting, that at the same time, a superposition of the coin for one person and a non-superposition of the coin for the observer is possible. 
  
This thought experiment is inspired by [Wigner's friend](https://en.wikipedia.org/wiki/Wigner%27s_friend) and [Schrödinger's cat](https://en.wikipedia.org/wiki/Schr%C3%B6dinger%27s_cat).

## Implementation

The `TruthValue` can be `FALSE`, `UNKNOWN` and `TRUE`. The `TruthVariable` class contains the implementation of the basic boolean operations. The `Logic.cpp` file contains functions to test the implementation.

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
