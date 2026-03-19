// automate the process of allocating and deleting memory
// wrapper around a real pointer
// unique pointer -> scoped pointers, when it goes out of scope, it gets destroyed. you cannot copy a unique pointer

#include<iostream>
#include<string>
#include<memory>

class Entity
{
public:
    Entity()
    {
        std::cout  << "Created entity!" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Destroyed entity" << std::endl;
    }
    void print()
    {
        std::cout << "just printing something" << std::endl;
        
    }
};

int main()
{
    {
        // // needs to be called explicityly
        // std::unique_ptr<Entity> entity1 = std::make_unique<Entity>();
        // // will result in an errror 
        // // copy function is dleeted
        // std::unique_ptr<Entity> entity2 = entity1; // will result in an errror 
        // entity1->print();        
    }
    { 
        std::shared_ptr<Entity> e0;
        {
            // SHARED Pointers work by reference counting
            // as soon as the reference count reaches 0, it gets deleted.
            std::shared_ptr<Entity> shared_entity = std::make_shared<Entity>();
            shared_entity->print();
            e0 = shared_entity;
        }
    }
    std::cin.get();
}
