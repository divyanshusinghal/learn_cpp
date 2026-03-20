#include<iostream>
#include<vector>

void HelloWorld()
{
    std::cout << "Hello World " << std::endl;
}

void HelloWorld1(int a)
{
    std::cout << "Hello World " << a << std::endl;
}


int main()
{

    // calling with function() will given an error. 
    // however, if we do &HelloWorld, we might get the pointer to function
    auto function = &HelloWorld;
    auto function2 = HelloWorld;
    std::cout << "function: " << function << std::endl;
    std::cout << "function2: " << function2 << std::endl;
    // Both print same values above
    function();
    function2();

    // THIS ALSO WORKS
    // ACTUAL TYPE OF FUNCTION and FunCTION 2 variable => how do we know? However over function() or function2()
    void (*func_ptr)();     
    func_ptr = HelloWorld;
    func_ptr();

    // another way of doing this
    typedef void(*HELLOWORLDFUNCTION)();
    HELLOWORLDFUNCTION func = HelloWorld;
    func();

    // for a funciton which acceps args
    typedef void(*HelloWorldFunction2)(int);
    HelloWorldFunction2 func2 = HelloWorld1;
    func2(2);
    std::cin.get();
    
}

