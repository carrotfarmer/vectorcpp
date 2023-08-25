#include <iostream>

#include "./vector.hpp"

template <typename T>
void print_vec(Vector<T>& vec)
{
    std::cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    Vector<int> myVec;
    myVec.push_back(3);
    myVec.push_back(4);
    myVec.push_back(5);

    print_vec(myVec);

    std::cout << "current size: " << myVec.size() << std::endl;
    std::cout << "current capacity: " << myVec.capacity() << std::endl;

    Vector<int> vec2 = myVec;

    print_vec(vec2);

    Vector<int> vec3;
    vec3.push_back(2);
    vec3.push_back(3);
    vec3.push_back(4);
    vec3.push_back(5);
    vec3.push_back(6);

    Vector<int> vec4;
    vec4 = vec3;

    print_vec(vec3);
    print_vec(vec4);

    std::cout << vec4.at(2) << std::endl;

    // should error
    std::cout << vec4.at(7) << std::endl;

    return 0;
}
