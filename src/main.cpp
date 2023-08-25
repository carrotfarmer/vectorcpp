#include <iostream>

#include "./vector.hpp"

int main()
{
    Vector<int> myVec;
    myVec.push_back(3);
    myVec.push_back(4);
    myVec.push_back(5);

    for (int i = 0; i < myVec.size(); i++) {
        std::cout << myVec[i] << std::endl;
    }

    std::cout << "current size: " << myVec.size() << std::endl;
    std::cout << "current capacity: " << myVec.capacity() << std::endl;

    Vector<int> vec2 = myVec;

    for (int i = 0; i < vec2.size(); i++) {
        std::cout << vec2[i] << std::endl;
    }

    return 0;
}
