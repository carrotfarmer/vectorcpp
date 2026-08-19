# vectorcpp

A simple vector implementation for C++.

## Methods

- `push_back(value)` — append an element
- `pop_back()` — remove the last element, if present
- `at(index)` — access an element with bounds checking
- `size()` — return the number of stored elements
- `capacity()` — return the current allocated capacity
- `begin()` and `end()` — iterate over the elements

## Operators

- `vector[index]` — access an element with bounds checking
- `<destination> = <source>` — copy assignment with independent storage
- range-based `for` loops through `begin()` and `end()`

Vectors can also be copied with the copy constructor. A copy does not affect the original vector.

## Usage

```cpp
#include <iostream>

#include "src/vector.hpp"

int main()
{
    Vector<int> numbers = { 1, 2, 3 };
    numbers.push_back(4);

    numbers[0] = 10;
    std::cout << numbers.at(1) << '\n';

    for (int number : numbers) {
        std::cout << number << ' ';
    }
    std::cout << '\n';

    Vector<int> copy = numbers;
    copy.pop_back();

    std::cout << "original size: " << numbers.size() << '\n';
    std::cout << "copy size: " << copy.size() << '\n';
}
```
