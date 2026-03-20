#include<iostream>
#include<vector>

void PrintValue(int value)
{
    std::cout << "Value: " << value << std::endl;
}


void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for(int v:values)
    {
        func(v);
    }
}

int main()
{
    std::vector<int> values = {1, 5, 4, 2, 3};
    ForEach(values, PrintValue);
    // in the below example, yu can see that lambda is passed sa a function pointer
    ForEach(values, [](int value){std::cout << "Value: "<< value << ::std::endl;});

    std::cin.get();
}