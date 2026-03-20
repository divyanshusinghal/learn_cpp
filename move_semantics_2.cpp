// Usage of std::move
// Usage of move assignment operator -> move an object to an existing object
#include<iostream>
#include<cstring>


class String
{
public:
    String(): m_Size(0), m_Data(nullptr){}

    String(const char* string)
    {
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }
    String(const String& other)
    {
        printf("Copied\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, other.m_Size);
    }

    String(String&& other) noexcept
    {
        printf("Moved\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;
        // now other does not point to anything, so we need to point it to null
        other.m_Size = 0;
        other.m_Data = nullptr;
    }
    String& operator=(String&& other) noexcept
    { // here we are not creating a new constructor
        // we are moving to current 
        printf("Moved\n");

        // basically if you try to assign it to itself, then this canot work.
        // you just return as it is
        if (this != &other)
        {
            delete[] m_Data;
            m_Size = other.m_Size;
            m_Data = other.m_Data;
            // now other does not point to anything, so we need to point it to null
            other.m_Size = 0;
            other.m_Data = nullptr;
        }
        return *this;

    }

    ~String()
    {
        printf("Destroyed");
        delete[] m_Data;
    }
    void Print()
    {
        for(u_int32_t i =0; i< m_Size; i++)
        {
            printf("%c", m_Data[i]);
        }
        printf("\n");
    }

private:
    u_int32_t m_Size;
    char* m_Data;
};

class Entity
{
public:
    Entity(const String& name): m_Name(name){}
    // we cna use std::move here only because we have overloaded it in String cclass
    Entity(String&& name): m_Name(std::move(name)){}

    void PrintName()
    {
        m_Name.Print();
    }

private:
    String m_Name;
};

int main()
{
    // Entity entity("Div");
    // entity.PrintName();

    // String string = "Hello";
    // String dest = string; // this is a copy;
    // // move constructor takes a temporary object (r value reference)

    // // BELOW we cast it to a rvalue.
    // String dest2 = (String&&) string; // this is a copy;

    // // below is a cleaner way of doing this
    // String dest3(std::move(string));

    String apple = "Apple";
    String dest;

    std::cout << "Before Move:\n";
    apple.Print();
    dest.Print();

    dest = std::move(apple);
    std::cout << "After Move:\n";
    
    apple.Print();
    dest.Print();

    std::cin.get();

} 