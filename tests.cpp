#include <cassert>
#include <stdexcept>

#include "vector.hpp"

int main()
{
    Vector<int> empty;
    assert(empty.size() == 0);
    assert(empty.capacity() > 0);
    empty.pop_back();
    assert(empty.size() == 0);

    // tests growth past the initial capacity
    Vector<int> values;
    const size_t initial_capacity = values.capacity();
    for (size_t i = 0; i <= initial_capacity; ++i) {
        values.push_back(static_cast<int>(i));
    }
    assert(values.size() == initial_capacity + 1);
    assert(values.capacity() > initial_capacity);
    assert(values[initial_capacity] == static_cast<int>(initial_capacity));

    // pop until empty, then grow again from the reduced capacity
    Vector<int> regrowth = { 1, 2 };
    regrowth.pop_back();
    regrowth.pop_back();
    assert(regrowth.size() == 0);
    assert(regrowth.capacity() > 0);
    regrowth.push_back(3);
    regrowth.push_back(4);
    assert(regrowth[0] == 3);
    assert(regrowth[1] == 4);

    // copies should be independent
    Vector<int> original = { 10, 20, 30 };
    Vector<int> copy(original);
    copy[0] = 99;
    assert(original[0] == 10);
    assert(copy[0] == 99);

    // assigned vectors shouldbe independent and assignment returns *this
    Vector<int> assigned;
    Vector<int>* result = &(assigned = original);
    assigned[1] = 88;
    assert(result == &assigned);
    assert(original[1] == 20);
    assert(assigned[1] == 88);
    assigned = assigned;
    assert(assigned[0] == 10);

    auto is_out_of_range = [](auto access) {
        try {
            access();
        }
        catch (const std::out_of_range&) {
            return true;
        }
        return false;
    };
    assert(is_out_of_range([&] { (void)original.at(original.size()); }));
    assert(is_out_of_range([&] { (void)original[original.size()]; }));

    // iteration visits every element
    int sum = 0;
    for (int value : original) {
        sum += value;
    }
    assert(sum == 60);
}
