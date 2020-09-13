# A many-valued and temporal logic implementation

This implementation uses a [many-valued](https://en.wikipedia.org/wiki/Many-valued_logic) and a [temporal](https://en.wikipedia.org/wiki/Temporal_logic) logic and is inspired by the following thought experiment:

## Thought experiment
Before a [coin flipping](https://en.wikipedia.org/wiki/Coin_flipping), the truth value for e.g. heads up is unknown. If the coin is flipped and kept covered, the truth value stays unknown. It only becomes either true or false, if the coin is uncovered by the observer. However, if the coin is flipped again, the previous flipped truth value stays unknown.  
It seems, that the truth value unknown - a superposition truth value - is the same in the future, the present and the past.

This thought experiment is inspired by [Wigner's friend](https://en.wikipedia.org/wiki/Wigner%27s_friend), [Schrödinger's cat](https://en.wikipedia.org/wiki/Schr%C3%B6dinger%27s_cat) and the [Law of excluded middle](https://en.wikipedia.org/wiki/Law_of_excluded_middle).

## Logic

Following truth values are given:

- `TRUE`
- `UNKNOWN`
- `FALSE`

Unknown is either true or false but is not known by the observer. Not unknown is either true or false, which leads to unknown again.

Following truth tables are given:

| P         | NOT P     |
|-----------|-----------|
| `TRUE`    | `FALSE`   |
| `UNKNOWN` | `UNKNOWN` |
| `FALSE`   | `TRUE`    |

| P         | Q         | P OR Q    |
|-----------|-----------|-----------|
| `TRUE`    | `TRUE`    | `TRUE`    |
| `TRUE`    | `UNKNOWN` | `TRUE`    |
| `TRUE`    | `FALSE`   | `TRUE`    |
| `UNKNOWN` | `UNKNOWN` | `UNKNOWN` |
| `UNKNOWN` | `FALSE`   | `UNKNOWN` |
| `FALSE`   | `FALSE`   | `FALSE`   |

| P         | Q         | P AND Q   |
|-----------|-----------|-----------|
| `TRUE`    | `TRUE`    | `TRUE`    |
| `TRUE`    | `UNKNOWN` | `UNKNOWN` |
| `TRUE`    | `FALSE`   | `FALSE`   |
| `UNKNOWN` | `UNKNOWN` | `UNKNOWN` |
| `UNKNOWN` | `FALSE`   | `FALSE`   |
| `FALSE`   | `FALSE`   | `FALSE`   |

As a truth variable can change over time, one or more discrete time points can be associated to the truth value. This allows to evaluate the truth variables at specific time points.

`TruthVariable` -> [`timePoint`, ...]

## Implementation

The `TruthValue` enumeration defines the truth values `TRUE`, `UNKNOWN` and `FALSE`. The `TruthVariable` class contains the implementation of the basic boolean operations, where the given `TruthValue` is associated with a given `timePoint`. The `Logic.cpp` contains test functions and the main entry point of the application.

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
