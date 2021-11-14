#include <iostream>

template <typename T> //마지막 1개 요소만 남았을 때, 개행을 위해 따로!
void print(T arg)
{
    std::cout << arg << std::endl;
}

template <typename T, typename... Types> //가변 길이 템플릿
void print(T arg, Types... args)
{
    std::cout << arg << ", ";
    print(args...);
}

int main()
{
    print(1, 3.1, "abc");
    print(1, 2, 3, 4, 5, 6, 7);
}